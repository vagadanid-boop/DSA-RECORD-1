Aim:
Implement a menu-driven doubly linked list in C supporting:

Insert at beginning
Insert at end
Insert at position
Delete by value
Display forward and backward

Algorithm:

1.Define a DNode with data, prev, next.
2.For insertion:
  Beginning: new->next = head; if head exists set head->prev = new; head = new.
  End: traverse to last node; last->next = new; new->prev = last.
  Position: traverse to position-1 node and adjust prev/next of involved nodes.
3.Deletion by value:
  If head contains value, update head and free.
  Else find node with value, unlink by updating prev->next and next->prev and free.
4.Display forward: traverse from head via next. Display backward: go to tail then traverse via prev.

Program:

#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

// Create node
struct DNode* CreateNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void InsertAtBeginning(struct DNode **head, int data) {
    struct DNode *newNode = CreateNode(data);
    if (!newNode) return;
    newNode->next = *head;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
    printf("Inserted %d at beginning.\n", data);
}

// Insert at end
void InsertAtEnd(struct DNode **head, int data) {
    struct DNode *newNode = CreateNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct DNode *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end.\n", data);
}

// Insert at given position (1-based)
void InsertAtPosition(struct DNode **head, int data, int pos) {
    if (pos < 1) { 
        printf("Invalid position!\n"); 
        return; 
    }
    if (pos == 1) { 
        InsertAtBeginning(head, data); 
        return; 
    }
    struct DNode *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; ++i) temp = temp->next;
    if (temp == NULL) { 
        printf("Position out of range!\n"); 
        return; 
    }
    struct DNode *newNode = CreateNode(data);
    if (!newNode) return;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next) newNode->next->prev = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}

// Delete node by value
void DeleteByValue(struct DNode **head, int value) {
    if (*head == NULL) { 
        printf("List is empty. Cannot delete.\n"); 
        return; 
    }
    struct DNode *temp = *head;
    while (temp != NULL && temp->data != value) temp = temp->next;
    if (temp == NULL) { 
        printf("Element %d not found.\n", value); 
        return; 
    }
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next; 
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted %d from list.\n", value);
}

// Display forward
void DisplayForward(struct DNode *head) {
    if (!head) { 
        printf("List is empty.\n"); 
        return; 
    }
    printf("Forward: ");
    struct DNode *temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display backward
void DisplayBackward(struct DNode *head) {
    if (!head) { 
        printf("List is empty.\n"); 
        return; 
    }
    struct DNode *tail = head;
    while (tail->next) tail = tail->next;
    printf("Backward: ");
    while (tail) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

int main() {
    struct DNode *head = NULL;
    int choice, data, pos;

    // Menu loop
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete by Value\n5. Display Forward\n6. Display Backward\n7. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter data: "); scanf("%d", &data);
                InsertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: "); scanf("%d", &data);
                InsertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: "); scanf("%d %d", &data, &pos);
                InsertAtPosition(&head, data, pos);
                break;
            case 4:
                printf("Enter value to delete: "); scanf("%d", &data);
                DeleteByValue(&head, data);
                break;
            case 5:
                DisplayForward(head);
                break;
            case 6:
                DisplayBackward(head);
                break;
            case 7:
                printf("Exiting...\n");
                // Free all nodes
                while (head) {
                    struct DNode *t = head;
                    head = head->next;
                    free(t);
                }
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}


Sample Output:
--- Doubly Linked List Menu ---
Enter choice: 1
Enter data: 10
Inserted 10 at beginning.

Enter choice: 2
Enter data: 30
Inserted 30 at end.

Enter choice: 3
Enter data and position: 20 2
Inserted 20 at position 2.

Enter choice: 5
Forward: 10 <-> 20 <-> 30 <-> NULL

Enter choice: 6
Backward: 30 <-> 20 <-> 10 <-> NULL

Enter choice: 4
Enter value to delete: 20
Deleted 20 from list.

Enter choice: 5
Forward: 10 <-> 30 <-> NULL

Enter choice: 7
Exiting...

Result:
The doubly linked list program supports forward/backward traversal plus insert/delete operations at arbitrary positions. It's ready to compile and run; memory is cleaned up on exit. You can extend it with search, sort, or reverse functions.
