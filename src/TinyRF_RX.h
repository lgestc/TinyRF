#ifndef TINYRF_RX_H
#define TINYRF_RX_H

#include "TinyRF.h"

//todo: add TINYRF_ to all global variables and defines or add them to namespace
//Constants
const uint8_t TINYRF_ERR_SUCCESS = 0;
const uint8_t TINYRF_ERR_NO_DATA = 1;
const uint8_t TINYRF_ERR_BAD_CRC = 2;
const uint8_t TINYRF_ERR_BUFFER_OVERFLOW = 3;
//only define this constant if ERROR_CHECKING_NONE is not defined so that user will get an error
//when they try to use this in their code with error checking disabled
#ifndef ERROR_CHECKING_NONE
const uint8_t TINYRF_ERR_DUPLICATE_MSG = 4;
#endif


/**
 * Buffer size, i.e. number of bytes received that will be buffered.
 * When buffer is full it will start rewriting from the beggining
**/
const uint16_t RX_BUFFER_SIZE = 256;


/**
 * Function definitions
**/
void setupReceiver(uint8_t pin);
void interrupt_routine();
uint8_t getReceivedData(byte buf[], uint8_t bufSize, uint8_t &numRcvdBytes, uint8_t &numLostMsgs);
uint8_t getReceivedData(byte buf[],  uint8_t bufSize, uint8_t &numRcvdBytes);


#endif	/* TINYRF_RX_H */