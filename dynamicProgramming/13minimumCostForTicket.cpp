// question link : https://leetcode.com/problems/minimum-cost-for-tickets/

#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;

//==========================================================================================

// Recursion -> base of dynamic programming
int solve(vector<int> &days, vector<int> &costs, int index) {
    // base case
    if (index >= days.size()) {
        return 0;
    }

    // 1 Day pass
    int option1 = costs[0] + solve(days, costs, index + 1);

    // 7 Days pass
    int i;
    for (i = index; i < days.size() && days[i] < days[index] + 7; i++);

    int option2 = costs[1] + solve(days, costs, i);

    // 30 Days pass
    for (i = index; i < days.size() && days[i] < days[index] + 30; i++);

    int option3 = costs[2] + solve(days, costs, i);

    return min(option1, min(option2, option3));
}
int mincostTickets(vector<int> &days, vector<int> &costs) {
    return solve(days, costs, 0);
}

//==========================================================================================

// Recursion + memoization = top down approch
//  time complexity :
//  space complexity :
int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp) {
    // base case
    if (index >= days.size()) {
        return 0;
    }

    if(dp[index] != -1) return dp[index];

    // 1 Day pass
    int option1 = costs[0] + solve(days, costs, index + 1, dp);

    // 7 Days pass
    int i;
    for (i = index; i < days.size() && days[i] < days[index] + 7; i++);
    int option2 = costs[1] + solve(days, costs, i, dp);

    // 30 Days pass
    for (i = index; i < days.size() && days[i] < days[index] + 30; i++);
    int option3 = costs[2] + solve(days, costs, i, dp);

    return min(option1, min(option2, option3));
}
int mincostTickets(vector<int> &days, vector<int> &costs) {
    int n = days.size();
    vector<int> dp(n+1, -1);
    return solve(days, costs, 0, dp);
}




//================================================================================================

// Bottom up approach = tabulation method
//  time complexity :
//  space complexity :
int solve(vector<int>& days, vector<int>& costs){
    int n = days.size();
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
        
    for(int k=n-1; k>=0; k--){
        // 1day pass
        int option1 = costs[0] + dp[k + 1];

        // 7 Days pass
        int i;
        for (i = k; i < days.size() && days[i] < days[k] + 7; i++);
        int option2 = costs[1] + dp[i];

        // 30 Days pass
        for (i = k; i < days.size() && days[i] < days[k] + 30; i++);            
        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    return solve(days, costs);
}