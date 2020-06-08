class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A)  
    {  
        int maxKadane = kadane(A); 
        if(maxKadane < 0)            
            return maxKadane;
        vector<int> temp= A;          
        int sum=0;
        for(auto &n: temp){
            sum=sum+n;
            n *= -1;
        }   
        
        int circle= sum+ kadane(temp);
        return max(circle, maxKadane);
    }  
    int kadane(vector<int>& A) 
    {
        int highestMax = INT_MIN, currentElementMax = 0;   
        for(int i = 0; i < A.size(); i++)  
        {  
            if(currentElementMax < 0)
                currentElementMax=A[i];
            else
                currentElementMax+=A[i];
            
            highestMax= max(highestMax, currentElementMax);
        }  
        return highestMax; 
    }
};
