#include <stdio.h>
#include "../include/carta.h"

int main() {
    struct Carta carta1, carta2;
    
    // Leitura da primeira carta
    printf("\nInsira os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Código (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta1.nome_cidade);
    printf("População: ");
    scanf("%d", &carta1.populacao_cidade);
    printf("Área (km²): ");
    scanf("%f", &carta1.area_cidade);
    printf("PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);

    // Cálculos da primeira carta
    carta1.densidade_populacional = carta1.populacao_cidade / carta1.area_cidade;
    carta1.pib_per_capita = (carta1.pib * 1000000000.0) / carta1.populacao_cidade; // Convertendo bilhões para reais

    // Leitura da segunda carta
    printf("\nInsira os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Código (ex: A01): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta2.nome_cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao_cidade);
    printf("Área (km²): ");
    scanf("%f", &carta2.area_cidade);
    printf("PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);

    // Cálculos da segunda carta
    carta2.densidade_populacional = carta2.populacao_cidade / carta2.area_cidade;
    carta2.pib_per_capita = (carta2.pib * 1000000000.0) / carta2.populacao_cidade; // Convertendo bilhões para reais

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome_cidade);
    printf("População: %d\n", carta1.populacao_cidade);
    printf("Área: %.2f km²\n", carta1.area_cidade);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pib_per_capita);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome_cidade);
    printf("População: %d\n", carta2.populacao_cidade);
    printf("Área: %.2f km²\n", carta2.area_cidade);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pib_per_capita);

    return 0;
}