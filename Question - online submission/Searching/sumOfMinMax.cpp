//
// Created by amirp on 10/25/2022.
//

//code studio - Easy Very Easy

//Sum of Maximum number and Minimun number in  array - Approach - Brute Force

#include <bits/stdc++.h>
int sumOfMaxMin(int arr[], int n){

    int max ,min,sum;





    max = INT_MIN;
    min  = INT_MAX;

    for(int i=0;i<n;i++){

        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min  = arr[i];
        }
    }

    sum  = max+min;
    return sum;






}