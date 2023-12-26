#include<iostream>
using namespace std;
int main()
{
	int a, b=0;
	int i;
	for(i=0;i<5;++i)
	{
		cin>>a;
		b+=a;
	}
	cout<<b;
}