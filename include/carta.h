#ifndef CARTA_H
#define CARTA_H

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char estado[3];                    // Estado (ex: "SP")
    char codigo[4];                    // Código da carta (ex: "A01")
    char nome_cidade[50];              // Nome da cidade/país
    int populacao;                     // População
    float area;                        // Área em km²
    float pib;                         // PIB em bilhões
    int pontos_turisticos;             // Número de pontos turísticos
    float densidade_populacional;      // Densidade populacional (calculada)
    float pib_per_capita;             // PIB per capita (calculado)
};

// Enumeração para os atributos disponíveis para comparação
typedef enum {
    POPULACAO = 1,
    AREA = 2,
    PIB = 3,
    PONTOS_TURISTICOS = 4,
    DENSIDADE_POPULACIONAL = 5,
    PIB_PER_CAPITA = 6
} AtributoComparacao;

// Declarações das funções
void lerCarta(struct Carta* carta, int numeroCarta);
void calcularAtributosDerivativos(struct Carta* carta);
void exibirCarta(struct Carta carta, int numeroCarta);
void exibirMenu();
void exibirMenuDinamico(int atributoJaEscolhido);
int lerOpcaoMenu();
void compararUmAtributo(struct Carta carta1, struct Carta carta2, int atributo);
void compararDoisAtributos(struct Carta carta1, struct Carta carta2, int atributo1, int atributo2);
float obterValorAtributo(struct Carta carta, int atributo);
const char* obterNomeAtributo(int atributo);
const char* obterUnidadeAtributo(int atributo);
int determinarVencedor(float valor1, float valor2, int atributo);
void exibirResultadoComparacao(struct Carta carta1, struct Carta carta2, int atributo, float valor1, float valor2, int vencedor);
void exibirResultadoComparacaoCompleta(struct Carta carta1, struct Carta carta2, int atributo1, int atributo2, 
                                      float valor1_attr1, float valor1_attr2, float valor2_attr1, float valor2_attr2,
                                      float soma1, float soma2, int vencedorFinal);
int menuPrincipal();

#endif