#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn=500;
const int inf=0x3f3f3f3f;

struct Edge{
	int u,v,cap,flow;
	Edge(int u,int v,int c,int f):u(u),v(v),cap(c),flow(f){}
};

struct EK{
	vector<Edge> edge;
	vector<int> G[maxn];
	int dis[maxn],p[maxn];
	
	void init(int n){
		for(int i=0;i<n;i++)	G[i].clear();
		edge.clear();
	}
	
	void addedge(int u,int v,int cap){
		edge.push_back(Edge(u,v,cap,0));
		edge.push_back(Edge(v,u,0,0));
		int m=edge.size();
		G[u].push_back(m-2);
		G[v].push_back(m-1);
	}
	
	int maxflow(int s,int t){
		int flow=0;
		for(;;){
			memset(dis,0,sizeof(dis));
			queue<int> q;
			q.push(s);
			dis[s]=inf;
			while(!q.empty()){
				int u=q.front();	q.pop();
				for(int i=0;i<G[u].size();i++){
					Edge& e=edge[G[u][i]];
					if(!dis[e.v]&&e.cap>e.flow){
						p[e.v]=G[u][i];
						dis[e.v]=min(dis[u],e.cap-e.flow);
						q.push(e.v);
					}
				}
				if(dis[t])	break;
			}
			if(!dis[t])	break;
			for(int i=t;i!=s;i=edge[p[i]].u){
				edge[p[i]].flow+=dis[t];
				edge[p[i]^1].flow-=dis[t];
			}
			flow+=dis[t];
		}
		return flow;
	}
};

int main(){
	
}
