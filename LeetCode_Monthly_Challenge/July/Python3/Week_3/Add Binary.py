"""
PROBLEM:
Given two binary strings, return their sum (also a binary string
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
"""




class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = ""
        i, j = len(a)-1, len(b)-1;
        carry = 0
        while i>=0 or j>=0:
            sum = carry
            if i >= 0: sum += ord(a[i]) - ord('0')
            if j >= 0: sum += ord(b[j]) - ord('0')
            i,j = i-1, j-1
            carry = 1 if sum > 1 else 0
            result += str(sum%2)
        if carry != 0: result += str(carry)
        return result[::-1]
