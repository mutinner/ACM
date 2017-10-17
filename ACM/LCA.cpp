#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=1e5+10;
int a[maxn],deep[maxn],first[maxn],ver[2*maxn],dir[maxn];
bool vis[maxn];
int cnt,n,m,tot,dp[maxn][25];
vector<int> G[maxn];

void init(){
	for(int i=1;i<=n;i++)	G[i].clear();
	memset(vis,0,sizeof(vis));
	tot=0;
}

void dfs(int u,int pre,int d){
	vis[u]=true;
	ver[++tot]=u;
	first[u]=tot;
	deep[tot]=d;
	int sz=G[u].size();
	for(int i=0;i<sz;i++){
		int v=G[u][i];
		if(vis[v]==0&&v!=pre){
			dir[v]=dir[u]+1;
			dfs(v,u,d+1);
			ver[++tot]=u;
			deep[tot]=d;
		}
	}
}

void RMQ_init(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=tot;i++)	dp[i][0]=i;
	for(int j=1;(1<<j)<=tot;j++){
		for(int i=1;i+(1<<j)-1<=tot;i++){
			int x=dp[i][j-1],y=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=deep[x]<deep[y]?x:y;
		}
	}
}

int RMQ(int L,int R){
	int k=log(R-L+1)/log(2);
	int x=dp[L][k],y=dp[R-(1<<k)+1][k];
	return deep[x]<deep[y]?x:y;
}

int LCA(int u,int v){
	int x=first[u],y=first[v];
	if(x>y)		swap(x,y);
	int res=RMQ(x,y);
	return ver[res];
}


int main(){
	while(scanf("%d%d",&n,&m)==2){
		init();
		for(int i=1;i<=n;i++)	scanf("%d",a+i);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0,1);
		RMQ_init();
		while(m--){
			int L,R;
			scanf("%d%d",&L,&R);
			printf("%d\n",LCA(L,R));
		}
	}
	return 0;
}
