#include <stdio.h>
#include <math.h>

#define IDX_UNDEF -1

void getInput(int *input, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
}

int idxCheckRight(int *input, int start, int N) {
    for (int i = start; i < N; i++) {
        if (input[i] != IDX_UNDEF) {
            return i;
        }
    }
    return IDX_UNDEF;
}

int idxCheckLeft(int *input, int start, int N) {
    for (int i = start; i >= 0; i--) {
        if (input[i] != IDX_UNDEF) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void calc(int *input, int N) {
    for (int i = 0; i < N ; i++) {
        int idxRight = 0;
        int idxLeft = 0;
        if (input[i] == IDX_UNDEF) {
            if (i == N - 1) {
                idxLeft = idxCheckLeft(input, i - 1, N);
                if (idxLeft != IDX_UNDEF) input[i] = input[idxLeft];
                else input[i] = 0;
            }
            else if (i == 0) {
                idxRight = idxCheckRight(input, i + 1, N);
                if (idxRight != IDX_UNDEF) input[i] = input[idxRight];
                else input[i] = 0;
            }
            else {
                idxRight = idxCheckRight(input, i + 1, N);
                idxLeft = idxCheckLeft(input, i - 1, N);
                if (idxRight != IDX_UNDEF && idxLeft != IDX_UNDEF) {
                    input[i] = floor((double)((input[idxRight] + input[idxLeft])) / 2);
                }
                else if (idxLeft != IDX_UNDEF) {
                    input[i] = input[idxLeft];
                }
                else if(idxRight != IDX_UNDEF) {
                    input[i] = input[idxRight];
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

    int sum = a[0];
    int sumprev = 0;
    printf("RECOVERED ");
    for (int i = 1; i < N; i++) {
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