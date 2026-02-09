#include<bits/stdc++.h>
using namespace std;

void distinctElementsinK(vector<int>arr,int k){
    map<int,int>freq;
    for(int i=0;i<k;i++){
        freq[arr[i]]++;
    }
    cout<<freq.size()<<" ";
    for(int i=k;i<arr.size();i++){
        freq[arr[i-k]]--;

        if(freq[arr[i-k]]==0){
            freq.erase(arr[i-k]);
        }

        freq[arr[i]]++;

        cout<<freq.size()<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int >arr={10,20,20,30,30,30,40,50,60};

    int k=3;

    distinctElementsinK(arr,k);
}