
#include<iostream>
using namespace std;


bool linearSearch(int arr[], int size, int value){
    if(size == 0)
        return false;
    
    if(arr[0] == value){
        return true;
    }

    return linearSearch(arr+1, size-1, value); 
}



int  main(){
    int arr[] = {2, 3, 10, 7, 9};
    cout << linearSearch(arr, 5, 11) << endl;
}