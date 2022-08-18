//
// Created by amir on 8/18/22.
//
//coding studio -- runtime error - medium

class TwoStack {

    int top1;
    int top2;
    int size;
    int* arr;


public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size = s;
        this->arr = new int(size);
        this->top1 = -1;
        this->top2 = size;

    }

    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top1<top2-1){
            top1++;
            arr[top1] = num;
        }

    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2>top1+1){
            top2--;
            arr[top2] = num;

        }
    }


    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>-1){

            return arr[top1--];
        }else{
            return-1;
        }

    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size){

            return arr[top2++];
        }else{
            return -1;
        }

    }
};
