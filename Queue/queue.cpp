//
// Created by amir on 8/14/22.
//

//Queue Implementation Using Array

#include "iostream"
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int *arr;
public:
    Queue(int size){
        this->size = size;
        this->arr = new int(size);
        this->front = 0;
        this->rear = 0;

    }

    bool isFull(){
        if(rear>=size){
            return true;
        }else return false;
    }

    bool isEmpty(){
        if(rear==0){
            return true;
        } else return false;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue Is FUll!!";
            return;
        }else{
            arr[rear]=data;
            rear++;
        }

    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Is Empty!!";
            return;
        } else {
            arr[front] = -1;
            front++;
            if (front == rear) {
                front = 0;
                rear = 0;
            }

        }
    }

    int frontData(){
        return arr[front];
    }

    int rearData(){
        return arr[rear];
    }

};


int main(){

    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout<<queue.frontData();
    queue.dequeue();
    cout<<endl;cout<<queue.frontData();
    queue.dequeue();
    cout<<endl;cout<<queue.frontData();
    queue.dequeue();
    cout<<endl;cout<<queue.frontData();
    queue.dequeue();
    cout<<endl;cout<<queue.frontData();
    queue.dequeue();
    cout<<endl;cout<<queue.frontData();
    queue.dequeue();
    cout<<endl;cout<<queue.frontData();


    return 0;
}