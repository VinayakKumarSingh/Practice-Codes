#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    void printfreq(vector<int>arr){
        unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        for(auto e:freq){
            cout<<e.first<<" \t"<<e.second<<endl;
        }
    }
};
int main(){
    solution sol;

    vector<int>arr={10,20,20,30,10,30,10,20};

    sol.printfreq(arr);

    return 0;
}