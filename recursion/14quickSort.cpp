#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[start];

    int count = 0;
    //count smaller element which is less than pivot
    for(int i=start+1; i<=end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    //place pivot at right position 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    //left and right wala part sambhal lete hai
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end){
    //base case
    if(start >= end){
        return;
    }

    //partition karenge
    int p = partition(arr, start, end);

    //left part sort kro
    quickSort(arr, start, p-1);

    //right part sort kro
    quickSort(arr, p+1, end);

}

int main(){
    int arr[] = {4, 8, 9, 2, 4, 2, 5};
    int size = 7;
    quickSort(arr, 0, size - 1);

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
}