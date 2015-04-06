/**
 Problem: https://www.hackerrank.com/challenges/mark-and-toys/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    sort(prices.begin(), prices.end());
    
    int answer = 0;
    int i = 0;
    while( k > 0 && n > i ){
        // Write the code for computing the final answer using n,k,prices
        if( k >= prices[i] ){
            answer++;
            k -= prices[i];
            i++;
        }else{
            break;
        }
    }
    cout << answer << endl;
    
    return 0;
}
