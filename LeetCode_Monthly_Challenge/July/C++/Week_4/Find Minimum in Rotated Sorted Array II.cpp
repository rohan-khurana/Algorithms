/*
PROBLEM:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, h=nums.size()-1;
        while(l < h)
        {
            int mid = (l+h)/2;
            if(nums[h] < nums[mid]) l = mid+1;
            else if(nums[h] > nums[mid]) h = mid;
            else h--;
        }
        return nums[l];
    }
};
