#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    int n;
    srand((unsigned)time(NULL));

    printf("Podaj dlugosc tablicy: ");
    scanf("%d", &n);
    int tab1[n], tab2[21] = {};

    for(int i = 0; i < n; i++){
        int x = rand() % 21;
        tab1[i] = x;
        tab2[x] += 1;
    }
    printf("tab1 = ");

    for(int j = 0; j < n; j++){
        printf("%d ", tab1[j]);
    }

    printf("\nliczby ktore sie nie powtarzaja: ");

    for(int i = 0; i < 21; i++) {
        if (tab2[i] == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
