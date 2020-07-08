/*
PROBLEM:
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) 
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // Skip duplicate numbers of j
                    while (j+1 <= k && nums[j] == nums[j+1]) j++;
                    j++;
                    k--;
                }
            }
            // Skip duplicate numbers of i
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return result;
    }
};
