#include <cstdio>
#include <vector>

#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;

typedef struct ENode{
    int ivex;
    struct ENode *next_edge;
}ENode, *PENode;

typedef struct VNode{
    char data;
    ENode *first_edge;
}VNode;

typedef struct LGraph{
    int vexnum;
    int edgenum;
    VNode vexs[MaxVertexNum];
}LGraph;


int main() {


    return 0;
}
