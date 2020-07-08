"""
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
"""



class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums=sorted(nums)
        result = []
        for i in range(len(nums)):
            if nums[i] > 0: 
                continue
            j = i + 1 
            k = len(nums) - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum < 0:
                    j+=1
                elif sum > 0: 
                    k-=1
                else:
                    result.append([nums[i], nums[j], nums[k]])
                    j+=1
                    k-=1
        return result
