#include<iostream>
using namespace std;
void rutgon(int a,int b){
	int ucln=1;
	for(int i=1;i<=a&&i<=b;i++){
		if(a%i==0&&b%i==0){
			ucln=i;
		}
	}
	a=a/ucln;
	b=b/ucln;
	cout<<"Phan so sau khi rut gon:"<<a<<"/"<<b<<endl;
}
int main(){
	int a,b;
	cout<<"Nhap tu so a: ";
	cin>>a;
	cout<<"Nhap mau so b: ";
	cin>>b;
	rutgon(a, b);
	return 0;
}
//Do phuc tap thoi gian O(min(a,b)) ,memory O(1) 