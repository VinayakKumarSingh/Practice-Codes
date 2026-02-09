#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
int secondlargest(vector <int> nums){
	int max=INT_MIN;
	int smax=INT_MIN;
	for(int i=0;i<nums.size();i++){
		if(max<nums[i]){
			smax=max;
			max=nums[i];
		}
		if(smax<nums[i]&&nums[i]<max)
			smax=nums[i];
	}
	return smax;
}
int main(){
	vector <int> nums={23,22,15,25,24};
	cout<<secondlargest(nums)<<endl;
}
