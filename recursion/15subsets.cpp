#include<iostream>
using namespace std;
#include<vector>

void generateSubset(vector<int>&nums, vector<vector<int>> &ans, vector<int> output, int index){
    if(index >= nums.size()){
        ans.push_back(output);
            return;
    }
    generateSubset(nums, ans, output, index + 1);
    output.push_back(nums[index]);
    generateSubset(nums, ans, output, index + 1);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    generateSubset(nums, ans, output, 0);
    return ans;
}