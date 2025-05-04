#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree {
    struct binarytree *left;
    struct binarytree *right;
    int data;
} bnt;

bnt* createNode(int data) {
    bnt *newNode = (bnt*)malloc(sizeof(bnt));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bnt* insertNode(bnt *root) {
    int dat;
    scanf("%d", &dat);
    if (dat == -1)
        return NULL;

    root = createNode(dat);
    printf("Enter Left child of %d or -1 for no node: ", dat);
    root->left = insertNode(root);
    printf("Enter Right child of %d or -1 for no node: ", dat);
    root->right = insertNode(root);
    return root;
}

void inorder(bnt *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(bnt *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(bnt *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    bnt *root = NULL;
    int ch;

    while (1) {
        printf("\n1. Insert Node\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data or -1 for no node: ");
                root = insertNode(root);
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Pre-order traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Post-order traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
