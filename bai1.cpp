#include<iostream>
using namespace std;
int main() {
	int N;
	cout<<"Nhap so luong phan tu N: " ;
	cin>>N;
	int a[1000] ;
	cout<<"Nhap"<<N<<"phan tu cua day.\n";
	for(int i=0;i<N;i++) {
		cout<<"a["<<i<<"]: ";
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<N;i++) {
		sum+=a[i];
	}
	cout<<"Tong cac phan tu cua day la: "<<sum<<endl;
	return 0;
}
//Ðo phuc tap thuat toan tine  O(n) ,memory O(1) 
