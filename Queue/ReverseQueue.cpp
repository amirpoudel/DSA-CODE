//
// Created by amir on 8/14/22.
//

//Reverse Queue
#include "queue"
#include "iostream"

using namespace std;


void reverseQueue(queue<int>* &input){
    if(input->empty()){
        return;
    }
    int data = input->front();
    input->pop();
    reverseQueue(input);
    input->push(data);

}

int main(){

    queue<int>* input =new queue<int>;
    input->push(1);
    input->push(2);
    input->push(3);
    input->push(4);
    input->push(5);
    input->push(6);

    cout<<input->front();
    cout<<endl<<input->back()<<endl;

    reverseQueue(input);

    cout<<input->front();
    cout<<endl<<input->back()<<endl;





    return 0;
}
