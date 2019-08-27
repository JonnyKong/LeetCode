#include <iostream>
#include <pthread.h>
#include <functional>


class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    int turn = 0;   // [zero, odd, zero, even]
    int num_to_print = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            unique_lock lk(mtx);
            cv.wait(lk, [this] { return turn == 0 || turn == 2; });
            turn = (turn + 1) % 4;

            printNumber(0);
            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock lk(mtx);
            cv.wait(lk, [this] { return turn == 3; });
            turn = (turn + 1) % 4;

            printNumber(num_to_print++);
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock lk(mtx);
            cv.wait(lk, [this] { return turn == 1; });
            turn = (turn + 1) % 4;

            printNumber(num_to_print++);
            lk.unlock();
            cv.notify_all();
        }
    }
};