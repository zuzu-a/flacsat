#ifndef FEMTA_H_   
#define FEMTA_H_

// DEFINITIONS

#define NUM_THR            16
#define VALVE_DELAY        15000
#define THERMISTOR_CURRENT 100E-6

// ENUMS

typedef enum {

  THRUSTER_ALL     = 16,
  THRUSTER_FWD     = 17,
  THRUSTER_AFT     = 18,
  THRUSTER_PPX_FWD = 0,
  THRUSTER_PPY_FWD = 1,
  THRUSTER_PNX_FWD = 2,
  THRUSTER_PNY_FWD = 3,
  THRUSTER_NNX_FWD = 4,
  THRUSTER_NNY_FWD = 5,
  THRUSTER_NPX_FWD = 6,
  THRUSTER_NPY_FWD = 7,
  THRUSTER_PPX_AFT = 8,
  THRUSTER_PPY_AFT = 9,
  THRUSTER_PNX_AFT = 10,
  THRUSTER_PNY_AFT = 11,
  THRUSTER_NNX_AFT = 12,
  THRUSTER_NNY_AFT = 13,
  THRUSTER_NPX_AFT = 14,
  THRUSTER_NPY_AFT = 15
  
} ThrusterType;

typedef enum {

  VALVE_ALL      = 0,
  VALVE_FWD      = 1,
  VALVE_AFT      = 2,
  VALVE_TANK_FWD = 3,
  VALVE_FILL_FWD = 4,
  VALVE_PPX_FWD  = 5,
  VALVE_PPY_FWD  = 6,
  VALVE_PNX_FWD  = 7,
  VALVE_PNY_FWD  = 8,
  VALVE_NNX_FWD  = 9,
  VALVE_NNY_FWD  = 10,
  VALVE_NPX_FWD  = 11,
  VALVE_NPY_FWD  = 12,
  VALVE_TANK_AFT = 13,
  VALVE_FILL_AFT = 14,
  VALVE_PPX_AFT  = 15,
  VALVE_PPY_AFT  = 16,
  VALVE_PNX_AFT  = 17,
  VALVE_PNY_AFT  = 18,
  VALVE_NNX_AFT  = 19,
  VALVE_NNY_AFT  = 20,
  VALVE_NPX_AFT  = 21,
  VALVE_NPY_AFT  = 22

} ValveType;

typedef enum {

  VALVE_CLOSE = 0,
  VALVE_OPEN  = 1

} ValveStateType;

typedef enum {

  HEATER_ALL       = 0,
  HEATER_FWD       = 1,
  HEATER_AFT       = 2,
  HEATER_TANK_FWD  = 16,
  HEATER_FEMTA_FWD = 18,
  HEATER_TANK_AFT  = 20,
  HEATER_FEMTA_AFT = 22,

} HeaterType;

typedef enum {

  HEATER_DISABLE = 0,
  HEATER_ENABLE  = 1

} HeaterStateType;

typedef enum {

  GPIO_ALL = 0,
  GPIO_FWD = 1,
  GPIO_AFT = 2

} GPIOType;

typedef enum {

  DPT_ALL       = 0,
  DPT_FWD       = 1,
  DPT_AFT       = 2,
  DPT_HFE_1_FWD = 3,
  DPT_HFE_2_FWD = 4,
  DPT_TANK_FWD  = 5,
  DPT_FILL_FWD  = 6,
  DPT_HFE_1_AFT = 3,
  DPT_HFE_2_AFT = 4,
  DPT_TANK_AFT  = 5,
  DPT_FILL_AFT  = 6

} DPTType;

typedef enum {

  ADC_ALL = 0,
  ADC_FWD = 1,
  ADC_AFT = 2

} ADCType;

typedef enum {

  DAC_ALL = 0,
  DAC_FWD = 1,
  DAC_AFT = 2

} DACType;

#endif