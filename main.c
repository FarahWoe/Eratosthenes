#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int isNotPrim[n];
    for (int i = 2; i < n; i++){
        isNotPrim[i] = 1;               // initialize all entries with false
    }
    for (int j = 2; j <= sqrt(n); j++ ) {
        if(isNotPrim[j] != 0) {
           // printf("%d", j);
            for(int k = j*j;k < n  ; k+=j ){
                isNotPrim[k] = 0;
            }
        }

    }
    for(int i = sqrt(n) +1; i < n; i++) {
        if(isNotPrim[i] != 0){
            printf("%d\n", i);
        }
    }

    return 0;
}
