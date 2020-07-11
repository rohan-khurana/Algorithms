/*
PROBLEM:
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet = {{}};
        for (int num : nums) {
            int n = powerSet.size();
            for (int i = 0; i < n; i++) {
                powerSet.push_back(powerSet[i]); 
                powerSet.back().push_back(num);
            }
        }
        return powerSet;
    }
};
