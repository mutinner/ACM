#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
int head[maxn],d[maxn],cnt;
bool vis[maxn];

struct node{
	int v,w,next;
}edge[maxn];

void add(int u,int v,int w){
	edge[++cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

int spfa_dfs(int u){
	vis[u]=1;
	for(int i=head[u];i!=0;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(d[u]+w<d[v]){
			d[v]=d[u]+w;
			if(!vis[v]){
				if(spfa_dfs(v))	return 1;
			}
			else	return 1;
		}
	}
	vis[u]=0;
	return 0;
}

int main(){
	
}
