// question link : https://leetcode.com/problems/climbing-stairs/

#include<iostream> 
#include<vector>
using namespace std;


//===============================================================================================

// Recursion -> base of dynamic programming
int climbStairs(int n) {
    if(n < 0) return 0;
        
    if(n == 0) return 1;
        
    return climbStairs(n-1) + climbStairs(n-2);
}



//============================================================================================

//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n)
int climbStairsUtil(int n, vector<int> &dp){
    if(n < 0) return 0;

    if(n == 0) return 1;
        
    if(dp[n] > 0){
        return dp[n];
    }
        
    return dp[n] = climbStairsUtil(n-1, dp) + climbStairsUtil(n-2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return climbStairsUtil(n, dp);
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
        int curr = previous1 + previous2;
        previous1 = previous2;
        previous2 = curr;
    }
    return previous2;
}