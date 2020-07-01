/*
PROBLEM:
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return nums;
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        vector<int> len(n, 1);
        vector<int> prev(n, 0);
        int max = 0, max_index = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(len[i]<len[j]+1){
                        len[i] = len[j]+1;
                        prev[i] = j;
                    }
                }
            }
            
            if(len[i]>max){
                max = len[i];
                max_index = i;
            }
        }
        
        for(int i=0; i<max; i++){
            result.push_back(nums[max_index]);
            max_index = prev[max_index];
        }
        
        return result;
   }
};
