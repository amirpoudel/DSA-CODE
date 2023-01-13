//
// Created by amirp on 10/25/2022.
//

// code studio - Easy --
//nearest largest square root of an integer

#include <bits/stdc++.h>

int search(int a ){

    int start = 1;
    int end  = a;
    int mid = (start+end)/2;
    int answer;
    while(start<=end){

        int square  = mid*mid;

        if(square==a){
            answer = mid;
            return answer;
        }
        if(square>a){
            end = mid-1;
        }
        if(square<a){
            answer = mid;
            start = mid+1;
        }
        mid = (start+end)/2;


    }
    return answer;





}

int squareRoot(int a)
{
    // Write your code here.

    if(a==1){
        return a;
    }

    return search(a);


}
