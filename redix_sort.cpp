#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1e9+7
void count_sort(vector<int>&v)
{   
    int n=v.size();
    vector<int>cnt(10,0),ans(n,0);
    for (int i = 0; i < n; i++)
    {
        cnt[v[i]]++;
    }
    for (int i = 1; i < n; i++)
    {
       cnt[i]+=cnt[i-1];
    }
    for (int i=n-1;i>=0;i--)
    {
        ans[cnt[v[i]]-1]=v[i];
        cnt[v[i]]--;
    }
    v=ans;
    for(auto i:v)cout<<i<<" ";   
}
int count_digit(int num)
{
    string s=to_string(num);
    return s.size();
}

void redix_sort(vector<int>&v)
{
    int mx=*max_element(v.begin(),v.end());
    int d=count_digit(mx);
    int n=v.size();
    int num=1;

    for (int j = 0; j < d; j++)
    {        
        vector<int>count_array(10,0),ans(n);
        for (int i = 0; i < n; i++)
        {            
            int e =(v[i]/num)%10;
            count_array[e]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count_array[i]+=count_array[i-1];
        }
        for (int i = n-1; i >=0; i--)
        {
            ans[count_array[((v[i])/num)%10]-1]=v[i];
            count_array[((v[i])/num )%10]--;
        }
        num*=10;
        v=ans;        
    }
    // for(auto i:v)cout<<i<<" ";

}
int main() {
vector<int>v={5000012,2,1,3,4,508737,6192};
    
// count_sort(v);
redix_sort(v);
for(auto i:v)
cout<<i<<" ";


return 0;
}


/*
Radix Sort is a linear sorting algorithm that sorts elements by processing them digit by digit. It is an efficient sorting algorithm for integers or strings with fixed-size keys. 


Radix Sort Algorithm
The key idea behind Radix Sort is to exploit the concept of place value. It assumes that sorting numbers digit by digit will eventually result in a fully sorted list. Radix Sort can be performed using different variations, such as Least Significant Digit (LSD) Radix Sort or Most Significant Digit (MSD) Radix Sort.


When to not use redix sort

Variable-Length Keys: Radix Sort is designed for sorting keys with a fixed length, such as integers represented in binary or decimal form. If your data consists of keys with variable lengths, Radix Sort would not be directly applicable. In such cases, algorithms like Quick Sort or Merge Sort, which are not dependent on the length of the keys, might be more appropriate.

Large Range of Values: Radix Sort's performance can degrade significantly when dealing with a large range of input values. If the range of values in the input data is significantly larger than the number of elements to be sorted, the counting and distribution steps of Radix Sort may become inefficient, leading to increased time and space complexity. In such scenarios, other sorting algorithms like Quick Sort or Merge Sort, which have better average-case performance for a wide range of input values, might be preferable.

Space Complexity Concerns: Radix Sort typically requires additional space for auxiliary data structures, such as counting arrays or buckets. If memory usage is a concern, especially for large datasets, Radix Sort's space complexity may become a limitation. In such cases, in-place sorting algorithms like Quick Sort or Heap Sort, which do not require additional space proportional to the input size, might be more suitable.

Non-Integer Data Types: Radix Sort is specifically designed for sorting integer keys or data with a fixed-length representation. If your data consists of non-integer keys or data with variable-length representations, Radix Sort would not be applicable. Sorting algorithms like Merge Sort or Tim Sort, which are not limited to integer keys, might be more appropriate for such data types.

Need for Stability: While Radix Sort is a stable sorting algorithm, there are scenarios where stability is not a requirement. If maintaining the relative order of elements with equal keys is not important for your application, other sorting algorithms with potentially better average-case performance, such as Quick Sort or Heap Sort, might be preferred over Radix Sort.

In summary, while Radix Sort can be efficient in specific scenarios, it's essential to consider the characteristics of your data and the requirements of your application before choosing Radix Sort as the sorting algorithm. Depending on factors such as the range of values, space constraints, and data types, other sorting algorithms might be more suitable alternatives.
*/



