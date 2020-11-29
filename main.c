
#include <stdio.h>
#include <math.h>

int main() {
    int counter = 0;
    int n;
    printf(": ");
    scanf("%d", &n);
    int sqrtN = (int) sqrt(n);
    int isNotPrim[n+1];
    for (int i = 2; i < n+1; i++){
        isNotPrim[i] = 1;               // initialize all entries with false
    }
    for (int j = 2; j <= sqrtN; j++ ) {
        if(isNotPrim[j] != 0) {
            printf("%d ", j);
            counter++;
            if(counter%10 == 0) {
                printf("\n");
            }
            for(int k = j*j;k < n  ; k+=j ){
                isNotPrim[k] = 0;                  //z.B j = 2 -> 4,6,8,... auf Null gesetzt (Vielfache deshalb + j)
            }
        }

    }
    for(int i = sqrtN+1; i < n; i++) {
        if(isNotPrim[i] != 0){
            printf("%d ", i);
            counter++;
            if(counter%10 == 0) {
                printf("\n");
            }
        }
    }

return 0;
}
