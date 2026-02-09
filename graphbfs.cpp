#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>adj[],int V,int s){
  bool visited[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  queue<int>q;
  q.push(s);
  visited[s]=true;
  
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    for(auto v:adj[curr]){
      if(visited[v]==false){
        visited[v]=true;
        q.push(v);
      }
    }
  }
}
void addedge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main(){
  int V=5;
  vector<int>adj[V];
  addedge(adj,0,1);
  addedge(adj,0,2);
  addedge(adj,1,3);
  addedge(adj,1,2);
  addedge(adj,2,4);
  addedge(adj,2,3);
  addedge(adj,3,4);
  bfs(adj,V,0);
}
