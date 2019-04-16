#include <cstdio>
#include <cstdlib>

#include "worker.hpp"

class Balckboard {
    Worker* Andrei;
    Worker* Bogdan;
    Worker* Costel;
    Worker* Florin;
    Worker* Petrica;
    Worker* Stelica;
    Chair** chairs;
    int chairCnt;
public:
    Balckboard() {
        Bogdan  = new Worker("Bogdan");
        Costel  = new Worker("Costel");
        Florin  = new Worker("Florin");
        Petrica = new Worker("Petrica");
        Stelica = new Worker("Stelica");
        chairs = nullptr;
        chairCnt = 0;
    }

    ~Balckboard() {
        delete Bogdan;
        delete Costel;
        delete Florin;
        delete Petrica;
        delete Stelica;
        for(int i = 0; i < chairCnt; i++) delete chairs[i];
        free(chairs);
    }

    void addChair(const int productId) {
        chairs = (Chair**)realloc(chairs, sizeof(Chair*)*(chairCnt+1));
        if (!chairs) {
            printf("ERROR : BLACKBOARD : addChair() : FATAL MEMORY ALLOCATION ERROR\n");
            exit(1);
        }

        chairs[chairCnt] = new Chair(productId);
        if (!chairs[chairCnt]) {
            printf("ERROR : BLACKBOARD : addChair() : MEMORY ALLOCATION ERROR\n");
            return;
        }

        chairCnt++;
    }

    void removeChair(const int index) {
        Chair** tmp = (Chair**)malloc(sizeof(Chair*)*(chairCnt-1));

        if (!tmp) {
            printf("ERROR : BLACKBOARD : removeChair() : MEMORY ALLOCATION ERROR\n");
            return;
        }

        for(int i = 0, j = 0; i < chairCnt; i++) {
            if (i == index) continue;
            tmp[j] = chairs[i];
            j++;
        }

        delete chairs[index];
        free(chairs);
        chairs = tmp;
        chairCnt--;
    }

    void assignWork() {
        for(int i = 0; i < chairCnt; i++) {
            if (chairs[i]->isDone(NORMAL_CHAIR)) {
                printf("BLACKBOARD : assignWork() : Chair with product ID %d completed\n", getPID(chairs[i]));
                removeChair(i);
                continue;
            }

            Bogdan->work(chairs[i]);
            Costel->work(chairs[i]);
            Florin->work(chairs[i]);
            Petrica->work(chairs[i]);
            Stelica->work(chairs[i]);
        }
    }

};

int main(void) {
    Balckboard* balckboard = new Balckboard();

    balckboard->addChair(3264);
    balckboard->addChair(3173);
    balckboard->addChair(5365);
    balckboard->addChair(2432);
    balckboard->addChair(2411);

    balckboard->assignWork();

    balckboard->addChair(1225);
    balckboard->addChair(1332);
    balckboard->addChair(7681);

    balckboard->assignWork();

    delete balckboard;

    return 0;
}