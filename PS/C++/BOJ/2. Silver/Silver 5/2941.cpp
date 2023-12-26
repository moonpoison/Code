#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i, j;
    int cnt=0;
    int S=s.size();
    string c[8]={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    if(S<=1)//아래 s.size()-c[i].size() 에서 c[i].size()가 s.size()보다 클 경우 오버플로우 발생(string .size()의 반환값은 size_t인데 이것은 unsigned long long 으로 선언되어있음. 따라서 음수 X)
    {
        cout<<S;
        return 0;
    }
    for(i=0;i<8;++i)
    {
        for(j=0;j<s.size()-c[i].size()+1;++j)
        {
            int a=0;
            for(int l=0;l<c[i].size();++l) 
            {
                if(c[i][l]==s[j+l])
                {
                    a++;
                }
            }
            if(a==c[i].size())
            {
                if(i==7&&s[j-1]=='d')
                {

                }
                else
                {
                    cnt++;
                    S-=c[i].size();
                }
            }
        }
    }
    cout<<cnt+S;
}