/**************************************************************************************

 3. O usuário escolhe um nome de arquivo, que obrigatoriamente estara no formato texto.
    O programa abre este arquivo e exibe seu conteudo na tela.

 **************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>

 int main ()
 {
     setlocale(LC_ALL,"");

     FILE *fp;            //ponteiro para o arquivo
     char namefile[50];   //armazena o endereço do arquivo
     char ch;             //variavel para auxiliar na exibição da mensagem

     printf("Digite o endereço do arquivo de texto que você quer exibir: ");
     gets(namefile);

     //abre  o arquivo com o endereço que o usuário digitou apenas para leitura
     fp=fopen(namefile,"rt");

     //se a função fopen retornar NULL, significa que o arquivo não pode ser aberto
     if(fp==NULL)
        printf("\nO arquivo não pode ser aberto corretamente.\n");

     printf("\nEstes são os dados presentes no arquivo: \n\n");

     //inicializa ch com o primeiro caractere do arquivo
     ch=getc(fp);

     //a função feof retorna verdadeiro quando o ponteiro se localizar no fim do arquivo
     //portant, o programa só sai do laço quando todos os caracteres do arquivo forem impressos
     while(!feof(fp))
     {
          putchar(ch);   //exibe ch
          ch=getc(fp);   //atribui a ch o próximo caractere do arquivo
          //(o ponteiro do arquivo incrementa a posição automaticamente)
     }

     //fechando o arquivo
     fclose(fp);

     //finalizando o programa
     printf("\n\n");
     system("pause");
     return 0;
 }
