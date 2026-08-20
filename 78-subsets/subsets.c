#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, int** result, int* returnSize, int** returnColumnSizes) {
    // Save current subset
    result[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) {
        result[*returnSize][i] = path[i];
    }
    (*returnColumnSizes)[*returnSize] = pathSize;
    (*returnSize)++;

    // Generate remaining subsets
    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, result, returnSize, returnColumnSizes);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Total subsets for numsSize elements is 2^numsSize (max 2^10 = 1024)
    int totalSubsets = 1 << numsSize;
    
    int** result = (int**)malloc(totalSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, path, 0, result, returnSize, returnColumnSizes);

    free(path);
    return result;
}