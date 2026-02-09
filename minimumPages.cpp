#include<bits/stdc++.h>
using namespace std;
bool isfeasible(vector<int>arr,int k,int max){
  int students=1;
  int sum=0;
  
  for(int j=0;j<arr.size();j++){
    if(sum>max){
      students++;
      sum=arr[j];
    }
    else
      sum+=arr[j];
  }
  if(students>k) return false;
  else return true;
}
int minimumPages(vector<int>arr,int n,int k){
  if(n==1)
    return arr[0];
  
  int high=arr[0],low=arr[0];
  for(int i=1;i<n;i++){
    high+=arr[i];
    low=max(low,arr[i]);
  }
  if(k==1)
    return high;
  
  int res;
  while(low<=high){
    int mid=low+(high-low)/2;
    
    if(isfeasible(arr,k,mid)){
      res = mid;
      high=mid-1;
    }
    else
      low=mid+1;
  }
  return res;
}
int main(){
  int k=3;
  vector<int>arr={10,5,30,1,2,5,10,10};
  int n=arr.size();
  cout<<minimumPages(arr,n,k)<<endl;
}
