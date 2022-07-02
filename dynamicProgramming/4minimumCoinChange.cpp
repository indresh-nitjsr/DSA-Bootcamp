// question link : https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h> 
#include<vector>
using namespace std;

//==================================================================================================

// Recursion -> base of dynamic programming
int coinChangeUtil(vector<int>& coins, int amount){
    if(amount == 0) return 0;
        
    if(amount < 0) return INT_MAX;
        
    int minimum = INT_MAX;
        
    for(int i=0; i<coins.size(); i++){
        int ans =  coinChangeUtil(coins, amount - coins[i]);
            
        if(ans != INT_MAX){
            minimum = min(minimum, 1 + ans);
        }
    }
    return minimum;
}
int coinChange(vector<int>& coins, int amount) {
    int ans = coinChangeUtil(coins, amount);
        
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}


//==================================================================================================

//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n) // one for space and other onr for function call
int coinChangeHelper(vector<int>& coins, int amount, vector<int>& dp){
    if(amount == 0) return 0;
        
    if(amount < 0) return INT_MAX;
    
    if(dp[amount] != -1) return dp[amount];

    int minimum = INT_MAX;
        
    for(int i=0; i<coins.size(); i++){
        int ans =  coinChangeHelper(coins, amount - coins[i], dp);
            
        if(ans != INT_MAX){
            minimum = min(minimum, 1 + ans);
        }
    }
    return dp[amount] = minimum;
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = coinChangeHelper(coins, amount, dp);
        
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}





//=================================================================================================================

//Bottom up approach = tabulation method
int coinChangeSolve(vector<int>& coins, int amount, vector<int>& dp){
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=amount; i++){
        //i am trying to solve for every amount figure from 1 to amount
        for(int j=0; j<coins.size(); j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if(dp[amount] == INT_MAX){
        return -1;
    }
    return dp[amount];
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = coinChangeSolve(coins, amount, dp);
        
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}





//space optimiization not possible
// because        this is variable  -> dp[i - coins[j]] i can not store in two variable multiple variable required