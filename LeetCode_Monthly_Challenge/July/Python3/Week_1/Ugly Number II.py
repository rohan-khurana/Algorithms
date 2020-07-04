"""
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
Example:
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.
"""


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        list=[1]
        i2 = i3 = i5 = 0
        while(len(list) < n):
            list.append(min(2*list[i2], 3*list[i3], 5*list[i5]))
            if list[-1]==2*list[i2]: i2+=1
            if list[-1]==3*list[i3]: i3+=1
            if list[-1]==5*list[i5]: i5+=1
        return list[-1];
