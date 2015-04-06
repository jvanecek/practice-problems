#include <iostream>
using namespace std;

int find(int *v, int n, int k){
	int first = 0;
	int last = n;
	int mid = (last+first)/2;
	while( v[mid] != k ){
		if( first < last ){
			if( k < v[mid] )	last = mid;
			else				first = mid;
			mid = (last+first)/2;
		}else
			return -1;
	}
	return mid;
}

int main(){
	int n, k; cin >> n; cin >> k;
	int v[n];
	for( int i = 0; i < n; i++ )
		cin >> v[i];
	
	cout << find(v, n, k) << endl;

	return 0;
}
