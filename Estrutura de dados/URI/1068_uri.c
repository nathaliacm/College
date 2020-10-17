#include <stdio.h>

int main () {
    char N[1000];
    int abreParentese, fechaParentese;
    int i;

    while(scanf("%s", &N) != EOF){
        abreParentese = 0;
        fechaParentese = 0;
        for(i = 0; N[i] != '\0'; i++){
            if(N[i] == '('){
                abreParentese++;
            }else if(N[i] == ')'){
                fechaParentese++;
                if(fechaParentese > abreParentese){
                    break;
                }
            }
        }
        if(abreParentese == fechaParentese){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }

    return 0;
}
