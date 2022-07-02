// question link : https://leetcode.com/problems/fibonacci-number/

#include<iostream> 
#include<vector>
using namespace std;


//==========================================================================================

// Recursion -> base of dynamic programming
int fib(int n) {
    if(n <= 1){
        return n;
    }   
    return fib(n-1) + fib(n-1);
}



//==========================================================================================

//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n)
int fibUtil(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }
        
    if(dp[n] != -1){
        return dp[n];
    }
        
    return dp[n] = fibUtil(n-1, dp) + fibUtil(n-2, dp);
}
int fib(int n) {
    vector<int> dp(n+1, -1);
    return fibUtil(n, dp);
}


//================================================================================================

//Bottom up approach = tabulation method
// time complexity : O(n)
// space complexity : O(n)
int fib(int n) {
    vector<int> dp(n+2, -1);
    dp[0] = 0;
    dp[1] = 1;
        
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


//======================================================================================================

///Space optimization
// time complexity : O(n)
// space complexity : O(1)
int fib(int n) {
    if(n == 0) return 0;
    int previous1 = 0;
    int previous2 = 1;
        
    for(int i=2; i<=n; i++){
        int curr = previous1 + previous2;
        previous1 = previous2;
        previous2 = curr;
    }
    return previous2;
}
