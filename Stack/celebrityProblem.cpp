//
// Created by amir on 8/12/22.
//

//The Celebrity Problem

#include "iostream"
#include "stack"
#include "vector"
using namespace std;

bool knows(vector<vector<int>> vector , int a,int b){
    if(vector[a][b]==1){
        return true;
    } else return false;
}

int findCelebrity(vector<vector<int>> input,int n){
    //put all element in stack
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()!=1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(input,a,b)){
            s.push(b);
        } else{
            s.push(a);
        }

    }

    int possibleCelebrity = s.top();
    //verify possible celebrity

    int rowCount =  0;//celebrity knows no one row must be zero
    bool rowCheck = false;
    for(int i=0;i<n;i++){
        if(input[i][possibleCelebrity]==0){
            rowCount++;
        }
    }
    if(rowCount==n){
        rowCheck = true;
    }

    int colCount = 0;//everyone knows celebrity - check all col except diagonal
    bool colCheck = false;
    for(int i=0;i<n;i++){
        if(input[i][possibleCelebrity]==1) {
            colCount++;
        }
    }
    if(colCount==n-1){
        colCheck= true;
    }

    if(rowCheck== true and colCheck== true){
        return possibleCelebrity;
    } else{
        return -1;
    }



}

int main(){
    vector<vector<int>>input
            {
                    {0, 1, 0},
                    {0, 0, 0},
                    {0, 1, 0}
            };

    cout<<findCelebrity(input,3);

}