#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "Queue.c"

int infinity = INT_MAX;
static int tsp = INT_MAX;
static int size = 0;
int max_id = 0;

void build_graph_cmd(pnode *head, int len) {
    if (*head == NULL) {
        pnode *temp = (pnode *) malloc(sizeof(pnode));
        if (temp == NULL) { // if there is no place in memory to allocate
            printf("Memory not allocated");
            exit(1);
        }
        *head = *temp;
    }

    for (int i = 0; i < len; i++) {
        create_node(&(*head), i);
        if(i>max_id){
            max_id = i;
        }
    }

}

void insert_node_cmd(pnode *head, int src) {
    int id = src;
    pnode temp = *head;
    pedge *p = (pedge *) malloc(sizeof(struct edge_));
    if (p == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    if (size == 0) {
        create_node(&temp, id);
        *p = temp->edges;
        *p = (pedge) malloc(sizeof(edge));
        temp->edges = *p;
        temp->edges->next = NULL;
        temp->numOfEdges++;
    } else {
        int counter = 0;
        int bool = 0;
        while (counter < size) {
            if (temp->node_num != id) {
                if (size == 1) {
                    break;
                } else {
                    if (temp->next == NULL) {
                        create_node(&temp, id);
                        temp = temp->next;
                        break;
                    } else {
                        temp = temp->next;
                        counter++;
                    }
                }

            } else if (temp->node_num == id) {
                bool = 1;
                break;
            }
        }

        if (bool == 1) {
            while (temp->numOfEdges > 0) {
                temp->numOfEdges--;
                pedge next = temp->edges->next;
                free(temp->edges);
                temp->edges = next;

            }
        }

    }


}

void delete_node_cmd(pnode *head, int id) {
    pnode temp = *head;
    pedge p = temp->edges;
    if (temp == NULL) {
        return;
    }
    //if the node is the head of the list
    if (temp->node_num == id) {
        while (temp->numOfEdges > 0) {
            pedge next_e = temp->edges->next;
            free(temp->edges);
            temp->edges = next_e;
            temp->numOfEdges--;
        }
        pnode next_head = (*head)->next;
        free(*head);
        (*head) = next_head;
        size--;

    } else {
        // finding the prev node
        while (temp->next->node_num != id) {
            temp = temp->next;
        }
        p = temp->next->edges;
        // removing the node's edges
        while (temp->next->numOfEdges > 0) {
            pedge cur = p->next;
            free(p);
            if (cur != NULL) {
                p = cur;
            }
            temp->next->numOfEdges--;
            //temp->next->edges = temp->next->edges->next;

        }
        p = NULL;
        pnode next_node = temp->next->next;
        free(temp->next);
        temp->next = next_node;

        size--;
    }
    temp = *head;
    p = temp->edges;

    // a loop to remove all the edges to the node we're removing
    while (temp != NULL) {
        while (p != NULL) {
            // no edges
            if ((temp)->numOfEdges == 0) {
                break;
            }
                // if there is only one edge from the node
            else if ((temp)->numOfEdges == 1) {
                if (p->endpoint == id) {
                    free(p);
                    temp->numOfEdges--;
                    temp->edges = NULL;
                }
                break;

            }
                // if there is more them one edge from the node
            else {
                // if this is the first node in the list
                if (p->endpoint == id && p->next != NULL) {
                    edge *cur = p->next;
                    free(p);
                    *p = *cur;
                    temp->numOfEdges--;
                    break;
                }
                    // a node in the middle
                else if (p->next != NULL && p->next->endpoint == id) {
                    if (p->next->next == NULL) {
                        free(p->next);
                        temp->numOfEdges--;
                        p->next = NULL;
                    } else {
                        edge *cur = p->next->next;
                        free(p->next);
                        p->next = cur;
                        temp->numOfEdges--;
                    }
                    break;
                } else {
                    p = p->next;
                }
            }
        }
        temp = (temp)->next;
        if (temp != NULL) {
            p = (temp)->edges;
        }
    }

    if(id == max_id){
        max_id = 0;
        while(temp!=NULL){
            if(temp->node_num > max_id){
                max_id = temp->node_num;
            }
        }
    }
}

void printGraph_cmd(pnode head) { //for self debug

}

void deleteGraph_cmd(pnode *head) {
    pnode temp = *head;
    while (temp != NULL) {
        while ((temp)->numOfEdges > 0) {
            if ((temp)->edges->next != NULL) {
                pedge next_edge = (temp)->edges->next;
                free((temp)->edges);
                (temp)->edges = next_edge;
                (temp)->numOfEdges--;
            } else {
                free((temp)->edges);
                (temp)->edges = NULL;
                (temp)->numOfEdges--;
            }
        }
        pnode next_node = (temp)->next;
        free(temp);
        (temp)->edges = NULL;
        temp = next_node;
        *head = temp;
        size--;
    }
}

int shortsPath_cmd(pnode *head, int src, int dest) {
    pnode temp = (*head);
    int dist[max_id + 1];
    int visited[max_id + 1];
    for (int i = 0; i < max_id + 1; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    struct Queue *q = creatQueue(max_id+1);
    int len = 0;
    enqueue(q, src);
    while (!isEmpty(q)) {
        int curNode = dequeue(q);
        if (visited[curNode] == 0) {
            while (temp->node_num != curNode) {
                temp = (temp)->next;
            }
            pedge edge = (temp)->edges;
            while (edge != NULL) {
                len = edge->weight + dist[curNode]; // first node + weight of the edge
                int curLen = dist[edge->endpoint]; // the edge end point wight
                if (len < curLen) {
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
    if (visited[dest] == 0) {
        return INT_MAX;
    }
    else {
        return dist[dest];
    }

}

void TSP_cmd(pnode *head, int len, int arr[]) {
    pnode temp = *head;
    tsp = INT_MAX;
    permute(&temp, arr, 0, len - 1);
    if (tsp == INT_MAX) {
        tsp = -1;
    }
    printf("TSP shortest path: %d\n", tsp);
    tsp = INT_MAX;
}

void create_node(pnode *head, int id) {
    if (max_id < id) {
        max_id = id;
    }
    pnode n = (node *) malloc(sizeof(node));
    if (n == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
    n->node_num = id;
    n->edges = NULL;
    n->next = NULL;
    n->numOfEdges = 0;

    if (size == 0) {
        *head = n;
        size++;

    } else {
        pnode temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        size++;
    }

}

void add_edge(pnode *head, int src, int dest, int w) {
    pnode temp = *head;
    pedge *p = (pedge *) malloc(sizeof(struct edge_));
    if (p == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }
    if (temp->numOfEdges > 0) {
        while (temp->node_num != src) {
            temp = temp->next;
        }
    }
    *p = temp->edges;
    int counter = 0;
    int boo = 0;
    if ((*p) != NULL) {
        while ((*p)->next != NULL) {
            (*p) = (*p)->next;
            counter++;
        }
        (*p)->next = (pedge) malloc(sizeof(edge));
        (*p) = (*p)->next;
        boo = 1;
    }

    if (boo == 0) {
        (*p) = (pedge) malloc(sizeof(edge));
        temp->edges = *p;
    }

    (*p)->endpoint = dest;
    (*p)->weight = w;
    (*p)->next = NULL;
    temp->numOfEdges++;

}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(pnode *head, int *a, int start, int end) {
    if (start == end) {
        int sum = 0;
        int j = 1;
        for (int i = 0; i <= end; ++i) {
            if (j <= end) {
                int **p = &a;
                int s = *(i + *p);
                int d = (*(j + *p));
                if((s==3 || s==0) && (d==3||d==0)){
                    int x=0;
                    int y=0;
                }
                int temp = shortsPath_cmd(head, s, d);
                if (temp == INT_MAX) {
                    sum = INT_MAX;
                    return;
                } else {
                    sum = sum + temp;
                    j++;
                }
            }
        }
        if (sum < tsp) {
            tsp = sum;
        }

    } else {
        for (int i = start; i <= end; i++) {
            swap((a + start), (a + i));
            permute(head, a, start + 1, end);
            swap((a + start), (a + i)); //backtrack
        }
    }
}

int getSize(pnode *head) {
    return size;
}