#include"polynomial.h"
vector<pid> v;
vector<slist> s;

int main() {
	int n,x;double y;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>y>>x;
		v.push_back(make_pair(x,y));
	}
	s.push_back(construct(v));
	s[0].output();
	/*s.push_back(s[0]+s[0]);
	s[1].output();
	s.push_back(s[0]-s[0]);
	s[2].output();*/
	slist s0=construct(v),s1=construct(v);
	slist s2=s0-s0;
	s2.output();
	cout<<s[0].calculate(1)<<endl;
	return 0;
}