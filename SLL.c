#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *getnode(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertfront(node **head, int data) {
    node *newnode = getnode(data);
    newnode->next = *head;
    *head = newnode;
}

void insertEnd(node **head, int data) {
    node *newnode = getnode(data);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}

void insertAtPosition(node **head, int data, int position) {
    if (position == 0) {
        insertfront(head, data);
        return;
    }
    node *newnode = getnode(data);
    node *temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bound!! \n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefirst(node **head) {
    if (*head == NULL) {
        printf("Linked List is Empty \n");
        return;
    }
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deletelast(node **head) {
    if (*head == NULL) {
        printf("Linked List is Empty \n");
        return;
    }
    node *temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void printlist(node **head) {
    if (*head == NULL) {
        printf("The Linked List is Empty \n");
        return;
    }
    node *temp = *head;
    printf("The Linked List contains: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    insertfront(&head, 10);
    insertfront(&head, 20);
    insertfront(&head, 30);
    insertfront(&head, 14);
    insertfront(&head, 50);
    insertfront(&head, 60);

    printlist(&head);

    insertEnd(&head, 70);

    printlist(&head);

    insertAtPosition(&head, 40, 4);

    printlist(&head);

    deletefirst(&head);

    printlist(&head);

    deletelast(&head);

    printlist(&head);

    return 0;
}

