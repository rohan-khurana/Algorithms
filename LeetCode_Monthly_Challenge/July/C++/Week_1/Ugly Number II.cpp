/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
Example:
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.
*/


class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> list(1,1);
        static int i2=0, i3=0, i5=0;
        while(list.size()<n){
            list.push_back(min(2*list[i2],min(3*list[i3],5*list[i5])));
            if(list.back()==2*list[i2]) i2++;
            if(list.back()==3*list[i3]) i3++;
            if(list.back()==5*list[i5]) i5++;
        }
        return list[n-1];
    }
};
