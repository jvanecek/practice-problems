/**
 Problem: https://www.hackerrank.com/challenges/gem-stones
*/

#include <iostream>
using namespace std;
#define FOR(i,ini,fin) for(int i = ini; i < fin; i++)

unsigned int count[256]; // count of appearances of each unique char; if char[i] = N then is gem-element


void count_uniques( string gem ){
    bool appear[256] = {0};
    FOR(i,0,gem.size())
        appear[ gem[i] - 'a' ] = 1;
    
    FOR(i,0,256)
        count[i] += appear[i];
}

int main(){
    int N; string element;
    cin >> N;
    getline( cin, element ); // discard pseudo-line
    FOR(i,0,N){
        getline( cin, element );
        count_uniques( element );
    }
    
    int res = 0;
    FOR(i,0,256) res += (count[i] == N);
    
    cout << res;
}
    