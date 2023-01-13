//
// Created by amir on 8/31/22.
//

//Heap
//max heap order property
//#include "iostream"
//
//using namespace std;
//
//
//class Heap{
//public:
//
//    int arr[100];
//    int size ;
//
//    Heap(){
//        arr[0]=-1;
//        size = 0;
//    }
//
//    void insert(int data){
//        size = size+1;
//        int index = size;
//        arr[index]=data;
//
//        while(index>1){
//            int parent = index/2;
//            if(arr[index]>arr[parent]){
//                swap(arr[parent],arr[index]);
//                index = parent;
//            }else{
//                return;
//            }
//        }
//    }
//
//    void deleteFromHeap(){
//
//        if(size<=1){
//            cout<<"Nothing to delete";
//            return;
//        }
//
//
//
//        arr[1] = arr[size];
//        size--;
//        int index = 1;
//        while(index<size){
//            int leftChild =  2*index;
//            int rightChild = 2*index+1;
//
//            if(leftChild<size && arr[1]<arr[leftChild]){
//                swap(arr[index],arr[leftChild]);
//                index = leftChild;
//            }else if(rightChild<size && arr[1]<arr[rightChild]){
//                swap(arr[index],arr[rightChild]);
//                index = rightChild;
//            }else{
//                return;
//            }
//
//
//        }
//
//
//    }
//
//
//
//
//
//
//
//    void print(){
//        for(int i=1;i<=size;i++){
//            cout<<arr[i]<<" ";
//        }
//    }
//
//
//
//};
//
//
//
//
//
//void heapify(int arr[],int size,int i){
//    int largest = i;
//    int left = 2*i;
//    int right = 2*i+1;
//
//    if(left<=size and arr[left]>arr[largest]){
//        largest = left;
//    }
//    if(right <=size and arr[right]>arr[largest]){
//        largest = right;
//    }
//
//    if(largest!=i){
//        swap(arr[largest],arr[i]);
//        heapify(arr,size,largest);
//    }
//
//}
//
//void heapSort(int arr[],int size){
//
//    while(size>0){
//        swap(arr[size],arr[1]);
//        size--;
//        heapify(arr,size,1);
//
//
//    }
//
//}
//
//
//
//int main(){
//    Heap h;
//    h.insert(10);
//    h.insert(8);
//    h.insert(5);
//    h.insert(3);
//    h.insert(2);
//    h.insert(1);
//    h.insert(7);
//    h.print();
//    h.deleteFromHeap();
//    cout<<endl;
//    h.print();
//
//
//    int arr[6]= {-1,54,53,55,52,50};
//   for(int i=5/2;i>0;i--){
//       heapify(arr,5,i);
//   }
//    heapSort(arr,5);
//    cout<<"Printing the array now"<<endl;
//
//    for(int i=1;i<=5;i++){
//        cout<<arr[i]<<" ";
//    }
//
//
//
//    return 0;
//}


#include "iostream"

using namespace std;

class MaxHeap{
private:
    int *arr;

    int index;


public:
    MaxHeap(int n){
        arr = new int(n);
        index = 0;
        arr[0]=-1;
    }
    void insertion(int data){

        index = index+1;
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



    }
    void deletion(){
        if(index<=1){
            cout<<"NO Need To Deletion";
            return;
        }
        //step 1 swap root node with last element

        arr[1] = arr[index];

        //step 2 delete last node - just decrease index
        index--;

        //step 3 correst the postion of root node

        int i = 1;

        while(i<index){


            int left = 2*i;
            int right = 2*i+1;
            if(arr[1]<arr[left]){
                swap(arr[1],arr[left]);
                i=left;
            }else if(arr[1]<arr[right]){
                swap(arr[1],arr[right]);
                i = right;
            }else{
                return;
            }


        }


    }


    void print(){
        for(int i=1;i<=index;i++){
            cout<<arr[i]<<",";
        }
        cout<<endl;
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
    heap.deletion();
    heap.print();
    return 0;
}