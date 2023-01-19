#include <iostream>
#include <map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;
  map<int,int> JBNU;
  int N,M,K;
  cin>>N>>M>>K;
  while(N--)
  {
    int a,b; cin>>a>>b;
    JBNU[a]=b;
  }
  while(M--)
  {
    int command,key,value;
    cin>>command>>key;
    auto it_back = JBNU.lower_bound(key);
    auto it_front=(--JBNU.lower_bound(key));
    int a,b;
    a=abs(key-it_front->first);
    b=abs(key-it_back->first);
    if(command==1)
    {
      cin>>value;
      JBNU[key]=value;
    }
    else if(command==2)
    {
      cin>>value;
      if(a<=K or b<=K)
      {
      if(a==b)
        continue;
      else if(a<b)
        JBNU[it_front->first]=value;
      else if(a>b)
        JBNU[it_back->first]=value;
      }
      else
        continue;
    }
    else if(command==3)
    {
      if(a<=K or b<=K)
      {
      if(a==b)
        cout<<"?\n";
      else if(a<b)
        cout<<it_front->second<<"\n";
      else if(a>b)
        cout<<it_back->second<<"\n";
      }
      else
        cout<<"-1\n";
    }
  }
}