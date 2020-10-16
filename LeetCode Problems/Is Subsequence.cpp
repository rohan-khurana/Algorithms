/*
Given a string s and a string t, check if s is subsequence of t.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
    string s,t;
public:
    Solution(string s, string t){
        this->s=s;
        this->t=t;
    }
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

int main()
{
  string s, t;
  getline(cin,s);
  getline(cin,t);
  Solution obj(s,t);
  cout<<(obj.isSubsequence(s,t) ? "True" : "False");
  return 0;
 }
}
