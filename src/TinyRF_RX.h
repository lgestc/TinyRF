#ifndef TRF_RX_H
#define TRF_RX_H

#include "TinyRF.h"


/**
 * Error codes returned by getReceivedData()
**/

#define TRF_ERR_SUCCESS 0
#define TRF_ERR_NO_DATA 1
#define TRF_ERR_CORRUPTED 2
#define TRF_ERR_BUFFER_OVERFLOW 3
//only define this constant if TRF_ERROR_CHECKING_NONE is not defined so that user will get an error
//when they try to use this in their code with error checking disabled
#ifndef TRF_ERROR_CHECKING_NONE
#define TRF_ERR_DUPLICATE_MSG 4
#endif


/**
 * Buffer size, i.e. number of bytes received that will be buffered.
 * When buffer is full it will start rewriting from the beggining
 * Do not change
**/
#define TRF_RX_BUFFER_SIZE 256


/**
 * Function definitions
**/

// Sets up the receiver. Needs to be called in setup()
void setupReceiver(uint8_t pin);

void interrupt_routine();

// Gets "one" message from the received data buffer
// Number of received bytes will be put in numRcvdBytes
// Number of messages that were lost before this message will be put in numLostMsgs
// Returns one of the errors codes defined in TinyRF_RX.h
uint8_t getReceivedData(byte buf[], uint8_t bufSize, uint8_t &numRcvdBytes, uint8_t &numLostMsgs);

// Gets "one" message from the received data buffer
// Number of received bytes will be put in numRcvdBytes
// Returns one of the errors codes defined in TinyRF_RX.h
uint8_t getReceivedData(byte buf[],  uint8_t bufSize, uint8_t &numRcvdBytes);


#endif	/* TRF_RX_H */