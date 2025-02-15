#include "queue.h"

int initialize_queue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    return 0;
}

int is_empty(Queue* queue) {
    return (queue->head == NULL);
}

int enqueue(Queue* queue, User user) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return 1; // Memory allocation failed
    }

    new_node->user = user;
    new_node->next = NULL;

    if (is_empty(queue)) {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    return 0;
}

User dequeue(Queue* queue) {
    if (is_empty(queue)) {
        User empty_user = { "", 0, RED }; // Return a default user if queue is empty.  Consider improving error handling
        return empty_user; // Or handle the error as you see fit.
    }

    Node* temp = queue->head;
    User dequeued_user = temp->user;
    queue->head = temp->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    return dequeued_user;
}

int enqueue_random_users(Queue* queue, int num_users) {
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < num_users; i++) {
        User new_user;
        generate_random_username(new_user.username);
        new_user.level = (rand() % 60) + 1; // Levels 1-60
        new_user.faction = rand() % 3; // RED, BLUE, or GREEN

        if (enqueue(queue, new_user) != 0) {
            return 1; // Enqueue failed
        }
    }
    return 0;
}