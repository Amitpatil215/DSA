///? Frog Jump 
// venice3
/* 
? Problem Statement
There is a frog on the 1st step of an N stairs long staircase. 
The frog wants to reach the Nth stair. 
HEIGHT[i] is the height of the (i+1)th stair.
If Frog jumps from ith to jth stair, the energy lost in the jump is given 
by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, 
he can jump either to (i+1)th stair or to (i+2)th stair. 
Your task is to find the minimum total energy used by the frog to reach 
from 1st stair to Nth stair.

* For Example
If the given ‘HEIGHT’ array is [10,20,30,10], 
the answer 20 as the frog can jump from 1st stair to 2nd stair 
(|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair 
(|10-20| = 10 energy lost). So, the total energy lost is 20. */

/* 
Sample Input 2:
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 
Sample Output 2:
7
2

 */
///? Recursive Solution

/* #include<bits/stdc++.h>
int fj(int index,vector<int>&heights){
    if(index == 0)
        return 0;
    int oneJump=abs(heights[index] - heights[index-1]) + fj(index-1,heights);
    
    int twoJump=INT_MAX;
    if(index > 1)
        twoJump=abs(heights[index] - heights[index-2]) + fj(index-2,heights);
    
    return min(oneJump,twoJump);
}
int frogJump(int n, vector<int> &heights)
{
    return fj(n-1,heights);
} */

///? Recursion + Memoization
/* #include<bits/stdc++.h>
int fj(int index,vector<int>&heights, vector<int>&dp){
    if(index == 0)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    
    int oneJump=abs(heights[index] - heights[index-1]) + fj(index-1,heights,dp);
    
    int twoJump=INT_MAX;
    if(index > 1)
        twoJump=abs(heights[index] - heights[index-2]) + fj(index-2,heights,dp);
    
    dp[index] = min(oneJump,twoJump);
    return dp[index];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    return fj(n-1,heights,dp);
} */

///? Tabulation
/* #include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,0);
    dp[0]=0;
    for(int index=1;index<n;index++){
        int oneJump=abs(heights[index]-heights[index-1])+dp[index-1];
        int twoJump=INT_MAX;
        if(index>1){
            twoJump=abs(heights[index]-heights[index-2])+dp[index-2];
        }
        dp[index]=min(oneJump,twoJump);
    }
    return dp[n-1];
} */

///? Space Optimized Tabulation

#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    int prev1i=0;
    int prev2i=0;//its value could be anything
    for(int index=1;index<n;index++){
        int oneJump=abs(heights[index]-heights[index-1])+prev1i;
        int twoJump=INT_MAX;
        if(index>1){
            twoJump=abs(heights[index]-heights[index-2])+prev2i;
        }
        int curr=min(oneJump,twoJump);
        prev2i = prev1i;
        prev1i=curr;
    }
    return prev1i;
}
