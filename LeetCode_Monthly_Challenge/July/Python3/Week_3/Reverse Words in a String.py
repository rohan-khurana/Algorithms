"""
PROBLEM:
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
"""



class Solution:
    def reverseWords(self, s: str) -> str:
        result, i, n = '',0, len(s)
        while i<n:
            while i<n and s[i]==' ': i+=1
            if i>=n: break
            j=i+1
            while j<n and s[j]!=' ': j+=1
            sub = s[i:j]
            if len(result)==0: result = sub
            else: result = sub+" "+result
            i=j+1
        return result
