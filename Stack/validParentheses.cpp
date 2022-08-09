//
// Created by amir on 8/9/22.
//


#include "iostream"

using namespace std;

class Stack{
    char* data;
    int top;
    int size;
public:

    Stack(int size){
        this->size = size;
        this->data = new char(size);
        this->top = -1;
    }

    void push(char data){
        if(top<size-1){
            top++;
            this->data[top] = data;
        }else{
            cout<<"Stack is full";
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        } else return false;

    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty";
            return;
        }else{
            top--;
        }
    }

    char peek(){
        if(isEmpty()){
            return NULL;
        }else return data[top];
    }



};
bool matchBracket(char bracket1 , char bracket2){
    if(bracket1=='[' and bracket2 ==']'){
        return true;
    }else if(bracket1=='{' and bracket2 =='}'){
        return true;
    }else if (bracket1=='(' and bracket2 ==')'){
        return true;
    }
    return false;
}
bool validParentheses(string input,int size){
    Stack stack(size);

    for(int i=0;i<size;i++){
        char bracket = input[i];
        if(bracket=='[' or bracket=='{' or bracket=='('){
            stack.push(bracket);
          //  cout<<stack.peek()<<endl;
        }else{
            char topBrakcet = stack.peek();

            if(matchBracket(topBrakcet,bracket)){
                //cout<<endl<<bracket<<endl;
                stack.pop();
                //cout<<stack.peek();
            } else{
                return false;
            }
        }

    }

    if(stack.isEmpty()){

        return true;

    } else{
        return false;
    }

}

int main(){
    string input = "[{()}]";
    cout<<validParentheses(input,input.size());
    return 0;
}