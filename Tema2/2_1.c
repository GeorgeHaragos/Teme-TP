#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[50];
    float nota;
} Student;



int compara_studentii(const void *a, const void *b) { //functie pentru sortarea descrescatoare a notelor pentru apelul qsort
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s2->nota != s1->nota) //daca nota din structura s2 este mai mare ca cea din prima atunci s1 este inversat cu s2 (1 - trebuie schimbate, -1 - sunt ordonate corect)
        return (s2->nota > s1->nota) - (s2->nota < s1->nota);
    return strcmp(s1->nume, s2->nume); //daca au aceeasi nota atunci structurile vor fi ordonate alfabetic dupa structura "nume", strcmp da return perfect pentru lucrul cu qsort (1 - daca al doilea argument este inainte primului, 0 - daca sunt egale, -1 - daca sunt ordonate corect)
}


int main() {
    int n;
    char nume[50];
    printf("Numarul de studenti: ");
    scanf("%d", &n);
    Student studenti[n]; //creem un array de structuri de tip Student pentru a stoca informatiile pentru fiecare student in parte (nume si nota)
    for (int i = 0; i < n; i++) {
        printf("Introduceti numele studentului %d:\n",i+1);
        getchar();//clear la buffer deoarece se regaseste un caracter '\n' aici,
        fgets(nume,50,stdin); //consideram ca numele va fi introdus de la tastatura si pe un rand intreg
        strcpy(studenti[i].nume,nume);
        (studenti[i].nume)[strcspn(studenti[i].nume,"\n")]='\0'; //eliminam newlineul din nume
        printf("Introduceti nota studentului %d: ",i+1); 
        scanf("%f",&studenti[i].nota);//citim nota direct in structura
    }
    qsort(studenti, n, sizeof(Student), compara_studentii); //folosim qsort pentru a sorta arrayul de structuri
    printf("Rezultate sortate:\n");
    for (int i = 0; i < n; i++)
        printf("Nume: %s, Nota: %.2f\n", studenti[i].nume, studenti[i].nota); //afisam numele si nota (numar float cu 2 zecimale exacte)
    return 0;
}
