/**
 Problem: https://www.hackerrank.com/challenges/flowers
*/

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int getResult(int *C, int N, int K){
    std::sort(C, C+N, std::greater<int>()); // order descendingly
    
    int res = 0;
    for( int i = 0; i < N; i++ ){
        int flowers_bougth = i/K;
        res += C[i]*(flowers_bougth+1);
    }
    return res;
}

int main(void){
    //Helpers for input and output

    int N, K, c;
    cin >> N >> K;
    int C[N];
    for(int i = 0; i < N; i++)
        cin >> C[i];
    
    int result = getResult(C, N, K);
    cout << result << "\n";

    return 0;
}
