#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
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
            root->children[index] = child;
        }

        //Recursion
        insertWordUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertWordUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root -> children[index] != NULL){
            child = root->children[index];
        }else{
            //absent
            return false;
        }

        //Recursion
        return searchUtil(child, word.substr(1));

    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }


};

int main(){
    Trie *t = new Trie();
    t->insertWord("abcd");
    t->insertWord("indresh");
    t->insertWord("time");

    cout << "Present or not " << t->searchWord("time");
    return 0;
}


/*
    time complexity :

    insertion : O(n)
    search : O(n)
    delete : O(n)


    n -> length of string


*/