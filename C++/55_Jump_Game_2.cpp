class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        if (length == 0)
            return false;
        int maxStep = 0;
        for(int i = 0; i < length; i++)
        {
            if(i > maxStep)
                return false;
            if(maxStep > length)
                return true;
            maxStep = max(maxStep, nums[i] + i);
        }
        
        return true;
    }
};