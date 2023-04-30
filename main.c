#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main (){
    int i,j;
    int n;
    int x;
    int **graph;

    printf("Give the number of the nodes:\n") ;
    scanf("%d",&n);
    graph = malloc(n * sizeof(int*)) ;
    if (graph == NULL) return -1 ;
    /**/for ( i = 0; i < n; i++) { //Στον πίνακα graph αποθηκεύονται οι διαδρομές
        graph[i] = malloc(n * sizeof(int)) ;
        if (graph[i] == NULL) return -1 ;
    }
    /**/
    printf("Give input:\n") ;
    /**/for ( i = 0; i < n; i++) {
        /**/for ( j = 0; j < i; j++){
            scanf("%d", &graph[i][j]) ;
            graph[j][i] = graph[i][j];
        }
        /**/
    }
    /**/

    printf("\n\nResult:\n") ;

    solve(n , graph);//Η function solve αναζητά την μικρότερη διαδρομή δυο κόμβων

    /**/for ( i = 0; i < n; i++) {
        free(graph[i]);
    }
    /**/
    free(graph) ;

    return 0 ;
}
