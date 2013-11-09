#include "graph.h"
#include <vector>

struct TreeNode
{
public:
    TreeNode (int Vertex_A_in = 0, int Vertex_B_in = 0, int cost_in = 0)
        :Vertex_A (Vertex_A_in),
        Vertex_B (Vertex_B_in),
        cost (cost_in)
    { }
public:
    int Vertex_A ;
    int Vertex_B ;
    int cost ;
} ;

class MST_Prim {
        private:
               Graph g;   
               vector<TreeNode>    MSTree ;    
               int   vertex_Count ;

        public:
               MST_Prim (const Graph G);    //Constructor
               void Do_Prim ();              //do Prim's algorithm
};

