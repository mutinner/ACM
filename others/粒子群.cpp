#include<iostream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<random>
#include<vector>
using namespace std;

const double pi=acos(-1.0);
const double c1=1.49445,c2=1.49445;
const pair<double,double> Vextra=make_pair(-0.5,0.5);
const pair<double,double> Pextra=make_pair(-2,2);

struct Indival{
	vector<double> x,v,pbest;
	double fit,bestfit;
	bool operator < (const Indival& cnt)const{
		return fit<cnt.fit;
	}
	void init(int n){
		x.resize(n);
		v.resize(n);
		pbest.resize(n);
	}
	double func(){
		double tmp=pow(x[0],2)+pow(x[1],2);
		return sin(sqrt(tmp))/sqrt(tmp)+exp((cos(2*pi*x[0])+cos(2*pi*x[1]))/2)-exp(1.0);
	}
};

bool cmp(const pair<double,vector<double>>& x,const pair<double,vector<double>>& y){
	return x.first<y.first;
}

struct node{
	vector<double> x;
	vector<pair<double,vector<double>>> result;
	double bestfit;
	double func(){
		double tmp=pow(x[0],2)+pow(x[1],2);
		return sin(sqrt(tmp))/sqrt(tmp)+exp((cos(2*pi*x[0])+cos(2*pi*x[1]))/2)-exp(1.0);
	}
}group;

vector<Indival> cnt;
int dim=2,maxgen=300,IndSize=20;

mt19937 rd(time(NULL));
uniform_real_distribution<> dis(0,1);

double random(double start,double end){
	return start+(end-start)*dis(rd);
}

void init(){
	cnt.resize(IndSize);
	for(auto& it:cnt){
		it.init(dim);
		for(auto& jt:it.x)	jt=random(-2,2);
		for(auto& jt:it.v)	jt=random(-0.5,0.5);
		it.bestfit=it.fit=it.func();
		it.pbest=it.x;
	}
}

void PSO(){
	init();
	auto c=max_element(cnt.begin(),cnt.end());
	group.x=c->x;
	group.bestfit=c->bestfit;
	int T=maxgen;
	while(T--){
		for(auto& it:cnt){
			for(int j=0;j<dim;j++){
				double L=random(0,1),R=random(0,1);
				it.v[j]+=c1*L*(it.pbest[j]-it.x[j])+c2*R*(group.x[j]-it.x[j]);
				it.v[j]=min(it.v[j],Vextra.second);
				it.v[j]=max(it.v[j],Vextra.first);
				it.x[j]+=it.v[j];
				it.x[j]=min(it.x[j],Pextra.second);
				it.x[j]=max(it.x[j],Pextra.first);
			}
			it.fit=it.func();
		}
		for(auto& it:cnt){
			if(it.fit>it.bestfit){
				it.pbest=it.x;
				it.bestfit=it.fit;
			}
			if(it.fit>group.bestfit){
				group.bestfit=it.fit;
				group.x=it.x;
			}
		}
		group.result.push_back(make_pair(group.bestfit,group.x));
	}
}

int main(){
	PSO();
	cout<<max_element(group.result.begin(),group.result.end(),cmp)->first<<endl;
	return 0;
}
