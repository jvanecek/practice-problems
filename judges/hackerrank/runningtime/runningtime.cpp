/**
 Problem: https://www.hackerrank.com/challenges/runningtime/
*/

#include <iostream>
using namespace std;

#define FOR(i,ini,fin) for( int i = ini; i <= fin; i++ )
#define ROF(i,fin,ini) for( int i = fin; i >= ini; i-- )
#define shift(i,j) int aux = i; i = j; j = aux; 

int main(){
    int n; cin >> n;
    int V[n]; 
    int moves = 0;
    FOR(i,0,n) cin >> V[i];
        
    FOR(i,1,n-1){
        ROF(j,i-1,0){
            if( V[j] > V[j+1] ){
                shift(V[j],V[j+1])
                moves++;
            }
        }
    }
    cout << moves;
}