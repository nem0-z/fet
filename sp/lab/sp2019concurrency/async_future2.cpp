#include <thread>
#include <future>
#include <iostream>
#include <chrono>
#include <vector>

int main(){
    std::vector<std::future<size_t>> futures;

    for (size_t i = 0; i < 10; ++i) {
        futures.emplace_back(std::async(std::launch::async, [](size_t param){
            std::this_thread::sleep_for(std::chrono::seconds(param));
            return param;
        }, i));
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Start querying" << std::endl;

    for (auto &future : futures) {
      std::cout << future.get() << std::endl;
    }

    return 0;
}
