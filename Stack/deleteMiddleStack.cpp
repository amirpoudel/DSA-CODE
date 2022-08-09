//
// Created by amir on 8/9/22.
//

//delete middle element from stack

#include "iostream"


using namespace std;

class Stack {
// properties
    int *arr;
    int size;
    int topIndex;
public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        topIndex = -1;
    }

    //operation

    void push(int data) {
        if (topIndex >= size - 1) {
            cout << "Stack Is FULL";
            return;
        } else {
            topIndex++;
            arr[topIndex] = data;
        }
    }

    bool isEmpty() {
        if (topIndex == -1) {
            return true;
        } else return false;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty";
            return;
        } else {
            topIndex--;
        }
    }

    int peek() {
        return arr[topIndex];
    }
    int stackSize(){
        return size;
    }
};

void solve(Stack* &stack,int count,int middle){
    //base case
    if(count==middle ){
        stack->pop();
        return;
    }
    int element = stack->peek();

    stack->pop();
    //Recursive call
    solve(stack,count+1,middle);
    //Returning after pop middle element
    stack->push(element);
}

void deleteMiddleElement(Stack* &stack){
    int count = 0;
    int middle = stack->stackSize()/2;
    solve(stack,count,middle);

}


int main(){

    Stack* stack = new Stack(5);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);

    deleteMiddleElement(stack);
    cout<<stack->peek();
    stack->pop();
    cout<<stack->peek();
    stack->pop();
    cout<<stack->peek();
    stack->pop();
    cout<<stack->peek();
    stack->pop();
    cout<<stack->peek();



    return 0;
}