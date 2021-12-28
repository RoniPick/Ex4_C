#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

#define int numOfNodes;


void build_graph_cmd(pnode *head) {
    int len = 0;
    scanf("%c", &len);
    pnode temp;
    temp = *head;
    pnode n;
    n = (node*)malloc(len*sizeof(node));
    if(n == NULL){ // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit();
    }
    for(int i=0; i<len; i++){

    }

    int input=0;
    int cur = 0;
    scanf("%d", &input);
    n.node_num = input;
    n->edges = NULL;
    pedge e = n->edges;

    while(cur < num){ // n value in ASCII
        scanf("%d", &input);
        if(input == 110){
            next = (node*)malloc(sizeof(node));
            n->next = next;
            pedge e = next->edges;
            n = next;
            cur++;
        }

        e = (edge*)malloc(sizeof(edge_));
        e.endpoint = input;
        scanf("%d", &input);
        e.weight = input;
        e->next=NULL;
        e=e->next;

    }

    //n->edges = e;

    if(temp == NULL){  // if this is a new list
        head = n;
    }

    else{
        temp.next = n;
    }


}

void insert_node_cmd(pnode *head) {
    pnode n;
    n = (node*)malloc(sizeof(node));
    if(n == NULL){ // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit();
    }

    int input=0;
    scanf("%d", &input);
    n.node_num = input;
    n->edges =NULL;
    pedge e = n->edges;

    while(input != 110){ // n value in ASCII
        scanf("%d", &input);
        if(input == 110){
            break;
        }

        e = (edge*)malloc(sizeof(edge_));
        e.endpoint = input;
        scanf("%d", &input);
        e.weight = input;
        e->next=NULL;
        e=e->next;

    }

    n->edges = e;

    if(temp == NULL){  // if this is a new list
        head = n;
    }

    else{
        node temp = *head;
        temp.next = n;
    }

}

void delete_node_cmd(pnode *head) {

}

void printGraph_cmd(pnode head){//for self debug

}

void deleteGraph_cmd(pnode* head){


}

void shortsPath_cmd(pnode head) {

}

void TSP_cmd(pnode head) {

}

void setNumOfNodes(int num){
    numOfNodes = num;
}
#endif
