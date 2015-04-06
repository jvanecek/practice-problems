#include <iostream>
#include <string>
using namespace std;

#define max(x,y) ((x>y) ? x : y)
#define min(x,y) ((x<y) ? x : y)

int op2palindrome(string word){
    if( word.length() <= 1 )  
        return 0;
    
    int first = int(word.front());
    int last = int(word.back());
    string subword = word.substr(1, word.length()-2);
    
    if( first - last == 0 )
        return op2palindrome(subword);
    
    return max(first, last) - min(first, last) + op2palindrome(subword);
}

int main(){
    int n; 
    cin >> n;
    while(n-- > 0){
        string word; 
        cin >> word;
        cout << op2palindrome(word) << endl;
    }
    return 0;
}