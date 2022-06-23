#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000
char* strupr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = toupper((unsigned char) *tmp);
    }
    return s;
}

void dscenar(char *ming) {
    for (int i = 0; i < strlen(ming); i++) {
        char a = ming[i];
        if (ispunct(a)) {
            for (int j = i; j <strlen(ming); j++) {
                ming[j] =ming[j +1];
            }
            i--;
        }
        else{
            ming[i]=a;
        }
    }
}
void pscenar(char *ming) {
    for (int i = 0; i < strlen(ming); i++) {
        char a = ming[i];
        if (isdigit(a)) {
            for (int j = i; j <strlen(ming); j++) {
                ming[j] =ming[j +1];
            }
            i--;
        }
        else{
        }
    }
}
void clasicscenar(char *ming) {
    for (int i = 0; i < strlen(ming); i++) {
        char a = ming[i];
        if (isdigit(a)  || ispunct(a)) {
            for (int j = i; j <strlen(ming); j++) {
                ming[j] =ming[j +1];
            }
            i--;
        }
        else{
            ming[i]=a;
        }
    }
}
void ll(char  *ming){
    for (int i = 0; i < strlen(ming); i++) {
        ming[i] = tolower(ming[i]);
    }
}
void ul(char  *ming){
    for (int i = 0; i < strlen(ming); i++) {
        ming[i] = toupper(ming[i]);
    }
}
void rscenar(char *ming,char *parameter,int nl){
    int p = 0;
    if (nl > 0){
        printf("\n");
    }
    for (int i = 0; i < (strlen(ming)-1); i++) {
        char a = ming[i];

        if (ming[i] == ' ') {
            p=0;
            printf("%c",a);
        }
        else if (isalnum(a)==0){
            p = 0;
            printf("%c", a);
        }
        else if (p<strlen(parameter)){
            printf("%c",parameter[p]);
            p++;
        }
        else{
            printf("%c", a);
        }
    }
}


void Rscenar(char *ming,char *parameter,int nl){
    int p = 0;
    if (nl > 0){
        printf("\n");
    }

    for (int i = 0; i < (strlen(ming)-1); i++) {
        char a = ming[i];
        if (ming[i] == ' ') {
            p=0;
            printf("%c",a);
        }
        else if (isalnum(a)==0){
            p = 0;
            printf("%c", a);
        }
        else if (p<strlen(parameter)){
            if(isdigit(a)){
                printf("%c", parameter[p]);
                p++;
            }
            else if(isupper(a)==0) {
                printf("%c", tolower(parameter[p]));
                p++;
            }
            else if(isupper(a)>0){
                printf("%c", toupper(parameter[p]));
                p++;
            }
        }
        else{
            printf("%c", a);
        }
    }
}

int main(int argc, char *argv[])
{
    int d = 0;
    int p = 0;
    int u = 0;
    int l = 0;
    int r = 0;
    int R = 0;
    int nl = 0;
    char ming[MAX];
    char parameter[100];
    int neviem = 0;
    int opt;
    char* optstring = ":dpulr:R:";
    
    
    //zisti ktory spinac je zapnuty a zmeni hodnotu premenny zapnuteho spinaca na 1
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'd':
                d++;
                break;
            case 'p':
                p++;
                break;
            case 'u':
                u++;
                break;
            case 'l':
                l++;
                break;
            case 'r':
                strcpy(parameter,optarg);
                r++;
                break;
            case 'R':
                strcpy(parameter,optarg);
                R++;
                break;
            case '?':
                return 1;
            case ':':
                return 2;

        }
    }

    //podla toho ktory je zapnuty vykona sa editovanie textu 
    while (*(fgets(ming, MAX, stdin)) != '\n'){
        if(d==1 && p==1){

        }
        if(d==1 && p==0){
            dscenar(ming);
        }
        if(d==0 && p==1){
            pscenar(ming);
        }
        if(d==0 && p==0){
            clasicscenar(ming);
        }
        if(l==1){
            ll(ming);
        }
        if(u==1){
            ul(ming);
        }
        if(r==1){
            if (optind<argc){
                int p = 0;
                char nahrada[100];
                int pnahrady = 0;
                char kopia[100];
                if (nl > 0){
                    printf("\n");
                }
                for (int i = 0; i < (strlen(ming)-1); i++){
                    char a = ming[i];
                    strncpy(kopia, ming + i, strlen(ming) - i);
                    for(int j=optind;j<argc;j++){
                       strcpy(nahrada, argv[j]);
                       if(strncmp(kopia, nahrada, strlen(nahrada))==0){
                           if(i !=0 ){
                               char anaporovnanie = ming[i-1];
                               if(isalnum(anaporovnanie) != 0){
                                   j=argc;
                               }
                               else{
                                   printf("%c", parameter[p]);
                                   p++;
                                   pnahrady++;
                                   i++;
                                   j=argc;
                               }
                           }
                           else{
                               printf("%c", parameter[p]);
                               p++;
                               pnahrady++;
                               i++;
                               j=argc;
                           }

                       }
                    }
                    a = ming[i];
                    if(a=='\n') {
                        continue;
                    }
                    else if(isalnum(a)==0){
                        printf("%c", ming[i]);
                        p=0;
                        pnahrady=0;
                    }
                    else if(ming[i] == ' '){
                        printf("%c",ming[i]);
                        p=0;
                        pnahrady = 0;
                    }
                    else if(pnahrady>0 && pnahrady<strlen(parameter)){
                        printf("%c",parameter[p]);
                        pnahrady++;
                        p++;
                    }
                    else{
                        printf("%c", a);
                    }
                }
                nl++;

            }
            else{
                rscenar(ming,parameter,nl);
                nl++;
            }
        }
        if(R==1){


            if (optind<argc){
                int p = 0;
                char nahrada[100];
                int pnahrady = 0;
                char kopia[100];
                if (nl > 0){
                    printf("\n");
                }
                for (int i = 0; i < (strlen(ming)-1); i++){
                    char a = ming[i];
                    strncpy(kopia, ming + i, strlen(ming) - i);
                    for(int j=optind;j<argc;j++){
                        strcpy(nahrada, argv[j]);
                        if(strncmp(strupr(kopia), strupr(nahrada), strlen(nahrada))==0) {
                            if(strlen(nahrada)==1 && i !=0 ){
                                char anaporovnanie = ming[i-1];
                                if(isalnum(anaporovnanie) != 0){
                                    j=argc;
                                }
                                else if(isupper(a)==0){
                                    printf("%c", tolower(parameter[p]));
                                    p++;
                                    pnahrady++;
                                    i++;
                                    j=argc;
                                }
                                else if(isupper(a)>0){
                                    printf("%c", toupper(parameter[p]));
                                    p++;
                                    pnahrady++;
                                    i++;
                                    j=argc;
                                }

                            }
                            else if(isdigit(a)){
                                printf("%c", parameter[p]);
                                p++;
                                pnahrady++;
                                i++;
                                j=argc;
                            }
                            else if(isupper(a)==0){
                                printf("%c", tolower(parameter[p]));
                                p++;
                                pnahrady++;
                                i++;
                                j=argc;
                            }
                            else if(isupper(a)>0){
                                printf("%c", toupper(parameter[p]));
                                p++;
                                pnahrady++;
                                i++;
                                j=argc;
                            }
                        }
                    }
                    a = ming[i];
                    if(a=='\n'){
                        continue;
                    }
                    else if(isalnum(a)==0){
                        printf("%c", ming[i]);
                        p=0;
                        pnahrady=0;
                    }
                    else if(ming[i] == ' '){
                        printf("%c",ming[i]);
                        p=0;
                        pnahrady = 0;
                    }
                    else if (p>strlen(parameter)){
                        printf("%c", a);
                    }


                    else if(pnahrady>0 && (pnahrady<strlen(parameter))){
                        if(isdigit(a)){
                            printf("%c", parameter[p]);

                            p++;
                            pnahrady++;
                        }
                        else if(isupper(a)==0){
                            printf("%c", tolower(parameter[p]));
                            p++;
                            pnahrady++;
                        }
                        else if(isupper(a)>0){
                            printf("%c", toupper(parameter[p]));
                            p++;
                            pnahrady++;
                        }
                    }
                    else{
                        printf("%c", a);
                    }
                }
                nl++;

            }
            else{
                Rscenar(ming, parameter, nl);
                nl++;
            }
        }
        else if(r==0 && R==0){
            printf("%s",ming);
        }

    }

    return 0;
}
