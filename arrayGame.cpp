//
// Created by amir on 9/3/22.
//

#include "iostream"

using namespace std;

bool arrayGame(int arr[],int leap,int n){

    int i=0;
    //move backward
    while(i<n){
        if(i>0){
            if(arr[i-1] and arr[i-1]==0){
                i--;
            }

        }

        //move forward

        if(arr[i+1]==0){
            i++;
        }
        if(arr[i+leap]==0){
            i = leap;
        }

        if(arr[i+1]!=0 and arr[i+leap]!=0){
            return false;
        }

        if(i==n-1 or i+leap>=n){
            return true;
        }


    }


}


int main(){

    int arr[]={0,0,1,1,1,0};
    cout<<arrayGame(arr,3,6);


    return 0;
}
