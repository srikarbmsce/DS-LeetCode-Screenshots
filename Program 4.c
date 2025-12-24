#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create() {
    int n, x;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &x);
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

// Insert at beginning
void insert_begin() {
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end() {
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;

    printf("Enter data: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Insert at any position
void insert_pos() {
    int pos, x;
    struct node *newnode, *temp = head;

    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &x);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Display list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    int choice;

    while (1) {
        printf("\n1.Create\n2.Insert at Beginning\n3.Insert at Position\n");
        printf("4.Insert at End\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert_begin();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
