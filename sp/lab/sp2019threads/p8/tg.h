#ifndef _tg_h
#define _tg_h
#include <thread>
class TGuard {
    public:
        enum class DMethod {join, detach};
        TGuard(std::thread &&t, DMethod m = DMethod::join) :
            t_{std::move(t)}, m_{m} {}
        ~TGuard() {
            if ( t_.joinable()  )
                (m_ == DMethod::join) ? t_.join() : t_.detach();

        }
        std::thread& get() {
            return t_;

        }
    private:
        DMethod m_;
        std::thread t_;

};
#endif
