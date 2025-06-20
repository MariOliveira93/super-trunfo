#ifndef CARTA_H
#define CARTA_H

struct Carta {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    int populacao_cidade;
    float area_cidade;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

#endif