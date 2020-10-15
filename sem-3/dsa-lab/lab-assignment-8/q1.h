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

int max(int a, int b)
{
    return a > b ? a : b;
}

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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void delete_tree(Node *root)
{
    if (root == NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

int number_of_elements(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + number_of_elements(root->left) + number_of_elements(root->right);
}

char max_node(Node *root)
{
    if (root->right == NULL)
        return root->data;
    return max_node(root->right);
}



char min_node(Node *root)
{
    if (root->left == NULL)
        return root->data;
    return min_node(root->left);
}

#endif //_Q1_H_