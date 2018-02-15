#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1000;
vector<int> G[maxn];
int sz[maxn],fa[maxn],top[maxn];
int dep[maxn],tid[maxn],rnk[maxn];
int tot=0;

void dfs(int x,int pre,int depth){
	sz[x]=1;	fa[x]=pre;
	dep[x]=depth;
	for(auto it:G[x]){
		if(it==pre)	continue;
		dfs(it,x,depth+1);
		sz[x]+=sz[it];
		if(son[x]==-1||sz[it]>sz[son[x]])	son[x]=it;
	}
}

void dfs_2(int u,int cur){
	top[u]=cur;	tid[u]=++tot;
	rnk[tot]=u;
	if(son[u]==-1)	return;
	dfs_2(son[u],cur);
	for(auto it:G[u]){
		if(it!=son[u]&&it!=fa[u])	dfs_2(it,it);
	}
}

int pathQuery(int u,int v){
	int ans=0;
	int x=top[u],y=top[v];
	while(x!=y){
		if(dep[x]>dep[y]){
			ans+=query(tid[x],tid[u]);
			u=fa[x];
		}
		else {
			ans+=query(tid[y],tid[v]);
			v=fa[y];
		}
		x=top[u];	y=top[v];
	}
	if(u!=v)	ans+=query(min(tid[u],tid[v]),max(tid[u],tid[v]));
	else	ans+=query(tid[x],tid[y]);
	return ans;
}
