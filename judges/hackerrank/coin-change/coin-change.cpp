/**
 Problem: https://www.hackerrank.com/challenges/coin-change
*/
 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int perm;
int n, m;

void print_vector( int* X ){
	for(int i = 0; i < m-1; i++){
		cout << X[i] << ", ";
	}
	cout << X[m-1];
}

void f(int N, int i, int* C, int* X){
	// print_vector( X ); cout << " -> " << N << endl;

	if( N == 0 ){
		perm++;
		// cout << "\tNEW SOLUTION!" << endl;
	}else{
		if( i < m ){
			int x = 0;
			while( N - x * C[i] >= 0 ){
				X[i] = x;
				f( N - x * C[i], i+1, C, X );
				x++;
			}
		}
	}
}

int main() {
    cin >> n; cin >> m;
    int C[m];
    int X[m];
    for(int i=0; i<m; i++) cin >> C[i];

    perm = 0;

	f(n, 0, C, X);

	cout << perm; 

    return 0;
}
