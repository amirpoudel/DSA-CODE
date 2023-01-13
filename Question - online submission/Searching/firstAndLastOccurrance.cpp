//
// Created by amirp on 10/23/2022.
//


//code studio - Easy

//first and last occurrance recursive

#include <bits/stdc++.h>

int firstOccurrance(vector<int>&arr,int n,int k ,int start,int end){

    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;

    if((mid==0 or k>arr[mid-1]) and arr[mid]==k ){
        return mid;
    }else if(arr[mid]==k and arr[mid-1]==k){
        return firstOccurrance(arr,n,k,start,mid-1);
    }else if(k>arr[mid]){
        return firstOccurrance(arr,n,k,mid+1,end);
    }else{
        return firstOccurrance(arr,n,k,start,mid-1);
    }

}

int lastOccurrance(vector<int>&arr,int n,int k,int start,int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if((mid==n-1 or k<arr[mid+1])and arr[mid]==k ){
        return mid;
    }else if(k==arr[mid] and k==arr[mid+1]){
        return lastOccurrance(arr,n,k,mid+1,end);
    }else if(k>arr[mid]){
        return lastOccurrance(arr,n,k,mid+1,end);
    }else{
        return lastOccurrance(arr,n,k,start,mid-1);
    }
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here


    int first = firstOccurrance(arr,n,k,0,n-1);
    int last = lastOccurrance(arr,n,k,0,n-1);
    return make_pair(first,last);

}