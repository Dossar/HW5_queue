/* 
 * File:   queue.h
 * Author: mike
 *
 * Created on October 21, 2013, 10:26 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h> 
    
    typedef struct node {
        QueueData data;
        struct node *next;
    } Node, *NodePtr;

    typedef struct queueType {
        NodePtr head, tail;
    } QueueType, *Queue;

    /*Sets up and initializes the queue*/
    Queue initQueue() {
        Queue qp = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue
        // set head and tail to null
        qp -> head = NULL;
        qp -> tail = NULL;
        return qp; // return our new queue
    }
    
    /*Decides if the queue is empty or not*/
    int isEmpty(Queue Q) {
        return (Q -> head == NULL); // check if head is null
    }

    /*Add a value to the tail of the queue*/
    void enqueue(Queue Q, QueueData d) {
        NodePtr np = (NodePtr) malloc(sizeof (Node)); // allocate needed space for new value
        // add data to this new value
        np -> data = d;
        np -> next = NULL;
        
        if (isEmpty(Q)) { // check if queue is empty first
            // if it is empty head and tail are the same.
            Q -> head = np; 
            Q -> tail = np;
        } else {
            // otherwise set only the tail
            Q -> tail -> next = np;
            Q -> tail = np;
        }
    }

    /*Remove a value from the head of the queue*/
    QueueData dequeue(Queue Q) {
        if (isEmpty(Q)) { // check if its empty first
            printf("\nAttempt to remove from an empty queue\n");
            exit(1); // exits the program here (perhaps add error case?)
        }

        QueueData hold = Q -> head -> data; // create temp of current data
        NodePtr temp = Q -> head; // create temp of the entire head node
        Q -> head = Q -> head -> next; // push the head of the queue to the next value
        if (Q -> head == NULL) Q -> tail = NULL; // if head is now null then so is tail
        free(temp); // free associated memory
        return hold; // return our temp data
    }


#ifdef	__cplusplus
}
#endif

#endif	/* QUEUE_H */

