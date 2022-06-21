#include <stdio.h>
#include <malloc.h>
#include<string.h>
typedef struct stosik{
    char znak;
    struct stosik *nast;
}stos;

void dodaj(stos **head, char znak){
    stos * nowy = malloc(sizeof(stos));
    nowy -> znak = znak;

    if(*head == NULL){
        *head = nowy;
    }
    else{
        stos *n = *head;
        while(n -> nast !=NULL){
            n = n -> nast;
        }
    }
    nowy -> nast =NULL;

}
void usun_element_stosu(stos *head){
    stos *n = head;
    while(n-> nast != NULL){
        n = n->nast;
    }
    free(n);
}
void wypisz(stos *head){
    stos *n = head;
    while(n-> nast != NULL){
        n = n->nast;
    }
    printf("%c", n->znak);
    usun_element_stosu(head);
}

void usun_znaki(char *tab) {
    char korektor[] = " +*-=()/";
    char *schowek;
    schowek = strtok(tab, korektor);
    while (schowek != NULL) {
        printf("%s\n", schowek);
        schowek = strtok(NULL, korektor);
    }
}
void dodaj_znaki_do_stosu(int *tab) {
    char korektor[] = "1234567890() ";
    char *schowek = malloc(sizeof(schowek));
    stos *head = NULL;
    schowek = strtok(tab, korektor);
    while (schowek != NULL) {
        dodaj(&head, schowek);
        //schowek = strtok(NULL, korektor);
    }
wypisz(head);

//        for (int i = 0; i < 10; i++) {
//            dodaj(&head, schowek[i]);
//            printf("\n");
//            wypisz(head);
//
//        }

    }
    int main(int argc, char **argv) {

    printf("%s", argv[1]);
        dodaj_znaki_do_stosu(argv[1]);


    return 0;
}
