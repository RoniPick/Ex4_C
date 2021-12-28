#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    pnode head;
    head = (node*)malloc(sizeof(node));
    char input = 0;

    while(1){
        scanf("%c", &input);
        switch (input) {
            case 'A':
                if (head!= NULL){
                    deleteGraph_cmd(&head);
                }
                else{

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
