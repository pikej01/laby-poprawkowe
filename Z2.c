#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_float(float min, float max){
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}

float* where(float  *first, float *last){
    int negative = 0;
    int max_index = 0;
    float max_negative = -11;

    for(int i = 0; i <= last - first; i++){
        if(*(first + i) < 0){
            negative = 1;
            if(*(first + i) > max_negative){
                max_negative = *(first + i);
                max_index = i;
            }
        }
    }
    if(negative == 0){
        return NULL;
    }
    else{
        return (first + max_index);
    }
}


int main() {
    srand((unsigned)time(NULL));

    int n;
    printf("Podaj dlugosc tablicy: ");
    scanf("%d", &n);

    float *tab = malloc(n * sizeof(float));

    for(int i = 0; i < n; i++){
        *(tab + i) = random_float(-10, 10);
        printf("tab[%d] = %f, adres elementu: %p\n", i, *(tab + i), (tab + i));
    }

    float *p = where(tab, tab+n);

    if (p == NULL){
        printf("\nW tablicy nie ma elementow ujemnych");
    }
    else{
        printf("adres: %p\nwartosc: %f\nindeks: %d", p, *p, p-tab);
    }

    free(tab);

    return 0;
}
