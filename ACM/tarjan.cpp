#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> G[maxn];
int dfn[maxn],low[maxn],stack[maxn],father[maxn];
bool vis[maxn];
int cnt,top,con;
vector<int> cut;

void tarjan(int u,int pre){
	father[u]=pre;
	dfn[u]=low[u]=++cnt;
	vis[u]=true;
	stack[++top]=u;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==pre)	continue;
		if(dfn[v]==0){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])	low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		con++;
		do{
			vis[stack[top]]=false;
			color[stack[top]]=con;
		}while(u!=stack[top--]);
	}
}

void count(){
	int rootson=0;
	tarjan(1,-1);
	for(int i=2;i<=n;i++){
		int v=father[i];
		if(v==1)	rootson++;
		else if(low[i]>=dfn[v])	cut[v]=1;
	}
	if(rootson>1)	cut[1]=1;
	
	for(int i=1;i<=n;i++){
		int v=father[i];
		if(v>0&&low[i]>dfn[v])
			printf("%d-%d\n",v,i);
	}
}
