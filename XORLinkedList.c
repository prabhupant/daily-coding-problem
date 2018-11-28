#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node
{
    int data;
    struct Node* npx;
};

struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;

