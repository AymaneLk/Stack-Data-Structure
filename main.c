#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule Cellule;
struct Cellule{
    int val;
    Cellule *suivant;
};

Cellule *creer_cellule(int val)
{
    Cellule *c = (Cellule *)malloc(sizeof(Cellule));
    c->val = val;
    c->suivant = NULL;

    return c;
}

Cellule *empiler(Cellule *debut, int val)
{
    Cellule *nouveau = creer_cellule(val);

    if(nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->suivant = debut;
    debut = nouveau;

    return debut;
}

Cellule *depiler(Cellule *debut)
{
    if(debut == NULL)
    {
        printf("La pile est vide");
        exit(EXIT_FAILURE);
    }

    Cellule *elementDepile = debut;
    debut = elementDepile->suivant;
    free(elementDepile);

    return debut;
}

void afficherPile(Cellule *debut)
{
    if(debut == NULL)
        exit(EXIT_FAILURE);

    Cellule *elementActuel = debut;

    while(elementActuel != NULL)
    {
        printf("\t%d\n", elementActuel->val);
        elementActuel = elementActuel->suivant;
    }
}

int main()
{
    Cellule *pile = NULL;

    pile = empiler(pile, 1);
    pile = empiler(pile, 2);
    pile = empiler(pile, 3);
    pile = empiler(pile, 4);
    pile = empiler(pile, 5);

    printf("Etat de la pile:\n");
    afficherPile(pile);

    printf("\nJe depile %d\n", pile->val);
    pile = depiler(pile);
    printf("Je depile %d\n", pile->val);
    pile = depiler(pile);

    printf("\nEtat de la pile:\n");
    afficherPile(pile);
}