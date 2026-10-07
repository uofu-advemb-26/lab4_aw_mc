#include "signaling.h"


// This function creates the data that is wanted by the other function
void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
    {
        
        struct signal_data *args = data;

        if (xSemaphoreTake(request, portMAX_DELAY) == pdTRUE) {
            // if we receive the request, we compute the output, then give the response semaphore
            args->output = args->input + (int32_t) 5;
            // compute something then give semaphore
            xSemaphoreGive(response); 
        }
        
    }
// This function requests the data
BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
    {
        // take semaphore first, then do something with data
        xSemaphoreGive(request);

        BaseType_t result = xSemaphoreTake(response, (TickType_t) 100);
        return result;
    }
