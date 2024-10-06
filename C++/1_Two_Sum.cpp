class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> returnVector(2);
        for(int i = 0; i < nums.size(); i++){
            auto it = find(nums.begin(), nums.end(), target - nums[i]);
            if(it != nums.end() && i != it - nums.begin()){
                returnVector[0] = i;
                returnVector[1] = it - nums.begin();
                break;
            }
        }
        return returnVector;
    }
};