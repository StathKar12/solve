#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int rec(int i , int j, int n, int **graph)
{
    int st,ni,nj;// st = η διαδρμή που θέλουμε να ελέγξουμε για το αν είναι ποιο σύντομη απο την ni+nj
    if (n == -1) return graph[i][j] ; // Όταν τελειώσει το πρόγραμμα με την αναζήτηση επιστρέφει την τιμή που έχει βρει
    st = rec(i , j, n-1, graph) ;
    ni = rec(i , n, n-1, graph) ;
    nj = rec(n , j, n-1, graph) ;
    /**/ if ((st == -1) && (ni == -1) && (nj == -1)) // Αν όλες η μεταβλητες είναι -1 επιστρέφει -1
	return -1 ;
    else if ((ni == -1) || (nj == -1)) // αν οι ni,nj = -1 επιστρέφει την st
        return st ;
    else if (st == -1) // αν η st = -1 επιστρέφει ni+nj
        return ni + nj ;
    /**/
    return (st < ni + nj)? st : ni + nj ; //συγκρίνει τις δυο διαδρομές και επιστρέφει την ποιο μικρή
}


void solve (int n , int **graph)
{
    int i,j;
    /**/for (i = 0 ; i < n; i++){
		/**/for (j = 0 ; j < i; j++){
	    	printf("From node %d to node %d: ",i,j);
	    	(rec(i , j, n-1, graph) != -1)? printf("Length of shortest path is %d \n",rec(i , j, n-1, graph)): printf("There is no path \n") ;// Σε περίπτωση που δεν υπάρχει διαδρομή εμφανίζεται το κατάληλο μήνυμα
		}
		/**/
		printf("\n") ;
    }
    /**/
    printf(".....\n..........\n...............\n");
}
