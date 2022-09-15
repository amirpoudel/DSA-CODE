//
// Created by amir on 9/9/22.
//

#include "minTOMaxHeap.h"


void heapify(vector<int>&arr,int size,int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<size and arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size and arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }


}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
    // Write your code here.

    for(int i = n/2;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;


}