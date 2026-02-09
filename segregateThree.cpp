#include<bits/stdc++.h>
using namespace std;

void segregateThreeGrp(vector<int>&arr){
  int lo=0,mid=0,hi=arr.size()-1;
  while(mid<=hi){
    if(arr[mid]==0){
      swap(arr[lo],arr[mid]);
      lo++;
      mid++;
    }
    else if(arr[mid]==1)
      mid++;
    else{
      swap(arr[hi],arr[mid]);
      hi--;
    }
  }
}

int main(){
  vector<int>arr={1,2,0,0,1,2,2,2,1};
  cout<<"BEFORE SEGREGATION"<<endl;
  for(auto it:arr){
    cout<<it<<" ";
  }
  cout<<endl;
  cout<<endl;
  segregateThreeGrp(arr);
  cout<<"AFTER SEGREGATION"<<endl;
  for(auto it:arr){
    cout<<it<<" ";
  }
  cout<<endl;
}
