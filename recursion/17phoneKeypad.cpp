//question link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<iostream>
using namespace std;
#include<vector>

void generateLetterCombinations(string digit, vector<string> &ans, string output, int index, string mapping[]){
    if(index >= digit.size()){
        ans.push_back(output);
        return;
    }
           
    string value = mapping[digit[index] - '0'];
    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        generateLetterCombinations(digit, ans, output, index + 1, mapping); 
        output.pop_back();
    }     
}
    
vector<string> letterCombinations(string digits) {
    if(digits.length() == 0) return {};
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output;
    int index = 0;
        
    generateLetterCombinations(digits, ans, output, index, mapping);
    return ans;
}