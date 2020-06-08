class Solution {
public:
    bool isPerfectSquare(int num) {
        long i=1;
        while(i*i<=num)
        {
            if(num%i==0 && num/i==i)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};
