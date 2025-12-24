#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;      // Stack
struct node *front = NULL;    // Queue
struct node *rear = NULL;

// -------- STACK OPERATIONS --------

void push() {
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Pushed %d\n", x);
}

void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}


void display_stack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// -------- QUEUE OPERATIONS --------

void enqueue() {
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued %d\n", x);
}

void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display_queue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1.Stack Push\n2.Stack Pop\n3.Display Stack\n");
        printf("4.Queue Enqueue\n5.Queue Dequeue\n6.Display Queue\n");
        printf("7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                enqueue();
                break;
            case 5:
                dequeue();
                break;
            case 6:
                display_queue();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
