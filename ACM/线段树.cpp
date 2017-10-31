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
vector<ll> add;

void build(int x,int L,int R){
	cnt[x]=sgetree{L,R,0,-inf,inf};
	if(L==R)	return ;
	int mid=(L+R)>>1;
	build(x*2,L,mid);
	build(x*2+1,mid+1,R);
}

void insert(int x,int pos,ll num){
	if(pos==cnt[x].L&&pos==cnt[x].R){
		cnt[x].sum+=num;
		cnt[x].maxn+=num;
		cnt[x].minn+=num;
		return ;
	}
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(pos<=mid)	insert(x*2,pos,num);
	else	insert(x*2+1,pos,num);
	cnt[x].sum=cnt[x*2].sum+cnt[x*2+1].sum;
	cnt[x].maxn=max(cnt[x*2].maxn,cnt[x*2+1].maxn);
	cnt[x].minn=min(cnt[x*2].minn,cnt[x*2+1].minn);
}

ll querysum(int x,int L,int R){
	if(L==cnt[x].L&&R==cnt[x].R)	return cnt[x].sum;
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(R<=mid)	return querysum(x*2,L,R);
	else if(L>mid) return	querysum(x*2+1,L,R);
	else	return querysum(x*2,L,mid)+querysum(x*2+1,mid+1,R);
}

ll querymax(int x,int L,int R){
	if(L==cnt[x].L&&R==cnt[x].R)	return cnt[x].maxn;
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(R<=mid)  return querymax(x*2,L,R);
	else if(L>mid)  return querymax(x*2+1,L,R);
	else    return max(querymax(x*2,L,mid),querymax(x*2+1,mid+1,R));
}

void pushup(int x){
	cnt[x].sum=cnt[x*2].sum+cnt[x*2+1].sum;
}

void pushdown(int x,int L,int R){
	if(add[x]!=0){
		add[x*2]+=add[x];   add[x*2+1]+=add[x];
		int mid=(L+R)>>1;
		cnt[x*2].sum+=add[x]*(mid-L+1);
		cnt[x*2+1].sum+=add[x]*(R-mid);
		add[x]=0;
	}
}

void update(int x,int L,int R,ll addv){
	if(L==cnt[x].L&&R==cnt[x].R){
		add[x]+=addv;
		cnt[x].sum+=addv*(R-L+1);
		return ;
	}
	pushdown(x,L,R);
	int mid=(L+R)>>1;
	if(L<=mid)    update(x*2,L,mid,addv);
	else    update(x*2+1,mid+1,R,addv);
	pushup(x);
}

ll query(int x,int L,int R){
	if(L==cnt[x].L&&R==cnt[x].R)    return cnt[x].sum;
	pushdown(x,L,R);
	int mid=(L+R)>>1;
	return query(x*2,L,mid)+query(x*2+1,mid+1,R);
}

int main(){
	
}
