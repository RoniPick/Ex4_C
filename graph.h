#ifndef GRAPH_
#define GRAPH_
#include <stdio.h>
#include <stdlib.h>

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    int endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    int numOfEdges;
    struct GRAPH_NODE_ *next;
} node, *pnode;


void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head, int i, int dest, int w) ;
void delete_node_cmd(pnode *head, int id);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode *head, int src, int dest);
void TSP_cmd(pnode *head);

void create_node(pnode *head, int id);
void add_edge(pnode *head, int src, int dest, int w);

#endif
