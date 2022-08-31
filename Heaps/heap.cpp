//
// Created by amir on 8/31/22.
//

//Heap
//max heap order property
#include "iostream"

using namespace std;


class Heap{
public:

    int arr[100];
    int size ;

    Heap(){
        arr[0]=-1;
        size = 0;
    }

    void insert(int data){
        size = size+1;
        int index = size;
        arr[index]=data;

        while(index>1){
            int parent = index/2;
            if(arr[index]>arr[parent]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void deleteFromHeap(){

        if(size<=1){
            cout<<"Nothing to delete";
            return;
        }



        arr[1] = arr[size];
        size--;
        int index = 1;
        while(index<size){
            int leftChild =  2*index;
            int rightChild = 2*index+1;

            if(leftChild<size && arr[1]<arr[leftChild]){
                swap(arr[index],arr[leftChild]);
                index = leftChild;
            }else if(rightChild<size && arr[1]<arr[rightChild]){
                swap(arr[index],arr[rightChild]);
                index = rightChild;
            }else{
                return;
            }


        }


    }



    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }



};


int main(){
    Heap h;
    h.insert(10);
    h.insert(8);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.insert(7);
    h.print();
    h.deleteFromHeap();
    cout<<endl;
    h.print();


    return 0;
}