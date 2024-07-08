#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,S;cin>>n>>S;
    int w[n+1],v[n+1];
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int dp[n+1][n+1];
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<S;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=S;j++){
            //chua bo do vao tui
            dp[i][j]=dp[i-1][j];
            //bo vao thu 
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][S];
    return 0;
}