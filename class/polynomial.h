#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include "../include/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pid;
const int mod=998244353;

struct node {
	int coef,exp;//coef==0:head
	node *next;
	node() {coef=exp=0;next=NULL;}
};

int qpow(int x0,int y) {
	if(y<0) return qpow(qpow(x0,mod-2),-y);
	ll res=1,x=x0;
	for(;y;y>>=1) res=(y&1)?(res*x%mod):res,x=x*x%mod;
	return (int)res;
}

class slist {
private:
	node *head;
public:
	slist() {head=new node;}
	~slist() {}//
	void output() const{
		cout<<head->exp<<",";
		for(node* cur=head->next;cur!=NULL;cur=cur->next)
			cout<<cur->coef<<","<<cur->exp<<",";
		cout<<endl;
		return ;
	}
	slist operator + (const slist &b) const {
		slist res;
		node* cur1=head->next,*cur2=b.head->next,*cur=res.head;
		while(cur1!=NULL&&cur2!=NULL) {
			if(cur1->exp==cur2->exp) {
				if((cur1->coef+cur2->coef)%mod) {
					cur->next=new node;
					res.head->exp++;
					cur->next->exp=cur1->exp;
					cur->next->coef=(cur1->coef+cur2->coef)%mod;
					cur=cur->next;
				}
				cur1=cur1->next;cur2=cur2->next;
			} else if(cur1->exp>cur2->exp) {
				cur->next=new node;
				res.head->exp++;
				cur->next->exp=cur1->exp;
				cur->next->coef=cur1->coef;
				cur1=cur1->next;
				cur=cur->next;
			} else {
				cur->next=new node;
				res.head->exp++;
				cur->next->exp=cur2->exp;
				cur->next->coef=cur2->coef;
				cur2=cur2->next;
				cur=cur->next;
			}
		} 
		for(;cur1!=NULL;cur1=cur1->next,cur=cur->next) {
			cur->next=new node;
			res.head->exp++;
			cur->next->exp=cur1->exp;
			cur->next->coef=cur1->coef;
			cur=cur->next;
		}
		for(;cur2!=NULL;cur2=cur2->next,cur=cur->next) {
			cur->next=new node;
			res.head->exp++;
			cur->next->exp=cur2->exp;
			cur->next->coef=cur2->coef;
			cur=cur->next;
		}
		return res;
	}
	slist operator - (const slist &b) const {
		slist res;
		node* cur1=head->next,*cur2=b.head->next,*cur=res.head;
		while(cur1!=NULL&&cur2!=NULL) {
			if(cur1->exp==cur2->exp) {
				if((cur1->coef-cur2->coef+mod)%mod) {
					cur->next=new node;
					res.head++;
					cur->next->exp=cur1->exp; 
					cur->next->coef=(cur1->coef-cur2->coef+mod)%mod;
					cur=cur->next;
				}
				cur1=cur1->next;cur2=cur2->next;
			} else if(cur1->exp>cur2->exp) {
				cur->next=new node;
				res.head++;
				cur->next->exp=cur1->exp;
				cur->next->coef=cur1->coef;
				cur1=cur1->next;
				cur=cur->next;
			} else {
				cur->next=new node;
				res.head++;
				cur->next->exp=cur2->exp;
				cur->next->coef=mod-cur2->coef;
				cur2=cur2->next;
				cur=cur->next;
			}
		} 
		for(;cur1!=NULL;cur1=cur1->next,cur=cur->next) {
			cur->next=new node;
			res.head->exp++;
			cur->next->exp=cur1->exp;
			cur->next->coef=cur1->coef;
			cur=cur->next;
		}
		for(;cur2!=NULL;cur2=cur2->next,cur=cur->next) {
			cur->next=new node;
			res.head->exp++;
			cur->next->exp=cur2->exp;
			cur->next->coef=mod-cur2->coef;
			cur=cur->next;
		}
		return res;
	}
	int calculate(int x)const {
		node *cur=head->next;
		ll res=cur->coef;
		for(;cur->next!=NULL;cur=cur->next) 
			res=(res*qpow(x,cur->exp-cur->next->exp)%mod+cur->next->coef)%mod;
		res=res*qpow(x,cur->exp)%mod;
		return res;
	}
	friend slist construct(vector<pid> v);
};

slist construct(vector<pid> v) {
	cout<<"?"<<endl;
	slist res;
	node *cur=res.head;
	sort(v.rbegin(),v.rend());
	for(int i=0,sz=v.size();i<sz;i++) {
		cur->next=new node;
		res.head++;
		cur->next->exp=v[i].first;
		cur->next->coef=v[i].second;
		cur=cur->next;
	}
	return res;
}

#endif