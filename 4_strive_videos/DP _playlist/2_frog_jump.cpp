// Frog Jump
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

/* #include<bits/stdc++.h>
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
} */
