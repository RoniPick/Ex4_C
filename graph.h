#ifndef GRAPH_
#define GRAPH_
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *pnode;;

//typedef struct edge_ {
//    int weight;
//    pnode endpoint;
//    struct edge_ *next;
//} edge, *pedge;

typedef struct edge_ {
    int weight;
    int endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct Node{
    int node_num;
    pedge edges;
    struct Node *next;
    int numOfEdges;
} node, *pnode;


typedef struct GRAPH_{
    pnode nodes;
    int nodeSize;
    int edgeSize;

} graph, *pgraph;

void build_graph_cmd(pgraph g);
void insert_node_cmd(pgraph g);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

void setNumOfNodes(int num);
void isIn(int node_id);
pnode create_node(int id);
void create_edge(pedge *edge, int endpoint);
#endif