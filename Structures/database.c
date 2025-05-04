#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_NAMES 100

struct Name {
    char value[MAX_NAME_LENGTH];
};

int compareNames(const void *a, const void *b) {
    return strcmp(((struct Name *)a)->value, ((struct Name *)b)->value);
}

int main() {
    int numNames;
    printf("Enter the number of names: ");
    scanf("%d", &numNames);
    if (numNames < 1 || numNames > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }
    struct Name names[MAX_NAMES];
    printf("Enter %d names:\n", numNames);
    for (int i = 0; i < numNames; i++) {
        scanf("%s", names[i].value);
    }
    qsort(names, numNames, sizeof(struct Name), compareNames);
    printf("\nSorted names:\n");
    for (int i = 0; i < numNames; i++) {
        printf("%s\n", names[i].value);
    }

    return 0;
}