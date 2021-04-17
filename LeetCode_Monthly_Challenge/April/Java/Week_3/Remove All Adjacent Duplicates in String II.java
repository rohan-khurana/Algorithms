/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Constraints:
1 <= s.length <= 105
2 <= k <= 104
s only contains lower case English letters.
*/



class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char c: s){
            if(!st.empty()||st.top().first!=c){
                st.push(make_pair(c,1));
            }
            else{
                pair t(st.top());
                st.pop();
                st.push(make_pair(t.first,t.second+1));
                
                if(st.top().second==k){
                    st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            pair t(st.top());
            int freq=t.second();
            while(freq>0){
                ans=t.first + ans;
                freq--;
            }
        }
        return ans;
    }
};
