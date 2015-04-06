/**
 Problem: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
*/

#include <iostream>
#include <algorithm>

using namespace std;

unsigned int cycle_len(unsigned int n){
	unsigned int c = 1;
	while(n!=1){
		n = (n % 2 == 0	) ? (n/2) : (3*n + 1);
		c++;
	}
	return c;
}

int main(){
	unsigned int first, last, max_c, i;

	while( cin >> first >> last ){
		if( last < first ){
			unsigned int aux = first;
			first = last; last = aux;
		}
		max_c = 0;
		for(i = first; i <= last; i++){
			max_c = max( cycle_len(i), max_c );
		}
		cout << first << " " << last << " " <<  max_c << endl;
	}

	return 0;
}
