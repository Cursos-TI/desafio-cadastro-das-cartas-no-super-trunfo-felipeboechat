/*
 * Desafio Super Trunfo - Países
 * Nível: Novato
 * Tema: Cadastro das Cartas
 * 
 * Este programa implementa um sistema básico de cadastro de cartas para o jogo Super Trunfo.
 * O usuário pode cadastrar duas cartas, cada uma representando uma cidade com seus atributos.
 * 
 * Autor: Felipe Boechat
 * Data: 2024
 */

#include <stdio.h>

int main() {
    // Declaração das variáveis para a Carta 1
    char estado1;           // Letra do estado (A-H)
    char codigo1[4];        // Código da carta (ex: A01)
    char nomeCidade1[50];   // Nome da cidade
    int populacao1;         // População da cidade
    float area1;            // Área em km²
    float pib1;             // PIB em bilhões de reais
    int pontosTuristicos1;  // Número de pontos turísticos

    // Declaração das variáveis para a Carta 2
    char estado2;           // Letra do estado (A-H)
    char codigo2[4];        // Código da carta (ex: A01)
    char nomeCidade2[50];   // Nome da cidade
    int populacao2;         // População da cidade
    float area2;            // Área em km²
    float pib2;             // PIB em bilhões de reais
    int pontosTuristicos2;  // Número de pontos turísticos

    // Mensagem de boas-vindas
    printf("=== Super Trunfo - Cadastro de Cartas ===\n\n");

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &estado1);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade1);
    
    printf("Digite a população: ");
    scanf("%d", &populacao1);
    
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    
    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &pib1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo2);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade2);
    
    printf("Digite a população: ");
    scanf("%d", &populacao2);
    
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    
    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Exibição dos dados das cartas
    printf("\n=== RESULTADO DO CADASTRO ===\n");
    printf("┌─────────────────────────────────────────────────────────────\n");
    printf("│ CARTA 1\n");
    printf("├─────────────────────────────────────────────────────────────\n");
    printf("│ Estado: %c\n", estado1);
    printf("│ Código: %-4s\n", codigo1);
    printf("│ Cidade: %s\n", nomeCidade1);
    printf("│ População: %d habitantes\n", populacao1);
    printf("│ Área: %.2f km²\n", area1);
    printf("│ PIB: %.2f bilhões de reais\n", pib1);
    printf("│ Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("└─────────────────────────────────────────────────────────────\n\n");

    printf("┌─────────────────────────────────────────────────────────────\n");
    printf("│ CARTA 2\n");
    printf("├─────────────────────────────────────────────────────────────\n");
    printf("│ Estado: %c\n", estado2);
    printf("│ Código: %-4s\n", codigo2);
    printf("│ Cidade: %s\n", nomeCidade2);
    printf("│ População: %d habitantes\n", populacao2);
    printf("│ Área: %.2f km²\n", area2);
    printf("│ PIB: %.2f bilhões de reais\n", pib2);
    printf("│ Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("└─────────────────────────────────────────────────────────────\n");

    printf("\n=== FIM DO CADASTRO ===\n");

    return 0;
}
