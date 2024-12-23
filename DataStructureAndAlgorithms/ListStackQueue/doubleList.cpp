#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_at_head(Node **head, int data)
{
    Node *newNode = create_node(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insert_at_tail(Node **head, int data)
{
    Node *newNode = create_node(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete_node(Node **head, int key)
{
    Node *temp = *head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void clear_list(Node **head)
{
    Node *current = *head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

Node *find_node_by_value(Node *head, int value)
{
    Node *current = head;
    while (current != NULL && current->data != value)
    {
        current = current->next;
    }
    return current;
}

int insert_at_position(Node **head, int index, int data)
{
    Node *newNode = create_node(data);
    if (!newNode)
        return 0;

    if (index == 0)
    {
        newNode->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return 1;
    }

    Node *temp = *head;
    int position = 0;

    while (temp != NULL && position < index - 1)
    {
        temp = temp->next;
        position++;
    }

    if (temp == NULL || position > index - 1)
    {
        free(newNode);
        return 0;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return 1;
}