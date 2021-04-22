#include <stdio.h>

int main(){
    for (int i = 1; i <= 9; i++){
        for (int j = 0; j < 9-i; j++){
            printf(" ");
        }
        for (int k = 1; k <= i; k ++){
            printf("* ");
        }
        printf("\n");
        }
}
