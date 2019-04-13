#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

#include <chair.hpp>
#include <worker.hpp>

// TO DO: IMPLEMENT THE MUTI THREADED MECHANISM

class Factory
{
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

    
};