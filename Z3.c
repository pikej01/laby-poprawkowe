#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand((unsigned)time(NULL));

    int tab[100] = {};
    for(int i = 0; i < 100; i++){
        tab[i] = (rand() % 100);
    }

    int temp_dlugosc = 1, max_dlugosc = 1, temp_poczatek = 0, max_poczatek = 0, rosnacy = -1, max_rosnacy = -1;
    for(int j = 0; j < 100; j++){
        if(tab[j] < tab[j+1]){
            if(rosnacy == 1){
                temp_dlugosc += 1;
            }
            else if(rosnacy == -1){
                if(max_dlugosc < temp_dlugosc){
                    max_dlugosc = temp_dlugosc;
                    max_poczatek = temp_poczatek;
                    max_rosnacy = -1;
                }
                temp_dlugosc = 2;
                rosnacy = 1;
                temp_poczatek = j;
            }
            else{
                if(max_dlugosc < temp_dlugosc){
                    max_dlugosc = temp_dlugosc;
                    max_poczatek = temp_poczatek;
                    max_rosnacy = 0;
                }
                temp_dlugosc = 2;
                rosnacy = 1;
                temp_poczatek = j;
            }
        }
        else if(tab[j] > tab[j+1]){
            if(rosnacy == 1){
                if(max_dlugosc < temp_dlugosc){
                    max_dlugosc = temp_dlugosc;
                    max_poczatek = temp_poczatek;
                    max_rosnacy = 1;
                }
                temp_dlugosc = 2;
                rosnacy = -1;
                temp_poczatek = j;
            }
            else if(rosnacy == -1){
                temp_dlugosc += 1;
            }
            else{
                if(max_dlugosc < temp_dlugosc){
                    max_dlugosc = temp_dlugosc;
                    max_poczatek = temp_poczatek;
                    max_rosnacy = 0;
                }
                temp_dlugosc = 2;
                rosnacy = -1;
                temp_poczatek = j;
            }
        }
        else{
            if(rosnacy == 1){
                if(max_dlugosc < temp_dlugosc){
                    max_dlugosc = temp_dlugosc;
                    max_poczatek = temp_poczatek;
                    max_rosnacy = 1;
                }
                temp_dlugosc = 2;
                rosnacy = 0;
                temp_poczatek = j;
            }
            else if(rosnacy == -1){
                if(max_dlugosc < temp_dlugosc){
                    max_dlugosc = temp_dlugosc;
                    max_poczatek = temp_poczatek;
                    max_rosnacy = -1;
                }
                temp_dlugosc = 2;
                rosnacy = 0;
                temp_poczatek = j;
            }
            else{
                temp_dlugosc += 1;
            }
        }
    }

    int suma = 0;

    for(int i = max_poczatek; i < (max_poczatek + max_dlugosc); i++){
        suma += tab[i];
    }

    //for(int i = 0; i < 100; i++){
    //     printf("%d ", tab[i]);
    //}

    //printf("\n");

    //printf("%d %d %d ", max_dlugosc, max_poczatek, suma);

    printf("najdluzszy monotoniczny podciag ma %d elementow\njego suma to: %d\nciag ten jest ", max_dlugosc, suma);

    if(max_rosnacy == 1){
        printf("rosnacy");
    }
    else if(max_rosnacy == -1){
        printf("malejacy");
    }
    else{
        printf("staly");
    }

    return 0;
}
