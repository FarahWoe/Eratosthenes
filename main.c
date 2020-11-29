
#include <stdio.h>
float findSQRT(int number)
{
    int start = 0, end = number;
    int mid;

    // To store the answer
    float ans;

    // To find integral part of square
    // root of number
    while (start <= end)
    {

        // Find mid
        mid = (start + end) / 2;

        // If number is perfect square
        // then break
        if (mid * mid == number)
        {
            ans = mid;
            break;
        }

        // Increment start if integral
        // part lies on right side
        // of the mid
        if (mid * mid < number)
        {
            start = mid + 1;
            ans = mid;
        }

            // Decrement end if integral part
            // lies on the left side of the mid
        else
        {
            end = mid - 1;
        }
    }

    // To find the fractional part
    // of square root upto 5 decimal
    float increment = 0.1;
    for(int i = 0; i < 5; i++)
    {
        while (ans * ans <= number)
        {
            ans += increment;
        }

        // Loop terminates,
        // when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

// Driver Code

int main() {
    int counter = 0;
    int n;
    printf(": ");
    scanf("%d", &n);
    int sqrtN = (int) findSQRT(n);
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
