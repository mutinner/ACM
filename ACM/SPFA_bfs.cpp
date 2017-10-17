#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=2e5+10;
const int inf=1<<30;
int n,m,cnt;
bool vis[maxn];
int head[maxn],dis[maxn];

struct node{
	int v,w,next;
}edge[maxn<<2];

queue<int> q;

void add(int u,int v,int w){
	edge[++cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void SPFA(int s){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)	dis[i]=inf;
	dis[s]=0;
	while(!q.empty())	q.pop();
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i!=0;i=edge[i].next){
			int v=edge[i].v,w=edge[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(vis[v]==0){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}

int main(){
	cnt=0;
	memset(head,0,sizeof(head));
	
}
