#include<iostream>
using namespace std;
int main() {
	int n;
	cout<<"Nhap so nguyen n: ";
	cin>>n;
	long long kq=1;
	if(n==0){
		cout<<"Ket qua n!=1";
	}else{
		for(int i=1;i<=n;i++) {
			kq*=i;
		}
		cout<<"Ket qua "<<n<<"! = "<<kq;
	}
	return 0;
}
//Do phuc tap time O(n) ,memory O(1) 