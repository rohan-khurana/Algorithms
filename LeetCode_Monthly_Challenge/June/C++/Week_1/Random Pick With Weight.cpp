/*
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
*/

class Solution {
public:
    vector<int> sum;
    Solution(vector<int>& w) {
        sum=w;
        for ( int i=1;i<w.size();i++) {
            sum[i] = sum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int x=rand()%sum.back();
        int l=0;
        int r=sum.size()-1;
        while (l<r) 
        {
             int mid=l+(r-l)/2 ;
             if (sum[mid]<=x) 
                 l=mid + 1 ;
             else 
                 r=mid;
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
