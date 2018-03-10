#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
int prime[maxn];
bool vis[maxn*1000];

void init(){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	memset(prime,0,sizeof(prime));
	for(int i=2;i<maxn;i++){
		if(vis[i]==false)	prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=maxn;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)	break;
		}
	}
}

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Prime{
private :
	int maxn=0;
	deque<bool> vis;
	void init(){
		vis.assign(maxn*1000,false);
		for(int i=2;i<maxn;i++){
			if(vis[i]==false)	prime.push_back(i);
			for(auto jt:prime){
				if(i*jt>maxn)	break;
				vis[i*jt]=true;
				if(i%jt==0)	break;
			}
		}
	}
public :
	vector<int> prime;
	Prime(){
		maxn=1e5+10;
		init();
	}
	Prime(int val){
		maxn=val;
		init();
	}
};

int main(){
	Prime cnt=Prime();
	for(auto it:cnt.prime)	cout<<it<<endl;
	return 0;
}
