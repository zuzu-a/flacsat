// Includes
#include "ad7490.h"

class AD7490 {

    public:
    
    pthread_mutex_t mutex;
    char * name;
    int bus;
    uint8_t cs;


    // Initialize the device.
    AD7490(char * name, uint8_t cs) {

        pthread_mutex_init(&(mutex), NULL); // Initialize mutex.
        pthread_mutex_lock(&(mutex)); // Lock mutex.


        if((bus = openSPI(cs, AD7490_SPI_MODE, AD7490_SPI_BPW, AD7490_SPI_SPEED)) == -1) {
            logError(SPI_BUS_ERROR, name);
        }

        return dev;

        }

    void open(bus) {
        // Initialize SPI
        spi.begin(bus);
    }

    void close(Device * dev) {
        // Close SPI
        spi.end();
    }

};