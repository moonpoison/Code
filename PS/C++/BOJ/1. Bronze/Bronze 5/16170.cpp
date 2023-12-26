#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    time_t T=time(NULL);
    struct tm *t=localtime(&T);
    
    int year=t->tm_year+1900;
    int mon=t->tm_mon+1;
    int day=t->tm_mday;
    cout<<year<<endl<<mon<<endl<<day;
}