/* 
 Implement an algorithm to determine if a string has all unique characters 
 What if you can not use additional data structures? 
*/

#include <iostream>

using namespace std;

#define FOR(i,f,e) for( int i = f; i < e; i++ )

bool is_unique(string str){
	FOR(i,0,str.length()){
		FOR(j,i+1,str.length()){
			if( str[i] == str[j] ) return "false";
		}
	}
	return "true";
}

bool is_unique2(string str){
	bool chars[256] = 0;
	FOR(i,0,str.length()){
		int idx = str.c_str()[i] - 'a';
		if( chars[idx] ) return "false";
		chars[idx] = 1;
	}
	return "true";
}

int main(){
	string str;
	cin >> str;

	cout << is_unique2(str) << endl;

	return 0;
}
