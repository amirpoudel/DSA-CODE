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


//------------------------------Cycle Detection Using BFS---------------------------------------------------------

//#include<unordered_map>
//#include<list>
//#include<queue>

//bool bfsCycle(unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,int node){
//
//    unordered_map<int,int>parent;
//
//    queue<int>q;
//    q.push(node);
//    visited[node]=true;
//    parent[node]=-1;
//
//    while(!q.empty()){
//        int frontNode= q.front();
//        q.pop();
//
//        for(auto i:adjList[frontNode]){
//
//            if(visited[i]==true and i!=parent[frontNode]){
//                return true;
//            }else if(!visited[i]){
//                q.push(i);
//                parent[i]=frontNode;
//                visited[i]=1;
//            }
//
//
//
//        }
//
//    }
//
//    return false;
//
//
//
//}
//
//string cycleDetection (vector<vector<int>>& edges, int n, int m)
//{
//    // Write your code here.
//
//    //create adjLIst
//    unordered_map<int,list<int>> adjList;
//    for(int i=0;i<m;i++){
//        int a = edges[i][0];
//        int b = edges[i][1];
//
//        adjList[a].push_back(b);
//        adjList[b].push_back(a);
//    }
//
//
//    //create parent
//
//    //create visited list
//    unordered_map<int,bool>visited;
//
//    //traverse entire node in graph
//    for(int i=0;i<n;i++){
//        if(!visited[i]){
//            bool ans = bfsCycle(adjList,visited,i);
//            if(ans==true){
//                return "Yes";
//            }
//        }
//
//    }
//    return "No";
//
//}
//

//-----------------------------------Cycle Detection Using DFS----------------------------------------------------------
//#include<unordered_map>
//#include<list>
//
//bool dfs(unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,int node,int parent){
//
//    visited[node]=true;
//    for( auto i:adjList[node]){
//        if(!visited[i]){
//            bool ans = dfs(adjList,visited,i,node);
//            if(ans==true){
//                return true;
//            }
//        }else if(i!=parent){
//            return true;
//        }
//    }
//
//
//
//
//}
//
//string cycleDetection (vector<vector<int>>& edges, int n, int m)
//{
//    // Write your code here.
//
//    //create adjList;
//    unordered_map<int,list<int>>adjList;
//    for(int i=0;i<m;i++){
//        int a = edges[i][0];
//        int b = edges[i][1];
//
//        adjList[a].push_back(b);
//        adjList[b].push_back(a);
//    }
//
//    //visited d.s
//    unordered_map<int,bool>visited;
//    //parent
//    unordered_map<int,int>parent;
//    //traverse entire graph
//    for(int i=0;i<n;i++){
//        if(!visited[i]){
//            bool ans = dfs(adjList,visited,i,-1);
//            if(ans==true){
//                return "Yes";
//            }
//        }
//    }
//    return "No";
//}



//topological sort using dfs

//#include <bits/stdc++.h>
//
//void dfs(unordered_map<int,list<int>> &adjList,vector<bool>&visited,stack<int> &s,int node){
//
//    visited[node]=true;
//
//    for(auto i:adjList[node]){
//        if(!visited[i]){
//            dfs(adjList,visited,s,i);
//
//        }
//    }
//    s.push(node);
//
//
//}
//
//vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//    // Write your code here
//
//    //creating adjList
//    unordered_map<int,list<int>> adjList;
//    for(int i=0;i<e;i++){
//        int u = edges[i][0];
//        int v = edges[i][1];
//
//        adjList[u].push_back(v);
//
//    }
//    //visited
//    vector<bool>visited(v);
//    //answer
//
//    vector<int> answer;
//    //stack
//    stack<int> s;
//    for(int i=0;i<v;i++){
//        if(!visited[i]){
//            dfs(adjList,visited,s,i);
//        }
//    }
//    while(!s.empty()){
//        answer.push_back(s.top());
//        s.pop();
//    }
//
//    return answer;
//
//
//
//}vv




//cycle detection using bfs kahn's algo
//#include<unordered_map>
//#include<map>
//#include<vector>
//#include<queue>
//#include<list>
//bool isCyclic(vector<vector<int>>& edges, int v, int e)
//{
//    // Write your code here
//    //creating adjList;
//    unordered_map<int,list<int>>adjList;
//    for(int i=0;i<e;i++){
//        int a = edges[i][0];
//        int b = edges[i][1];
//
//        adjList[a].push_back(b);
//    }
//
//    //indegree of all nodes;
//    vector<int> indegree(v);
//
//    for(auto i:adjList){
//        for(auto j:i.second){
//            indegree[j]++;
//        }
//    }
//
//
//    queue<int>q;
//    //insert 0 indegree
//    for(int i=0;i<v;i++){
//        if(indegree[i]==0){
//            q.push(i);
//        }
//
//    }
//    int count=0;
//    while(!q.empty()){
//        int front = q.front();
//        q.pop();
//        count++;
//        for(auto i:adjList[front]){
//            indegree[i]--;
//            if(indegree[i]==0){
//                q.push(i);
//            }
//        }
//
//
//    }
//
//    if(count == v){
//        return false;
//    }
//
//    return true;
//
//
//}
//-------------------------------------Cycle Detection in Directed Graph Using DFS----------------------------
//#include<unordered_map>
//#include<list>
//
//bool dfsDetect(unordered_map<int,list<int>>&adjList, unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsVisited,int node){
//
//    visited[node]=true;
//    dfsVisited[node]=true;
//
//    for(auto i:adjList[node]){
//        if(!visited[i]){
//            int cycleDetect = dfsDetect(adjList,visited,dfsVisited,i);
//            if(cycleDetect){
//                return true;
//            }
//        }else if(dfsVisited[i]){
//            return true;
//        }
//    }
//    dfsVisited[node]=false;
//    return false;
//
//
//}
//
//int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//    // Write your code here.
//    //creating adjList;
//    unordered_map<int,list<int>>adjList;
//    for(int i=0;i<edges.size();i++){
//
//        adjList[edges[i].first].push_back(edges[i].second);
//
//    }
//
//    //visited and dfs visited;
//    unordered_map<int,bool> visited;
//    unordered_map<int,bool>dfsVisited;
//
//    for(int i=1;i<=n;i++){
//        if(!visited[i]){
//            bool cycle = dfsDetect(adjList,visited,dfsVisited,i);
//            if(cycle){
//                return 1;
//            }
//        }
//    }
//
//    return 0;
//}

// detect cycle in direct graph using kahn's algo
#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Write your code here.
    //creating adjList;
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<edges.size();i++){
        int a = edges[i].first-1;//creating zero based indexing
        int b = edges[i].second-1;

        adjList[a].push_back(b);
    }

    //calculating indegree
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto k:adjList[i]){
            indegree[k]++;
        }
    }

    //all zero indegree push to queue
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //doing bfs things
    int count = 0; //maintain count variable for track total number of sorting
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;
        //removing indegree of adjListl;
        for(auto i:adjList[front]){
            indegree[i]--;
            //if indegree is zero then push to queue;
            if(indegree[i]==0){
                q.push(i);
            }
        }

    }

    if(count==n){
        return 0;//valid topological sort i.e no cycle present;
    }
    return 1;//invalid topological sort i.e cycle present;


}


//------------------------------------Shortest path using BFS-----------------------------------------------
//vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
//
//    // Write your code here
//
//    //creating adjList;
//    unordered_map<int,list<int>>adjList;
//    for(int i=0;i<edges.size();i++){
//        int a = edges[i].first;
//        int b = edges[i].second;
//
//        adjList[a].push_back(b);
//        adjList[b].push_back(a);
//    }
//
//    //visited
//    unordered_map<int,bool>visited;
//    //parent;
//    unordered_map<int,int> parent;
//
//    //doing bfs stuff to find parent;
//
//
//
//
//    queue<int>q;
//    q.push(s);
//    parent[s]=-1;
//    visited[s]=true;
//    while(!q.empty()){
//
//        int front = q.front();
//        q.pop();
//
//        for(auto i:adjList[front]){
//            if(!visited[i]){
//
//                parent[i]=front;
//                visited[i]=true;
//                q.push(i);
//            }
//        }
//
//    }
//
//
//    int source = s;
//    int destination  = t;
//    vector<int> path;
//    path.push_back(t);
//    while(destination!=source){
//
//        destination = parent[destination];
//        path.push_back(destination);
//    }
//
//    reverse(path.begin(),path.end());
//    return path;
//
//
//}



////testing code get path using bfs

#include <bits/stdc++.h>

void getPathUsingBfs(unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,unordered_map<int,int>&parent,int node){
    queue<int>q;
    q.push(node);
    parent[node]=-1;
    visited[node]=true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i];
                parent[i]=front;
            }
        }
    }
}

vector<int> getPath(int V, int E, vector<int> a, vector<int> b, int v1, int v2) {
    //    Write your code here

    //creating adjList;
    unordered_map<int,list<int>>adjList;

    for(int i=0;i<E;i++){
        int u = a[i];
        int v = b[i];

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    //visited map
    unordered_map<int,bool>visited;

    //parent map
    unordered_map<int,int>parent;
    //storing path in vector
    vector<int>path;


    for(int i=0;i<V;i++){
        if(!visited[i]){
            getPathUsingBfs()
        }
    }

    int starting = v1;
    int ending = v2;

    path.push_back(v2);

    while(ending!=starting){

        ending = parent[ending]{
            path.push_back(ending);
        }
    }

    vector<int> empty;
    if(path.end()!=v1){
        return empty;
    }

    return path;




}