class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target){
        sort(nums.begin(), nums.end());
        int closest = INT_MAX, sum = 0;
        for(int start = 0; start < (nums.size() - 2); start++){
            int mid = start + 1, end = nums.size() - 1;
            while(mid < end){
                int result = nums[start] + nums[mid] + nums[end];
                int distance = abs(target - result);
                if(distance < closest){
                    closest = distance;
                    sum = result;
                }
                if(target < result)
                    end--;
                else if(target > result)
                    mid++;
                else
                    return target;
            }
        }
        return sum;
    }
};