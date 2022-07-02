// question link : https://leetcode.com/problems/house-robber/

#include<iostream> 
#include<vector>
using namespace std;


//==========================================================================================

// Recursion -> base of dynamic programming
int solve(vector<int> &nums, int i){
    if(i == nums.size() - 1){
        return nums[i];
    }
    if(i >= nums.size()) return 0;

    return max(solve(nums, i+2) + nums[i], solve(nums, i+3) + nums[i+1]);
}
int rob(vector<int>& nums) {
    return solve(nums, 0);
}



//==========================================================================================

//Recursion + memoization = top down approch
int solve(vector<int> &nums, int i, vector<int> &dp){
    if(i == nums.size() - 1){
        return nums[i];
    }
    if(i >= nums.size()) return 0;

    if(dp[i] != -1) return dp[i];

    return dp[i] = max(solve(nums, i+2, dp) + nums[i], solve(nums, i+3, dp) + nums[i+1]);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, 0, dp);
}



//======================================================================================================

///Space optimization
// time complexity : O(n)
// space complexity : O(1)
int rob(vector<int>& nums) {
    int n = nums.size();
    int previous2 = 0;
    int previous1 = nums[0];

    for(int i=2; i<n; i++){
        int include = previous2 + nums[i];
        int exclude = previous1;

        int ans = max(include, exclude);
        previous2 = previous1;
        previous1 = ans;
    }
    return previous1;
}
