/* 
 * File:   queueA.h
 * Author: Roy Van Liew
 *
 * Created on October 21, 2013, 1:16 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
    
    // Side note: "MaxStack" will be a defined value in the c program to state the max size of the stack. 
    
#define MaxQ 100    

    typedef struct queueType {
        int head, tail; // head is the front of the queue, tail is the end of the queue.
        int size; // size is for checking how big the queue is
        QueueData QA[MaxQ];
    } QueueType, *Queue;

    Queue initQueue() {
        // qp is the queue pointer, the pointer to the new queue being initialized here.
        Queue qp = (Queue) malloc(sizeof (QueueType));
        qp->head = qp->tail = 0; // Initialize both the head and tail of queue to be zero.
        qp->size = 0; // Initialize the size of the queue to be zero.
        return qp;
    }

    int isEmpty(Queue Q) {
        return ( Q->size == 0 ); // If size of queue is zero, that means it is empty
        //return (Q->head == Q->tail); // If the head and tail index are the same, the queue is empty.
    }

    void enqueue(Queue Q, QueueData data) {
        // We're using a circular array here. If tail index reaches end of array, set it back to zero.
        if (Q->tail == MaxQ - 1)
            Q->tail = 0;
        if ( (Q->tail)+1 == Q->head) {
            // If adding 1 to the tail index makes it equal to head index, then the queue is full.
            exit(1);
        }
        // Since in a queue we add at the tail, we add in the tail index of the Queue Array.
        Q->QA[Q->tail] = data; // Normal case, add to the tail.
        ++(Q->tail); // If not at the end of the array, add 1 to the tail index.
        ++(Q->size); // Increase size of queue by 1.
    }

    QueueData dequeue(Queue Q) {
        if ( isEmpty(Q) ) {
            // If the queue is empty, we are trying to remove from an empty queue.
            exit(1);
        }
        QueueData hold = malloc(sizeof (QueueData));
        hold->num = Q->QA[Q->head]->num; // Set the data of head element to be returned
        // We're using a circular array here. If tail index reaches end of array, set it back to zero.
        if (Q->head == MaxQ - 1)
            Q->head = 0;       
        else
            ++(Q->head); // If not at the end of the array, add 1 to the head index.
        --(Q->size); // Decrease size of queue by 1.
        return hold; // Return the element that was removed from the queue.
    }
    
    QueueData getFront(Queue Q) {
        if ( isEmpty(Q) ) {
            // Queue is empty, can't check a head of an empty queue.
            exit(1);
        }
        /* Return data of the queue head. */
        return Q->QA[Q->head];
         
    }
    
    /* Clear entire queue */
    void empty(Queue Q) {
        // This while loop continuously calls dequeue until the size of the queue becomes zero.
        while (Q->size != 0)
            dequeue(Q);
    }


#ifdef	__cplusplus
}
#endif

#endif	/* QUEUEL_H */

