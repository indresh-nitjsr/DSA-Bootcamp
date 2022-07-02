#include<iostream>
using namespace std;


bool palindrome(string str, int start, int end){
    if(start > end){
        return true;
    }

    if(str[start] != str[end]){
        return false;
    }

    return palindrome(str, start+1, end - 1);
}



int main(){
    string str = "bookoob";
    cout << palindrome(str, 0, 6) << endl;
}