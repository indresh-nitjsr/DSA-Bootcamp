
#include<iostream>
using namespace std;


bool isSorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        return isSorted(arr+1, size-1);
    }
}


int  main(){
    int arr[] = {2, 3, 10, 7, 9};
    cout << isSorted(arr, 5) << endl;
}