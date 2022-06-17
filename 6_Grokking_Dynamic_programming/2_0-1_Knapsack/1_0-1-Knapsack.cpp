//? recursive Solution
/* 
int knapsack(int n,int capacity, vector<int> profits,vector<int> weights){
    /// if no of items or capacity is zero then profit gonna be zero
    if(n==0 || capacity==0){
        return 0;
    }
    /// if weight of item is greater than capacity
    /// we can not pick the item
    if(weights[n-1]>capacity){
        return knapsack(n-1,capacity,profits,weights);
    }else{ 
        /// if we can pick the item
        /// we can include it or exclude it
        int incl=profits[n-1] + knapsack(n-1,capacity-weights[n-1],profits,weights);
        int excl= knapsack(n-1,capacity,profits,weights);
        return max(incl,excl);
    }
    
}

int Solution::solve(vector<int> &profits, vector<int> &weights, int capacity) {
    return knapsack(profits.size(),capacity,profits,weights);
}
*/


// ? Top down approach || Space and time complexity->O(n*c)
/* 
int knapsack(vector<vector<int>> &dp, int n,int capacity, vector<int> profits,vector<int> weights){
    /// if no of items or capacity is zero then profit gonna be zero
    if(n==0 || capacity==0){
        return 0;
    }
    /// if we alredy encountered this ub problem take from there
    if(dp[n-1][capacity]!=-1){
        return dp[n-1][capacity];
    }
    
    /// if weight of item is greater than capacity
    /// we can not pick the item
    if(weights[n-1]>capacity){
        return knapsack(dp, n-1,capacity,profits,weights);
    }else{ 
        /// if we can pick the item
        /// we can include it or exclude it
        int incl=profits[n-1] + knapsack(dp,n-1,capacity-weights[n-1],profits,weights);
        int excl= knapsack(dp,n-1,capacity,profits,weights);
        dp[n-1][capacity]= max(incl,excl);
        return dp[n-1][capacity];
    }
    
}

int Solution::solve(vector<int> &profits, vector<int> &weights, int capacity) {
    int n=profits.size();
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
    return knapsack(dp,n,capacity,profits,weights);
}

 */

//? Bottom Up Approach

/* int Solution::solve(vector<int> &profits, vector<int> &weights, int capacity) {
    int n=profits.size();
    int dp[n+1][capacity+1];
    
    for(int items=0;items<=n;items++){
        for(int c=0;c<=capacity;c++){
            if(items==0 || c==0){
                dp[items][c]=0;
            }else if(weights[items-1] > c){
                dp[items][c]=dp[items-1][c];   
            }else{
                int incl=profits[items-1]+dp[items-1][c-weights[items-1]];
                int excl=dp[items-1][c];
                dp[items][c]=max(incl,excl);
            }
        }
    }
    return dp[n][capacity];
} */