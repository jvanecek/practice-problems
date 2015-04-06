#include <iostream>
using namespace std;

#define max(x,y) ((x>y) ? x:y)
#define min(x,y) ((x<y) ? x:y)

int op2palindrome(string w){
    const char* c = w.c_str();
    int l = w.length();
    int op = 0;
    int i=0, j=((l-1) - i);
    while( i <= j ) {
        op += max( c[i], c[j] ) - min( c[i], c[j] );
        i++; j=((l-1) - i);
    }
    return op;
}

int main(){
    int n; 
    cin >> n;
    while(n-- > 0){
        string w;
        cin >> w;
        cout << op2palindrome(w) << endl;
    }
}