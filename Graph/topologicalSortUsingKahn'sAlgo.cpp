//
// Created by amir on 12/24/22.
//
#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    //creating adjList;
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<e;i++){
        int a = edges[i][0];
        int b = edges[i][1];

        adjList[a].push_back(b);
    }

    //calculating indegree
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto k: adjList[i]){
            indegree[k]++;
        }
    }

    //push all zero indegree to queue
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>answer;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        answer.push_back(front);

        for(auto i: adjList[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return answer;

}