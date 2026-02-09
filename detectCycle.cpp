#include<bits/stdc++.h>
using namespace std;
bool dfsrec(vector<int>adj[],int s,vector<bool>visited,vector<bool>rec_call_stack){
  visited[s]=true;
  rec_call_stack[s]=true;
  for(auto u:adj[s]){
    if(visited[u]==false&&dfsrec(adj,u,visited,rec_call_stack))
      return true;
    else if(rec_call_stack[u]==true)
      return true;
  }
  return false;
}
bool dfs(vector<int>adj[],int V){
  vector<bool>visited(V,false);
  vector<bool>rec_call_stack(V,false);
  for(int i=0;i<V;i++){
    if(visited[i]==false){
      if(dfsrec(adj,i,visited,rec_call_stack))
        return true;
    }
  }
  return false;
}
void addedge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
int main(){
   int V=6;
  vector<int>adj[V];
  addedge(adj,0,1);
  addedge(adj,2,1);
  addedge(adj,2,3);
  addedge(adj,3,4);
  addedge(adj,4,5);
  addedge(adj,5,3);
  if(dfs(adj,V))
    cout<<"CYCLE DETECTED MF";
  else
    cout<<"CYCLE NOT DETECTED MF";
  cout<<endl;
}
