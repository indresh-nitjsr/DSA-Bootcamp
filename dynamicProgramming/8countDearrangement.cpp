//question link : https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<iostream>
using namespace std;
#include<vector>



//==========================================================================================

// Recursion -> base of dynamic programming
//time complexity : exponential
#define MOD 1000000007
long long int countDerangements(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    int ans = ((n-1)%MOD * (countDerangements(n-1)%MOD + countDerangements(n-2)%MOD)%MOD)%MOD;
    
    return ans;
}



//==========================================================================================

//Recursion + memoization = top down approch
//time complexity : O(n)
//space complexity : O(n) + O(n)
long long int solveMemo(int n, vector<long long int> &dp){
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    if(dp[n] != -1) return dp[n];
    
    return dp[n] = ((n-1)%MOD * (solveMemo(n-1, dp)%MOD + solveMemo(n-2, dp)%MOD)%MOD)%MOD;
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    return solveMemo(n, dp);
}




//================================================================================================

//Bottom up approach = tabulation method
//time complexity : O(n)
//space complexity : O(n)
long long int solveTabu(int n){
    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i=3; i<=n; i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first + second)%MOD;
        
        long long int ans = ((i-1) * sum)%MOD;
        dp[i] = ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    return solveTabu(n);
}





//space opptimization
//time complexity : O(n)
//space complexity : O(1)
long long int countDerangements(int n) {
    long long int previous1 = 1;
    long long int previous2 = 0;
    
    for(int i=3; i<=n; i++){
        long long int first = previous1%MOD;
        long long int second = previous2%MOD;
        long long int sum = (first + second)%MOD;
        
        long long int ans = ((i-1) * sum)%MOD;
        previous2 = previous1;
        previous1 = ans;
    }
    return previous1;
}