#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;
const ll inf=1<<30;

struct sgetree{
	int L,R;
	ll sum,maxn,minn;	
};

vector<sgetree> cnt;

void build(int x,int L,int R){
	cnt[x]=sgetree{L,R,0,-inf,inf};
	if(L==R)	return ;
	int mid=(L+R)>>1;
	build(x*2,L,mid);
	build(x*2+1,mid+1,R);
}

void insert(int x,int pos,ll num){
	cnt[x].sum+=num;
	cnt[x].maxn=max(cnt[x].maxn,num);
	cnt[x].minn=min(cnt[x].minn,num);
	if(cnt[x].L==cnt[x].R)	return ;
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(pos<=mid)	insert(x*2,pos,num);
	else	insert(x*2+1,pos,num);
}

void alert(int x,int pos,ll num){
	if(pos==cnt[x].L&&pos==cnt[x].R){
		cnt[x].sum=num;
		cnt[x].maxn=num;
		cnt[x].minn=num;
	}
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(pos<=mid)	alert(x*2,pos,num);
	else	alert(x*2+1,pos,num);
	cnt[x].sum=cnt[x*2].sum+cnt[x*2+1].sum;
	cnt[x].maxn=max(cnt[x*2].maxn,cnt[x*2+1].maxn);
	cnt[x].minn=min(cnt[x*2].minn,cnt[x*2+1].minn);
}

ll querysum(int x,int L,int R){
	if(L==cnt[x].L&&R==cnt[x].R)	return cnt[x].sum;
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(R<=mid)	return querysum(x*2,L,R);
	else if(L>mid)	querysum(x*2+1,L,R);
	else	return querysum(x*2,L,mid)+querysum(x*2+1,mid+1,R);
}

int main(){
	
}
