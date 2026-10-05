#include "signaling.h"

struct signal_data {
    int32_t input;
    int32_t output;
};

// This function creates the data that is wanted by the other function
void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                                struct signal_data *data)
    {
    
        // compute something then give semaphore
    }
// This function requests the data
BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
    {
        // take semaphore first, then do something with data
    }
