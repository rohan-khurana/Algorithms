"""
PROBLEM:
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
"""




class Solution:
    def numSquares(self, n: int) -> int:
        if n<=0: return 0
        dp=[0]*(n+1)
        for i in range(1,n+1):
            minimum,j=i,1
            while j*j<=i:
                minimum=min(minimum,1+dp[i-(j*j)]);
                j+=1
            dp[i]=minimum
        return dp[n]
