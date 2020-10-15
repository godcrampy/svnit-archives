#include <stdio.h>
#include "q1.h"

int main(int argc, char const *argv[])
{
    printf("Enter data: ");
    char a;
    scanf("%c", &a);
    getchar();
    Node *root = new_node(a);
    while (1)
    {
        printf("Do you want to add another node? ");
        char response;
        scanf("%c", &response);
        getchar();
        if (response == 'y' || response == '1')
        {
            printf("Enter data: ");
            char data;
            scanf("%c", &data);
            getchar();
            Node *node = new_node(data);
            insert(root, node);
        }
        else if (response == 'n' || response == '0')
        {
            break;
        }
        else
            ;
    }
    while (1)
    {
        printf("s for search\n");
        printf("i for inorder traversal\n");
        printf("p for preorder traversal\n");
        printf("q for postorder traversal\n");
        printf("Enter command: ");
        char command;
        scanf("%c", &command);
        getchar();
        switch (command)
        {
        case 's':
            printf("Enter data to search: ");
            char temp;
            scanf("%c", &temp);
            getchar();
            if (search(root, temp))
                printf("\nData exists\n\n");
            else
                printf("\nData doesn't exist\n\n");
            break;
        case 'i':
            printf("\n");
            inorder(root);
            printf("\n");
            printf("\n");
            break;
        case 'p':
            printf("\n");
            preorder(root);
            printf("\n");
            printf("\n");
            break;
        case 'q':
            printf("\n");
            postorder(root);
            printf("\n");
            printf("\n");
            break;
        default:
            break;
        }
    }
    return 0;
}
