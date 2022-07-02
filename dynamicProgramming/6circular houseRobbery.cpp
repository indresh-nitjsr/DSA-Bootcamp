// Question link : https://leetcode.com/problems/house-robber-ii/

//see question no 5
// This probleb similar to this : https://leetcode.com/problems/house-robber/

#include<iostream>
#include<vector>
using namespace std;


//space optimization
int solve(vector<int>& nums) {
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

int rob(vector<int>& nums) {
    int n = nums.size();
        
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
        
    vector<int> first(n-1), second(n-1);
        
    for(int i=0; i<n; i++){
        if(i != n-1){
            first.push_back(nums[i]);
        }
        if(i != 0){
            second.push_back(nums[i]);
        }
    }
    return max(solve(first), solve(second));
}