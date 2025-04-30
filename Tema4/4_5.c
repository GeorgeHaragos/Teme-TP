#include <stdio.h>

struct Medicament{
    unsigned int varsta:5; // nr mai mic de 32 
    unsigned int grad:2; // 0- scazut, 1- mediu, 2- mare
    unsigned int reteta:1; // 0- nu, 1- da
};
int main(void){
    struct Medicament medicament;
    unsigned int grad_input, reteta_input, varsta_input;
    printf("Spatiul ocupat este de %lu octeti\n",sizeof(struct Medicament)); //din cauza alinierii ocupam 4 octeti desi ne-am astepta sa avem doar un singur octet avand in vedere faptul ca noi ocupam doar 8 biti
    do{
    printf("Introduceti gradul de periculozitate a medicamentului (0- scazut, 1- mediu, 2- mare):\n");
    scanf("%u",&grad_input);
    }while(grad_input<0 || grad_input>2); //citim pana avem o valoare corespunzatoare
    medicament.grad=grad_input;
    do{
        printf("Specificati daca este nevoie sau nu de reteta (0- nu, 1- da):\n");
        scanf("%u",&reteta_input);
    }while(reteta_input<0 || reteta_input>1); //citim pana avem o valoare corespunzatoare
    medicament.reteta=reteta_input;
    do{
        printf("Introduceti varsta minima de administrare (0-18 ani):\n");
        scanf("%u",&varsta_input);
    }while(varsta_input<0 || varsta_input>18); //citim pana avem o valoare corespunzatoare
    medicament.varsta=varsta_input;
    printf("Gradul de periculozitate este: ");
    switch(medicament.grad){ //tiparim gradul medicamentului
        case 0: printf("scazut\n");break;
        case 1: printf("mediu\n");break;
        case 2: printf("mare\n");break;
    }
    if(medicament.reteta) //tiparim daca este nevoie sau nu de reteta
    printf("Este nevoie de reteta!\n");
    else
    printf("NU este nevoie de reteta!\n");
    
    printf("Varsta minima de administrare este de %u ani.\n",medicament.varsta);
    return 0;
}
