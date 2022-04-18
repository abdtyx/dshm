#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include "../include/stdc++.h"

using namespace std;

typedef pair<int,double> pid;

/**
 * @brief Node in single linked list
 * stores one term in polynomial and pointer to the next node
 */
struct node {
	int coef;//coefficent of the term,should not be zero
	int exp;//exponent of the term,can be negative
	node *next;//pointer to the next

	/**
	 * @brief constuct&init of node
	 */
	node() {coef=exp=0;next=NULL;}
};

/**
 * @brief single linked list
 *
 * a polynomial and its head
 * the terms are linked in descending order by exponent
 */
class slist {
  private:
	node *head;//head node,not a term in polynomial
			   //head->exp used to store number of terms
  public:
  	slist();
	void output() const;
	slist operator + (const slist &b) const;
	slist operator - (const slist &b) const;
	double calculate(double x) const;
	friend slist construct(vector<pid> v);
};

/**
 * @brief conduct&init of slist
 *
 * uses dynamic memory allocation
 */
slist::slist() {head=new node;}

/** 
 * @brief output a polynomial
 *
 * in format like "n,c1,e1,c2,e2,...,cn,en"
 */
void slist::output() const{
	cout<<head->exp<<",";
	for(node* cur=head->next;cur!=NULL;cur=cur->next)
		cout<<cur->coef<<","<<cur->exp<<",";
	cout<<endl;
	return ;
}

/**
 * @brief calculate the sum of two polynomials
 * 
 * @param this implicit parameter of member function, the former in "a+b"
 * @param b the latter in "a+b"
 * @return result of the sum
 */
slist slist::operator + (const slist &b) const {
	slist res;//result
	node *cur1=head->next,*cur2=b.head->next;//starting from the one after head
	node *cur=res.head;//construct res

	//traverse two slists until one ends
	while(cur1!=NULL&&cur2!=NULL) {

		//if two terms are of the same exponent
		if(cur1->exp==cur2->exp) {
			if(cur1->coef+cur2->coef) {
				//only link node if coefficient is not zero
				cur->next=new node;
				res.head->exp++;
				cur->next->exp=cur1->exp;
				cur->next->coef=cur1->coef+cur2->coef;
				cur=cur->next;
			}
			cur1=cur1->next;cur2=cur2->next;
		} else if(cur1->exp>cur2->exp) {//else, link the one with larger exponent
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

	//still some terms left in a or b
	//link them to the end
	//only less than one for() will be active
	for(;cur1!=NULL;cur1=cur1->next) {
		cur->next=new node;
		res.head->exp++;
		cur->next->exp=cur1->exp;
		cur->next->coef=cur1->coef;
		cur=cur->next;
	}
	for(;cur2!=NULL;cur2=cur2->next){
		cur->next=new node;
		res.head->exp++;
		cur->next->exp=cur2->exp;
		cur->next->coef=cur2->coef;
		cur=cur->next;
	}

	return res;
}

/**
 * @brief calculate the difference of two polynomials
 * 
 * @param this implicit parameter of member function, the former in "a-b"
 * @param b the latter in "a-b"
 * @return result of the difference
 */
slist slist::operator - (const slist &b) const {
	slist res;
	node *cur1=head->next,*cur2=b.head->next;//starting from the one after head
	node *cur=res.head;//constructing res

	//traverse two slists until one ends
	while(cur1!=NULL&&cur2!=NULL) {

		//if two terms are of the same exponent
		if(cur1->exp==cur2->exp) {

			//only link node if coefficient is not zero
			if(cur1->coef-cur2->coef) {
				cur->next=new node;
				res.head->exp++;
				cur->next->exp=cur1->exp;
				cur->next->coef=cur1->coef-cur2->coef;
				cur=cur->next;
			}
			cur1=cur1->next;cur2=cur2->next;
		} else if(cur1->exp>cur2->exp) {//else, link the one with larger exponent
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
			cur->next->coef=-cur2->coef;//minused by 0, take opposite
			cur2=cur2->next;
			cur=cur->next;
		}
	} 

	//still some terms left in a or b
	//link them to the end
	//only less than one for() will be active
	for(;cur1;cur1=cur1->next) {
		cur->next=new node;
		res.head->exp++;
		cur->next->exp=cur1->exp;
		cur->next->coef=cur1->coef;
		cur=cur->next;
	}
	for(;cur2;cur2=cur2->next){
		cur->next=new node;
		res.head->exp++;
		cur->next->exp=cur2->exp;
		cur->next->coef=-cur2->coef;//minused by 0, take opposite
		cur=cur->next;
	}

	return res;
}

/**
 * @brief calculate the value of polynomial at x
 * 
 * @param x value of variable in polynomial
 * @return the value
 */
double slist::calculate(double x)const {
	node *cur=head->next;

	//if the polynomial is 0
	if(cur==NULL) return 0;

	//uses Horner's rule to calculate terms with positive exponents
	double res=cur->coef;
	for(;cur->next!=NULL&&cur->next->exp>=0;cur=cur->next) 
		res=res*pow(x,cur->exp-cur->next->exp)+cur->next->coef;
	res*=pow(x,cur->exp);

	//use traditional way to prevent precision loss
	for(cur=cur->next;cur!=NULL;cur=cur->next)
		res+=pow(x,cur->exp)*cur->coef;

	return res;
}

/**
 * @brief construct a slist
 * 
 * @param v data from input
 * @return the constructed slist
 */
slist construct(vector<pid> v) {
	slist res;
	node *cur=res.head;

	//sort the terms in descending order by exponent
	sort(v.rbegin(),v.rend());

	//link the terms to linked list
	for(int i=0,sz=v.size();i<sz;i++) {
		cur->next=new node;
		res.head->exp++;
		cur->next->exp=v[i].first;
		cur->next->coef=v[i].second;
		cur=cur->next;
	} 

	return res;
}

#endif