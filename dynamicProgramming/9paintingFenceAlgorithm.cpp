// question link : https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1/

#include<iostream> 
#include<vector>
using namespace std;
int MOD = 1e9+7;

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
    
int mul(int a, int b){
    return ((a%MOD) * (b%MOD))%MOD;
}
  

//==========================================================================================

// Recursion -> base of dynamic programming  
long long solve(int n, int k){
    if(n == 1) return k;
    if(n == 2) return add(k, mul(k, k-1));
        
    long long ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));
    return ans;
}
    
long long countWays(int n, int k){
    return solve(n, k);
}



//==========================================================================================

//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n)
long long solve(int n, int k, vector<long long> &dp){
    if(n == 1) return k;
    if(n == 2) return add(k, mul(k, k-1));
        
    if(dp[n] != -1) return dp[n];
        
    return dp[n] = add(mul(solve(n-2, k, dp), k-1), mul(solve(n-1, k, dp), k-1));
}
    
long long countWays(int n, int k){
    vector<long long> dp(n+1, -1);
    return solve(n, k, dp);
}





//================================================================================================

//Bottom up approach = tabulation method
// time complexity : O(n)
// space complexity : O(n)
long long solve(int n, int k){
    vector<long long> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));
        
    for(int i=3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}
    
long long countWays(int n, int k){
    return solve(n, k);
}




//space optimization
//time complexity : O(n)
//space complexity : O(1)
long long countWays(int n, int k){
    if(n == 1) return k;
    long long previous2 = k;
    long long previous1 = add(k, mul(k, k-1));
        
    for(int i=3; i<=n; i++){
        long long curr = add(mul(previous2, k-1), mul(previous1, k-1));
        previous2 = previous1;
        previous1 = curr;
    }
    return previous1;
}