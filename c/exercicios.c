/**
 * Exercícios do dia 04/09/2013, sobre funções
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define TAM 100

/**
 * FUNÇÕES DO MENU
 */
char get_option() {
    char c;

    puts("Selecione uma opção:\n");
    puts("\t[1] Imprime uma linha");
    puts("\t[2] Função que imprime um valor passado por argumento");
    puts("\t[3] Função que recebe 2 valores e retorne a média");
    puts("\t[4] Função que recebe um char e se não for minúsculo, transformá-lo em tal");
    puts("\t[5] Função que recebe a base e altura de um retângulo, e retorne sua área");
    puts("\t[6] Função que recebe um numero como argumento e retorne seu absoluto");
    puts("\t[7] Função que recebe um vetor e retorne seu menor elemento");
    puts("\t[8] Função que recebe um vetor e retorne duplicar os elementos");
    puts("\t[9] Função que recebe um vetor e retorne-o ordenado");
    puts("\t[0] Sair do programa");

    while((c = getchar()) != '\n')

    return c;
}

void cabecalho() {
    puts("---------------------------------------------------------");
    puts("\tExercícios do dia 04/09/2013 de funções");
    puts("---------------------------------------------------------");
}

void encerra() {
    puts("Encerrando...");
    exit(0);
}

void para() {
    char c;
    while((c = getchar()) != '\n');
    while((c = getchar()) != '\n');
}

/**
 * Limpa a stream stdin
 */
void limpa_stdin(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

/**
 * FUNÇÕES DO EXERCÍCIOS
 */

// ----- Exercício 1 -----
void print_line() {
    puts("---------");
}
// ----- Exercício 1 -----


// ----- Exercício 2 ------
void imprime_argumento(int num) {
    puts("\n---------------- Função ----------------");
    printf("Numero passado --> %d\n", num);
    puts("---------------- Função ----------------\n");
}

void exer_two() {
    int i;
    puts("\nDigite um número para passá-lo como argumento:");

    scanf("%d", &i);

    puts("Passando para a função...");
    imprime_argumento(i);
}
// ----- Exercício 2 ------


// ----- Exercício 3 ------
float media(float num1, float num2) {
    return (num1 + num2) / 2;
}

void exer_three() {
    float a, b;

    puts("\nDigite dois números para calcular sua média:");
    puts("1º Número:");
    scanf("%f", &a);

    puts("2º Número:");
    scanf("%f", &b);

    puts("Passando para a função...");
    printf("Para a = %f e b = %f, a média é: %f\n", a, b, media(a, b));
}
// ----- Exercício 3 ------


// ----- Exercício 4 ------
char minusculo(char l) {
    if(l >= 'A' && l <= 'Z')
        return (l + 'a' - 'A');
    else
        return l;
}

void exer_four() {
    char l;

    limpa_stdin();

    puts("\nDigite um caractere para converter em minúsculo");
    scanf("%c", &l);

    puts("Passando para a função...");
    printf("Caractere passado: %c; Minúscula: %c\n", l, minusculo(l));
}
// ----- Exercício 4 ------


// ----- Exercício 5 ------
float area_retangulo(float base, float altura) {
    return (base * altura);
}

void exer_five() {
    float b, a;

    puts("\nDigite a base e altura de um retângulo para calcular sua área:");
    puts("Digite a base:");
    scanf("%f", &b);

    puts("Digite a altura:");
    scanf("%f", &a);

    puts("Passando para a função...");
    printf("Base: %f, Altura: %f, Área: %f\n", b, a, area_retangulo(b, a));
}
// ----- Exercício 5 ------

// ----- Exercício 6 ------
float absoluto(int num) {

    int i;

    if(num > 0)
        return num;
    else {
        i = num * (-1);
        return i;
    }

}

void exer_six() {
    int a;

    puts("\nDigite um número para achar seu absoluto:");
    scanf("%d", &a);

    puts("Passando para a função...");
    printf("Número: %d, Absoluto: %5.2f\n", a, absoluto(a));
}
// ----- Exercício 6 ------


// ----- Exercício 7 ------
int min(int nums[], int tam) {

    int min, i, pos = 0;

    for(i = 0; i < tam; i++) {
        min = nums[i];

        if(nums[i + 1] < min)
            min = nums[i + 1];
    }

    return min;   

}

void exer_seven() {
    int tam = (TAM - 90), a[tam], i, aux;

    puts("\nDigite uma lista de números para achar seu menor:");

    for(i = 0; i < tam; i++) {
        printf("Nº%d: \n", i);
        scanf("%d", &a[i]);
    }

    puts("Passando para a função...");
    printf("Menor: %d\n", min(a, tam));
}
// ----- Exercício 7 ------


// ----- Exercício 8 ------
void duplica(int nums[], int tam) {

    int min, i;

    for(i = 0; i <= tam; i++) {
        nums[i] *= 2;
    }

}

void exer_eight() {
    int tam = TAM - 80;
    int a[tam], i, aux;

    puts("\nDigite uma lista de números para duplicá-los:");

    for(i = 0; i < tam; i++) {
        printf("Nº%d: \n", i);
        scanf("%d", &a[i]);
    }

    puts("Passando para a função...");
    duplica(a, tam);

    puts("+-----+");
    for(i = 0; i < tam; i++) {
        printf("|  %d  |\n", a[i]);
        puts("+-----+");
    }
}
// ----- Exercício 8 ------


// ----- Exercício 9 ------
void ordena(int nums[], int tam) {
    int i = tam, j, aux;
    while(i >= 0) {
        for (j = i; j < tam; j++)
            if(nums[j] > nums[j + 1]) {
                printf("Val atual: %d", nums[i]);
                aux = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = aux;
            }
        i--;
    }   
}

void imprime(int nums[], int tam){
    int i;
    for(i = 0; i < tam; i++)
        printf("+-----");
    putchar('\n');
    for (i = 0; i < tam; ++i) {
        printf("|%4d ", nums[i]);
    }
    putchar('|');
    putchar('\n');
    for(i = 0; i < tam; i++)
        printf("+-----");
    putchar('\n');
}

void exer_nine() {
    int tam = TAM - 90, i;
    int a[tam];
    puts("Digite os valores para ordenação:");

    for(i = 0; i < tam; i++) {
        printf("Valor: %d\n", i + 1);
        scanf("%d", &a[i]);
    }

    puts("Passando pra função...");
    ordena(a, i);

    puts("\nImprimindo...");
    imprime(a, i);

}

int main() {

    while(1) {
        system("clear");

        cabecalho();

        switch (get_option()) {
        case '1':
            print_line();
            break;
        case '2':
            exer_two();
            break;
        case '3':
            exer_three();
            break;
        case '4':
            exer_four();
            break;
        case '5':
            exer_five();
            break;
        case '6':
            exer_six();
            break;
        case '7':
            exer_seven();
            break;
        case '8':
            exer_eight();
            break;
        case '9':
            exer_nine();
            break;
        case '0':
            encerra();
            break;
        }

        para();
    }

    return 0;
}