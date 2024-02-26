#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1e9+7

string modifie_manacher_use_in_contest(string s) {
    int n = s.size();

    string modified_s;
    for (int i = 0; i < n; ++i) {
        modified_s += '#';
        modified_s += s[i];
    }
    modified_s += '#';

    vector<int> v(2 * n + 1, 0);
    int center = 0, r = 0;

    for (int i = 1; i <= 2 * n; ++i) {
        if (i < r) {
            v[i] = min(r - i, v[2 * center - i]);
        }
        int a = i + v[i] + 1;
        int b = i - v[i] - 1;
        while (a <= 2 * n && b >= 0 && modified_s[a] == modified_s[b]) {
            ++v[i];
            ++a;
            --b;
        }
        if (i + v[i] > r) {
            center = i;
            r = i + v[i];
        }
    }



    

}

vector<int>mnch(string s)
{
    int n=s.size();
    char ns[2*n+1];
    int j=0;
    for(auto i:s)
    {
      ns[j++]='#';
      ns[j++]=i;
    }
    ns[j++]='#';
    int center=0,r=0;
    vector<int>v(2*n+1,0);

    int maxCenter=0,maxCenterIndex=0;
    for(int i=0;i<=2*n;i++)
    {
        if(i<r)
        {
            v[i]=min(r-i,v[center-(i-center)]);
        }

        int a=i+(v[i]+1);
        int b=i-(v[i]+1);
        while(a<=2*n&&b>=0&&ns[a]==ns[b])
        {
            a++;
            b--;
            v[i]++;
        }
        if(v[i]>maxCenter)
        {
            maxCenter=v[i];
            maxCenterIndex=i;
        }

        if(i+v[i]>r) 
        {
            center=i;
            r=i+v[i];
        }
    }

    string ans="";
    for (int i =maxCenterIndex-maxCenter; i <=maxCenter+maxCenterIndex; i++)
    {
        ans+=ns[i];
    }
    ans.erase(remove(ans.begin(),ans.end(),'#'),ans.end());
    cout<<ans<<endl;    

return v;

}




vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    // cout<<t<<endl;
    auto res = manacher_odd(t + "#");

    int mx=0,l=0;
    for (int i = 1; i < t.size(); i++)
    {
        if(res[i] > mx)
        {
            mx=res[i];
            l=i;
        }
    }
    mx--;
    // cout<<mx<<" "<<l<<endl;
    string ans=t.substr(l-mx,l+mx);
    cout<<"ans="<<ans<<endl;
    ans.erase(std::remove(ans.begin(), ans.end(), '#'),ans.end());
    // cout<<ans<<endl;
    cout<<"ans="<<ans<<endl;




cout<<(t+"#")<<endl;
for(auto i:res)
cout<<i;
cout<<endl;

return vector<int>(begin(res) + 1, end(res) - 1);
}


int main() {

string s="fcabaabacde";
// vector<int>v=manacher(s);
// // cout<<v.size()<<endl;
// int mx=0,l=0;
// for(int i=1;i<v.size();i++)
// {
//  if(v[i]>mx)
//  {
//     mx=v[i];
//     l=i;
//  }
// }

mnch(s);


// for(auto i:v)cout<<i;




return 0;
}

