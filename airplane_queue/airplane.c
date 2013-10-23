/* 
 * File:   airplane.c
 * Author: mike
 *
 * Created on October 21, 2013, 10:26 AM
 */

#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>

#define VERBOSE 0
#define TEST 0

/*change this for our implementation*/
#if !TEST

typedef struct {
    int num;
} Data, *QueueData;
#include "queueL.h"

#endif

typedef struct {
    bool vacant;
    int busyTime;
} RunwayData, *Runway;

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
#if TEST
    // so that we dont run into the issue of having two main functions...    
    //testLinkedQueue(); // remember to comment out whichever one isnt being used.
    //testArrayQueue();  
    queueTest(); // run queue test
#endif

    srand(time(NULL)); // initilize random with time seed value.

#if !TEST
    // get user input for the the time and frequency ratios
    int result = 0;
    int timeDuration = 0;
    double arrivalAirProb = 0;
    double arrivalGroundProb = 0;

    while (result != 1) {
        printf("Time Duration: ");
        result = scanf("%d", &timeDuration);
        if (timeDuration > 100) {
            result = 0;
        }
    }
    result = 0; // reset result 
    while (result != 1) {
        printf("Arrival Air Probobility: ");
        result = scanf("%lf", &arrivalAirProb);
        if (arrivalAirProb > 1) {
            result = 0;
        }
    }
    result = 0; // reset result 
    while (result != 1) {
        printf("Arrival Ground Probobility: ");
        result = scanf("%lf", &arrivalGroundProb);
        if (arrivalGroundProb > 1) {
            result = 0;
        }
    }

    printf("\n\n"); // create separator

    simulate(timeDuration, arrivalAirProb, arrivalGroundProb); // run simulation with given values

#endif

    // predefined test cases.
    //   simulate(5, .4, .4);
    //   simulate(10, .1, .1);
    //   simulate(10, .1, .1);

    return (EXIT_SUCCESS);
}
#if !TEST

simulate(int timeDuration, double arrivalAirProb, double arrivalGroundProb) {
    //SIMULATION VARIABLES
    int timeCounter = 0;
    int totalAir = 0;
    int totalGround = 0;
    // init all queues
    Queue airQueue = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
    Queue groundQueue = (Queue) malloc(sizeof (QueueType));
    airQueue = initQueue();
    groundQueue = initQueue();
    // init the runway
    Runway runway = (Runway) malloc(sizeof (RunwayData)); // allocate base size of queue;
    runway->vacant = true;

    while (timeDuration > timeCounter) {
        // track current time counter
        printf("Time Counter = '%d' seconds\n", timeCounter);

        //randomize probobility generator
        float randomAir = rand() / (double) RAND_MAX; // RAND_MAX is a system defined number
        float randomGround = rand() / (double) RAND_MAX;

#if VERBOSE
        printf("randomAir = %f and arrivalAirProb = %f\n", randomAir, arrivalAirProb);
#endif

        // decide if airplane gets added to air
        if (randomAir < arrivalAirProb) {
            // decide if a second airplane gets added to the air queue
            if (randomAir < arrivalAirProb * arrivalAirProb) {
                QueueData airplane = malloc(sizeof (QueueData)); // allocate space for new airplane
                airplane->num = rand() % 1000; // returns a random number between 0 and 999
                enqueue(airQueue, airplane); // add plane to queue
                totalAir++;
                printf("Airplane #%d joined air queue.\n", airplane->num);
            }
            QueueData airplane = malloc(sizeof (QueueData)); // allocate space for new airplane
            airplane->num = rand() % 1000; // returns a random number between 0 and 999
            enqueue(airQueue, airplane); // add plane to queue
            totalAir++;
            printf("Airplane #%d joined air queue.\n", airplane->num);
        }
        printf("Total planes waiting to land = %d\n", totalAir);

#if VERBOSE	  
        printf("randomGround = %f and arrivalGroundProb = %f\n", randomGround, arrivalGroundProb);
#endif	  

        //decide if airplane get added to ground
        if (randomGround < arrivalGroundProb) {
            QueueData airplane = malloc(sizeof (QueueData));
            airplane->num = rand() % 1000; // returns a random number between 0 and 999
            enqueue(groundQueue, airplane);
            totalGround++;
            printf("Airplane #%d joined ground queue.\n", airplane->num);
        }
        printf("Total planes waiting to take off = %d\n", totalGround);



        printf("\n\n");
        sleep(1);
        timeCounter++;
    }
}


//////////////  HELPER FUNCTIONS  //////////////////

bool addToAir(double arrivalAirProb) {

}

bool addToGroud(double arrivalGroudProb) {

}
#endif