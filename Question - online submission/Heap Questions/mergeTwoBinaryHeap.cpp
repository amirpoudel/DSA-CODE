//
// Created by amir on 9/9/22.
//
//code studio
void heapify(vector<int> &arr,int size,int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<size and arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size and arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }

}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here

    vector<int> arr;



    for(int i=0;i<n;i++){
        arr.push_back(arr1[i]);
    }

    for(int i=0;i<m;i++){
        arr.push_back(arr2[i]);
    }

    int size = n+m;
    for(int i=size/2;i>=0;i--){
        heapify(arr,size,i);
    }

    return arr;



}