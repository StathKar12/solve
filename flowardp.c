#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

void print (int i , int j, int **Q) // H function print δέχεται ώς παράμετρους τα : i,j,**Q
{
	printf(" -> %d",Q[i][j]) ; //εμφανίζει το περιεχόμενο του πίνακα (τον ενδιάμεσο κόμβο)
	if (Q[i][j] != j) print(Q[i][j] , j, Q) ; // σε περίπτωση που δεν έχει βρει τον προορισμό συνεχίζει να ψάχνει
}

void solve (int n ,int **graph)
{
    int i,j,k ;
    int **Q ;
    Q = malloc(n * sizeof(int*)) ; // Ο πίνακας Q αποθηκεύει όλους του ενδιάμεσους κόμβους μεταξυ του 1ου και του τελευταίου κόμβου
    if (Q == NULL) return ;
    /**/for ( i = 0; i < n; i++) {
        Q[i] = malloc(n * sizeof(int)) ;
        if (Q[i] == NULL) return ;
    }
    /**/
    /**/for ( i = 0; i < n; i++) {
        /**/for ( j = 0; j < n; j++) {
		Q[i][j] = j ; // Απο τον i κόμβο πάμε στον j (αποθηκεύουμε τον j γιατι δεν λαμβάνουμε υπόψην μας ακόμη τους ενδιάμεσους κόμβους
        }
        /**/
    }
    /**/
    printf("...\n");
    /**/for (k = 0; k < n; k++) {
        /**/for (i = 0; i < n; i++) {
            /**/for (j = 0; j < n; j++){
                /**/if ((graph[i][k] != -1) && (graph[k][j] != -1)) {
                    /**/if ((graph[i][j] > (graph[i][k] + graph[k][j])) || (graph[i][j] == -1)){ //Σε περίπτωση που βρεθεί καλύτερη διαδρομή αποθηκεύεται η καινούρια απόσταση και ο αριθμός του κόμβου
                        graph[i][j] = graph[i][k] + graph[k][j] ;
                        Q[i][j] = Q[i][k] ;
                    }
                    /**/
                }
                /**/
            }
            /**/
        }
        /**/
    }
    /**/
    printf("......\n......\n") ;
    /**/for ( i = 1; i < n; i++) {
        /**/for ( j = 0; j < i; j++) {
        	/**/if (graph[i][j] == -1) {
        		printf("From node %d to node %d: There is no path \n",i,j) ;
			}
			else {
            printf("From node %d to node %d: Length of shortest path is %d \n",i,j,graph[i][j]) ;
            #ifdef PATH
            printf("Shortest path is : %d",i) ;
            print(i , j, Q);
            printf("\n");
            #endif //PATH
        	}
        }
        /**/
        printf("\n");
        //printf("%d\n",i);
    }
    /**/
    printf("..........................\n.................................\n");
    /**/for ( i = 0; i < n; i++) {
        free(Q[i]);
    }
    /**/
    free(Q) ;
}
