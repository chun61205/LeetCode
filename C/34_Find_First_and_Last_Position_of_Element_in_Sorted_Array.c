/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void binarySearch(int *nums, int start, int end, int target, int *returnSearch){
    if(start > end)
        return;
    int mid = (end+start)/2;
    int root = nums[mid];
    if(target > root){
        binarySearch(nums, mid+1, end, target, returnSearch);
    }
    else if(target < root){
        binarySearch(nums, start, mid-1, target, returnSearch);
    }
    else if(target == root){
        if(returnSearch[0] == -1 && returnSearch[1] == -1){
            returnSearch[0] = mid;
            returnSearch[1] = mid;
        }
        else if(returnSearch[0] > mid)
            returnSearch[0] = mid;
        else if(returnSearch[1] < mid)
            returnSearch[1] = mid;
        binarySearch(nums, mid+1, end, target, returnSearch);
        binarySearch(nums, start, mid-1, target, returnSearch);
    }
    return;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *returnSearch = (int*)malloc(sizeof(int)*2);
    returnSearch[0] = -1;
    returnSearch[1] = -1;
    binarySearch(nums, 0, numsSize-1, target, returnSearch);
    return returnSearch;
}