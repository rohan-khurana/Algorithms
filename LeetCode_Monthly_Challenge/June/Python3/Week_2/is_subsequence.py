/*
PROBLEM:
Given an integer, write a function to determine if it is a power of two.

Example 1:
Input: 1
Output: true 
Explanation: 20 = 1

Example 2:
Input: 16
Output: true
Explanation: 24 = 16

Example 3:
Input: 218
Output: false
*/



class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i=j=0
        while i<len(t) and j<len(s):
            if s[j]==t[i]:
                j+=1
            i+=1
        return j==len(s)
        
