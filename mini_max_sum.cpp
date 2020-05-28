/*
PROBLEM
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.
For example, . Our minimum sum is  and our maximum sum is . We would print
16 24
*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int arr[5],sum=0,b[5],min,max;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    for(int i=0;i<5;i++)
        b[i]=sum-arr[i];
    min=b[0];
    max=b[0];
    for(int i=0;i<5;i++)
    {
        if(min>b[i])
          min=b[i];
        if(max<b[i])
          max=b[i];
    }
    cout<<min<<" "<<max;
}
