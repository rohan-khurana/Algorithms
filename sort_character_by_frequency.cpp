/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
*/
class Solution {
public:
    string frequencySort(string s) 
    {
        string result;
        int count[256]={0};
        for(char c:s)
            count[c] += 1;
        vector<pair<int,char>> v;
        for(int c=0; c<256; ++c)
        {
            if(count[c]) 
                v.push_back({count[c],c});
        }
        sort(v.rbegin(), v.rend());
        for(auto p : v)
        {
            result+=string(p.first,p.second);
        }
        return result;
    }
        
};
