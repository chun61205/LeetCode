int search(int *nums, int numsSize, int target){
    int start = 0, end = numsSize-1;
    int mid;
    while(end >= start){
        mid = (start + end)/2;
        if(nums[mid] == target){
            return mid;
        }
        else{
            if((nums[mid] >= target) && (target >= nums[start]))
                end = mid - 1;
            else if((nums[end] >= target) && (target >= nums[mid]))
                start = mid + 1;
            else{
                if(nums[mid] >= (nums[start]>nums[end]?nums[start]:nums[end]))
                    start = mid + 1;
                else
                    end = mid - 1;     
            }
        }
    }
    return -1;
}