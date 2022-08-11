//
// Created by amir on 8/11/22.
//

//check Redundant Brackets
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

bool isOpenBracket(char element){
    if(element=='[' or element=='{' or element=='('){
        return true;
    } else return false;
}

bool isOperator(char element){
    if(element=='/' or element=='*' or element=='+' or element=='-'){
        return true;
    }else return false;
}
bool isClosingBracket(char element){
    if(element==']' or element=='}' or element==')'){
        return true;
    } else return false;
}

bool isRedutantBrakcet(string expression){
    Stack stack(10);
    for(int i=0;i<expression.size();i++){
        char element = expression[i];
        if(isOpenBracket(element) or isOperator(element)){
            stack.push(element);
        }
        if(isClosingBracket(element)){
            if(isOperator(stack.peek())){
                stack.pop();
            } else{
                return true;
            }
        }

    }
    return false;
}

int main(){
    string expression = "(a+b)";
    cout<<isRedutantBrakcet(expression);
    return 0;
}