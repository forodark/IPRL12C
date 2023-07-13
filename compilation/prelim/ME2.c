#include <stdio.h>
#include "../glencrypt.h"

float getCharge(int n) {
    float charge = 0;
    if (n>200)
    {
        charge = (n-200)*0.5;
    }
    return charge;
}

void ME2() {
    int n = 0;
    float charge = 0;
    printf(
            "Send Fail Telecoms Charge Calculator\n"
            "------------------------------------\n"
            "For the first 200 messages, the charge\n"
            "is zero, any messages beyond that will\n"
            "charge Php 0.5 per message.\n"
            "------------------------------------\n");
    input(Int, "Please input number of messages: ", &n);
    
    printf("\n------------------------------------\n"
            "The charge incurred is: Php %.2f\n", getCharge(n));
            
}
