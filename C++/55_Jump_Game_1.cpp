class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            for(int j = 1; i + j < nums.size() && j <= nums[i]; j++){
                if(dp[i + j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};