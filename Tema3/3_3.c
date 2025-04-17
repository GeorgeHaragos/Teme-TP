#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNDO 100

typedef struct { //structura pentru a salva fiecare modificare in parte
    char text[100];
    int line;
} Modification;

typedef struct { //stiva pentru operatiile de undo
    Modification modifications[MAX_UNDO];
    int top;
} UndoStack;

void initUndoStack(UndoStack* s) { //functie de initializare stiva
    s->top = -1;
}

void pushModification(UndoStack* s, char* text, int line) { //functie de adaugare in stiva
    if (s->top == MAX_UNDO - 1) { //daca avem stiva plina nu mai putem adauga
        printf("Nu mai este loc pentru undo!\n");
        return;
    }
    s->top++;
    strcpy(s->modifications[s->top].text, text);
    s->modifications[s->top].line = line;
}

Modification popModification(UndoStack* s) { //functie de scos din stiva
    if (s->top == -1) { //daca nu avem elemente in stiva nu avem ce scoate
        printf("Nu exista modificari de anulat!\n");
        Modification empty = {"", -1};
        return empty;
    }
    return s->modifications[s->top--];
}

int main() {
    UndoStack *s=(UndoStack *)malloc(sizeof(UndoStack));
    initUndoStack(s);

    pushModification(s, "Primul rand de text.", 1); //introducem in stiva modificarile
    pushModification(s, "Al doilea rand de text.", 2);

    Modification m = popModification(s);
    printf("Anulat: %s de pe randul %d\n", m.text, m.line); //scoatem din stiva modificarile

    m = popModification(s);
    printf("Anulat: %s de pe randul %d\n", m.text, m.line);

    return 0;
}