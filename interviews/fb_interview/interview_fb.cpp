/*
PROBLEMA 1

[1,5,3,4,2] -> 1
[1,5,3,5,2] -> 1/3

Return the *index* of the largest element, if more than one element reaches the maximum, pick one uniformly at random.
*/
#define FOR(i,ini,fin) for(int i=ini; i < fin; i++)
#define MAX(a,b) ((a)>(b)?(a):(b))

int max_index(int const * const v, int n){ // O(n log n)
    vector<int> indexes; // maximum indexes O(n)
    int max_value;
    
    if( n == 0 ) 
        return -1;
    
    max_value = v[0];
       
    FOR(i,1,n)
        max_value = MAX(max_value, v[i]);
        
    // ^ ignore what's above, assume that max_value = is max, max_value_times = how many times
    
    FOR(i,0,n)
        if( v[i] == max_value ) indexes.push( i );
        
    // random0_1 -> double (between 0 and 1)
    int uniform_index = (int)(random0_1() * indexes.size()) ; // [0..1] -> [0..indexes.size()]
    return indexes[uniform_index];
}

/*
PROBLEMA 2
Dado un grafo G=(V,E)

G := [V1, ..., Vn]

Vi := {
         Data data // 
         [&Vi_1, ..., &Vi_k] // Outgoing
      }

Implement: clone
G2 <- clone(G1)
*/

template<Data>
class Graph{
  public:
    vector< Vertex<Data> > v;
};

template<Data>
class Vertex{
  public:
    Data data;
    vector< *Vertex<data> > outgoing;
};

Graph* Graph::clone() const { 
    Map< *Vertex<Data>, *Vertex<Data> > map; // Hash Table ( Keys = address_original, Value = address_copy )

    vector< Vertex<Data> > vertexes; 
    
    for( int i = 0; i < v.size(); i++ ){
        Vertex<Data> v_copy;
        
        v_copy.data = v[i].data.clone();
        
        vertexes.push( v_copy );

        map[v[i]] = v_copy;
    }

    for( int i = 0; i < v.size(); i++ ){
        for( int j = 0; j < v[i].outgoing.size(); i++ ){

            vertexes[i].outgoing.push( map[v[i].outgoing[j]] );
        }
    }
    
    // this.vertexes is in the same order as vertexes
}
