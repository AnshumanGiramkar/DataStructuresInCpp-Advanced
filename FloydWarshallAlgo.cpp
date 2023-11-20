#include <stdio.h>  
#define INF 2147483647  
   
int n = 4; // size of the adjacency matrix  
   
// O(n^2)  
void fillDistanceMatrix(int A[n][n], int D[n][n]) {  
   for (int i = 0; i < n; i++) {  
       for (int j = 0; j < n; j++) {  
           if (i == j)  
               D[i][j] = 0;  
           else if (A[i][j] == 0)  
               D[i][j] = INF;  
           else  
               D[i][j] = A[i][j];  
       }  
   }  
}  
   
// O(n^3)  
void floydWarshall(int A[n][n], int D[n][n]) {  
   fillDistanceMatrix(A, D);  
   
   for (int k = 0; k < n; k++) {  
       for (int i = 0; i < n; i++) {  
           for (int j = 0; j < n; j++) {  
               if (D[i][k] < INF && D[k][j] < INF)  
                   if (D[i][k] + D[k][j] < D[i][j])  
                       D[i][j] = D[i][k] + D[k][j];  
           }  
       }  
   }  
}  
int main() {  
    int A[4][4] = {{0, 5, INF, 10},  
                   {INF, 0, 3, INF},  
                   {INF, INF, 0, 1},  
                   {INF, INF, INF, 0}};  
    int D[4][4];  
   
    floydWarshall(A, D);  
   
    printf("Shortest distances between all pairs of vertices:\n");  
    for (int i = 0; i < 4; i++) {  
        for (int j = 0; j < 4; j++) {  
            if (D[i][j] == INF)  
                printf("%7s", "INF");  
            else  
                printf("%7d", D[i][j]);  
        }  
        printf("\n");  
    }  
   
    return 0;  
} 
