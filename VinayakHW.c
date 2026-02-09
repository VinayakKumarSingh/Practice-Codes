#include<stdio.h>
int main(){
	int *pt1,*pt2;
	int a,b;
	a=10;
	b=24;
	pt1=&a;
	pt2=&b;
	
	int add=sum(a,b);
	printf("The sum is %d\n",add);
	swap(a,b);
	
	int n1;
	printf("Enter the size of the array\n");
	scanf("%d\n",&n1);
	arr(n1);
	
	int x[]={1,4,5,6,7};
	int y[5];
	cpy(x,y);
	
	char st[]="PALINDROME";
	int length=stlen(st);
	printf("The length of the string is %d\n",length);
	
	max(a,b);
	
}
int sum(int p,int q){
	int *p1=&p;
	int *p2=&q;
	return (*p1+*p2);
}
int swap(int c,int d){
	int *p1=&c;
	int *p2=&d;
	*p1=*p1+*p2;
	*p2=*p1-*p2;
	*p1=*p1-*p2;
	printf("a is %d \n",*p1);
	printf("b is %d \n",*p2);
}
int arr(int n){
	int a[n];
	int *pt=a;
	printf("Enter the array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d ",(pt+i));
	for(int i=0;i<n;i++)
		printf("%d ",*(pt+i));
}
int cpy(int a1[5],int a2[5]){
	int *pr1=a1;
	int *pr2=a2;
	for(int i=0;i<5;i++){
		*(pr2+i)=*(pr1+i);
	}
	for(int i=0;i<5;i++){
		printf("%d ",*(pr2+i));
	}
}
int stlen(char st[]) {
    char *s1 = st;
    int len = 0;
    while (*(s1 + len) != '\0') {
        len++;
    }
    return len;
}

int max(int a,int b){
	int *ps1=&a;
	int *ps2=&b;
	int maxi=(*ps1>*ps2)?*ps1:*ps2;
	printf("Maximum of 2 numbers is %d\n",maxi);
}

