#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {
    pnode mainHead = (node*)malloc(sizeof(node));
    if(mainHead == NULL){ // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    pnode head = mainHead;
    build_graph_cmd(&head);
    add_edge(&head,0 , 2, 5);
    add_edge(&head,0 , 3, 3);
    add_edge(&head, 1, 3, 7);
    add_edge(&head, 1, 0, 2);
    add_edge(&head, 2, 0, 4);
    add_edge(&head, 2, 1, 1);
    TSP_cmd(&head);
//    add_edge(&head,0 , 2, 5);
//    add_edge(&head,0 , 3, 3);
//    add_edge(&head, 1, 3, 7);
//    add_edge(&head, 1, 0, 2);
//    add_edge(&head, 2, 0, 4);
//    add_edge(&head, 2, 1, 1);
//    shortsPath_cmd(&head, 2, 0);

//    insert_node_cmd(head, 4, 3, 10);
//    insert_node_cmd(head, 1, 0, 10);
//    add_edge(head, 2, 3);
//    add_edge(head, 1, 3);

//    delete_node_cmd(head, 2);
//    deleteGraph_cmd(head);
//    build_graph_cmd(head);
//    insert_node_cmd(head, 2, 2, 1);
//    insert_node_cmd(head, 4, 1, 2);
//    delete_node_cmd(head, 0);

//    char input = 0;
//
//    while(1){
//        scanf("%c", &input);
//        switch (input) {
//            case 'A':
//                if (input != NULL){
//                    deleteGraph_cmd(head);
//                }
//                else{
//                    build_graph_cmd(head);
//                }
//
//                break;
//
//            case 'B':
//                scanf("%d", &input);
//                int id = input;
//                scanf("%d", &input);
//                int dest = input;
//                scanf("%d", &input);
//                int w = input;
//                insert_node_cmd(head, id, dest, w);
//
//
//
//
//
//                break;
//
//            case 'n':
//
//                break;
//
//            case 'D':
//
//                break;
//
//            case 'S':
//
//                break;
//
//            case 'T':
//
//                break;
//        }
//    }




    return 0;
}
