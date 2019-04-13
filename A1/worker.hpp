#include <cstdio>
#include <cstdlib>
#include <list>

#include <chair.hpp>

class Worker {
    // The first letter of teh workers name determines the task that he is able to do
    char name[20];

    // Pointers to the specific tasks and pId of a specific chair
    void (*task)(void);
    bool (*isDone)(void);
    int (*getPID)(void);
public:
    Worker(const char* name) {     
        sprintf(this->name, "%19s", name);
    }

    // This function determines the task and performs it 
    void work(Chair* chair) {
        switch(name[0]) {
            case 'A':
                this->task = chair->A;
                this->isDone = chair->Adone;
            case 'B':
                this->task = chair->B;
                this->isDone = chair->Bdone;
            case 'C':
                this->task = chair->C;
                this->isDone = chair->Cdone;
            case 'F':
                this->task = chair->F;
                this->isDone = chair->Fdone;
            case 'P':
                this->task = chair->P;
                this->isDone = chair->Pdone;
            case 'S':
                this->task = chair->S;
                this->isDone = chair->Sdone;
            default:
                printf("%20s: I'm not qualified for this task. Who gave me this chair?\n", name);
                return;
        }
        this->getPID = chair->getPID;

        // If the task is already done, don't do anything
        if(isDone()) {
            printf("%20s: This task is already done for chair %d. I won't do anything.\n", name, getPID());
            return;
        }

        // Basically just wait for half a second
        _sleep(500);
        // Perform the task
        this->task();
        printf("%20s: I've done my task for chair %d\n", name, getPID());
    }
};