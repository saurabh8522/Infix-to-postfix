#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) 	for(int i=a;i<b;++i)
#define rf(i,a,b) 	for(int i=b;i>=a;--i)
#define ln 		"\n"
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mod 1000000007
#define debug(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<endl
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;}return temp;}

int isoperand(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c>='Z'))
	return 1;
	else return 0;
}

int prec(char c)
{
	switch(c)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
	}
}

int main()
{
	 	string s;
	 //char x='*';
	 //cout<<isoperand(x);
	 	
	 	cin>>s;
	 	stack<char> final;
	 	int k=-1;
	 
	 	for(int i=0; i<s.size(); i++)
	 	{
	 		if(isoperand(s[k]))
	 		{
	 			cout<<"in one	";
	 			debug(k,s,i);
			 	s[++i]=s[i];
				debug(k,s,i);
	 		}
	 		else (s[i]=='(')
	 			final.push(s[i]);
	 			
	 		else if(s[i]==')')
	 		{
				while(final.empty()==0&&final.top()!='(')
	 			{
	 				cout<<"in two	";
	 				debug(k,s,i);
					s[++k]=final.pop();
					final.pop();
					debug(k,s,i);
				}
	 				final.pop();
	 		}
	 		else
	 		{
	 			while(final.empty()==0 && prec(s[i]) >= prec(final.top()))
				{
					final.pop();
					debug(k,s,i);
				}
			}		
		}
		while(final.empty()==0)
	    {
	    	debug(k,s,"final");
			s[++k]=final.top();
			final.top();
			debug(k,s,"final");
		}
		s[++k]='\n';
		cout<<s;
	
}

