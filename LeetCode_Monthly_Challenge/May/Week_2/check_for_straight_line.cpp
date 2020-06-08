class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
         if(coordinates.size()==2)
            return true;
        int x1=coordinates[0][0],y1=coordinates[0][1],x2=coordinates[1][0],y2=coordinates[1][1];
        for(int i=2;i<coordinates.size();i++)
        {   
            if (((coordinates[i][1]-y1)*(x2-x1)-(coordinates[i][0]-x1)*(y2-y1))!=0)
                return false;
        }
        return true;
    }
};
