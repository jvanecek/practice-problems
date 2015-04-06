/**
 Problem: https://www.hackerrank.com/challenges/utopian-tree
*/

#include <iostream>

using namespace std;

int utopian_height(int i){
    int res = 1;
    for( int j = 0; j < i; j++ ){
        res = (j%2 == 0) ? res*2 : res+1;
    }
    return res;
}

int main(){
    int n, i; 
    cin >> n;
    while( n-- > 0 ){
        cin >> i; 
        cout << utopian_height(i) << endl;
    }
}