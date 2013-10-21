
/* 
 * File:   airplane.c
 * Author: mike
 *
 * Created on October 21, 2013, 10:26 AM
 */

#include <stdlib.h>
#include <stdio.h> 
#include <time.h> // for creating truly random numbers
#include <unistd.h> // for use of the sleep function

/*change this for our implementation*/
//typedef struct {
//    int num;
//} Data, *QueueData;

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
//int testLinkedQueue();
//
//int testLinkedQueue() {
//    srand(time(NULL)); // initalize random with a seed value from the current epoch time
//    int r = rand();
//
//    // create a random number between 0 and 1
//    float randNumb = rand() / (double) RAND_MAX; // RAND_MAX is a system defined number
//    int y = 0;
//    for (y = 0; y < 20; y++) {
//        randNumb = rand() / (double) RAND_MAX; // RAND_MAX is a system defined number
//        printf("randNumb == %f\n", randNumb);
//    }
//
//
//    // create a queue and add some values to it
//    Queue queue = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
//    queue = initQueue();
//
//    int x = 0;
//    for (x = 0; x < 10; x++) {
//        QueueData np = malloc(sizeof (QueueData));
//        np->num = x; // will hit a segmentation fault if you do not malloc first.
//        enqueue(queue, np);
//        printf("enqueue -> %d\n", x);
//        //sleep(1); // sleep for one second
//    }
//
//    for (x = 0; x < 8; x++) {
//        printf("dequeue -> %d\n", dequeue(queue)->num);
//    }
//    
//    // checking getFront function
//    printf("getFront -> %d\n", getFront(queue)->num);
//    printf("getFront -> %d\n", getFront(queue)->num);
//    
//
//
//
//
//
//    return (EXIT_SUCCESS);
//}
//
