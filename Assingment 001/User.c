#include "user.h"

void generate_random_username(char* username) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charset_len = strlen(charset);

    for (int i = 0; i < MAX_USERNAME_LENGTH; i++) {
        int index = rand() % charset_len;
        username[i] = charset[index];
    }
    username[MAX_USERNAME_LENGTH] = '\0'; // Null-terminate the string
}


// queue.h
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