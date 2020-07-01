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


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)
            return true;
        if(t.size()==0)
            return false;
        int j=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[j]){
                j++;
            }
            if(j==s.size())
                return true;
        }
        return false;
    }
};
