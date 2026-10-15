#include<iostream>
using namespace std;
void sort(int a[], int n) {
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++) {
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main() {
	int n;
	cout<<"Nhap so luong phan tu N: ";
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]: ";
		cin>>a[i];
	}
	sort(a,n);
	cout<<"Day sau khi sap xep tang dan la: ";
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
// Do phuc tap thuat toan time O(n^2) ,memory O(1) 