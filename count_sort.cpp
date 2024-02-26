#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1e9+7
void count_sort(vector<int>&v)
{
    int mn=*min_element(v.begin(),v.end());
    int mx=*max_element(v.begin(),v.end());
    int range=mx-mn+1;
    int n=v.size();
    vector<int>cnt(n+1,0),ans(n,0);

    for (int i = 0; i < n; i++)
    {
        cnt[v[i]-mn]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cnt[i]+=cnt[i-1];
    }
   for (int i = n-1; i >=0; i--)
   {
    ans[cnt[v[i]-mn]-1]=v[i];
    cnt[v[i]-mn]--;
   }
   for (int i = 0; i < n; i++)
   {
    v[i]=ans[i];
   }
   
//    for (auto x:ans)
//    {
//        cout<<x<<" ";
//    }
}


int main() {
vector<int>v={5,2,1,3,4,5,6};

 count_sort(v);
for (auto x:v)
{
    cout<<x<<" ";
}


return 0;
}
/*
Counting Sort is a non-comparison-based sorting algorithm that works well when there is limited range of input values. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
*/
