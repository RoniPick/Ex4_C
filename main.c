#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    pgraph g;
    g = (graph*)malloc(sizeof(graph));
    if(g == NULL){ // if there is no place in memory to allocate
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
    char input = 0;

    while(1){
        scanf("%c", &input);
        switch (input) {
            case 'A':
                if (g != NULL){
                    deleteGraph_cmd(&g);
                }
                else{
                    build_graph_cmd(&g);

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
