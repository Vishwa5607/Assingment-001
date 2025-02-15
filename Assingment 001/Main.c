#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_users>\n", argv[0]);
        return 1;
    }

    int num_users = atoi(argv[1]);
    if (num_users <= 0) {
        fprintf(stderr, "Number of users must be a positive integer.\n");
        return 1;
    }

    Queue queue;
    if (initialize_queue(&queue) != 0) {
        fprintf(stderr, "Queue initialization failed.\n");
        return 1;
    }

    if (enqueue_random_users(&queue, num_users) != 0) {
        fprintf(stderr, "Adding users to queue failed.\n");
        return 1;
    }

    printf("Users added to the queue:\n");

    while (!is_empty(&queue)) {
        User dequeued_user = dequeue(&queue);
        printf("Username: %s, Level: %d, Faction: %s\n", dequeued_user.username, dequeued_user.level,
            (dequeued_user.faction == RED) ? "RED" : (dequeued_user.faction == BLUE) ? "BLUE" : "GREEN");
    }

    printf("Queue is now empty.\n");

    return 0;
}