#include<bits/stdc++.h>
using namespace std;
void dfsrec(vector<int>adj[],int s,bool visited[])
{
  visited[s]=true;
  
  for(auto u:adj[s]){
    if(visited[u]==false)
      dfsrec(adj,u,visited);
  }
}
int dfs(vector<int>adj[],int V){
  bool visited[V];int count=0;
  for(int i=0;i<V;i++)
    visited[i]=false;
  for(int i=0;i<V;i++){
    if(visited[i]==false){
      dfsrec(adj,i,visited);
      count++;
      }
  }
  return count;
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
  cout<<dfs(adj,V);
  cout<<endl;
}
