//
// Created by amir on 8/14/22.
//
//Circular Queue

#include "iostream"

using namespace std;

class CircularQueue{
    int front;
    int rear;
    int* arr;
    int size;
public:
    CircularQueue(int size){
        this->size = size;
        arr = new int(size);
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if((front==0 and rear ==0) or (rear==(front-1)%(size-1))){
            return true;
        } else return false;
    }

    void enqueue(int data){
        if (isFull()){
            cout<<"Queue is Full";
            return;
        } else{
            if(front==-1){
                //this is for first element;
                front = 0;
                rear = 0;
                arr[rear]=data;
                rear++;
            }else{
                arr[rear]=data;
                rear++;
                if(rear>=size and  front!=0){
                    rear=0;
                }
            }
        }
    }

    bool isEmpty(){
        if(front==-1 and rear== -1){
            return true;
        }else return false;
    }

    int dequeue(){
        int data = arr[front];
        if(isEmpty()){
            cout<<"Queue is Empty";
            data = 0;
        }else if(front ==rear){//for single element

            front=-1;
            rear=-1;
        }else if(front==size-1){
            front=-1;
        } else{
            front++;
        }
        return data;
    }



};


int main(){
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);


    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;


    return 0;
}