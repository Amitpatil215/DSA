//? Frog Jump with K Distance
// venice None

// In frog jump question frog allowed to jump from 1 step or 2 step. 
// But what if we want to jump any arbitary k
// i.e. k=3 means frog allowed to jump from index-1, index-2, index-3 

///? Bottom up approach T=O(nk) S=O(n) 
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    int k=2;
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        int minEnergy=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int energy=abs(heights[i]-heights[i-j])+dp[i-j];
                minEnergy=min(minEnergy,energy);
            }
        }
        dp[i]=minEnergy;
    }
    return dp[n-1];
}