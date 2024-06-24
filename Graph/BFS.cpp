#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void BFS(vector<vector<int>>&adjlist,int startnode,vector<bool>&visited){
    queue<int>q;             //creating datastructure queue
    visited[startnode]=true;    //initializing first node int visited array to 1
    q.push(startnode);         //after initialing pushing it into queue
    while(!q.empty()){
        int currentnode=q.front();    //frontmost ele wil be brought in current node
        q.pop();   //pop currentnode
        cout<<currentnode<<" ";      //just printing the current node
        for(int neighbour :adjlist[currentnode]){   //by this loop traversing the list of first node
            if(!visited[neighbour]){               //while traversing if current node neighbour is not visited simply mark them visited and put it into the queue
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
}
//simply creating adjacency list or matrix
void addedge(vector<vector<int>> &adjlist,int u,int v){
    adjlist[u].push_back(v);                          
}
int main(){
    int vertices=5;    //taking vertices as 5
    vector<vector<int>>adjlist(vertices);    //creating adjlist with the help of vertices
    //calling addedge() to add edge between vertices
    addedge(adjlist,0,1);
    addedge(adjlist,0,2);
    addedge(adjlist,1,3);
    addedge(adjlist,1,4);
    addedge(adjlist,2,4);
    //initially making visited list 0
    vector<bool>visited(vertices,0);
    //calling bfs fun to display result
    cout<<"breathfirst traversal starting with vertex 0 : ";
    BFS(adjlist,0,visited);
    return 0;
    
}