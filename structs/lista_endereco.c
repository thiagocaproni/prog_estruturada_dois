#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct addr {
    char name[30];
    char street [40];
    char city [20];
    char state [3];
    unsigned long int zip;
}addr_info[MAX];

void init_list(void); 
void enter(void);
void delete(void); 
void list(void);
int menu_select(void); 
int find_free(void );

int main(void){
    char choice;
    init_list(); /* inicializa */
    for (;;) {
        choice = menu_select ();
        switch (choice) {
            case 1: enter();
                    break;
            case 2: delete();
                    break ;
            case 3: list();
                    break ;
            case 4: exit (0);
        }
    }
}

/* Inicializa a lista */
void init_list(void) {
    register int t;
    for(t = 0; t < MAX; ++t)
        addr_info[t].name[0] ='\0';
}

int menu_select (void) {
    char s[80];
    int c;

    printf("1. Inserir um nome \n");
    printf("2. Excluir um nome \n");
    printf("3. Listar o arquivo \n");
    printf("4. Sair \n");
    do {
        printf ("\nDigite sua escolha:");
        fgets(s,sizeof(s),stdin); 
        c = atoi(s);
    }while(c < 0 || c > 4);

    return c;
}

int find_free (void) {
    register int t;
    for (t = 0; addr_info[t].name[0] && t < MAX ; ++t);
    
    if (t == MAX ) /* nenhum elemento livre */
        return -1;
    return t;
}

void enter ( void ) {
    int slot ;
    char s[80];
    slot = find_free();
    if ( slot == -1) {
        printf ("\nLista cheia ");
        return;
    }

    printf ("Digite o nome: ");
    fgets(addr_info[slot].name, sizeof(addr_info[slot].name), stdin);
    strtok(addr_info[slot].name, "\n");
    printf("Digite a rua: ");
    fgets(addr_info[slot].street, sizeof(addr_info[slot].street), stdin);
    strtok(addr_info[slot].street, "\n");
    printf("Digite a cidade: ");
    fgets (addr_info[slot].city,sizeof(addr_info[slot].city), stdin);
    strtok(addr_info[slot].city, "\n");
    printf ("Digite o estado: ");
    fgets(addr_info[slot].state,sizeof(addr_info[slot].state), stdin);
    strtok(addr_info[slot].state, "\n");
    printf ("Digite o cep: ");
    fgets(s, sizeof(s), stdin);
    strtok(s, "\n");
    scanf("%ld%*c", &addr_info[slot].zip);
}

void delete (void) {
    register int slot ;
    char s[80];
    printf("Digite o registro #: ");
    fgets(s, sizeof(s), stdin);
    slot = atoi(s);
    if (slot >= 0 && slot < MAX )
        addr_info [slot].name[0] = '\0';
}

void list ( void ) {
    register int t;
    for (t = 0; t < MAX; ++t) {
        if (addr_info[t].name[0]) {
            printf ("%s\n", addr_info[t].name);
            printf ("%s\n", addr_info[t].street);
            printf ("%s\n", addr_info[t].city);
            printf ("%s\n", addr_info[t].state);
            printf ("%ld\n", addr_info[t].zip);
        }
    }
    printf ("\n\n");
}