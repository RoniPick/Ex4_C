#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void build_graph_cmd(pgraph g) {
    pnode head;
    head = (pnode) malloc(sizeof(node));
    if (head == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
    head->next = NULL;
    head->edges = NULL;
    head->node_num = NULL;
    head->numOfEdges = NULL;
    int len = 0;
    g->nodes = head;
    scanf("%d", &len);
    g->nodeSize = len;
    pnode *temp;
    temp = (pnode *) malloc(sizeof(pnode));
    temp = &(g->nodes);
    for (int i = 0; i < len; i++) {
        pnode newNode = create_node(i);
        if (i == 0) {
            g->nodes = newNode;
            temp = &(newNode->next);

        }
        else {
            newNode->next = *temp;
            *temp = newNode;
            temp = &(newNode->next);

        }
    }
//    int num=g->nodes[2].node_num;
    char cur;
    scanf("%d", &cur);

    while(cur!='A' && cur!='B' && cur!='T' && cur!='S' && cur!='D'){
        if(cur == 'n'){
            scanf("%d", &cur);
            temp = g->nodes[cur]->edges;
            while(cur!='n'){
                int end;
                scanf("%d", &cur);
                end = cur;
                create_edge(temp, end);
            }

        }
    }



}

void insert_node_cmd(pgraph g) {
    int id=0;
    int exist=0; // in order to know if the node is already exist
    scanf("%d", &id);
    pnode head;
    head = (pnode) malloc(sizeof(node));
    if (head == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
    g->nodes = head;
    for(int i=0; i<g->nodeSize; i++){
        if(exist == 1){
            break;
        }
        if(id == head.node_num){
            exist=1;
            while(head.edges!=NULL){
                free(head.edges);
                head.edges = head.edges->next;
            }
        }
        head = head->next;
    }
    if(exist == 0){
        while(head->next!=NULL){
            head = head->next;
        }
        head->next = create_node(id);
    }

}

void delete_node_cmd(pnode *head) {

}

void printGraph_cmd(pnode head) {//for self debug

}

void deleteGraph_cmd(pnode *head) {


}

void shortsPath_cmd(pnode head) {

}

void TSP_cmd(pnode head) {

}

pnode create_node(int id) {
    pnode n;
    n = (pnode) malloc(sizeof(struct Node));
    if (n == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
    n->node_num = id;
    n->edges = NULL;
    n->next = NULL;
    return n;
}

void create_edge(pedge *e, int endpoint) {
    pedge newEdge;
    newEdge = (pedge) malloc(sizeof(edge));
    if (newEdge == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    pedge temp;
    temp = (pedge) malloc(sizeof(edge));
    if (temp == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    newEdge->endpoint = endpoint;
    int w = 0;
    scanf("%d", &w);
    newEdge->weight = w;
    newEdge->next = NULL;

    if (e == NULL) {
        e = newEdge;
    } else {
        temp = newEdge;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newEdge->next = temp;
    }

    free(temp);

}



int main() {
    pgraph g;
    g = (pgraph) malloc(sizeof(graph));
    if (g == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
//    pnode head;
//    head = (node*)malloc(sizeof(node));
//    if(head == NULL){ // if there is no place in memory to allocate
//        printf("Memory not allocated");
//        exit();
//    }
//
//    g.nodes = head;
    char input = 'A';

    while (1) {
        // scanf("%c", &input);
        switch (input) {
            case 'A':
                if (g->nodes != NULL) {
                    deleteGraph_cmd(&g->nodes);
                } else {
                    build_graph_cmd(&g->nodes);
                }

                break;

            case 'B':

                break;

            case 'n':

                break;

            case 'D':

                break;

            case 'S':

                break;

            case 'T':

                break;
        }
    }


    return 0;
}

