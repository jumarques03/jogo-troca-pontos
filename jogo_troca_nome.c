//Bibliotecas
#include <stdio.h>
#include <stdlib.h>    //Permite a utilização das funções exit() e system ()
#include <unistd.h>    //Permite a utilização da função sleep()

//Inicialização das variáveis e ponteiros
int opcao;

int pontos_jogador01 = 0;
int pontos_jogador02 = 0;
int *ptr_pontos01 = &pontos_jogador01;
int *ptr_pontos02 = &pontos_jogador02;

char jogador01[20] = "Jogador 01";
char jogador02[20] = "Jogador 02";
char *ptr_jogador01 = jogador01;
char *ptr_jogador02 = jogador02;

int lista_pontos_jogador01[] = {1, 2, 3};
int lista_pontos_jogador02[] = {4, 5, 6};
int tamanho_lista = 3;

int *ptr_lista_jogador01 = lista_pontos_jogador01;
int *ptr_lista_jogador02 = lista_pontos_jogador02;

int soma_jogador01 = 0;
int soma_jogador02 = 0;
int *ptr_soma01 = &soma_jogador01;
int *ptr_soma02 = &soma_jogador02;

//Função responsável por limpar a tela do terminal
void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Função responsável por exibir o menu principal do jogo
void exibirMenu() {
    printf("--- JOGO DA TROCA: PONTEIROS EM AÇÃO ---\n\n");
    printf("1. Trocar listas de pontos entre jogadores\n");
    printf("2. Somar os pontos\n");
    printf("3. Ver quem está vencendo\n");
    printf("4. Alterar ponto de um jogador\n");
    printf("5. Mostrar endereços de memória\n");
    printf("6. Sair\n\n");
}

//Função responsável por somar os pontos dos jogadores sem exibir os resultados
void somar(int *a, int *b, int *lista1, int *lista2, int tamanho) {
    *ptr_soma01 = 0;
    *ptr_soma02 = 0;

    for (int i = 0; i < tamanho; i++) {
        *ptr_soma01 += lista1[i];
        *ptr_soma02 += lista2[i];
    }
}

//Função responsável por somar os pontos dos jogadores exibindo os resultados
void somarComPrint(int *a, int *b, int *lista1, int *lista2, int tamanho) {
    somar(a, b, lista1, lista2, tamanho);

    limpar();
    printf("Soma dos pontos do Jogador01: %d\n", *ptr_soma01);
    printf("Soma dos pontos do Jogador02: %d\n\n", *ptr_soma02);
    printf("Voltando para o menu inicial automaticamente em 7s!\n");
    sleep(7);
}

//Função responsável por mostrar quem está vencendo 
void mostrarVencedor(int *a, int *b, char *c, char *d) {
    limpar();
    printf("Mostrando quem está vencendo:\n\n");

    if (*a > *b)
        printf("O %s está vencendo com %d pontos!\n\n", c, *a);
    else if (*b > *a)
        printf("O %s está vencendo com %d pontos!\n\n", d, *b);
    else
        printf("Os jogadores estão empatados!\n\n");

    printf("Voltando para o menu inicial automaticamente em 7s!\n");
    sleep(7);
}

//Função responsável pela troca das listas pontos entre os jogadores
void trocarPontos(int *a, int *b, int *lista1, int *lista2, int tamanho) {
    limpar();
    printf("Trocando listas de pontos entre os jogadores!\n\n");

    int *temp = ptr_lista_jogador01;
    ptr_lista_jogador01 = ptr_lista_jogador02;
    ptr_lista_jogador02 = temp;

    // Atualiza valores internamente, mas sem exibir nada
    somar(a, b, ptr_lista_jogador01, ptr_lista_jogador02, tamanho);

    printf("Listas trocadas com sucesso!\n\n");
    printf("Voltando para o menu inicial automaticamente em 7s!\n");
    sleep(7);
}

//Função responsável pela alteração os pontos de um jogador
void alterarValor(int *a, int *b, int *lista1, int *lista2, int tamanho){
    int opcao_jogador;

    do {
        limpar();
        printf("Altere os pontos de um jogador:\n");
        printf("1. Jogador 01 (pontos totais)\n");
        printf("2. Jogador 02 (pontos totais)\n\n");
        printf("3. Jogador 01 (ponto específico)\n");
        printf("4. Jogador 02 (ponto específico)\n\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao_jogador);

        switch (opcao_jogador) {
            case 1:
                limpar();
                printf("Insira o novo valor: ");
                scanf("%d", a);
                printf("Ponto alterado com sucesso!\n\n");
                sleep(3);
                return;

            case 2:
                limpar();
                printf("Insira o novo valor: ");
                scanf("%d", b);
                printf("Ponto alterado com sucesso!\n\n");
                sleep(3);
                return;

            case 3: {
                int indice01, novo_valor01;
                limpar();
                printf("Digite o índice a alterar (0 a %d): ", tamanho - 1);
                scanf("%d", &indice01);
                
                if (indice01 < 0 || indice01 >= tamanho) {
                    printf("Índice inválido!\n");
                    sleep(3);
                    return;
                }
                
                printf("Novo valor: ");
                scanf("%d", &novo_valor01);
                
                lista1[indice01] = novo_valor01;
                somar(a, b, lista1, lista2, tamanho);
                printf("Valor alterado com sucesso!\n\n");
                sleep(3);
                return;
            }

            case 4: {
                int indice02, novo_valor02;
                limpar();
                printf("Digite o índice a alterar (0 a %d): ", tamanho - 1);
                scanf("%d", &indice02);
                
                if (indice02 < 0 || indice02 >= tamanho) {
                    printf("Índice inválido!\n");
                    sleep(3);
                    return;
                }
                
                printf("Novo valor: ");
                scanf("%d", &novo_valor02);
                
                lista2[indice02] = novo_valor02;
                somar(a, b, lista1, lista2, tamanho);
                printf("Valor alterado com sucesso!\n\n");
                sleep(3);
                return;
            }

            default:
                printf("Opção inválida!\n");
                sleep(3);
                break;
        }
    } while (1);
}
//Função responsável por mostrar os endereços de memória 
void mostrarEnderecos(int *ptr_a, int *ptr_b, char *ptr_c, char *ptr_d, int *ptr_e, int *ptr_f){
    limpar();

    printf("Endereço de 'pontos_jogador01': %p\n", &pontos_jogador01);
        printf("Endereço de 'ptr_pontos01': %p\n\n", ptr_a);

        printf("Endereço de 'pontos_jogador02': %p\n", &pontos_jogador02);
        printf("Endereço de 'ptr_pontos02': %p\n\n", ptr_b);

        printf("Endereço de 'jogador01': %p\n", jogador01);
        printf("Endereço de 'ptr_jogador01': %p\n\n", ptr_c);

        printf("Endereço de 'jogador02': %p\n", jogador02);
        printf("Endereço de 'ptr_jogador02': %p\n\n", ptr_d);

        printf("Endereço de 'lista_pontos_jogador01': %p\n", lista_pontos_jogador01);
        printf("Endereço de 'ptr_lista_jogador01': %p\n\n", ptr_e);

        printf("Endereço de 'lista_pontos_jogador02': %p\n", lista_pontos_jogador02);
        printf("Endereço de 'ptr_lista_jogador02': %p\n\n", ptr_f);

        printf("Voltando para o menu inicial automaticamente em 15s!\n");
        sleep(15);
}


//Função responsável pela seleção da opção escolhida
void opcao_selecionada() {
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            trocarPontos(ptr_pontos01, ptr_pontos02, ptr_lista_jogador01, ptr_lista_jogador02, tamanho_lista);
            break;
        case 2:
            somarComPrint(ptr_pontos01, ptr_pontos02, ptr_lista_jogador01, ptr_lista_jogador02, tamanho_lista);
            break;
        case 3:
            mostrarVencedor(ptr_soma01, ptr_soma02, ptr_jogador01, ptr_jogador02);
            break;
        case 4:
            alterarValor(ptr_pontos01, ptr_pontos02, ptr_lista_jogador01, ptr_lista_jogador02, tamanho_lista);
            break;
        case 5:
            mostrarEnderecos(ptr_pontos01, ptr_pontos02, ptr_jogador01 ,ptr_jogador02, ptr_lista_jogador01, ptr_lista_jogador02);
            break;
        case 6:
            exit(0);
        default:
            printf("Opção inválida!\n");
            sleep(3);
            break;
    }
}

//Função principal do programa
int main() {
    do {
        limpar();
        exibirMenu();
        opcao_selecionada();
    } while (1);

    return 0;
}