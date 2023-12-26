#include<iostream>
using namespace std;
int main()
{
	int a[6];
	int b[6]={1, 1, 2, 2, 2, 8};
	int i;
	for(i=0;i<6;++i)
	{
		cin>>a[i];
		cout<<b[i]-a[i];
		if(i!=5)
		{
			cout<<' ';
		}
	}
}