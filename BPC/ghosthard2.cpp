#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#define mod 998244353

using namespace std;

int vis[100][100];
long long ans[100];

void dfs(int x,int y,int n){
    vis[x][y]=1;
    ans[28-n]++;
    if (n==0) {
        return;
    }
    if (!vis[x-1][y]) {
        vis[x-1][y]=1;
        dfs(x-1,y,n-1);
        vis[x-1][y]=0;
    }
    if (!vis[x+1][y]) {
        vis[x+1][y]=1;
        dfs(x+1,y,n-1);
        vis[x+1][y]=0;
    }
    if (!vis[x][y-1]) {
        vis[x][y-1]=1;
        dfs(x,y-1,n-1);
        vis[x][y-1]=0;
    }
    if (!vis[x][y+1]) {
        vis[x][y+1]=1;
        dfs(x,y+1,n-1);
        vis[x][y+1]=0;
    }
}

int main()
{
    for (int i=0;i<=20;++i) vis[0][i]=1,vis[i][0]=1,vis[7][i]=1,vis[i][10]=1;
    dfs(1,1,28);
    for (int i=1;i<=28;++i) {
		cout << i << ' ' << ans[i] << '\n';
    }
    return 0;
}
