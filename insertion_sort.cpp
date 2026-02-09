#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int>&a){
  for(int i=1;i<a.size();i++){
    int key=a[i];
    int j=i-1;
    while(j>=0&&a[j]>key){
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
  }
}
int main(){
  vector<int>a;
  a={12,24,18,15,20};
  insertion_sort(a);
  for(int i:a)
  
  cout<<i<<" ";
  cout<<endl;
}
