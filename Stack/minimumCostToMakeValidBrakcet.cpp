//
// Created by amir on 8/11/22.
//

//Minimum Cost To Make String Valid
#include "iostream"

using namespace std;

class Stack {
    char *data;
    int top;
    int size;
public:

    Stack(int size) {
        this->size = size;
        this->data = new char (size);
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

    char peek() {
        if (isEmpty()) {
            return NULL;
        } else return data[top];
    }

};

int minimunCostToMakeValid(string expression){
    if(expression.length()%2==1){
        return -1;
    }
    Stack stack(10);
    for(int i=0;i<expression.size();i++){
        char element = expression[i];
        if(element=='{'){
            stack.push(element);
        } else{
            if(!stack.isEmpty() and stack.peek()=='{'){
                stack.pop();//this is valid part
            } else{
                stack.push(element);
            }
        }
    }

    //stacks contains invalid expression
    int openBracket = 0;
    int closeBracket = 0;
    while(!stack.isEmpty()){
        if(stack.peek()=='{'){
            openBracket++;
        } else{
            closeBracket++;
        }
        stack.pop();
    }
    int result = (openBracket+1)/2+(closeBracket+1)/2;

}

int main(){
    string expression = "{{}{}{{}{}";
    cout<<minimunCostToMakeValid(expression);
    return 0;

}