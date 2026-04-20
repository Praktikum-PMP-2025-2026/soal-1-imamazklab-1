#include <stdio.h>
#include <math.h>

#define IDX_UNDEF -1

void getInput(int *input, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
}

void calc(int *input, int N) {
    for (int i = N - 1; i >=0 ; i--) {
        if (input[i] == IDX_UNDEF) {
            if (i == N - 1) {
                if(input[i - 1] != IDX_UNDEF) {
                    input[i] = input[i - 1];
                }
                else {
                    input[i] = 0;
                }
            }
            else if (i == 0) {
                if(input[i + 1] != IDX_UNDEF) {
                    input[i] = input[i + 1];
                }
                else {
                    input[i] = 0;
                }
            }

            else {
                if (input[i + 1] != IDX_UNDEF && input[i - 1] != IDX_UNDEF) {
                    input[i] = floor((double)((input[i + 1] + input[i - 1])) / 2);
                }
                else if (input[i + 1] != IDX_UNDEF) {
                    input[i] = input[i + 1];
                }
                else if(input[i - 1] != IDX_UNDEF) {
                    input[i] = input[i + 1];
                }
                else {
                    input[i] = 0;
                }
            }
        }
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    int a[N];
    getInput(a, N);

    calc(a, N);

    int sum = 0;
    int sumprev = 0;
    printf("RECOVERED ");
    for (int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if (i != N - 1) printf(" ");
        sum += a[i];
        if (sumprev > sum) {
            sum = sumprev;
        }
        sumprev = sum;
    }
    printf("\nMAX_SUM %d", sum);

    return 0;
}