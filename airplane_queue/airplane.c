/* 
 * File:   airplane.c
 * Author: mike
 *
 * Created on October 21, 2013, 10:26 AM
 */

#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>


/*change this for our implementation*/
//typedef struct {
//    int num;
//} QueueData;
//
//#include "queueL.h"

/* MUST INCLUDE ALL OF THESE TYPES
airQ: Queue,
groundQ: Queue,
airplane: QueueData - struct {int id}
runway: pointer to struct {bool vacant; int timeTillVacant}
randomAir: decimal number between 0 and 1
randomGr: decimal number between 0 and 1
randomID: integer 3-digit number
 */

int main(int argc, char** argv) {

    // so that we dont run into the issue of having two main functions...    
    //testLinkedQueue(); // remember to comment out whichever one isnt being used.
    //testArrayQueue();

    simulate(10,.1,.1);

    return (EXIT_SUCCESS);
}

simulate(int timeDuration, double arrivalAirProb, double arrivalGroundProb) {
    int timeCounter = 0;
    while(timeDuration > timeCounter){
        
        // add simulate function here
        
        
        printf("Time Counter = '%d' seconds\n", timeCounter);
        
        
        sleep(1);
        timeCounter++;
    }
}


//////////////  HELPER FUNCTIONS  //////////////////

bool addToAir(double arrivalAirProb) {

}

bool addToGroud(double arrivalGroudProb) {

}