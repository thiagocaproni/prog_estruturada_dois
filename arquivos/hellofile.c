#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    char c;

    if(argc == 3){
        fp1 = fopen(argv[1], "rb");
        fp2 = fopen(argv[2], "wb");

        if(fp1 == NULL || fp2 == NULL){
            printf("erro!!!");
            return 1;
        }

        while(!feof(fp1)){
            c = getc( fp1 );
            if (!feof(fp1));
                putc(c, fp2);
        }
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}