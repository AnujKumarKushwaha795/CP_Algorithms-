#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1e9+7
vector<int>z_fun(string s)
{
    int n=s.size();
    vector<int>Z(n);
    Z[0]=0;
    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        if(i<r)
        {
            Z[i]=min(r-i,Z[i-l]); // if r is greater than i then min of r-i and Z[i-l] will be the value of Z[i]. 
        }
       while (i+Z[i]<n&&s[i+Z[i]]==s[Z[i]])
       {
        Z[i]++;
       }

       if(i+Z[i]>r)
       {
        l=i;
        r=i+Z[i];
       }      
    }
return Z;
}

int main() {
string s="absckaesabc";
vector<int>z=z_fun(s);
for(auto i:z)cout<<i<<" ";


return 0;
}

