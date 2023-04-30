#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int rec(int i , int j, int n, int **graph, int ***SV)
{
    int st,ni,nj;// st = η διαδρμή που θέλουμε να ελέγξουμε για το αν είναι ποιο σύντομη απο την ni+nj
    if (n == -1) return graph[i][j] ;// Όταν τελειώσει το πρόγραμμα με την αναζήτηση επιστρέφει την τιμή που έχει βρει
    st = (SV[i][j][n] != -12)? SV[i][j][n]: (SV[i][j][n] = rec(i , j, n-1, graph, SV)) ;//Αν ο πίνακας SV  δεν έχει αποθηκευμένη την μικρότερη απόσταση των i,j την αναζητά αλλιώς την αποθηκεύει στην st
    ni = (SV[i][n][n] != -12)? SV[i][n][n]: (SV[i][n][n] = rec(i , n, n-1, graph, SV)) ;//Αν ο πίνακας SV  δεν έχει αποθηκευμένη την μικρότερη απόσταση των i,n την αναζητά αλλιώς την αποθηκεύει στην ni
    nj = (SV[n][j][n] != -12)? SV[n][j][n]: (SV[n][j][n] = rec(n , j, n-1, graph, SV)) ;//Αν ο πίνακας SV  δεν έχει αποθηκευμένη την μικρότερη απόσταση των n,j την αναζητά αλλιώς την αποθηκεύει στην nj
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
    int i,j,k;
    int ***SV;
    SV = malloc(n * (sizeof(int**))) ;
    if (SV == NULL) return ;// SV τρισδιάστατος πίνακας που αποθηκεύει τις μικρότερες διαδρομές που θα αναζητηθουν στην rec για τισ διάφορες τιμές των i,j
    /**/for (i = 0 ; i < n; i++) {
        SV[i] = malloc(n * (sizeof(int*))) ;
        if (SV[i] == NULL) return ;
        /**/for (j = 0 ; j < n; j++) {
            SV[i][j] = malloc(n * (sizeof(int))) ;
            if (SV[i][j] == NULL) return ;
        }
        /**/
    }
    /**/
    /**/for(i = 0 ; i < n ; i++) {
        /**/for (j = 0 ; j < n; j++) {
            /**/for (k = 0 ; k < n; k++) {
                SV[i][j][k] = -12 ; // Εκχωρούμε όλα τα στοιχεία του πίνακα με την τιμή -12 έτρι ώστε να μπορεί το πρόγραμμα να αναγνωρίσει οποιαδήποτε αλλαγή
            }
            /**/
        }
        /**/
    }
    /**/
    /**/for (i = 0 ; i < n; i++){
		/**/for (j = 0 ; j < i; j++){
	    	printf("From node %d to node %d: ",i,j);
	    	(rec(i , j, n-1, graph, SV) != -1)? printf("Length of shortest path is %d \n",rec(i , j, n-1, graph, SV)): printf("There is no path \n") ;// Σε περίπτωση που δεν υπάρχει διαδρομή εμφανίζεται το κατάληλο μήνυμα
		}
		/**/
		printf("\n") ;
    }
    /**/
    printf(".....\n..........\n...............\n");
    /**/for (i = 0 ; i < n; i++) {
        /**/for (j = 0 ; j < n; j++) {
            free(SV[i][j]) ;
        }
        /**/
    }
    /**/
    /**/for (i = 0 ; i < n; i++) {
        free(SV[i]) ;
    }
    /**/
    free(SV) ;
}
