#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "Queue.c"

#define infinity INT_MAX;

static int size=0;
void build_graph_cmd(pnode *head) {
    if(head == NULL){
        pnode *temp = (pnode*)malloc(sizeof(node));
        if(temp == NULL){ // if there is no place in memory to allocate
            printf("Memory not allocated");
            exit(1);
        }
        head = temp;
    }

    int len = 4;
    // scanf("%d", &len);

    for (int i = 0; i < len; i++) {
        create_node(&(*head), i);
    }

    //   pnode *temp = head;
//    int i=0;
//    int dest = 4;
//    int w = 0;
//    while((*temp)->node_num!=i){
//        *temp = (*temp)->next;
//    }
//    add_edge(temp, dest, w);
    // insert_node_cmd(temp, i, dest, w);
//    char cur = ' ';
//    scanf("%c", &cur); // scanning the space - ' '
//    scanf("%c", &cur);
//    while(cur == 'n'){
//        scanf("%c", &cur);
//        while(cur>=48 && cur<=57){
//            cur = cur-48;
//            while(temp->node_num!=cur){
//                temp = temp->next;
//            }
//
//        }
//    }



}

void insert_node_cmd(pnode *head, int i, int dest, int w) {
    int id = i;
    pnode temp = *head;
    pedge *p = (pedge*) malloc(sizeof(edge));
    if (p == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    if(size == 0){
        create_node(&temp, id);
        *p = temp->edges;
        *p = (pedge)malloc(sizeof(edge));
        (*p)->endpoint = dest;
        (*p)->weight = w;
        temp->edges = *p;
        temp->edges->next = NULL;
        temp->numOfEdges++;
    }
    else{
        int counter=0;
        int bool = 0;
        while(counter<size){
            if(temp->node_num != id){
                if(size==1){
                    break;
                }
                else{
                    if(temp->next == NULL){
                        create_node(&temp, id);
                        temp = temp->next;
                        break;
                    }
                    else{
                        temp = temp->next;
                        counter++;
                    }
                }

            }
            else if(temp->node_num == id){
                bool = 1;
                break;
            }
        }

        if (bool == 1){
            while(temp->numOfEdges>0){
                temp->numOfEdges--;
                free(temp->edges);
                temp->edges = temp->edges->next;

            }
        }

        add_edge(&temp, i, dest, w);

    }


}

void delete_node_cmd(pnode *head, int id) {
    pnode temp = *head;
    edge *p = temp->edges;
    if(temp == NULL){
        return;
    }
    //if the node is the head of the list
    if(temp->node_num == id){
        while(temp->numOfEdges>0){
            free(temp->edges);
            temp->edges = temp->edges->next;
            temp->numOfEdges--;
        }

        free(*head);
        (*head) = (*head)->next;
        size--;

    }
    else{
        // finding the prev node
        while(temp->next->node_num!=id){
            temp = temp->next;
        }
        // removing the node's edges
        while(temp->next->numOfEdges>0){
            free(temp->next->edges);
            temp->next->edges = temp->next->edges->next;
            temp->next->numOfEdges--;
        }
        free(temp->next);
        temp->next = temp->next->next;
        temp = temp->next;
        size--;
    }
    temp = *head;
    p = temp->edges;

    // a loop to remove all the edges to the node we're removing
    while(temp!=NULL){
        while(p != NULL){
            // no edges
            if((temp)->numOfEdges == 0){
                break;
            }
                // if there is only one edge from the node
            else if((temp)->numOfEdges == 1){
                if(p->endpoint == id){
                    free(p);
                    temp->numOfEdges--;
                    temp->edges = NULL;
                }
                break;

            }
                // if there is more them one edge from the node
            else{
                // if this is the first node in the list
                if(p->endpoint == id && p->next != NULL){
                    edge *cur = p->next;
                    free(p);
                    *p = *cur;
                    temp->numOfEdges--;
                    break;
                }
                    // a node in the middle
                else if(p->next != NULL && p->next->endpoint == id ){
                    if(p->next->next == NULL){
                        free(p->next);
                        temp->numOfEdges--;
                    }
                    else{
                        edge *cur = p->next->next;
                        free(p->next);
                        p->next = cur;
                        temp->numOfEdges--;
                    }
                    break;
                }

                else{
                    p = p->next;
                }
            }
        }
        temp = (temp)->next;
        if(temp!=NULL){
            p = (temp)->edges;
        }
    }
}

void printGraph_cmd(pnode head) { //for self debug

}

void deleteGraph_cmd(pnode* head) {
    pnode *temp = head;

    while (*head != NULL){
        while((*temp)->numOfEdges>0){
            free((*temp)->edges);
            (*temp)->edges = (*temp)->edges->next;
            (*temp)->numOfEdges--;
        }

        free(*head);
        size--;
        *temp = (*head)->next;
        *head = *temp;
    }
    free(*temp);
}

void shortsPath_cmd(pnode *head, int src, int dest) {
    int dist[size];
    int visited[size];
    for(int i=0; i<size; i++){
        dist[i] = infinity;
        visited[i] = 0;
    }
    dist[src] = 0;
    struct Queue* q = creatQueue(size);
    pnode temp = (*head);
    enqueue(q, src);
    int len=0;
    while(!isEmpty(q)){
        int curNode = dequeue(q);
        if(visited[curNode] == 0){
            while(temp->node_num != curNode){
                temp = (temp)->next;
            }
            pedge edge = (temp)->edges;
            while(edge != NULL){
                len = edge->weight + dist[curNode]; // first node + weight of the edge
                int curLen = dist[edge->endpoint]; // the edge end point wight
                if(len < curLen){
                    dist[edge->endpoint] = len;
                    enqueue(q, edge->endpoint);
                }
                edge = edge->next;
            }
            temp = *head; // temp point to the first node in the list, so we can go throw the whole nodes
        }
        visited[curNode] = 1;
    }

    free(q->arr);
    free(q);

    printf("Dijsktra shortest path:%d", dist[dest]);
}

void TSP_cmd(pnode *head) {

}

void create_node(pnode *head, int id) {
    pnode n = (pnode) malloc(sizeof(node));
    if (n == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
    n->node_num = id;
    n->edges = NULL;
    n->next = NULL;

    if(size == 0){
        head = &n;
        size++;

    }

    else{
        pnode temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
        size++;
    }

}

void add_edge(pnode *head, int src, int dest, int w){
    pnode temp = *head;
    pedge *p = (pedge*) malloc(sizeof(edge));
    if (p == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    while(temp->node_num != src){
        temp = temp->next;
    }

    *p = temp->edges;
    int counter = 0;
    int boo = 0;
    if(temp->numOfEdges > 0) {
        while ((*p)->next != NULL) {
            (*p) = (*p)->next;
            counter++;
        }
        (*p)->next = (pedge)malloc(sizeof(edge));
        (*p) = (*p)->next;
        boo = 1;
    }

    if (boo == 0){
        (*p) = (pedge)malloc(sizeof(edge));
        temp->edges = *p;
    }

    (*p)->endpoint = dest;
    (*p)->weight = w;
    temp->numOfEdges++;

}
