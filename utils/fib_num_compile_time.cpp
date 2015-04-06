/**
Disclaimer: I'm not the author but was a nice code I found and wanted to save. 

Compile instructions: 
	g++ -std=gnu++11 -Os -Ofast code.cxx 

And see a really fast and compile-time computation of 45th fibonacci number! also gcc uses dynamic-programming method to compute it! 
*/

#include <iostream>

template<int n>
struct fib
{
    long long int ans = 0;
    fib () {
        fib<n - 1> f1;
        fib<n - 2> f2;
        ans = f1.ans + f2.ans;
	}
};

template <> struct fib<2> { long long int ans = 1; };
template <> struct fib<1> { long long int ans = 1; };

int main ()
{
    fib<45> f;
    std::cout << f.ans;
}
