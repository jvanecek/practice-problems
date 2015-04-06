/**
 Problem: https://www.hackerrank.com/challenges/maximizing-xor
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX(x,y) ((x)>(y))?(x):(y);

int maxXor(int l, int r) {
    int max = l ^ r;
    for( int i = l; i < r; i++ ){
        for( int j = i+1; j <= r; j++ ){
            max = MAX( max, i^j );
        }
    }
    return max;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
