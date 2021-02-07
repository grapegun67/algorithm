#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;


void insert(int data, Node* head)
{
    Node* tmp = head->next;
    
    if (tmp == NULL) {
        head->next = (Node*)malloc(sizeof(Node));
        head->next->data = data;
        head->next->next = NULL;

        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = (Node*)malloc(sizeof(Node));
    tmp->next->data = data;
    tmp->next->next = NULL;
}

void delete(Node* head)
{
    Node* tmp = head;

    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = NULL;
}


void print_node(Node* head)
{
    Node* tmp = head->next;

    while(tmp != NULL) {

        printf("%d-", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int main()
{

    int flag, data;

    Node* head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;


    while (1) {

        printf("1.insert 2.print 3.delete\n");
        printf("input: ");
        scanf("%d", &flag);


        switch (flag)
        {
        case 1:
            printf("input data: ");
            scanf("%d", &data);
            insert(data, head);
            break;
        case 2:
            print_node(head);
            break;
        case 3:
            delete(head);
            break;
        }

    }

    return 0;
}

