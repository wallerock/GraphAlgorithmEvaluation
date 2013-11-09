#include <iostream>
#include <limits>
#include "prim_mst.h"

using namespace std ;

MST_Prim::MST_Prim (Graph G) {
        g = G ;
        vertex_Count = G.V() ;
}

void MST_Prim::Do_Prim (){
        vector<bool> Flag (vertex_Count, false) ;
        Flag[0] = true ; //visted or unvisted

        int IndexA ;
        int IndexB ;
        int j = 0 ;
        while (j < vertex_Count-1) {
            int MaxCost = numeric_limits<int>::max () ;
            //find the less cost path.
            int i = 0 ;
            while (i < vertex_Count) {
                // if vertex i is visted, pass it
                if (!Flag[i]) {  
                    ++ i ;
                    continue ;
                }
                for (int j = 0; j < vertex_Count; ++ j) {
                   if(g.get_cost(i,j)!=-1){
                    if (!Flag[j] && MaxCost > g.get_cost(i,j)) { 
                        MaxCost = g.get_cost(i,j) ;
                        IndexA = i ;
                        IndexB = j ;
                    } 
                   }
                }
                ++ i ;
            }
            //find it, push it into tree
            Flag[IndexB] = true ;
            MSTree.push_back (TreeNode(IndexA, IndexB, MaxCost)) ;
            ++ j ;
        }
       //print MSTree
        for (vector<TreeNode>::const_iterator ite = MSTree.begin() ;ite != MSTree.end() ; ++ ite ) {
            cout << (*ite).Vertex_A << "->" << (*ite).Vertex_B << " : "<< (*ite).cost << endl ;
        }
}
