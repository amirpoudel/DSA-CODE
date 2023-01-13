//
// Created by amirp on 10/15/2022.
//

//question - shortest path in directed acyclic graph (DAG)


#include "bits/stdc++.h"

using namespace std;


class Graph{

public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u,int v,int weight){
        pair<int,int>p = make_pair(v,weight);
        adjList[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adjList){

//            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<" ,"<<j.second<<")"<<",";
            }
            cout<<endl;
        }
    }

    void dfs(unordered_map<int,bool>&visited,stack<int>&sorted,int node){

        visited[node]=true;

        for(auto i:adjList[node]){
            if(!visited[i.first]){
                dfs(visited,sorted,i.first);
            }
        }

        sorted.push(node);

    }

    stack<int> topologicalSort(){
        unordered_map<int,bool>visited;
        stack<int>sorted;

        for(int i=0;i<6;i++){
            if(!visited[i]){
                dfs(visited,sorted,i);
            }
        }
        return sorted;

    }

    vector<int> shortestPath(int source){
        vector<int>distance(6);

        for(int i=0;i<6;i++){
            distance[i]=INT_MAX;
        }
        distance[source]=0;

        stack<int>topo = topologicalSort();



        while(!topo.empty()) {

            int top = topo.top();
            topo.pop();

            if (distance[top] != INT_MAX) {

                for (auto i: adjList[top]) {

                    if (distance[top] + i.second < distance[i.first]) {
                        distance[i.first] = distance[top] + i.second;
                    }

                }

            }
        }

        return distance;


    }




};

int main(){

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,3,6);
    g.addEdge(1,2,2);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

   // stack<int> sorting = g.topologicalSort();
//    sorting.pop();
//    cout<<sorting.top();

    vector<int>distance = g.shortestPath(1);

    for(int i=0;i<6;i++){
        cout<<distance[i]<<" , ";
    }

    return 1;
}



//DIJKATRA's ALGO
#include <bits/stdc++.h>
//vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
//    // Write your code here.
//
//    //creating adjList;
//
//    unordered_map<int,list<pair<int,int>>>adjList;
//
//    for(int i=0;i<edges;i++){
//
//        int a = vec[i][0];
//        int b = vec[i][1];
//        int weight = vec[i][2];
//
//        adjList[a].push_back(make_pair(b,weight));
//        adjList[b].push_back(make_pair(a,weight));
//
//    }
//
//    //creating distance vector
//    vector<int>distance(vertices);
//    //init the distance with INT_MAX;
//
//    for(int i=0;i<vertices;i++){
//        distance[i]=INT_MAX;
//    }
//    //creating set for store pair value of distance and node
//
//    set<pair<int,int>> st;
//
//    //update distance of source node to zero
//    distance[source]=0;
//
//    //insert distance and source node
//    st.insert(make_pair(distance[source],source));
//
//    while(!st.empty()){
//
//        auto top = *(st.begin());
//
//
//        int nodeDistance = top.first;
//        int topNode = top.second;
//        st.erase(st.begin());
//        for(auto i:adjList[topNode]){
//
//            if(nodeDistance+i.second<distance[i.first]){
//                distance[i.first]=nodeDistance+i.second;
//                st.insert(make_pair(distance[i.first],i.first));
//            }
//
//        }
//
//
//
//    }
//
//
//    return distance;
//
//
//
//}
