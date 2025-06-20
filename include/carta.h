#ifndef CARTA_H
#define CARTA_H

struct Carta {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    unsigned long int populacao_cidade;  // Changed from int to unsigned long int
    float area_cidade;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;  // Added Super Poder field
};

// Function declarations
void lerCarta(struct Carta* carta, int numeroCarta);
void calcularAtributos(struct Carta* carta);
void calcularSuperPoder(struct Carta* carta);
void compararCartas(struct Carta carta1, struct Carta carta2);
void exibirCarta(struct Carta carta, int numeroCarta);

#endif