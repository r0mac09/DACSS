#include <cstdio>
#include <cstdlib>
#include <list>
#include <iostream>
#include <windows.h>

#include "chair.hpp"

void sleep(unsigned milliseconds)
{
    Sleep(milliseconds);
}

class Worker {
    // The first letter of teh workers name determines the task that he is able to do
    char name[20];

    // Pointers to the specific tasks and pId of a specific chair
    void (*task)(Chair* chair);
    bool (*isDone)(Chair* chair);
    int (*getPID)(Chair* chair);

public:
    Worker(const char* name) {     
        sprintf(this->name, "%-19s", name);
    }

    // This function determines the task and performs it 
    Chair* work(Chair* chair) {
        if (!chair) {
            printf("ERROR : WORKER : %s : work() : Worker recieved null chair pointer\n", name);
        }

        char qualif = name[0];

        switch(qualif) {
            case 'A':
                this->task   = (void (*)(Chair*))A;
                this->isDone = (bool (*)(Chair*))Adone;
                break;
            case 'B':
                this->task   = (void (*)(Chair*))B;
                this->isDone = (bool (*)(Chair*))Bdone;
                break;
            case 'C':
                this->task   = (void (*)(Chair*))C;
                this->isDone = (bool (*)(Chair*))Cdone;
                break;
            case 'F':
                this->task   = (void (*)(Chair*))F;
                this->isDone = (bool (*)(Chair*))Fdone;
                break;
            case 'P':
                this->task   = (void (*)(Chair*))P;
                this->isDone = (bool (*)(Chair*))Pdone;
                break;
            case 'S':
                this->task   = (void (*)(Chair*))S;
                this->isDone = (bool (*)(Chair*))Sdone;
                break;
            default:
                printf("WORKER : %s : I'm not qualified for this task. Who gave me this chair?\n", name);
                return chair;
        }
        this->getPID = (int (*)(Chair*))getPID;

        // If the task is already done, don't do anything
        if ((*isDone)(chair)) {
            printf("WORKER : %s : This task is already done for chair %d. I won't do anything.\n", name, getPID(chair));
            return chair;
        }

        // Basically just wait for half a second
        sleep(500);
        // Perform the task
        this->task(chair);
        printf("WORKER : %s : I've done my task for chair %d\n", name, getPID(chair));

        return chair;
    }

    // To be used for variant 3
    //
    const char* getName() { return name; }
    void acknowledge(Chair*) {
        printf("WORKER : %s : acknowledge() : Uuuuuuhmmmmm..... What?\n", name);
    };
};

