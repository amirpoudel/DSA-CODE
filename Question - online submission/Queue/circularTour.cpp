//
// Created by amirp on 11/11/2022.
//

//Circular Tour - The famous Problem
//Find the first circular tour that visits all petrol pump;



//optimized - not able to passs code studio fault in code studio
// write your code here
//     int start = 0;
//     int balance = 0;
//     int require = 0;

//     for(int i=0;i<N;i++){
//         balance = balance+(petrol[i]-distance[i]);
//         if(balance<0){
//             require +=balance;
//
//              start = i+1;
//             balance = 0;
//         }
//     }
//     if(require+balance>=0){
//         return start;
//     }else{
//         return -1;
//     }
// }

//This -code compile while use long long int
long long int start=0;
long long int balance=0;
long long int deficit=0;
for(int i=0;i<N;i++){
balance+=petrol[i]-distance[i];
if(balance<0){
deficit+=balance;
start=i+1;
balance=0;
}
}
if(balance+deficit>=0)
return start;
else
return -1;




//MY owm Approach which pass 7/14 Casses on code studio
#include <bits/stdc++.h>
//int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
//{
//    // write your code here \
//   // int pump =-1 ;
//    bool isComplete = false;
//    int start = 0;
//
//    while(start<N){
//        int pet = 0;
//        int dis =0;
//
//        for(int i=start;i<N;i++){
//
//            if(i==N-1 and start==0){
//                isComplete = true;
//                //   pump  = 0;
//                break;
//            }else if(i==N-1 and start>0){
//                for(int j=0;j<start;j++){
//                    if(j==start-1){
//                        isComplete = true;
//                        //   pump = start;
//                        break;
//                    }
//                    pet = pet + petrol[j];
//                    dis = distance[j];
//
//                    if(pet<dis){
//                        break;
//                    }
//                    pet = pet-dis;
//                }
//            }
//
//            pet = pet + petrol[i];
//            dis = distance[i];
//
//            if(pet<dis){
//                break;
//            }
//            pet = pet-dis;
//
//
//        }
//
//        if(isComplete){
//            return start;
//            // return pump;
//        }else{
//            start++;
//        }
//
//    }
//    return -1;
//
//}
