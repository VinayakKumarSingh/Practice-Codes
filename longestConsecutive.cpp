#include<bits/stdc++.h>
using namespace std;

int longestsubseq(vector<int>arr){
    unordered_set<int>h(arr.begin(),arr.end());
    int res=1;

    for(auto e:h){
        if(h.find(e-1)==h.end()){
            int curr=1;
            while(h.find(e+curr)!=h.end())
                curr++;
            res=max(res,curr);
        }
    }
    return res;
}


int main(){
    vector<int>arr={1,10,6,6,30,2,4,3,5};

    cout<<longestsubseq(arr)<<endl;
}