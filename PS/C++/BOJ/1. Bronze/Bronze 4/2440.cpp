#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	for(i=n;i>0;--i)
	{
		for(int j=0;j<i;++j)
		{
			cout<<'*';
		}
		cout<<endl;
	}
	return 0;
}