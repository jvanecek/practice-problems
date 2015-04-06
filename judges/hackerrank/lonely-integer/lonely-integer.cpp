#include <iostream>
using namespace std;

#define FOR(i,ini,fin) for(int i = ini; i < fin; i++)
#define MAX_VAL 100

// space complexity = O(n)
// time complexity = O(n)
int lonelyinteger(int *a, int n) {
    int b[MAX_VAL+1] = {0};
    FOR(i,0,n)
        b[a[i]]++;
    
    FOR(i,0,MAX_VAL+1){
        if( b[i] == 1 ){
            return i;
        }
    }
    return 0;
}

int main() {
    int res;
    
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << lonelyinteger(a,n) << endl;
    
    return 0;
}
