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
    public int nthUglyNumber(int n) {
        int[] list=new int[n];
        list[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            list[i]=(Math.min(list[i2]*2, Math.min(list[i3]*3,list[i5]*5)));
            if(list[i]==(list[i2]*2)) i2++;
            if(list[i]==(list[i3]*3)) i3++;
            if(list[i]==(list[i5]*5)) i5++;
        }
        return list[n-1];
    }
}
