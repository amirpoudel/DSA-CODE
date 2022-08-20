//
// Created by amir on 8/20/22.
//
//code studio -easy
//geek for geeks



void solve (queue<int> &q){
    if(q.empty()){

        return;
    }

    int data = q.front();
    q.pop();
    solve(q);
    q.push(data);


}


queue<int> rev(queue<int> q)
{
    // add code here.
    solve(q);
    return q;

}