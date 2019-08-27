#include <semaphore.h>
#include <functional>

using namespace std;

class H2O {
    sem_t sem_o;
    sem_t sem_h;
public:
    H2O() {
        sem_init(&sem_o, 0, 0);
        sem_init(&sem_h, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_post(&sem_h);
        sem_wait(&sem_o);
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&sem_h);
        sem_wait(&sem_h);
        sem_post(&sem_o);
        sem_post(&sem_o);
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};