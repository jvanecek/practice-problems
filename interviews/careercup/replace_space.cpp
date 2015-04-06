/**
 1.5 Write a method to replace all spaces in a string with ‘%20’
*/
 
#include <iostream>
using namespace std;

#define FOR(i,ini,fin) for( int i = ini; i < fin; i++ )
#define ROF(i,fin,ini) for( int i = fin; i >= ini; i-- )

string replace_space(string s){
	int n = s.length();
	int space_count = 0;
	FOR(i,0,n){
		space_count += (s[i] == ' ');
	}

	int newL = s.length() + space_count*2;
	string newS(newL, ' ');
	ROF(i,n-1,0){
		if( s[i] == ' ' ){
			newS[newL - 1] = '0';
			newS[newL - 2] = '2';
			newS[newL - 3] = '%';
			newL = newL - 3;
		}else{
			newS[newL - 1] = s[i];
			newL = newL - 1;
		}
	}

	return newS;
}

int main(){
	string line; 
	getline(cin, line);

	cout << replace_space(line) << endl;

	return 0;
}