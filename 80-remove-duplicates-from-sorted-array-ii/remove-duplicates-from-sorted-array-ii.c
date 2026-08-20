int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }

    int k = 2; // Pointer for the next valid position
    
    for (int i = 2; i < numsSize; i++) {
        // Compare current element with the element two positions back in the modified array
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}