#include<iostream>
using namespace std;
int main() {
	int n;
	cout<<"Nhap vao so luong phan tu: ";
	cin>>n;
	float a[1000];
	float sum=0;
	cout<<"Nhap cac phan tu cua day:\n";
	for(int i=0;i<n;i++){
		cout<<"Phan tu thu "<<i+1<<": ";
		cin>>a[i];
		sum+=a[i];
	}
	float trungbinh=sum/n;
	cout<<"Cac gia tri lon hon hoac bang gia tri trung binh la: ";
	for(int i=0;i<n;i++){
		if(a[i]>=trungbinh){
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}
//Do phuc tap time O(n) ,memory O(1) 