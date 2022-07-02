
#include<iostream>
using namespace std;


int sumOfArray(int arr[], int size){
    if(size == 0)
        return 0;
    

    int sum = arr[0] + sumOfArray(arr+1, size-1);
    return sum;
}



int  main(){
    int arr[] = {2, 3, 10, 7, 9};
    cout << sumOfArray(arr, 5) << endl;
}