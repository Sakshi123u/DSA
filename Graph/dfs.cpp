#include<iostream>
#include<vector>
#include<list>
using namespace std;
class graph{
    int vertices;
    vector<list<int>>adj; //cresting empty list with size 0
    public:
    graph(int vertices);
    void addedge(int u,int v);
    void dfs(int v,vector<bool>&visited);
};
graph::graph(int vertices){
    this->vertices=vertices;
    adj.resize(vertices);  //adjusting size of adjlist as per nu of vertices
}
void graph::addedge(int u,int v){
    adj[u].push_back(v);       //add v to u list
}
void graph::dfs(int v,vector<bool>&visited){
    //mark the current node as visted
    visited[v]=true;
    cout<<v<<" ";
    //recur for all vertices adajacent to this vertex
    for(int neighbour:adj[v]){
        if(!visited[neighbour]){
            dfs(neighbour,visited);
        }
    }
}
int main(){
    graph g(4);  //creating graph of 4 vertices
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    //mark all vertices as non-visited
    vector<bool>visited(4,0);
    cout<<"dfs treversal from vertex 2: ";
    g.dfs(2,visited);
    return 0;
}