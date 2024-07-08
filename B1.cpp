#include <iostream>
using namespace std;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int a[10][10];
int n,dem=0;
void Init(){
    freopen("Ma.inp","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
}
void Print(){
    cout<<"Phương án thứ "<<++dem <<":\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
void Ma(int x, int y, int d){
    a[x][y]=d;
    if (a[n-1][n-1]!=0){
        Print();
    }
    for(int i=0;i<8;i++){
        int u=x+dx[i],v=y+dy[i];
        if (a[u][v]==0&&u>=0&&u<n&&v>=0&&v<n)
            Ma(u,v,d+1);
    }
    a[x][y]=0;
}
int main() {
    Init();
    Ma(0,0,1);
    cout<<"Có "<< dem<<" phương án";
    return 0;
}