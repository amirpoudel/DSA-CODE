//
// Created by amirp on 10/24/2022.
//
//code studion -Easy

#include <bits/stdc++.h>

int findPivotIndex(vector<int>&arr,int n){

    //case -1 pivot lies on first postion i.e arr is not rotated
    if(arr[0]<=arr[n-1]){
        return 0;
    }
    int start = 0;
    int end   = n-1;
    int mid = start+(end-start)/2;
    while(start<end){


        if(arr[mid]>=arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }

        mid = start+(end-start)/2;
    }
    return start;





}

int search(vector<int>&arr,int n,int k,int start,int end){
    if(start>end){
        return -1;
    }

    int mid = start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==k){
            return mid;
        }

        if(k>arr[mid]){
            start = mid+1;
        }else{
            end  = mid-1;
        }

        mid = start+(end-start)/2;
    }
    return -1;

}

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int pivot  = findPivotIndex(arr,n);

    if(k>=arr[pivot] and k<=arr[n-1]){
        return search(arr,n,k,pivot,n-1);
    }else{
        return search(arr,n,k,0,pivot-1);
    }


}

