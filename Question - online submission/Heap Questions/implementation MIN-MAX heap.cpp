//
// Created by amirp on 11/20/2022.
//

//Implement MIN / MAX Heap using arra and recursion;

#include "iostream"

using namespace std;

class MaxHeap{
private:
    int *arr;

    int index;


public:
    MaxHeap(int n){
        arr = new int(n);
        index = 1;
        arr[0]=-1;
    }
    void insertion(int data){


        arr[index]= data;
        int i = index;

        while(i>1){
            int parent = i/2;
            if(arr[i]>arr[parent]){
                swap(arr[parent],arr[i]);
                i = parent;
            }else{
                return;
            }

        }
        index++;


    }
    void deletion(){

    }


    void print(){
        for(int i=1;i<=index;i++){
            cout<<arr[i]<<",";
        }
    }
};

int main() {
    MaxHeap heap(10);
    heap.insertion(10);
    heap.insertion(20);
    heap.insertion(30);
    heap.insertion(40);
    heap.insertion(25);
    heap.print();
    return 0;
}