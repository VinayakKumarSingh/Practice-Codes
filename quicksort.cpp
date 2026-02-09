#include<bits/stdc++.h>
#include<vector>
using namespace std;

/*int lpartition(vector<int>&a,int l,int h){
	int pivot=a[h];
	int i=-1;
	for(int j=0;j<h;j++){
		if(a[j]<pivot){
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i+1],a[h]);
	return i+1;
}*/
int hpartition(vector<int>&a,int l,int h){
	int pivot=a[l];
	int i=l-1;
	int j=h+1;
	while(true){
		do{
			i++;
		}while(a[i]<pivot);
		
		do{
			j--;
		}while(a[j]>pivot);
		
		if(i>=j)
			break;
		swap(a[i],a[j]);
	}
	return j;
}
void quicksort(vector<int>&a,int l,int h){
	if(l<h){
		int p=hpartition(a,l,h);
		quicksort(a,l,p);
		quicksort(a,p+1,h);
	}
}
int main(){
	vector<int>a={10,6,8,2,5,7,1,3};
	for(auto i:a){
		cout<<i<<" ";
		}
	cout<<endl;
	quicksort(a,0,a.size()-1);
	for(auto i:a){
		cout<<i<<" ";
		}
	cout<<endl;
}
