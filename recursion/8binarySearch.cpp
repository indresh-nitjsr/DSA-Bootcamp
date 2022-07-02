
#include<iostream>
using namespace std;


bool binarySearch(int arr[], int value, int start, int end){
    if(start > end)
        return false;
    
    int mid = start + (end - start)/2;

    if(arr[mid] == value){
        return true;
    }

    if(arr[mid] > value){
        return binarySearch(arr, value, start, mid - 1); 
    }else{
        return binarySearch(arr, value, mid + 1, end); 
    } 
}



int  main(){
    int arr[] = {2, 3, 10, 7, 9};
    cout << binarySearch(arr, 7, 0 ,4) << endl;
}