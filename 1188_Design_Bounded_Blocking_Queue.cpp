#include <iostream>
#include <semaphore.h>
#include <queue>
#include <functional>

using namespace std;


class BoundedBlockingQueue {
private:
    sem_t sem;
    condition_variable cv;
    queue<int> q;
    mutex mtx;

public:
    BoundedBlockingQueue(int capacity) {
        sem_init(&sem, 0, capacity);
    }

    void enqueue(int element) {
        sem_wait(&sem);
        q.emplace(element);
        cv.notify_all()
    }

    int dequeue() {
        unique_lock lk(mtx);
        cv.wait(lk, [this] { return q.size() > 0; });

        int ret = q.front();
        q.pop();
        sem_post(&sem);

        lk.unlock();
        return ret;
    }

    int size() {
        return q.size();
    }
};
