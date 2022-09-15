//
// Created by amir on 9/14/22.
//
//Graph implementation using Adjacency List

#include "iostream"
#include "unordered_map"
#include "list"
using namespace std;

class Graph{
public:

    unordered_map<int,list<int>>adj;

    void addEdge(int u ,int v,bool direction){
        // undirected graph ->0
        // directed graph ->1;

        adj[u].push_back(v);
        //undirected Graph case
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
     for(auto i:adj){
         cout<<i.first<<"-> ";
         for(auto j:i.second){
             cout<<j<<" ";
         }
         cout<<endl;
     }
    }

};


int main(){

    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.printAdj();
    return 0;
}

//bfs traversal code studio
//#include<unordered_map>
//#include<queue>
//#include<list>
//#include<set>
//void createAdjList(unordered_map<int,set<int> > &adjList,vector<pair<int, int>> edges){
//    for(int i=0;i<edges.size();i++){
//        int v = edges[i].first;
//        int u  = edges[i].second;
//        adjList[v].insert(u);
//        adjList[u].insert(v);
//    }
//
//}
//
//void bfs(unordered_map<int,set<int> > &adjList, unordered_map<int,bool> &visited,vector<int> &answer,int node){
//
//    queue<int>q;
//    q.push(node);
//    visited[node]=1;
//    while(!q.empty()){
//        int frontNode= q.front();
//        q.pop();
//
//        answer.push_back(frontNode);
//
//        for(auto i:adjList[frontNode]){
//            if(!visited[i]){
//                q.push(i);
//                visited[i]=1;
//            }
//        }
//
//    }
//
//
//}
//
//
//vector<int> BFS(int vertex, vector<pair<int, int>> edges)
//{
//    // Write your code here
//    unordered_map<int,set<int> > adjList;
//    vector<int> answer;
//    unordered_map<int,bool> visited;
//
//    createAdjList(adjList,edges);
//
//
//    for(int i=0;i<vertex;i++){
//
//        if(!visited[i]){
//            bfs(adjList,visited,answer,i);
//        }
//    }
//
//
//
//
//    return answer;
//}

//DFS Traversal

//#include<unordered_map>
//#include<list>
//
//void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>> &adjList,vector<int>&component){
//
//component.push_back(node);
//visited[node]=true;
//
//for(auto i:adjList[node]){
//if(!visited[i]){
//dfs(i,visited,adjList,component);
//}
//}
//
//}
//
//
//vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
//{
//    // Write your code here
//    unordered_map<int,list<int>> adjList;
//    //create adjList
//    for(int i=0;i<edges.size();i++){
//        int a = edges[i][0];
//        int b = edges[i][1];
//
//        adjList[a].push_back(b);
//        adjList[b].push_back(a);
//    }
//
//    vector<vector<int>> answer;
//    unordered_map<int,bool>visited;
//
//    for(int i=0;i<V;i++){
//        if(!visited[i]){
//            vector<int> component;
//            dfs(i,visited,adjList,component);
//            answer.push_back(component);
//        }
//    }
//
//    return answer;
//
//}
