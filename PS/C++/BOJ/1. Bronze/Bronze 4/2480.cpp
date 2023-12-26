#include<iostream>
using namespace std;
int main()
{
	int a[3];
	int b[7]={0};
	int i;
	for(i=0;i<3;++i)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	int max=0;
	for(i=1;i<=7;++i)
	{
		if(b[i]==1)
		{
			b[i]=i*100;
			if(max<b[i])
			{
				max=b[i];
			}
		}
		else if(b[i]==2)
		{
			b[i]=i*100+1000;
			if(max<b[i])
			{
				max=b[i];
			}
		} 
		else if(b[i]==3)
		{
			b[i]=i*1000+10000;
			if(max<b[i])
			{
				max=b[i];
			}
		}
	}
	cout<<max;
	return 0;
}