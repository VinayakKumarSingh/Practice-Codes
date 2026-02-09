#include<bits/stdc++.h>
using namespace std;
void transpose(vector<int>arr[],int m){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<arr[i].size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int j=0;j<arr[0].size();j++){
    int low=0,high=m-1;
    while(low<high){
            swap(arr[low][j],arr[high][j]);
            low++;
            high--;
        }
    }
}
void printMatrix(vector<int>arr[],int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<arr[i].size();j++){
            if(j+1==arr[i].size()){
                cout<<arr[i][j]<<"\n";
            }
            else
                cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int m=3;int n=3;int k=1;
    vector<int>arr[m];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            arr[i].push_back(k++);
    }
    cout<<"Before Rotation"<<endl;
    printMatrix(arr,m);
    transpose(arr,m);
    cout<<"After Rotation (anticlockwise 90 degree)"<<endl;
    printMatrix(arr,m);
}