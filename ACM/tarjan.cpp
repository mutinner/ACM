#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=100;
int n,m,cnt;
vector<int> G[maxn];
int dfn[maxn],low[maxn];
int ans;

void tarjan(int u,int fa){
	dfn[u]=low[u]=++cnt;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa)	continue;
		if(dfn[v]==0){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])	ans++;
		}
		else	low[u]=min(low[u],dfn[v]);
	}
}

int main(){
	while(scanf("%d%d",&n,&m)==2){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		cnt=0;
		for(int i=1;i<=n;i++)	G[i].clear();
		for(int i=0;i<m;i++){
			int u,v;	scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(dfn[i]==0)	tarjan(i,-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
