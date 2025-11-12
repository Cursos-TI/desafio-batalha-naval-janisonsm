#include <stdio.h>

#define TAM_TABULEIRO 10   // tamanho fixo do tabuleiro 10x10
#define TAM_NAVIO 3        // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]; // matriz do tabuleiro
    int i, j;

    // -------------------------------
    // 1. Inicializa o tabuleiro com 0 (água)
    // -------------------------------
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------------
    // 2. Definição dos navios (vetores com valor 3)
    // -------------------------------
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // -------------------------------
    // 3. Definir coordenadas iniciais
    // -------------------------------
    int linhaH = 2; // linha inicial do navio horizontal
    int colunaH = 4; // coluna inicial do navio horizontal

    int linhaV = 5; // linha inicial do navio vertical
    int colunaV = 7; // coluna inicial do navio vertical

    // -------------------------------
    // 4. Validação de limites
    // -------------------------------
    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // -------------------------------
    // 5. Verificação de sobreposição
    // -------------------------------
    int sobreposicao = 0;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] == 3) sobreposicao = 1;
        if (tabuleiro[linhaV + i][colunaV] == 3) sobreposicao = 1;
    }

    if (sobreposicao) {
        printf("Erro: os navios se sobrepõem!\n");
        return 1;
    }

    // -------------------------------
    // 6. Posiciona o navio horizontal
    // -------------------------------
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // -------------------------------
    // 7. Posiciona o navio vertical
    // -------------------------------
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // -------------------------------
    // 8. Exibe o tabuleiro
    // -------------------------------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n0 = Água | 3 = Navio\n");
    printf("Navio horizontal começa em (%d,%d)\n", linhaH, colunaH);
    printf("Navio vertical começa em (%d,%d)\n", linhaV, colunaV);

    return 0;
}