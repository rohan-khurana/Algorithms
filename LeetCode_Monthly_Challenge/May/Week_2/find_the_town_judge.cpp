class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> a(N+1,0);
    for(int i=0;i<trust.size();i++)
    {
        a[trust[i][1]]++;
        a[trust[i][0]]--;
    }
    for(int i=1;i<=N;i++)
    {
        if(a[i]==N-1)
        {
            return i;
        }
    }
    return -1;
    }
};
