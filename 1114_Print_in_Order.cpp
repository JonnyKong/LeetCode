#include <semaphore.h>
#include <functional>

using namespace std;

// Semaphores
class Foo {
    sem_t s1;
    sem_t s2;
public:
    Foo() {
        sem_init(&s1, 0, 0);
        sem_init(&s2, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        sem_post(&s1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&s1);
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        sem_post(&s2);
    }

    void third(function<void()> printThird) {
        sem_wait(&s2);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

// No sync primitives used: very slow
class Foo2 {
    int order;
public:
    Foo2() {
        order = 1;
    }

    void first(function<void()> printFirst) {
        while (order != 1) {}
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        order = 2;
    }

    void second(function<void()> printSecond) {
        while (order != 2) {}
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        order = 3;
    }

    void third(function<void()> printThird) {
        while (order != 3) {}
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};