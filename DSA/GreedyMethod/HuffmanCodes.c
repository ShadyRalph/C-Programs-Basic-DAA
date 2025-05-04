#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} node;

node *newNode(char data, int freq) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(node **arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left]->freq < arr[smallest]->freq)
        smallest = left;

    if (right < size && arr[right]->freq < arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, size, smallest);
    }
}

void buildHeap(node **arr, int size) {
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(arr, size, i);
}

node *extractMin(node **heap, int *size) {
    node *minNode = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return minNode;
}

void insertHeap(node **heap, int *size, node *newNode) {
    heap[*size] = newNode;
    (*size)++;
    buildHeap(heap, *size);
}

void countFrequency(char *str, char **data, int **freq, int *size) {
    int count[256] = {0}; 

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }

    int unique = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0)
            unique++;
    }

    *data = (char *)malloc(unique * sizeof(char));
    *freq = (int *)malloc(unique * sizeof(int));
    *size = unique;

    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            (*data)[index] = (char)i;
            (*freq)[index] = count[i];
            index++;
        }
    }

    printf("\nCharacter Frequency Table:\n");
    printf("Character\t|\tFrequency\n");
    printf("---------\t|\t---------\n");
    for (int i = 0; i < unique; i++) {
        printf("\t%c\t|\t%d\n", (*data)[i], (*freq)[i]);
    }
}

node *buildHuffmanTree(char *data, int *freq, int n) {
    node **heap = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
        heap[i] = newNode(data[i], freq[i]);

    buildHeap(heap, n);

    while (n > 1) {
        node *left = extractMin(heap, &n);
        node *right = extractMin(heap, &n);

        node *merged = newNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        insertHeap(heap, &n, merged);
    }

    return heap[0];
}

void printCodes(node *root, int *arr, int top, char codes[256][100]) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codes);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codes);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");

        for (int i = 0; i < top; i++)
            codes[(unsigned char)root->data][i] = arr[i] + '0';
        codes[(unsigned char)root->data][top] = '\0';
    }
}

int main() {
    char str[1000];
    printf("Enter the string: ");
    scanf(" %[^\n]", str);

    char *data;
    int *freq;
    int size;

    countFrequency(str, &data, &freq, &size);

    node *root = buildHuffmanTree(data, freq, size);

    char codes[256][100] = {0}; 
    int arr[100]; 

    printf("\nHuffman Codes:\n");
    printCodes(root, arr, 0, codes);

    printf("\nEncoded String: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%s", codes[(unsigned char)str[i]]);
    }
    printf("\n");

    return 0;
}
