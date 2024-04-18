#include "satellite.h"

///////////////////////////////////////////
//
// PURPOSE: builds and instance of FLaCSat satellite
//
// RETURN: pointer to satellite
//
///////////////////////////////////////////

class Satellite {

    public:

    pthread_mutex_t mutex;

    Satellite() {
        
        pthread_mutex_init(&mutex, NULL);
        pthread_mutex_lock(&mutex);

        cdh = CDH CDH();
        comm = COMM COMM();
        eps = EPS EPS();
        adcs = ADCS ADCS();
        laser = LASER LASER();
        femta = FEMTA FEMTA();
        femta.boot();

        pthread_mutex_unlock(&mutex);
    }

    void free() {

        pthread_mutex_lock(&mutex);

        cdh.free();
        comm.free();
        eps.free();
        adcs.free();
        laser.free();
        femta.free();

        pthread_mutex_unlock(&mutex);
        pthread_mutex_destroy(&mutex);

        delete Satellite
        
    }

    ~Satellite() {
        free();
    }

};
