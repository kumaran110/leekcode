#include <stdlib.h>

void backtrack(int start, int n, int k, int* path, int pathSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (pathSize == k) {
        result[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    // Pruning: stop early if remaining elements aren't enough to reach size k
    for (int i = start; i <= n - (k - pathSize) + 1; i++) {
        path[pathSize] = i;
        backtrack(i + 1, n, k, path, pathSize + 1, result, returnSize, returnColumnSizes);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    // Maximum possible combinations for constraints n <= 20 (20 choose 10 = 184,756)
    int maxCombinations = 200000;
    
    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(k * sizeof(int));
    
    backtrack(1, n, k, path, 0, result, returnSize, returnColumnSizes);

    free(path);
    return result;
}