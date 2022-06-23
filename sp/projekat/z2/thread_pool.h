#ifndef thread_pool_
#define thread_pool_
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <atomic>
#include <type_traits>
#include <iostream>
#include <stdexcept>

using function_t = std::function<void()>;

class task_queue {
  public:
    bool blocking_pop(function_t& fun) {
      std::unique_lock<std::mutex> queue_lock{mtx_};
      while ( tasks_.empty() ) {
        if ( stopped_ ) return false;
        cv_.wait(queue_lock);
      }
      fun = std::move(tasks_.front());
      tasks_.pop();
      return true;
    }

    bool pop(function_t& fun) {
      std::lock_guard<std::mutex> queue_lock{mtx_};
      if ( tasks_.empty() ) {
        return false;
      }

      fun = std::move(tasks_.front());
      tasks_.pop();
      return true;
    }

    template<typename F>
      void push(F&& f) {
        {
          std::unique_lock<std::mutex> queue_lock{mtx_};
          tasks_.emplace(std::forward<F>(f));
        }
        cv_.notify_one();
      }

    void stop() {
      {
        std::unique_lock<std::mutex> queue_lock{mtx_};
        stopped_ = true;
      }
      cv_.notify_all();
    }

  private:
    std::queue<function_t> tasks_;
    std::mutex mtx_;
    std::condition_variable cv_;
    bool stopped_ = false;
};

class thread_pool {
  public:
    thread_pool(size_t th_num = std::thread::hardware_concurrency()) : thread_number_{th_num}, tasks_(th_num) {
      for(int i = 0; i < thread_number_; ++i) {
        threads_.emplace_back( std::thread{ [this, i](){ run(i); }});
      }
    }

    ~thread_pool() {
      for (auto &t : tasks_)
        t.stop();
      for(auto &t : threads_ )
        t.join();
    }

    template<typename T>
      void async(T&& fun) {
        tasks_[cnt_++ % thread_number_].push(std::forward<T>(fun));
      }

  private:
    bool steal_task(int tn, function_t &fun) {
      for (int i = 0; i <= thread_number_; ++i) {
        if (tasks_[++tn % thread_number_].pop(fun)) {
          return true;
        }
      }
      return false;
    }

    void run(int thread_order_number) {
      while(true) {
        function_t fun;
        if (tasks_[thread_order_number].pop(fun)) {
          fun();
        } else {
          if (!steal_task(thread_order_number, fun) && !tasks_[thread_order_number].blocking_pop(fun))
            return;
          fun();
        }
      }
    }

    const size_t thread_number_;
    int cnt_{0};
    std::vector<std::thread> threads_;
    std::vector<task_queue> tasks_;
    std::mutex mtx_;
};

#endif /* ifndef thread_pool_ */

