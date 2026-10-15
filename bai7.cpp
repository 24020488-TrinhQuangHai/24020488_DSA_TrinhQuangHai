#include<iostream>
using namespace std;
int tongmang(int a[][100],int N,int M){
	int tong=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			tong+=a[i][j];
	}
  }
  return tong;
}
void xoadong(int a[][100],int &N,int M,int i){
	for(int k=i;k<N-1;k++){
		for(int j=0;j<M;j++){
			a[k][j]=a[k+1][j];
		}
	}
	N--;
}
int main(){
	int N,M;
	int a[100][100];
	cout<<"Nhap vao so hang va so cot cua mang: ";
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Tong cac phan tu cua mang = "<<tongmang(a,N,M)<<endl;
	int i;
	cout<<"Nhap vao dong can xoa i= ";
	cin>>i;
	xoadong(a,N,M,i);
	cout<<"Mang sau khi xoa:\n";
	for(int k=0;k<N;k++){
		for(int j=0;j<M;j++){
			cout<<a[k][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
//Do phuc tap time O( N.M) ,memory O(1) 