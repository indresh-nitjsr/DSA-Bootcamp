// question link : https://leetcode.com/problems/combination-sum-iv/

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>


//======================================================================================================

// Recursion -> base of dynamic programming
int solve(vector<int> &num, int target){
    if(target < 0) return 0;
    if(target == 0) return 1;

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += solve(num, target-num[i]);
    }
    return ans;
}
    
int combinationSum4(vector<int>& nums, int target) {
    return solve(nums, target);
}



//==========================================================================================

//Recursion + memoization = top down approch
// time complexity : O(n)
// space complexity : O(n) + O(n)
int solve(vector<int> &num, int target, vector<int> &dp){
    if(target < 0) return 0;
    if(target == 0) return 1;

    if(dp[target] != -1) return dp[target];

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += solve(num, target-num[i], dp);
    }
    return dp[target] = ans;
}
    
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, -1);
    return solve(nums, target, dp);
}




//================================================================================================

//Bottom up approach = tabulation method
// time complexity : O(n)
// space complexity : O(n)
int solve(vector<int> &nums, int target){
    vector<unsigned int> dp(target+1, 0);

    dp[0] = 1;
        
    for(int i=1; i<=target; i++){
        for(int j=0; j<nums.size(); j++){
            if(i-nums[j] >= 0){
                dp[i] += dp[i-nums[j]];
            }
        }   
    }
    return dp[target];
}
    
int combinationSum4(vector<int>& nums, int target) {
    return solve(nums, target);
}