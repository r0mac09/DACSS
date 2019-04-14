#include <cstdio>
#include <cstdlib>

#include "worker.hpp"

class Factory {
private:
    Worker* Andrei;
    Worker* Bogdan;
    Worker* Costel;
    Worker* Florin;
    Worker* Petrica;
    Worker* Stelica;

public:
    Factory() {
        Andrei  = new Worker("Andrei");
        Bogdan  = new Worker("Bogdan");
        Costel  = new Worker("Costel");
        Florin  = new Worker("Florin");
        Petrica = new Worker("Petrica");
        Stelica = new Worker("Stelica");
    }

    ~Factory() {
        delete Andrei;
        delete Bogdan;
        delete Costel;
        delete Florin;
        delete Petrica;
        delete Stelica;
    }

    Chair* makeNormalChair(const int productId) {
        Chair* chair = new Chair(productId);

        if(!chair) {
            printf("ERROR : FACTORY : makeNormalChair(%d) : MEMORY ALLOCATION ERROR\n", productId);
            exit(1);
        }

        // PIPELINE
        chair = Petrica->work(Stelica->work(Bogdan->work(Florin->work(Costel->work(chair)))));

        if(!chair) {
            printf("ERROR : FACTORY : makeNoBackrestChair(%d) : NULL CHAIR AFTER\n", productId);
        }

        if(!chair->isDone(NORMAL_CHAIR)) {
            printf("FACTORY : makeNormalChair(%d) : Final chair does not match the requested product\n", productId);
        } else {
            printf("FACTORY : makeNormalChair(%d) : Final chair COMPLETE\n", productId);
        }

        return chair;
    }

    Chair* makeArmrestChair(const int productId) {
        Chair* chair = new Chair(productId);

        if(!chair) {
            printf("ERROR : FACTORY : makeArmrestChair(%d) : MEMORY ALLOCATION ERROR\n", productId);
            exit(1);
        }

        // PIPELINE
        chair = Petrica->work(Andrei->work(Stelica->work(Bogdan->work(Florin->work(Costel->work(chair))))));

        if(!chair) {
            printf("ERROR : FACTORY : makeArmrestChair(%d) : NULL CHAIR AFTER\n", productId);
        }

        if(!chair->isDone(ARMREST_CHAIR)) {
            printf("FACTORY : makeArmrestChair(%d) : Final chair does not match the requested product\n", productId);
        } else {
            printf("FACTORY : makeArmrestChair(%d) : Final chair COMPLETE\n", productId);
        }

        return chair;
    }

    Chair* makeNoBackrestChair(const int productId) {
        Chair* chair = new Chair(productId);

        if(!chair) {
            printf("ERROR : FACTORY : makeNoBackrestChair(%d) : MEMORY ALLOCATION ERROR\n", productId);
            exit(1);
        }

        // PIPELINE
        chair = Petrica->work(Stelica->work(Florin->work(Costel->work(chair))));

        if(!chair) {
            printf("ERROR : FACTORY : makeNoBackrestChair(%d) : NULL CHAIR AFTER\n", productId);
        }

        if(!chair->isDone(NOBACKREST_CHAIR)) {
            printf("FACTORY : makeNoBackrestChair(%d) : Final chair does not match the requested product\n", productId);
        } else {
            printf("FACTORY : makeNoBackrestChair(%d) : Final chair COMPLETE\n", productId);
        }

        return chair;
    }

    // This function chooses which type of chair will be built based on the chair type
    Chair* makeChair(const unsigned char chairType, const int productId) {
        switch(chairType) {
            case ARMREST_CHAIR :
                printf("FACTORY : makeChair() : Recieved order for a chair with armrest\n");
                return makeNormalChair(productId);
            case NOBACKREST_CHAIR :
                printf("FACTORY : makeChair() : Recieved order for a chair without backrest\n");
                return makeNoBackrestChair(productId);
            default :
                printf("FACTORY : makeChair() : Recieved order for a normal chair\n");
                return makeNormalChair(productId);
        }
    }
};

int main(void) {

    Factory* factory = new Factory();
    Chair* c1 = factory->makeChair(NORMAL_CHAIR, 123);
    Chair* c2 = factory->makeChair(ARMREST_CHAIR, 9432);
    Chair* c3 = factory->makeChair(NOBACKREST_CHAIR, 1312);

    if (c1) delete c1;
    if (c2) delete c2;
    if (c3) delete c3;

    delete factory;

    return 0;
}