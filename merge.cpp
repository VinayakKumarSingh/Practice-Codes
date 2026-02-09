#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int n,int low,int high,int mid){
	int n1=mid-low+1;
	int n2=high-mid;
	int left[n1];
	int right[n2];
	for(int i=0;i<n1;i++)
		left[i]=a[i];
	for(int i=0;i<n2;i++)
		right[i]=a[n1+i];
	
}
int main()
