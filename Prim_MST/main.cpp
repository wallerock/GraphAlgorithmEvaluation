#include <iostream>
#include <cstring>
#include <cstdlib>
#include "prim_mst.h"

using namespace std;

int main(int argc, char *argv[]) {
        if(argc!=2){
          cout<<"usage: ./exe filename.txt" <<endl;
          return -1;
        }
        
        Graph g(argv[1]);
        MST_Prim mp(g); 

        mp.Do_Prim();
        
	return 0;
}
