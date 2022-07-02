// question link : https://leetcode.com/problems/min-cost-climbing-stairs/

#include<iostream> 
#include<vector>
using namespace std;

//==================================================================================================

// Recursion -> base of dynamic programming
int minCost(int n, vector<int> &cost){
    if(n == 0) return cost[0]; //base case
    if(n == 1) return cost[1]; //base case

    return cost[n] + min(minCost(n-1, cost), minCost(n-2, cost));
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    return min(minCost(n-1, cost), minCost(n-2, cost));
}



//==================================================================================================



//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n) // one for space and other onr for function call
int minCostClimbingStairsUtil(int n, vector<int> &cost, vector<int> &dp){
    if(n == 0) return cost[0]; //base case
    if(n == 1) return cost[1]; //base case

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = cost[n] + min(minCostClimbingStairsUtil(n-1, cost, dp), minCostClimbingStairsUtil(n-2, cost, dp));
}

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n+1, -1);
    return min(minCostClimbingStairsUtil(n-1, cost, dp), minCostClimbingStairsUtil(n-2, cost, dp));
}



//=================================================================================================================


//time complexity : O(n)
//space complexity : O(n)
//Bottom up approach = tabulation method
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1);
        
    dp[0] = cost[0];
    dp[1] = cost[1];
        
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    return min(dp[n-1], dp[n-2]);
}




//===========================================================================================


//space optimization
//time complexity : O(n)
//space complexity : O(1)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
        
    int previous1 = cost[0];
        int previous2 = cost[1];
        
    for(int i=2; i<n; i++){
        int curr = cost[i] + min(previous1, previous2);
        previous1 = previous2;
        previous2 = curr;
    }
    return min(previous1, previous2);
}