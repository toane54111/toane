#include <bits/stdc++.h>
using namespace std;

int a[10][10];
int x,y;
int dx[3]={1,1,1};
int dy[3]={-1,0,1};
int tong=0;
int maxx=INT_MIN;
int n;
void nhap(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>a[i][j];
		}
	}
}

void Tong(int x,int y){
	if(tong>maxx && x==3){
		maxx=tong;
		tong=0;
	}
	for(int i=0;i<3;i++){
		int u=x+dx[i];int v=y+dy[i];
		if(u>=0&&u<n&&v>=0&&v<n){
			tong+=a[x][y];
			Tong(u,v);
		}
	}
}

int main(){
	cin>>n;
	nhap();
	Tong(0,0);
	cout<<maxx;
	return 0;
}