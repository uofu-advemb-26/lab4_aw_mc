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
        
        struct signal_data *args = data;

        if (xSemaphoreTake(request, portMAX_DELAY) == pdTRUE) {
            // if we receive the request, we compute the output, then give the response semaphore
            args->output = args->input + (int32_t) 5;
            // compute something then give semaphore
            xSemaphoreGive(response); 

            // NEED TO WAIT FOR ACKNOWLEDGE that response has been taken by requester successfully
        }
        // NEED TO REASON about how to successfully give response
        // try to take response (wait) then give request

        if (xSemaphoreTake(ack) == pdTRUE){
            xSemaphoreGive(request);
        }
        xSemaphoreTake(response);

        xSemaphoreGive(ack);
        
    }
// This function requests the data
BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
    {
        // TAKE ACK (other semaphotre - symbol that system is ready)
        xSemaphoreTake(ack);
        // take semaphore first, then do something with data
        xSemaphoreGive(request);

        BaseType_t result = xSemaphoreTake(response, portMAX_DELAY);
        // need to give result for initial state

        // GIVE ACK
        xSemaphoreGive(ack);

        // wait for request
        xSemaphoreTake(request);
        xSemaphoreGive(response);
        
    }
