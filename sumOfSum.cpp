#include<bits/stdc++.h>
using namespace std;

class solution{
    bool isSumOfSubarray(vector<int>arr,int sum){
        unordered_set<int> h;

        int ps=0;

        for(int i=0;i<arr.size();i++){
            ps+=arr[i];

            if(h.find(ps-sum)!=h.end())
                return true;
            if(ps==sum)
                return true;
            h.insert(ps);
        }
        return false;
    }
};

int main(){     
}