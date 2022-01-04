#ifndef GRAPH_
#define GRAPH_
#include <stdio.h>
#include <stdlib.h>

typedef struct GRAPH_NODE_ *pnode;

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


void build_graph_cmd(pnode *head, int len);
void insert_node_cmd(pnode *head, int src) ;
void delete_node_cmd(pnode *head, int id);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode *head, int src, int dest);
void TSP_cmd(pnode *head, int len, int arr[]);
void create_node(pnode *head, int id);
void add_edge(pnode *head, int src, int dest, int w);
void swap(int *x, int *y);
void permute(pnode *head, int *a, int start, int end);
void checkSum(pnode *head, int *a, int start, int end);
int getSize(pnode *head);

char caseA(pnode *head, char input);
char caseB(pnode *head, char input);
char caseD(pnode *head, char input);
char caseT(pnode *head, char input);
char caseS(pnode *head, char input);
#endif