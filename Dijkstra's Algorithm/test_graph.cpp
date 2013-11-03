#include"graph.h"

using namespace std;


int main(){
Graph g(10, 0.4, 10);

int vc;
int ec;

vc=g.V();

ec=g.E();

cout<< vc<<endl;

cout<< ec<<endl;

g.add_edge(3,2);

ec=g.E();

cout<< ec<<endl;

return 0;

}
