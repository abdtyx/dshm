#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include "../include/stdc++.h"
using namespace std;
typedef pair<int,double> pid;

struct node {
	int coef,exp;//coef==0:head
	node *next;
	node() {coef=exp=0;next=NULL;}
};

class slist {
private:
	node *head;
public:
	slist() {head=new node;}
	~slist() {}//
	void insert(int e,double c) {
		node *cur=head;
		while(cur->next!=NULL&&cur->next->exp>e)
			cur=cur->next;
		node* tmp=cur->next;
		cur->next=new node;
		cur->next->next=tmp;
		cur->next->exp=e;
		cur->next->coef=c;
		head->exp++;
		return ;
	}
	void output() const{
		cout<<head->exp<<",";
		for(node* cur=head->next;cur!=NULL;cur=cur->next)
			cout<<cur->coef<<","<<cur->exp<<",";
		cout<<endl;
		return ;
	}
	slist operator + (const slist &b) const {
		slist res;
		node* cur1=head->next,*cur2=b.head->next;
		while(cur1!=NULL&&cur2!=NULL) {
			if(cur1->exp==cur2->exp) {
				if(cur1->coef+cur2->coef) 
					res.insert(cur1->exp,cur1->coef+cur2->coef);
				cur1=cur1->next;cur2=cur2->next;
			} else if(cur1->exp>cur2->exp) {
				res.insert(cur1->exp,cur1->coef);
				cur1=cur1->next;
			} else {
				res.insert(cur2->exp,cur2->coef);
				cur2=cur2->next;
			}
		} 
		for(;cur1;cur1=cur1->next) 
			res.insert(cur1->exp,cur1->coef);
		for(;cur2;cur2=cur2->next)
			res.insert(cur2->exp,cur2->coef);
		return res;
	}
	slist operator - (const slist &b) const {
		slist res;
		node* cur1=head->next,*cur2=b.head->next;
		while(cur1!=NULL&&cur2!=NULL) {
			if(cur1->exp==cur2->exp) {
				if(cur1->coef-cur2->coef) 
					res.insert(cur1->exp,cur1->coef-cur2->coef);
				cur1=cur1->next;cur2=cur2->next;
			} else if(cur1->exp>cur2->exp) {
				res.insert(cur1->exp,cur1->coef);
				cur1=cur1->next;
			} else {
				res.insert(cur2->exp,-cur2->coef);
				cur2=cur2->next;
			}
		} 
		for(;cur1;cur1=cur1->next) 
			res.insert(cur1->exp,cur1->coef);
		for(;cur2;cur2=cur2->next)
			res.insert(cur2->exp,-cur2->coef);
		return res;
	}
	double calculate(double x)const {
		node *cur=head->next;
		double res=cur->coef;
		for(;cur->next!=NULL&&cur->next->exp>=0;cur=cur->next) 
			res=res*pow(x,cur->exp-cur->next->exp)+cur->next->coef;
		res*=pow(x,cur->exp);
		for(cur=cur->next;cur!=NULL;cur=cur->next)
			res+=pow(x,cur->exp)*cur->coef;
		return res;
	}
};

	slist construct(vector<pid> v) {
		slist res;
		for(int i=0,sz=v.size();i<sz;i++) 
			res.insert(v[i].first,v[i].second);
		return res;
	}

#endif