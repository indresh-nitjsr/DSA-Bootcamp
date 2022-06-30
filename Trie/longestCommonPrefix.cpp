// question link : https://leetcode.com/problems/longest-common-prefix/
// for better understanding visit this link : https://leetcode.com/submissions/detail/735015047/ 


#include<iostream>
#include<vector>
using namespace std;


//First approach -> basic approch
// time complexity : O(n^2)
// space complexity : O(n)
string longestCommonPrefix(vector<string>& strs) {
        int l = strs[0].length();
        int idx = 0;
        string ans = "";
        
        for(int i=1; i<strs.size(); i++){
            if(strs[i].length() < l){
                l = strs[i].length();
                idx = i;
            }
        }
        
        for(int j=0; j<l; j++){
            char ch = strs[idx][j];
            for(int i=0; i<strs.size(); i++){
                if(ch != strs[i][j]){
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
}

//=====================================================================================//
// this take more time as compare to first approch but this is implemented to learn trie data structure
// 2nd approach -> Using Trie
// time complexity : O(n^2)
// space complexity : O(n^2)
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie {
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWordUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        } 

        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root -> children[index] != NULL){
            child = root->children[index];
        } else {
            //absent
            child  = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        //Recursion
        insertWordUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertWordUtil(root, word);
    }

    void longestCommonPrefix(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            if(root->isTerminal){
                break;
            }
            if(root->childCount == 1){
                ans.push_back(ch);
                //check next character children
                int index = ch - 'a';
                root = root->children[index];
            }else{
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string>& strs) {
    Trie* t = new Trie();

    //insert kr do all string in trie
    for(int i=0; i<strs.size(); i++){
        t->insertWord(strs[i]);
    }

    string first = strs[0];
    string ans = "";

    t->longestCommonPrefix(first, ans);
    return ans;
}