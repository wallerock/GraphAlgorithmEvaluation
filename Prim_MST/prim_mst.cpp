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
        int cost_sum=0;
        int IndexA ;
        int IndexB ;
        int j = 0 ;
        while (j < vertex_Count-1) {
            int MaxCost = numeric_limits<int>::max () ;
            //find the less cost path.
            int i = 0 ;
            while (i < vertex_Count) {
                // if vertex i is unvisted, pass it
                //make i trace point from last time
                if (!Flag[i]) {  
                    ++ i ;
                    continue ;
                }
                //find minimum path from i to j
                for (int j = 0; j < vertex_Count; ++ j) {
                   //if i is connected with j, and j is new path's point
                   if(g.get_cost(i,j)>0){
                    if (!Flag[j] && MaxCost > g.get_cost(i,j)) { 
                        MaxCost = g.get_cost(i,j) ;
                        IndexA = i ;
                        IndexB = j ;
                    } 
                   }
                }
                ++ i ;
            }
            // push it into tree, update Flag[]
            Flag[IndexB] = true ;
            MSTree.push_back (TreeNode(IndexA, IndexB, MaxCost)) ;
            ++ j ;
        }
       //print MSTree
        for (vector<TreeNode>::const_iterator ite = MSTree.begin() ;ite != MSTree.end() ; ++ ite ) {
            cout << (*ite).Vertex_A << "->" << (*ite).Vertex_B << " : "<< (*ite).cost << endl ;
            cost_sum=cost_sum+(*ite).cost;
        }
       //print cost
        cout <<"Total Cost: "<<cost_sum<<endl;

}
