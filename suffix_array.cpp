// Algo. link= https://cp-algorithms.com/string/suffix-array.html
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1e9+7

// 1.
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }


    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

void suffix_array_construction(string s,vector<int>&v) {
    s += "!";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    for(auto i:sorted_shifts)cout<<i<<" ";

    cout<<endl;
    v=sorted_shifts;
}

// 2.
vector<int> lcp_array(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    for(auto i:lcp)cout<<i<<" ";
    return lcp;
}
// 3.
bool SearchString(string s,vector<int>&p,string original)
{
    int l=0,h=p.size()-1;    
    while (l<=h)
    {
        int mid=(l+h)/2;
        int res=s.compare(original.substr(p[mid]));
        if(res==0)return true;
        else if(res<0) h=mid-1;
        else l=mid+1;
    }
    return false;    
}



int main() {
// 1.
string s="banana";
int n=s.size();
vector<int>p(n,0);    
suffix_array_construction(s,p);
cout<<endl;
// for(auto x:p) cout<<x<<"="<<s.substr(x)<<endl;


// 2.
// size of lcp array is (n-1) 
lcp_array(s,p);


// 3.
cout<<"\nSearch="<<SearchString("ana",p,s);


return 0;
}








/*
Strictly speaking the following algorithm will not sort the suffixes, but rather the cyclic shifts of a string. However we can very easily derive an algorithm for sorting suffixes from it: it is enough to append an arbitrary character to the end of the string which is smaller than any character from the string. It is common to use the symbol $. Then the order of the sorted cyclic shifts is equivalent to the order of the sorted suffixes, as demonstrated here with the string  
$dabbb$ .




String Transformation:
First, we append a special character, typically denoted as '$', to the end of the original string. So, "dabbb" becomes "dabbb$".

Cyclic Shifts:
Next, we generate all cyclic shifts of the transformed string "dabbb$". These cyclic shifts are obtained by rotating the string one character at a time. Here are the cyclic shifts:

dabbb$
abbb$d
bbb$da
bb$dab
b$dabb
$dabbb
3
Sorting:
We then sort these cyclic shifts lexicographically. In this case, if we sort the cyclic shifts in ascending order, we get:
$dabbb
abbb$d
b$dabb
bb$dab
bbb$da
dabbb$

Suffix Array:
Finally, the sorted cyclic shifts represent the lexicographically sorted suffixes of the original string "dabbb$". The suffix array is a list of the starting indices of these suffixes in the original string:

Suffix Array: [6, 0, 4, 5, 1, 2]
Each number in the suffix array represents the starting index of a suffix of the original string "dabbb$". For example:

Index 6 corresponds to the suffix "$" (starting at index 6 in "dabbb$").
Index 0 corresponds to the suffix "dabbb$" (starting at index 0 in "dabbb$").
Index 4 corresponds to the suffix "bb$" (starting at index 4 in "dabbb$").
Index 5 corresponds to the suffix "b$" (starting at index 5 in "dabbb$").
Index 1 corresponds to the suffix "abbb$" (starting at index 1 in "dabbb$").
Index 2 corresponds to the suffix "bbb$" (starting at index 2 in "dabbb$").

So, the suffix array [6, 0, 4, 5, 1, 2] represents the lexicographically sorted suffixes of the original string "dabbb". Each index in the suffix array corresponds to a suffix of the original string, and the array is sorted based on the lexicographic order of these suffixes.

*/


/*
Let's illustrate the algorithm with a simple example using the string "banana".

Original String: "banana"

Cyclic Shifts:

The cyclic shifts of "banana" are: "banana", "anana$ba", "nana$ban", "ana$bana", "na$banan", "a$banan", "$banana".
For simplicity, we append the special character '$' to indicate the end of the string.
Iterations:

The algorithm will perform log₂(7) + 1 = 3 iterations because there are 7 cyclic shifts to be sorted.
Iteration 1 (k = 0):

Sort the cyclic substrings of length 2^0 = 1.
The sorted cyclic substrings are: "$bananab".
Iteration 2 (k = 1):

Sort the cyclic substrings of length 2^1 = 2.
The sorted cyclic substrings are: "a$banan", "ana$bana", "anana$b", "bananab$".
Iteration 3 (k = 2):

Sort the cyclic substrings of length 2^2 = 4.
The sorted cyclic substrings are: "a$banan", "ana$bana", "anana$b", "banana$".
Final Result:

The sorted cyclic shifts of "banana" are: "a$banan", "ana$bana", "anana$b", "banana$".
In this example, the algorithm iteratively sorts the cyclic substrings of increasing lengths until all cyclic shifts of the original string are sorted lexicographically. The final result represents the sorted cyclic shifts of the original string "banana".

*/

/*
Application

1. Finding the smallest cyclic shift
The algorithm above sorts all cyclic shifts (without appending a character to the string), and therefore  
p[0]  gives the position of the smallest cyclic shift.

2. Finding a substring in a string
The task is to find a string inside some text online - we know the text beforehand, but not the string
We can create the suffix array for the text in time. Now we can look for the substring in the
following way. The occurrence of must be a prefix of some suffix from . Since we sorted all the
suffixes we can perform a binary search for in . 
Comparing the current suffix and the substring within the 
                                  Binary search 
can be done in time, therefore the complexity for finding the substring is .
Also notice that if the substring occurs multiple times in , then all occurrences will be next to each
other in . Therefore the number of occurrences can be found with a second binary search, and all
occurrences can be printed easily

3.




*/








