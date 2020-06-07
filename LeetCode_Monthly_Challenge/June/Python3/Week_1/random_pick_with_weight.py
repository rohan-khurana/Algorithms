"""
PROBLEM:
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.

Example 1:
Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:
Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
"""


class Solution:
    def __init__(self, w: List[int]):
        self.pre_sum=[]
        pre_sum=0
        for i in w:
            pre_sum+=i
            self.pre_sum.append(pre_sum)
        self.total=pre_sum
            
    def pickIndex(self) -> int:
        x=self.total*random.random()
        l,r=0,len(self.pre_sum);
        while (l<r):
            mid=l+(r-l)//2
            if self.pre_sum[mid]<x:
                l=mid + 1
            else:
                r=mid
        return r;


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()