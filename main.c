//******************************************************
/*

Trabalho 1. ARQUITETURA E ORGANIZACAO DE COMPUTADORES I 
------------------------------------------------------
Nomes: 
  André Luiz Montanha
  Daniel Lopes Dienstmann   
  Laura Aparecida Oliveira Silva Soares

*/
//******************************************************

// Inclusão de bibs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 42

// Definindo estrutura (lista) de instruções que serão inseridas
typedef struct instrucao_t{
    char instrucao [6];
    char reg1[20];
    char reg2[20];
    char reg3[20];
    struct instrucao_t *prox;
} instrucao_t;

void imprimeCod(char *RegDst, char *RegWrite, char *ALUSrca, char *MemRead, char *MemWrite, char *MemToReg, char *IorD, char *IRWrite, char *PCWrite, char *PCWriteCond, char *ALUop, char *ALUSrcb, char *PCSrc, char *funcao){
  printf("\n\nO codigo da %s é:", funcao);

  printf("\n  RegDst: %s", RegDst);
  printf("\n  RegWrite: %s", RegWrite);
  printf("\n  ALUSrca: %s", ALUSrca);
  printf("\n  MemRead: %s", MemRead);
  printf("\n  MemWrite: %s", MemWrite);
  printf("\n  MemToReg: %s", MemToReg);
  printf("\n  IorD: %s", IorD);
  printf("\n  IRWrite: %s", IRWrite);
  printf("\n  PCWrite: %s", PCWrite);
  printf("\n  PCWriteCond: %s", PCWriteCond);
  printf("\n  ALUop: %s", ALUop);
  printf("\n  ALUSrcb: %s", ALUSrcb);
  printf("\n  PCSrc: %s\n", PCSrc);
}

// Função para efetuar a busca da instrução com base na entrada de dados
void buscaInstrucao(instrucao_t *instrucao, char *entrada){
    char *token = NULL; // inicializa ponteiro de token
    char separacao[] = ", "; // o que separa cada termo da instrução

    if (entrada[strlen(entrada)-1] == '\n') {
        entrada[strlen(entrada)-1] = '\0';
    }

    token = strtok(entrada, separacao); // faz as divisões na variavel token
    sprintf(instrucao->instrucao, "%s", token); // define na variavel estruturada a operação (primeira informação de token)

    token = strtok(NULL, separacao); // retira primeira informação da variável token e salva
    sprintf(instrucao->reg1, "%s", token); // define na variavel estruturada em reg1 a primeira informação de token

    token = strtok(NULL, separacao); // retira primeira informação da variável token e salva

    // verifica se token possui mais informação (se sim, ele armazena em reg2 na variavel estruturada)
    if(token != NULL){
        sprintf(instrucao->reg2, "%s", token); // define na variavel estruturada em reg2 a primeira informação de token
    } else{
        instrucao->reg2[0] = '\0';
    }

    token = strtok(NULL, separacao); // retira primeira informação da variável token e salva

    // verifica se token possui mais informação (se sim, ele armazena em reg3 na variavel estruturada)
    if(token != NULL){
        sprintf(instrucao->reg3, "%s", token); // define na variavel estruturada em reg3 a primeira informação de token
    } else{
        instrucao->reg3[0] = '\0';
    }

    token = strtok(NULL, separacao); // retira primeira informação da variável token e salva
    
    fflush(stdin); // limpando o buffer do teclado

    printf("\nBusca da instrução %s %s", instrucao->instrucao, instrucao->reg1); // mostra instrução e primeiro registro

    // caso exista o segundo registrador mostra ele
    if (instrucao->reg2[0] != '\0'){
        printf(", %s", instrucao->reg2);
    }

    // caso exista o terceiro registrador mostra ele
    if (instrucao->reg3[0] != '\0'){
        printf(", %s", instrucao->reg3);
    }

    printf(" da memória de instruções.\n");


    // VERIFICAÇÃO PARA O COD

    imprimeCod("NULL", "NULL", "0", "1", "NULL", "NULL", "0", "1", "1", "NULL", "00", "01", "00", "Busca");

}

// Função que decodifica a instrução
void decodificaInstrucao(instrucao_t *instrucao) {
    //char *RegDst, *RegWrite, *ALUSrca, *MemRead, *MemWrite, *MemToReg, *IorD, *IRWrite, *PCWrite, *PCWriteCond, *ALUop, *ALUSrcb, *PCSrc;

    imprimeCod("NULL", "NULL", "0", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "00", "11", "NULL", "Decodificacao");
}

// Função de execução das operações inseridas nas instruções
void execucao(instrucao_t *instrucao, int *ciclos) {
    if(strcmp(instrucao->instrucao, "add") == 0){ // verifica se instrução é ADD
        printf("\nUsa a ULA para calcular a soma dos valores armazenados nos registradores (%s e %s) e armazena no registrador %s.\n", instrucao->reg2, instrucao->reg3, instrucao->reg1);

        (*ciclos) = (*ciclos) + 4;

        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "010", "00", "NULL", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "sub") == 0){ // verifica se instrução é SUB
        printf("\nUsa a ULA para calcular a subtração dos valores armazenados nos registradores (%s e %s) e armazena no registrador %s.\n", instrucao->reg2, instrucao->reg3, instrucao->reg1);
        
        (*ciclos) = (*ciclos) + 4;
        
        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "110", "00", "NULL", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "slt") == 0){ // verifica se instrução é SLT
        printf("\nUsa a ULA para compar se um numero e menor que o outro (%s e %s) e vai para o registrador %s.\n", instrucao->reg2, instrucao->reg3, instrucao->reg1);
        
        (*ciclos) = (*ciclos) + 4;
        
        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "000", "00", "NULL", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "sw") == 0){ // verifica se instrução é SW
        printf("\nUsa a ULA para encontrar a posicao da memoria %s e passa para o Data Memory.\n", instrucao->reg2);
        
        (*ciclos) = (*ciclos) + 4;

        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "00", "10", "NULL", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "lw") == 0){ // verifica se instrução é LW
        // sw $s0, 100($t0)
        printf("\nUsa a ULA para encontrar a posicao da memoria %s e passa para o Data Memory.\n", instrucao->reg2);

        (*ciclos) = (*ciclos) + 5;

        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "00", "10", "NULL", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "beq") == 0){ // verifica se instrução é BEQ 
        // beq $t0, $t1, LOOP
        printf("\nUsa a ULA para comprar se os valores dos registradores (%s e %s) sao iguais e vai para a label %s.\n", instrucao->reg1, instrucao->reg2, instrucao->reg3);

        (*ciclos) = (*ciclos) + 3;

        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "1", "01", "00", "1", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "bne") == 0){ // verifica se instrução é BNE
        // bnq $t0, $t1, LOOP
        printf("\nUsa a ULA para comparar se os valores dos registradores (%s e %s) nao sao iguais e vai para a label %s.\n", instrucao->reg1, instrucao->reg2, instrucao->reg3);

        (*ciclos) = (*ciclos) + 3;

        imprimeCod("NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "1", "01", "00", "1", "Execucao");
    }
    else if (strcmp(instrucao->instrucao, "j") == 0){  // verifica se instrução é J (jump)
        //j LOOP
        printf("\nUsa a ULA para ir ao endereco de destino %s. \n", instrucao->reg1);

        (*ciclos) = (*ciclos) + 3;

        imprimeCod("NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "1", "NULL", "NULL", "10", "Execucao");
    }
}

// Função para verificar se possui acesso a memória de dados "lw" e "sw"
void acessoNaMemoria(instrucao_t *instrucao){
    if(strcmp(instrucao->instrucao, "lw") == 0){ // verifica se instrução é LW
        printf("\nbusca na memoria o valor armazenado na posição %s.\n",instrucao->reg2);
    
        imprimeCod("NULL", "NULL", "NULL", "1", "NULL", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "Acesso de memoria");
    }
    
    else if(strcmp(instrucao->instrucao, "sw") == 0){ // verifica se instrução é SW
        printf("\nsalva na memoria o valor do registrador %s na posição %s.\n",instrucao->reg1, instrucao->reg2);

        imprimeCod("NULL", "NULL", "NULL", "NULL", "1", "NULL", "1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "Acesso de memoria");
    }else{ // caso não satisfaça nenhuma das condições anteriores
        printf("\n%s não tem acesso a memória", instrucao->instrucao);
    }
}

// Função para escrever no banco de registradores com base nas instruções inseridas (caso seja ADD, SUB, SLT, LW)
void writeBack(instrucao_t *instrucao){
    if(strcmp(instrucao->instrucao, "add") == 0 ){ // verifica se instrução é ADD
        printf("\nescreve o valor da saida da ula no registrador %s. \n\n", instrucao->reg1);
    }
    else if(strcmp(instrucao->instrucao, "sub") == 0 ){ // verifica se instrução é SUB
        printf("\nescreve o valor da saida da ula no registrador %s. \n\n", instrucao->reg1);
    }
    else if(strcmp(instrucao->instrucao, "slt") == 0 ){ // verifica se instrução é SLT
        printf("\nescreve o valor da saida da ula no registrador %s. \n\n", instrucao->reg1);
    }
    else if(strcmp(instrucao->instrucao, "lw") == 0 ){ // verifica se instrução é LW
        printf("\nescreve no registrador o valor puxado da memoria %s.\n\n", instrucao->reg1);
    }
    else{ // caso não satisfaça nenhuma das condições anteriores
        printf("\n%s não tem acesso ao writeback\n", instrucao->instrucao);
    }
}


int main(){
    // cria uma variavel instrução do tipo scruct variavel_t (lista)
    instrucao_t instrucao;
    
    // inicializando contagem de ciclo
    int var = 0;
    int *ciclos = &var; // inicializa ponteiro ciclos que armazena endereço de var, no qual será Incrementado os ciclos


    // nome do arquivo de entrada de instruções
    char *nomeArquivo = "instrucoes.txt";

    // inicializa variavel de arquivo que vai ser aberto
    FILE *arquivo;

    // abre arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // inicializa variavel que vai armazenar  linha da instrução
    char input[30];

    int pos = 0;
    while (pos < TAM)
    { // enaquanto pos for menor que tamanho de linhas do arquivo de entrada. Ou seja quantidade de instruções que quero ler do arquivo
      char *linha = fgets(input, sizeof(input), arquivo); // pega linha do arquivo

      buscaInstrucao(&instrucao, linha); // etapa 1: realiza a busca de instruções (fetch)

      decodificaInstrucao(&instrucao); // etapa 2: realiza a decodificação da instrução e configura os sinais de controle da arquitetura (decode)

      execucao(&instrucao, ciclos); // etapa 3: realiza a execução da arquitetura 

      acessoNaMemoria(&instrucao); // etapa 4: realiza o acesso à memória quando necessário 

      writeBack(&instrucao); // etapa 5: informa que foi escrito no banco de registradores o valor
      
      // Incrementa o número de ciclos da arquitetura
      pos++;

      // Imprime a quantidade de ciclos passada pela arquitetura
      printf("\nCiclos: %d\n", *ciclos);

      printf("-----------------------------------------------------");
    }





    
    return 0;
}

/*

Conjunto de instruções

add $s1, $s2, $s3
sub $s1, $s2, $s3
lw  $1, 100($2)
sw  $1, 100($2)
beq $s1, $s2, 100
bne $s1, $s2, 100
j 1000

*/