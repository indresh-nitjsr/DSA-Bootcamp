//question link : https://leetcode.com/problems/permutations/submissions/


#include<iostream>
using namespace std;
#include<vector>




void permutation(vector<int> nums, vector<vector<int>> &ans, int index){
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
        
    for(int i=index; i<nums.size(); i++){
        swap(nums[i], nums[index]);
        permutation(nums, ans, index + 1);
        swap(nums[i], nums[index]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    permutation(nums, ans, index);
    return ans;
}