************************************************************************************
Trabalho 1. Arquitetura de Computadores I
-----------------------------------------


**Nomes:** *André, Daniel, Laura*
************************************************************************************

**Introdução**

  Como proposto o trabalho, foi desenvolvido um algoritmo que recebe como entrada intruções para arquitetura MIPS mono-cilclo, afim de simular as execuções feita pela mesma como por exemplo Tipo-R, LW, SW, BEQ, BNE e JUMP.


**Execução**

  Requisitos

  - Possuir GCC (Caso precise compilar)

  
Para a compilação do programa pode ser utilizado o GCC.
    
    gcc main.c -o arqMonociclo

  E ao executar no console (ou executar pela pasta raiz do programa o arquivo arqMonociclo.exe)

    ./arqMonociclo


**Sobre**

  Seu funcionamento se encontra em um loop no qual fica sempre esperando por instruções a serem inseridas no console de execução do programa. Dentro desse laço de repetição é chamada as respectivas funções para cumprir as verificações caso passe pelo componente e efetue a etapa que deve seguir cada instrução, sendo as funções:

  - Busca -> *buscaInstrucao()*
  - Decodificação -> **
  - Execução -> **
  - Acesso a memória -> **
  - Write-back -> **

---------------------------------

** Conjunto de instruções **

_add $s1, $s2, $s3_

_sub $s1, $s2, $s3_

_lw  $1, 100($2)_

_sw  $1, 100($2)_

_beq $s1, $s2, 100_

_bne $s1, $s2, 100_

_j 1000_

---------------------------------


************************************************************************************