#include<stdio.h>
#include<iostream>
using namespace std;
string bit(int d)
  {string s;
    for(int i=7;i>=0;i--)
      {
        if(d&(1<<i))
            s.push_back('1');
        else
            s.push_back('0');
       }
    return s;
    }
int decim(string s1)
   {int base,d;
    d=0;
    base=1;
      for(int i=s1.size()-1;i>=0;i--)
        {
          if(s1[i]=='1')
            {
               d=d+base;
            }
          base=base*2;
        }
     return d;
     }
int main()
{int a,b,c,d,e,t,sum1,i,d1,d2;
string s[4],s1,s2,s3,s4,s5;
 scanf("%d%*c%d%*c%d%*c%d%*c%d",&a,&b,&c,&d,&e);
 t=32-e;
 s[0]=bit(a);
 s[1]=bit(b);
 s[2]=bit(c);
 s[3]=bit(d);
 s1=s[0]+s[1]+s[2]+s[3];
 cout<<"network id:";
 sum1=0;
 i=s1.size()-1;
 while(sum1<=t)
 { if(s1[i]=='1')
      s1[i]='0';
   i--;
   sum1++;
 }
 s2=s1.substr(0,8);
 s3=s1.substr(8,8);
 s4=s1.substr(16,8);
 s5=s1.substr(24,8);
 cout<<decim(s2)<<"."<<decim(s3)<<"."<<decim(s4)<<"."<<decim(s5)<<"/"<<e;
 cout<<"\nbroadcast id:";
 s1=s[0]+s[1]+s[2]+s[3];
 i=s1.size()-1;
 sum1=0;
 while(sum1<=t)
 {
    if(s1[i]=='0')
        s1[i]='1';
    i--;
    sum1++;
 }
 s2=s1.substr(0,8);
 s3=s1.substr(8,8);
 s4=s1.substr(16,8);
 s5=s1.substr(24,8);
 d1=decim(s5);
 cout<<decim(s2)<<"."<<decim(s3)<<"."<<decim(s4)<<"."<<decim(s5);
 cout<<"\nsubnet mask:";
 s1=s[0]+s[1]+s[2]+s[3];
 i=s1.size()-1;
 sum1=0;
 while(sum1<=t)
 {
    s1[i]='0';
    i--;
    sum1++;
 }
 i=0;
 sum1=0;
 while(sum1<=e)
 {
    s1[i]='1';
    i++;
    sum1++;
 }
 s2=s1.substr(0,8);
 s3=s1.substr(8,8);
 s4=s1.substr(16,8);
 s5=s1.substr(24,8);
 d2=decim(s5);
 cout<<decim(s2)<<"."<<decim(s3)<<"."<<decim(s4)<<"."<<decim(s5);
 cout<<"\nRange:";
 printf("%d.%d.%d.%d-%d.%d.%d.%d",a,b,c,d1,a,b,c,d2);

return 0;
}
