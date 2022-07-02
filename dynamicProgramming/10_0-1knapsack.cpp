// question link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/#

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>


//======================================================================================================

// Recursion -> base of dynamic programming
int solve(int wt[], int val[], int W, int index){
    //base case
    //if only one item to carry in bag
    if(index == 0) {
        if(wt[0] <= W) return val[0];
        else return 0;
    }
    int include = 0;
    if(wt[index] <= W){
        include = val[index] + solve(wt, val, W-wt[index], index-1);
    }
        
    int exclude = 0 + solve(wt, val, W, index-1);
        
    int ans = max(include, exclude);
    return ans;
}
int knapSack(int W, int wt[], int val[], int n) { 
    return solve(wt, val, W, n-1);
}





//==========================================================================================

//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n)
int solve(int wt[], int val[], int W, int index, vector<vector<int>> &dp){
    //base case
    //if only one item to carry in bag
    if(index == 0) {
        if(wt[0] <= W) return val[0];
        else return 0;
    }
    if(dp[index][W] != -1) return dp[index][W];
    int include = 0;
    if(wt[index] <= W){
        include = val[index] + solve(wt, val, W-wt[index], index-1, dp);
    }
        
    int exclude = 0 + solve(wt, val, W, index-1, dp);
        
    return dp[index][W] = max(include, exclude);
}
int knapSack(int W, int wt[], int val[], int n) { 
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return solve(wt, val, W, n-1, dp);
}







//================================================================================================

//Bottom up approach = tabulation method
// time complexity : O(n^2)
// space complexity : O(n^2)
int solve(int wt[], int val[], int W, int n){
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    for(int i=wt[0]; i<=W; i++){
        if(wt[0] <= W){
            dp[0][i] = val[0];
        }else{
            dp[0][i] = 0;
        }
    }
        
    for(int index = 1; index < n; index++){
        for(int w=0; w<=W; w++){
            int include = 0;
            if(wt[index] <= w){
                include = val[index] + dp[index-1][w-wt[index]];
            }
                    
            int exclude = dp[index-1][w];
                
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n-1][W];
}
int knapSack(int W, int wt[], int val[], int n) { 
    return solve(wt, val, W, n);
}



//space optimisation 1
//time complexity : O(n*weight)
//space complexity : O(2*weight);
int solve(int wt[], int val[], int W, int n){
    vector<int> prev(W+1, 0);
    vector<int> curr(W+1, 0);

    for(int i=wt[0]; i<=W; i++){
        if(wt[0] <= W){
            prev[i] = val[0];
        }else{
            prev[i] = 0;
        }
    }
        
    for(int index = 1; index < n; index++){
        for(int w=0; w<=W; w++){
            int include = 0;
            if(wt[index] <= w){
                include = val[index] + prev[w-wt[index]];
            }
                    
            int exclude = prev[w];
                
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[W];
}
int knapSack(int W, int wt[], int val[], int n) { 
    return solve(wt, val, W, n);
}




//space optimisation 2
//time complexity : O(n*weight)
//space complexity : O(weight);
int solve(int wt[], int val[], int W, int n){
    vector<int> curr(W+1, 0);

    for(int i=wt[0]; i<=W; i++){
        if(wt[0] <= W){
            curr[i] = val[0];
        }else{
            curr[i] = 0;
        }
    }
        
    for(int index = 1; index < n; index++){
        for(int w=W; w>=0; w--){
            int include = 0;
            if(wt[index] <= w){
                include = val[index] + curr[w-wt[index]];
            }
                    
            int exclude = curr[w];
                
            curr[w] = max(include, exclude);
        }
    }
    return curr[W];
}
int knapSack(int W, int wt[], int val[], int n) { 
    return solve(wt, val, W, n);
}