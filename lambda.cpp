#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1e9+7
#include <iostream>

int main() {



 // Forward declaration of the lambda function
    std::function<int(int)> factorial;

    // Lambda function to calculate factorial recursively
    factorial = [&](int n) -> int {
        // Base case: factorial of 0 is 1
        if (n == 0) {
            return 1;
        } else {
            // Recursive case: factorial of n is n * factorial(n-1)
            return n * factorial(n - 1);
        }
    };

    // Calculate factorial of 5
    int result = factorial(5);
    std::cout << "Factorial of 5 is: " << result << std::endl; // Output: Factorial of 5 is: 120


    int a = 5;
    int b = 10;

    // Lambda function that returns the sum of two integers
    auto sum = [](int x, int y) {
        return x + y;
    };

    // Call the lambda function
     result = sum(a, b);
    std::cout << "Sum: " << result << std::endl; // Output: Result: 15






    
    return 0;

}

