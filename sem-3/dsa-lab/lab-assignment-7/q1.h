#ifndef _Q1_H_
#define _Q1_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} Node;

Node *new_node(char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node *root, Node *node)
{
    if (node->data == root->data)
        return;
    else if (node->data > root->data)
    {
        // right
        if (root->right == NULL)
            root->right = node;
        else
            (insert(root->right, node));
    }
    else
    {
        // left
        if (root->left == NULL)
            root->left = node;
        else
            (insert(root->left, node));
    }
}

int search(Node *root, char data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (data > root->data)
        return search(root->right, data);
    return search(root->left, data);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

#endif //_Q1_H_