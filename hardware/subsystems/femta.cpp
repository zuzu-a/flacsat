#include "femta.h"
class FEMTA {

    public:
    // Mutex
    pthread_mutex_t mutex;

    // Calibrations
    uint8_t dac_map[NUM_THR];
    double  dac_cal[NUM_THR][2];

    uint8_t adc_map[AD7490_NUM_CHAN*2];
    double  adc_cal[AD7490_NUM_CHAN*2][3];

    // FEMTA constructor... or initializer
    FEMTA() {

        // Initialize and lock mutex.
        pthread_mutex_init(&mutex, NULL);
        pthread_mutex_lock(&mutex);

        // DAC calibrations.
        dac_map[THRUSTER_PPY_FWD] = 4; // femta 1
        dac_map[THRUSTER_PPY_AFT] = 4; // femta 1
        dac_map[THRUSTER_PPX_FWD] = 5; // femta 2
        dac_map[THRUSTER_PPX_AFT] = 5; // femta 2
        dac_map[THRUSTER_PNX_FWD] = 6; // femta 3
        dac_map[THRUSTER_PNX_AFT] = 6; // femta 3
        dac_map[THRUSTER_PNY_FWD] = 7; // femta 4
        dac_map[THRUSTER_PNY_AFT] = 7; // femta 4
        dac_map[THRUSTER_NNY_FWD] = 0; // femta 5
        dac_map[THRUSTER_NNY_AFT] = 0; // femta 5
        dac_map[THRUSTER_NNX_AFT] = 1; // femta 6
        dac_map[THRUSTER_NNX_FWD] = 1; // femta 6 
        dac_map[THRUSTER_NPX_AFT] = 2; // femta 7
        dac_map[THRUSTER_NPX_FWD] = 2; // femta 7
        dac_map[THRUSTER_NPY_FWD] = 3; // femta 8
        dac_map[THRUSTER_NPY_AFT] = 3; // femta 8

        dac_cal[THRUSTER_PPX_FWD][0] = 82.4297;
        dac_cal[THRUSTER_PPX_FWD][1] = -21.3608;
        dac_cal[THRUSTER_PPY_FWD][0] = 82.4297;
        dac_cal[THRUSTER_PPY_FWD][1] = -21.3608;
        dac_cal[THRUSTER_PNX_FWD][0] = 82.4297;
        dac_cal[THRUSTER_PNX_FWD][1] = -21.3608;
        dac_cal[THRUSTER_PNY_FWD][0] = 82.4297;
        dac_cal[THRUSTER_PNY_FWD][1] = -21.3608;
        dac_cal[THRUSTER_NPX_FWD][0] = 82.4297;
        dac_cal[THRUSTER_NPX_FWD][1] = -21.3608;
        dac_cal[THRUSTER_NPY_FWD][0] = 82.4297;
        dac_cal[THRUSTER_NPY_FWD][1] = -21.3608;
        dac_cal[THRUSTER_NNX_FWD][0] = 82.4297;
        dac_cal[THRUSTER_NNX_FWD][1] = -21.3608;
        dac_cal[THRUSTER_NNY_FWD][0] = 82.4297;
        dac_cal[THRUSTER_NNY_FWD][1] = -21.3608;
        dac_cal[THRUSTER_PPX_AFT][0] = 82.4297;
        dac_cal[THRUSTER_PPX_AFT][1] = -21.3608;
        dac_cal[THRUSTER_PPY_AFT][0] = 82.4297;
        dac_cal[THRUSTER_PPY_AFT][1] = -21.3608;
        dac_cal[THRUSTER_PNX_AFT][0] = 82.4297;
        dac_cal[THRUSTER_PNX_AFT][1] = -21.3608;
        dac_cal[THRUSTER_PNY_AFT][0] = 82.4297;
        dac_cal[THRUSTER_PNY_AFT][1] = -21.3608;
        dac_cal[THRUSTER_NPX_AFT][0] = 82.4297;
        dac_cal[THRUSTER_NPX_AFT][1] = -21.3608;
        dac_cal[THRUSTER_NPY_AFT][0] = 82.4297;
        dac_cal[THRUSTER_NPY_AFT][1] = -21.3608;
        dac_cal[THRUSTER_NNX_AFT][0] = 82.4297;
        dac_cal[THRUSTER_NNX_AFT][1] = -21.3608;
        dac_cal[THRUSTER_NNY_AFT][0] = 82.4297;
        dac_cal[THRUSTER_NNY_AFT][1] = -21.3608;

        // ADC calibrations.
        adc_map[THRUSTER_PPY_FWD] = 9; // femta 1
        adc_map[THRUSTER_PPY_AFT] = 9; // femta 1
        adc_map[THRUSTER_PPX_FWD] = 7; // femta 2
        adc_map[THRUSTER_PPX_AFT] = 7; // femta 2
        adc_map[THRUSTER_PNX_FWD] = 6; // femta 3
        adc_map[THRUSTER_PNX_AFT] = 6; // femta 3
        adc_map[THRUSTER_PNY_FWD] = 5; // femta 4
        adc_map[THRUSTER_PNY_AFT] = 5; // femta 4
        adc_map[THRUSTER_NNY_FWD] = 4; // femta 5
        adc_map[THRUSTER_NNY_AFT] = 4; // femta 5
        adc_map[THRUSTER_NNX_AFT] = 3; // femta 6
        adc_map[THRUSTER_NNX_FWD] = 3; // femta 6 
        adc_map[THRUSTER_NPX_AFT] = 1; // femta 7
        adc_map[THRUSTER_NPX_FWD] = 1; // femta 7
        adc_map[THRUSTER_NPY_FWD] = 0; // femta 8
        adc_map[THRUSTER_NPY_AFT] = 0; // femta 8

        adc_map[HEATER_TANK_FWD]    = 10;
        adc_map[HEATER_TANK_FWD+1]  = 11;
        adc_map[HEATER_FEMTA_FWD]   = 8;
        adc_map[HEATER_FEMTA_FWD+1] = 2;
        adc_map[HEATER_TANK_AFT]    = 10;
        adc_map[HEATER_TANK_AFT+1]  = 11;
        adc_map[HEATER_FEMTA_AFT]   = 8;
        adc_map[HEATER_FEMTA_AFT+1] = 2;

    }

};