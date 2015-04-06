/**
 Problem: https://www.hackerrank.com/challenges/service-lane/
*/

#include <iostream>
using namespace std;

#define FOR(k,i,j) for(int k = i; k < j; k++)
int main(){ 
    int N, T; 
    cin >> N >> T;
    int w[N];
    
    FOR(i,0,N) cin >> w[i];
    
    while( T-- > 0 ){
        int i, j; 
        cin >> i >> j; 
        
        int min_w = 3; 
        FOR(k,i,j+1) min_w = (w[k] < min_w) ? w[k] : min_w;
        cout << min_w << endl;
    }
}