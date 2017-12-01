#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int head[maxn];
int dfn[maxn],low[maxn],color[maxn];
int stack[maxn],father[maxn],vis[maxn];
int cnt,top,con;
vector<int> cut;

struct e{
	int v,used,next;
}edge[maxn*4];

void init(int n){
	for(int i=0;i<n+10;i++){
		head[i]=-1;
		vis[i]=dfn[i]=low[i]=0;
	}
	cnt=cur=top=0;
}

void add(int u,int v){
	edge[cur].v=v;
	edge[cur].used=0;
	edge[cur].next=head[u];
	head[u]=cur++;
}

void tarjan(int u){
	father[u]=pre;
	dfn[u]=low[u]=++cnt;
	vis[u]=1;
	stack[++top]=u;
	for(int i=head[u];i!=-1;i=edge[i].next){
		if(edge[i].used==0){
			edge[i].used=edge[i^1].used=1;
			int v=edge[i].v;
			if(dfn[v]==0){
				father[v]=u;
				tarjan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(vis[v]==1)	low[u]=min(low[u],dfn[v]);
		}
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
