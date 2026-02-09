#include<bits/stdc++.h>
using namespace std;
void transpose(vector<int>arr[],int m){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<arr[i].size();j++){
            swap(arr[i][j],arr[j][i]);
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
    cout<<"Before transpose"<<endl;
    printMatrix(arr,m);
    transpose(arr,m);
    cout<<"After Transpose"<<endl;
    printMatrix(arr,m);
}