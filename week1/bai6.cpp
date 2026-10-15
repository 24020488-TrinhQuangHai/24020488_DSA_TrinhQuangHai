#include<iostream>
using namespace std;
void xoa(int a[],int &n,int k){
   if(k<0||k>=n){
   	cout<<"Phan tu can xoa khong hop le";
   	return;
   }
   for(int i=k;i<n-1;i++){
   	a[i]=a[i+1];
   }
   n--;
}
void insert(int a[],int &n,int m,int y){
	if(m<0||m>n){
		cout<<"Vi tri khong hop le";
		return;
	}
	for(int i=n;i>m;i--){
		a[i]=a[i-1];
	}
	a[m]=y; 
	n++;
}
void inmang(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int n;
	cout<<"Nhap so luong phan tu cua mang: ";
	cin>>n;
	int a[1000];
	cout<<"Nhap cac phan tu cua mang: ";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]: ";
		cin>>a[i];
	}
	int k;
	cout<<"Nhap vi tri k can xoa: ";
	cin>>k;
	xoa(a,n,k);
	cout<<"Day sau khi xoa: ";
	inmang(a,n);
	
	int y,m;
	cout<<"Nhap gia tri can chen: ";
	cin>>y;
	cout<<"Nhap vi tri can chen: ";
	cin>>m;
	insert(a,n,m,y);
	cout<<"Day sau khi chen: ";
	inmang(a,n);
	
	return 0;
	
}
//Do phuc tap thoi gian O(n),memory O(1) 