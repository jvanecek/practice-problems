/**
 Problem: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=58
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool es_mas_izq(const string path1, const string path2){
	int min_len = min( path1.length(), path2.length() );
	int max_len = max( path1.length(), path2.length() );

	for( int i = 0; i < min_len; i++ ){
		if( path1[i] == 'L' && path2[i] == 'R' && min_len == max_len )
			return true;	
		if( path1[i] == 'R' && path2[i] == 'L' && min_len == max_len )
			return false;
	}

	if( min_len < max_len && max_len == (int)path2.length())
		return true;

	return false;
}

class Pair{ 
	string val;
	string path; 

public: 
	Pair(string p){
		int del_idx = p.find_first_of(",");
		val = p.substr(1, del_idx-1);
		path = p.substr(del_idx+1, p.length()-del_idx-2);
	}

	Pair(string v, string p){
		val = v;
		path = p;
	}

	string getValue()
	{	
		return val;
	}

	string getPath() const
	{
		return path;
	}

	bool operator==(Pair other) 
	{
		return getPath() == other.getPath();
	}

	bool operator<(const Pair other) const
    {
        return es_mas_izq(getPath(), other.getPath());
    }

};

class Arbol{
	vector<Pair> nodos;

public:
	void agregar_nodo(string n){
		nodos.push_back( Pair(n) );
	}

	bool bien_formado(){
		for( unsigned int i = 0; i < nodos.size(); i++){
			
			string path_to_i = nodos.at(i).getPath();
			path_to_i = path_to_i == "" ? "" : path_to_i.substr(0, path_to_i.length()-1);
	 
			bool path_to_i_exists = false;
			for( unsigned int j = 0; j <= i; j++ ){

				if( j<i && nodos.at(j).getPath() == nodos.at(i).getPath() ){
					// hay duplicado
					return false;
				}
				if( nodos.at(j).getPath() == path_to_i){
					// existe el camino al nodo i
					path_to_i_exists = true;
				} 
			}
			if( !path_to_i_exists ) return false; // entra aca si no encuentra el camino al nodo
		}

		return true;
	}

	void imprimir(){
		sort(nodos.begin(), nodos.end());

		if( bien_formado() ){
			for(unsigned int i = 0; i < nodos.size()-1; i++)
				cout << nodos[i].getValue() << " ";
			cout << nodos.back().getValue() << endl;
		}else{
			cout << "not complete" << endl; 
		}
	}

	void clear(){
		nodos.clear();
	}
};

int main(){
	string elem;
	Arbol a;

	while( cin >> elem ){

		if( elem == "()" ){
			a.imprimir();
			a.clear();
		}else{
			a.agregar_nodo( elem );
		}
	}

	return 0;
}