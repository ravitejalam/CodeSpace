class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s;
        for(int i = 0;i < nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i = 0;i < nums.size(); i++){
            if(s.count(target-nums[i])){
                for(int j = i + 1;j<nums.size();j++){
                    if(nums[j] == target-nums[i])
                        return {i,j};
                }
            }
        }
        return {0,0};
    }
};