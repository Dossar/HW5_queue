
#define TEST 0
#if TEST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num;
} Data, *QueueData;

#include "queueL.h" 
//#include "queueA.h"

// Prototype
void queueTest();

// test function
void queueTest(void) {

    /* To clarify: I used rand to generate the number. scanf freaks out for me on NetBeans. */
    int n;
    Queue Q = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
    Q = initQueue();
    n = 123456; // Test on a 6-digit number
    printf("Digits in original order: %d", n);
    while (n > 0) {
        QueueData np = malloc(sizeof (QueueData));
        np->num = n%10; // will hit a segmentation fault if you do not malloc first.
        enqueue(Q, np);
        n = n / 10;
    }
    printf("\nDigits in reversed order: ");
    while (!isEmpty(Q))
        printf("%d", dequeue(Q)->num);
    printf("\n");    
    
/* I comment this part out because my NetBeans freaks out with scanf statements */
//    int n;
//    Queue Q = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
//    Q = initQueue();
//    printf("Enter a positive integer: ");
//    scanf("%d", &n);
//    while (n > 0) {
//        QueueData np = malloc(sizeof (QueueData));
//        np->num = n%10; // will hit a segmentation fault if you do not malloc first.
//        enqueue(Q, np);
//        n = n / 10;
//    }
//
//    printf("\nDigits in reverse order: ");
//    while (!isEmpty(Q))
//        printf("%d", dequeue(Q)->num);
//    printf("\n");
    
/* There were problems with adding to the head initially, so this snippet was to fix that problem */    
//    Queue testQueue = initQueue(); //Initialize S as a pointer to a Queue.
//    printf("The Queue has been initialized.\n");
//    
//    if( isEmpty(testQueue) )
//        printf("The Queue is currently empty.\n");
//    else
//        printf("The Queue is not empty.\n");
//    // Enter three randomly generated integers into the Queue
//    int s = 0;
//    while( s < 3 )
//    {
//        QueueData numinput = malloc(sizeof (QueueData));
//        numinput->num = rand()%1000;
//        enqueue(testQueue, numinput);
//        printf("%d has been added to the Queue.\n", numinput->num);
//        s++; 
//    }
//    if (isEmpty(testQueue))
//        printf("The Queue is currently empty.\n");
//    else
//        printf("The Queue is not empty.\n");
//    printf("The first element of the Queue is %d.\n", (getFront(testQueue))->num);
//    printf("Now emptying the Queue.\n");
//    while(!isEmpty(testQueue))
//        printf("%d has been removed from the Queue.\n", (dequeue(testQueue))->num);
//    if (isEmpty(testQueue))
//        printf("The Queue is currently empty.\n");
//    else
//        printf("The Queue is not empty.\n");

}
#endif
