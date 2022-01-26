#include <stdio.h>
#include <string.h>

int number_cmp(char *num_1, char *num_2){
    unsigned long l1 = strlen(num_1);
    unsigned long l2 = strlen(num_2);

    if (l1 > l2){
       return 1;
    }

    else if (l1 < l2){
        return -1;
    }

    else{
        for(unsigned long i = 0; i < l1; i++){
            if(strcmp(num_1 + i, num_2 + i) > 0){
                return 1;
            }
            else if(strcmp(num_1 + i, num_2 + i) < 0){
                return -1;
            }
        }
    }
    return 0;
}


int main(int argc, char *argv[]){

    printf("pierwsza liczba = ");
    puts(argv[1]);
    printf("druga liczba = ");
    puts(argv[2]);

    int result = number_cmp(argv[1], argv[2]);

    if(result == 1){
        printf("pierwsza jest wieksza");
    }
    else if(result == -1){
        printf("druga jest wieksza");
    }
    else{
        printf("liczby sa rowne");
    }

    return 0;
}
