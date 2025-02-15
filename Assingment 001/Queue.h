#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "user.h"

typedef struct Node {
    User user;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

// Function prototypes
int initialize_queue(Queue* queue);
int is_empty(Queue* queue);
int enqueue(Queue* queue, User user);
User dequeue(Queue* queue);
int enqueue_random_users(Queue* queue, int num_users);

#endif