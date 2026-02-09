#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    void printunion(vector<int>a,vector<int>b){
        unordered_set<int>h(a.begin(),a.end());
        for(auto e:b){
            h.insert(e);
        }
        cout<<h.size()<<endl;
    }
};

int main(){
    solution s;

    vector<int>a={10,20,30,40,10};
    vector<int>b={20,30,50,60};
    s.printunion(a,b);
}