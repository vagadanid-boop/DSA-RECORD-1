AIM:
To implement Circular Queue operations (Enqueue, Dequeue, Display) using Linked List in C.

ALGORITHM:

1. ENQUEUE (Insert)
1. Create a new node.
2. If queue is empty:
front = rear = new node
rear->next = front
3. Else:
rear->next = new node
rear = new node
rear->next = front
2. DEQUEUE (Delete)
1. If queue is empty → print “Queue is empty”.
2. If front == rear:
Remove single node
front = rear = NULL
3. Else:
temp = front
front = front->next
rear->next = front
free temp
3. DISPLAY
1. If empty → print “Queue empty”.
2. Start from front.
3. Traverse until node again becomes front.

PROGRAM:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert element
void enqueue(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {               // allocation check
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL) {                 // first element
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("%d inserted\n", x);
}

// Delete element
void dequeue() {
    if (front == NULL) {                 // underflow check
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) {                 // single element
        printf("%d deleted\n", front->data);
        front = rear = NULL;
    } else {                             // more than one
        printf("%d deleted\n", front->data);
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Free all nodes (cleanup)
void freeQueue() {
    if (front == NULL) return;
    // break the circle to make linear list
    rear->next = NULL;
    struct Node *temp;
    while (front != NULL) {
        temp = front->next;
        free(front);
        front = temp;
    }
    rear = NULL;
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &x) != 1) break;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                freeQueue();   // cleanup
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }

    freeQueue();
    return 0;
}


SAMPLE OUTPUT:

1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter choice: 1
Enter value: 10
10 inserted

Enter choice: 1
Enter value: 20
20 inserted

Enter choice: 1
Enter value: 30
30 inserted

Enter choice: 3
Circular Queue: 10 20 30

Enter choice: 2
10 deleted

Enter choice: 3
Circular Queue: 20 30

RESULT:
Circular Queue operations using linked list were successfully implemented and all operations worked correctly.
