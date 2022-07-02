// question link : https://leetcode.com/problems/perfect-squares/

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>


//======================================================================================================

// Recursion -> base of dynamic programming
int solve(int n){
	if(n == 0) return 0;
	    
    int ans = n;
	for(int i=1; i*i<=n; i++){
        ans = min(1 + solve(n - i*i), ans);
	}
	return ans;
}
int MinSquares(int n) {
	return solve(n);  
}



//==========================================================================================

//Recursion + memoization = top down approch
// time complexity :
// space complexity :
int solve(int n, vector<int> &dp){
	if(n == 0) return 0;
	    
    if(dp[n] != -1) return dp[n];


    int ans = n;
	for(int i=1; i*i<=n; i++){
        ans = min(1 + solve(n - i*i, dp), ans);
	}
	return dp[n] = ans;
}
int MinSquares(int n) {
    vector<int> dp(n+1, -1);
	return solve(n, dp);  
}



//================================================================================================

//Bottom up approach = tabulation method
// time complexity : 
// space complexity :
 int solve(int n){
	vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
	 
	for(int i=1; i<=n; i++){
        for(int j=1; j*j<=n; j++){
    	    if(i-j*j >= 0){
    	        dp[i] = min(1 + dp[i - j*j], dp[i]);
            }
	    }
    }
	return dp[n];
}
int MinSquares(int n) {
    return solve(n);
	  
}