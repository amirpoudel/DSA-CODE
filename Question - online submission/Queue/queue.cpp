//
// Created by amir on 8/20/22.
//
// code studio -easy
//implement queue

// class Queue {
//     public:
//         int *arr;
//         int f;
//         int r;
//         int size;
// public:
//     Queue(){
//         // Implement the Constructor
//         size = 100001;
//        arr=new int(size);
//         f = 0;
//         r = 0;
//         }

//     /*----------------- Public Functions of Queue -----------------*/

//     bool isEmpty() {
//         // Implement the isEmpty() function
//         if(r==f){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     void enqueue(int data) {
//         // Implement the enqueue() function


//             if(r==size){
//                 cout<<"Queue is Full"<<endl;
//             }else{
//                 arr[r]=data;
//                 r++;
//             }



//     }

//     int dequeue() {
//         // Implement the dequeue() function
//         if(isEmpty()){
//             return -1;
//         }else{
//             int data = arr[f];
//             arr[f]=-1;
//             f++;
//             if (f == r) {
//                 f = 0;
//                 r= 0;
//             }
//             return data;
//         }
//     }

//     int front() {
//         // Implement the front() function
//         if(isEmpty()){
//             return -1;
//         }else{
//             return arr[f];
//         }
//     }
// };


class Queue {

    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {    int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};
