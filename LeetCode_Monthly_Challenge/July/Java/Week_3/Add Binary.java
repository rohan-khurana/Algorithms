/*
PROBLEM:
Given two binary strings, return their sum (also a binary string
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/


class Solution {
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int i = a.length()-1, j = b.length()-1;
        int carry = 0;
        while( i>=0 || j>=0 ){
            int sum = carry;
            if(i >= 0) sum += a.charAt(i--) - '0';
            if(j >= 0) sum += b.charAt(j--) - '0';
            carry = sum > 1 ? 1 : 0;
            result.append(sum%2);
        }
        if(carry != 0) result.append(carry);
        return result.reverse().toString();
    }
}
