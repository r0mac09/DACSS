#include <cstdio>
#include <cstdlib>

#include "worker.hpp"

class EventBus;

class EvWorker : public Worker {
    EventBus* evBus;
public:
    EvWorker(const char* name, EventBus* evBus) : Worker(name) {
        this->evBus = evBus;
    }

    void notify(Chair* chair); 

    void acknowledge(Chair* chair) {
        printf("WORKER : %s : acknowledge() : I've been given work to do!\n", this->getName());
        notify(chair);
    }
};

class EventBus
{
private:
    Worker* Bogdan;
    Worker* Costel;
    Worker* Florin;
    Worker* Petrica;
    Worker* Stelica;
    Chair* chair;
public:
    EventBus() {
        Bogdan  = new EvWorker("Bogdan", this);
        Costel  = new EvWorker("Costel", this);
        Florin  = new EvWorker("Florin", this);
        Petrica = new EvWorker("Petrica", this);
        Stelica = new EvWorker("Stelica", this);
        chair = new Chair(312321);
        assign();
    }
    ~EventBus() {
        delete Bogdan;
        delete Costel;
        delete Florin;
        delete Petrica;
        delete Stelica;
        delete chair;
    }

    void acknowledge(Chair* chair) {
        if (chair->isDone(NORMAL_CHAIR)) {
            printf("EVENT BUS : acknowledge() : Normal chair complete.");
            return;
        } else assign();
    }

    void assign() {
        if (!chair->Bdone(chair)) {
            printf("EVENT BUS : assign() : I've assigned Bogdan to work further on this chair.\n");
            Bogdan->acknowledge(chair);
        } else if (!chair->Cdone(chair)) {
            printf("EVENT BUS : assign() : I've assigned Costel to work further on this chair.\n");
            Costel->acknowledge(chair);
        } else if (!chair->Fdone(chair)) {
            printf("EVENT BUS : assign() : I've assigned Florin to work further on this chair.\n");
            Florin->acknowledge(chair);
        } else if (!chair->Pdone(chair)) {
            printf("EVENT BUS : assign() : I've assigned Petrica to work further on this chair.\n");
            Petrica->acknowledge(chair);
        } else if (!chair->Sdone(chair)) {
            printf("EVENT BUS : assign() : I've assigned Stelica to work further on this chair.\n");
            Stelica->acknowledge(chair);
        } else {
            printf("EVENT BUS : assign() : Uhmmmmmm..... I'm lost ...\n");
            return;
        }
    }
};

void EvWorker::notify(Chair* chair) {
        evBus->acknowledge(this->work(chair));
    }


int main(void) {
    EventBus* evBus = new EventBus();

    return 0;
}