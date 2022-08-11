//
// Created by amir on 8/11/22.
//

//Next Smallest Element


#include "iostream"
#include "vector"
using namespace std;


class Stack {
    int *data;
    int top;
    int size;
public:

    Stack(int size) {
        this->size = size;
        this->data = new int(size);
        this->top = -1;
    }

    void push(int data) {
        if (top < size - 1) {
            top++;
            this->data[top] = data;
        } else {
            cout << "Stack is full";
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        } else return false;

    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty";
            return;
        } else {
            top--;
        }
    }

    int peek() {
        if (isEmpty()) {
            return NULL;
        } else return data[top];
    }};

vector<int> nextSmallestElement(vector<int> number){
    Stack stack(10);
    stack.push(-1);//init stack with -1

    vector<int> result(number.size()-1);
    for(int i= number.size()-1;i>=0;i--){
        int element = number[i];//last element of vector
            //search for small
            while(stack.peek()>=element){
                stack.pop();
            }
            result[i]=stack.peek();
            stack.push(element);


    }

    return result;

}

int main(){
    vector<int> number={2,1,4,3};
    vector<int> result = nextSmallestElement(number);
    for(int i=0;i<= result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}