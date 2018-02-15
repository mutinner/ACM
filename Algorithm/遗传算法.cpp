#include<iostream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<random>
using namespace std;

const int colSize=100,size=2,Gener=3000;
const double over=0.7,mut=0.1,upper=30.0,pi=3.1415926;
int GenNum=0;

struct Indival{
	double code[size],fit;
	double cfit,rfit;
	bool operator < (const Indival& cur)const{
		return fit>cur.fit;
	}
}cnt[colSize];

Indival newcnt[colSize];
Indival best;

mt19937 rd(time(NULL));
uniform_real_distribution<> dis(0,1);

double random(double start,double end){
	return start+(end-start)*dis(rd);
}

void initiate(){
	for(int i=0;i<colSize;i++)	cnt[i]=(Indival){random(-30,30),random(-30,30),0,0,0};
}

void calValue(){
	//	适应度计算 
	double sum=0;
	for(int i=0;i<colSize;i++){
		double x=cnt[i].code[0];
		double y=cnt[i].code[1];
		double L=-0.2*sqrt(pow(x,2)+pow(y,2)/size);
		double R=(cos(2*pi*x)+cos(2*pi*y))/size;
		cnt[i].fit=upper-(-20*exp(L)-exp(R)+exp(1)+20);
		sum+=cnt[i].fit;
	}
	for(int i=0;i<colSize;i++)	cnt[i].rfit=cnt[i].fit/sum;
	cnt[0].cfit=cnt[0].rfit;
	for(int i=1;i<colSize;i++)	cnt[i].cfit=cnt[i-1].cfit+cnt[i].rfit;
}

void select(){
	//	挑选 
	for(int i=0;i<colSize;i++){
		double p=random(0,1);
		if(p<cnt[i].cfit)	newcnt[i]=cnt[0];
		else {
			for(int j=1;j<colSize;j++){
				if(p>=cnt[j-1].cfit&&p<cnt[j].cfit){
					newcnt[i]=cnt[j];
					break;
				}
			}
		}
	}
	for(int i=0;i<colSize;i++)	cnt[i]=newcnt[i];
}

void xOver(int x,int y){
	//	基因交换 
	double p=random(0,1);
	for(int i=0;i<size;i++){
		double L=cnt[x].code[i],R=cnt[y].code[i];
		cnt[x].code[i]=L*p+R*(1-p);
		cnt[y].code[i]=L*(1-p)+R*p;
	}
}

void crossOver(){
	//	杂交 
	int first=0,one;
	for(int i=0;i<colSize;i++){
		if(random(0,1)<over){
			if(++first%2==0)	xOver(one,i);
			else	one=i;
		}
	}
}

double delta(int t,double x,double u,double v){
	//	基因变异 
	double L,R,r=random(0,1);
	L=pow((1-t/Gener),4);
	R=pow(r,L);
	if((int)random(0,2)==0)	return x+(u-x)*(1-R);
	else	return x-(x-v)*(1-R);
}

void mutate(){
	//	变异 
	for(int i=0;i<colSize;i++){
		for(int j=0;j<size;j++){
			double x=random(0,1);
			if(x<mut)	cnt[i].code[j]=delta(GenNum,cnt[i].code[0],30,-30);
		}
	}
}

int main(){
	initiate();
	calValue();
	while(GenNum++<=Gener){
		select();
		crossOver();
		mutate();
		calValue();
		sort(cnt,cnt+colSize);
		if(best.fit<cnt[0].fit){
			best.code[0]=cnt[0].code[0];
			best.code[1]=cnt[0].code[1];
			best.fit=cnt[0].fit;
		}
	}
	return 0;
}
