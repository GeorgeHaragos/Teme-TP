#include <stdio.h>
#include <string.h>
#define MAX_NUME 20

struct Student{
  char nume[MAX_NUME] ;
  float nota;
};

int main(void){
  struct Student student;
  printf("Introduceti numele studentului:\n");
  fgets(student.nume,sizeof(student.nume),stdin);
  student.nume[strcspn(student.nume,"\n")]='\0';//eliminam new lineul din numele studentului
  printf("Introduceti nota studentului:\n");
  scanf("%f",&student.nota);
  printf("Studentul %s are nota %0.2f.\n",student.nume,student.nota); //precizam ca numarul float printat sa aibe 2 zecimale exacte
  return 0;
}

