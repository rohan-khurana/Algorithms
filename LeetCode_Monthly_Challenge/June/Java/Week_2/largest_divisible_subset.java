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
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        List<Integer> result=new ArrayList<Integer>();
        if(n==0)
            return result;
        
        Arrays.sort(nums);

        int[] len=new int[nums.length];
        Arrays.fill(len,1);
        int[] prev=new int[nums.length];
        Arrays.fill(prev,0);

        int max = 0, max_index = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(len[i]<len[j]+1){
                        len[i] = 1 + len[j];
                        prev[i] = j;
                    }
                }
            }
            if(len[i] > max){
                max = len[i];
                max_index = i;
            }
        }
        for(int i=0; i<max; i++){
            result.add(nums[max_index]);
            max_index = prev[max_index];
        }
        return result;
    }
}
