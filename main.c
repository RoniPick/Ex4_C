#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {
    pnode mainHead = (node *) malloc(sizeof(node));
    if (mainHead == NULL) { // if there is no place in memory to allocate
        printf("Memory not allocated");
        exit(1);
    }

    pnode head = mainHead;

    char input = 0;
    scanf("%c", &input);

    while (1) {
        switch (input) {
            case 'A':
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }
                if (getSize((&head)) != 0) {
                    deleteGraph_cmd(&head);
                    mainHead = (node *) malloc(sizeof(node));
                    head = mainHead;
                    input = caseA(&head, input);
                } else {
                    input = caseA(&head, input);
                }

                break;

            case 'B':
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }
                if (isdigit(input)) {
                    input = caseB(&head, input);
                }

                break;

            case 'D':
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }

                if (isdigit(input)) {
                    input = caseD(&head, input);
                }

                break;

            case 'S':
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }

                if (isdigit(input)) {
                    input = caseS(&head, input);
                }
                if(input!=' '){
                    printf("\n");
                }
                break;

            case 'T':
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }

                if (isdigit(input)) {
                    input = caseT(&head, input);
                }
                if(input!=' '){
                    printf("\n");
                }
                break;

            default:
                deleteGraph_cmd(&head);
                free(mainHead);
                return 0;
        }
    }
//    deleteGraph_cmd(&head);
//    free(mainHead);
    return 0;
}

char caseA(pnode *head, char input) {
    if (input == ' ') {
        scanf("%c", &input);
    }

    if (isdigit(input)) {
        build_graph_cmd(&(*head), input - '0');
    }

    scanf("%c", &input);
    if (input == ' ') {
        scanf("%c", &input);
    }

    if (input == 'n') {

        while (input < 65 || input > 90) { // while we don't get an upper char
            if (input == 'n') {
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }
                int src = 0;
                int dest = 0;
                int w = 0;
                if (isdigit(input)) {
                    src = input - '0';
                }
                scanf("%c", &input);
                if (input == ' ') {
                    scanf("%c", &input);
                }
                while (input != 'n' && (input < 65 || input > 90)) {
                    if (isdigit(input)) {
                        dest = input - '0';
                    }
                    scanf("%c", &input);
                    if (input == ' ') {
                        scanf("%c", &input);
                    }
                    if (isdigit(input)) {
                        w = input - '0';
                    }

                    add_edge(head, src, dest, w);
                    scanf("%c", &input);
                    if (input == ' ') {
                        scanf("%c", &input);
                    }
                }

            }
        }
    }
    return input;
}

char caseB(pnode *head, char input) {
    int src = input - '0';
    int dest = 0;
    int w = 0;

    insert_node_cmd(head, src); // inserting the node to the graph
    scanf("%c", &input);
    //inserting the edges
    while (input < 65 || input > 90) { // while we don't get an upper char
        dest = 0;
        w = 0;
        if (input == ' ') {
            scanf("%c", &input);
        }
        if (isdigit(input)) {
            dest = input - '0';
        }
        scanf("%c", &input);
        if (input == ' ') {
            scanf("%c", &input);
        }
        if (isdigit(input)) {
            w = input - '0';
        }
        add_edge(head, src, dest, w);
        scanf("%c", &input);
        if (input == ' ') {
            scanf("%c", &input);
        }
    }
    return input;
}

char caseD(pnode *head, char input) {
    delete_node_cmd(&(*head), input - '0');
    scanf("%c", &input);
    if (input == ' ') {
        scanf("%c", &input);
    }
    return input;
}

char caseT(pnode *head, char input) {
    int len = input - '0';
    int counter = 0;
    int arr[len];
    while (counter < len) {
        scanf("%c", &input);
        if (input == ' ') {
            scanf("%c", &input);
        }
        if (isdigit(input)) {
            arr[counter] = input - '0';
        }
        counter++;
    }
    TSP_cmd(head, len, arr);
    scanf("%c", &input);
    if (input == ' ') {
        scanf("%c", &input);
    }
    return input;
}

char caseS(pnode *head, char input) {
    int src = input - '0';
    int dest = 0;
    scanf("%c", &input);
    if (input == ' ') {
        scanf("%c", &input);
    }
    if (isdigit(input)) {
        dest = input - '0';
    }
    int len = shortsPath_cmd(head, src, dest);
    printf("Dijsktra shortest path: %d ", len);

    scanf("%c", &input);
    if (input == ' ') {
        scanf("%c", &input);
    }
    return input;
}