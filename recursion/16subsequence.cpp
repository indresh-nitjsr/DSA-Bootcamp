//question link : https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16


#include<iostream>
using namespace std;
#include<vector>


void generateSubsequence(string str, vector<string> &ans, string res, int index){
    if(index >= str.size()){
        if(res.size() != 0){
            ans.push_back(res);
        }
        return;
    }
    
    generateSubsequence(str, ans, res, index+1);
    res.push_back(str[index]);
    generateSubsequence(str, ans, res, index+1);
    
}
vector<string> subsequences(string str){
	vector<string> ans;
    string res = "";
    generateSubsequence(str, ans, res, 0);
    return ans;
}
