
#define TEST 0
#if TEST

#include <stdio.h> 
#define MaxQ 10 

typedef struct {
    int num;
} Data, *QueueData;

#include "queueL.h" 

// Prototype
void queueTest();

// test function
void queueTest(void) {

    int n;
    Queue Q = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
    Q = initQueue();
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while (n > 0) {
        QueueData np = malloc(sizeof (QueueData));
        np->num = n%10; // will hit a segmentation fault if you do not malloc first.
        enqueue(Q, np);
        n = n / 10;
    }

    printf("\nDigits in reverse order: ");
    while (!isEmpty(Q))
        printf("%d", dequeue(Q)->num);
    printf("\n");

}
#endif