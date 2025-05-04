#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct node{
    int val;
    int arind;
    int eleind;
} node;

void adjust(node *harr, int sz, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int small = i;
    node temp;

    if (l < sz && harr[l].val < harr[small].val)
        small = l;

    if (r < sz && harr[r].val < harr[small].val)
        small = r;

    if (small != i) {
        temp = harr[i];
        harr[i] = harr[small];
        harr[small] = temp;
        adjust(harr, sz, small);
    }
}

void buildheap(node *hrr, int sz) {
    int i;
    for (i = (sz - 1) / 2; i >= 0; i--) {
        adjust(hrr, sz, i);
    }
}

node getmin(node *hrr) {
    return hrr[0];
}

void replacemin(node *hrr, int sz, node root) {
    hrr[0] = root;
    adjust(hrr, sz, 0); 
}

int *merge(int **arr, int k, int *sz, int *mergedsz) {
    node *hparr = (node *)malloc(k * sizeof(node));

    int tot = 0;
    for (int i = 0; i < k; i++) {
        tot += sz[i];
    }

    int *res = (int *)malloc(tot * sizeof(int));
    int resind = 0;

    for (int i = 0; i < k; i++) {
        if (sz[i] > 0) {
            hparr[i].val = arr[i][0];
            hparr[i].arind = i;
            hparr[i].eleind = 0;
        } 
        else {
            hparr[i].val = INT_MAX;
        }
    }

    buildheap(hparr, k);

    int hsz = k;
    while (hsz > 0) {
        node root = getmin(hparr);

        if (root.val == INT_MAX) {
            hsz--;
            hparr[0] = hparr[hsz];
            adjust(hparr, hsz, 0);
            continue;
        }

        res[resind++] = root.val;

        if (root.eleind + 1 < sz[root.arind]) {
            root.val = arr[root.arind][root.eleind + 1];
            root.eleind++;
            replacemin(hparr, hsz, root);
        } 
        else {
            hparr[0] = hparr[hsz - 1];
            hsz--;
            adjust(hparr, hsz, 0);
        }
    }

    *mergedsz = resind;
    return res;
}

int main() {
    int k;
    printf("Enter the number of sorted arrays (k): ");
    scanf("%d", &k);

    int **arr = (int **)malloc(k * sizeof(int *));
    int *sz = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        printf("Enter the number of elements in array %d: ", i + 1);
        scanf("%d", &sz[i]);

        arr[i] = (int *)malloc(sz[i] * sizeof(int));
        printf("Enter %d sorted elements for array %d: ", sz[i], i + 1);
        for (int j = 0; j < sz[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int mergedsz;
    int *mergedarr = merge(arr, k, sz, &mergedsz);

    printf("Merged Array: ");
    for (int i = 0; i < mergedsz; i++) {
        printf("%d ", mergedarr[i]);
    }
    printf("\n");
    return 0;
}
