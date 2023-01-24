/**************************************************************************************

 3. O usu�rio escolhe um nome de arquivo, que obrigatoriamente estara no formato texto.
    O programa abre este arquivo e exibe seu conteudo na tela.

 **************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>

 int main ()
 {
     setlocale(LC_ALL,"");

     FILE *fp;            //ponteiro para o arquivo
     char namefile[50];   //armazena o endere�o do arquivo
     char ch;             //variavel para auxiliar na exibi��o da mensagem

     printf("Digite o endere�o do arquivo de texto que voc� quer exibir: ");
     gets(namefile);

     //abre  o arquivo com o endere�o que o usu�rio digitou apenas para leitura
     fp=fopen(namefile,"rt");

     //se a fun��o fopen retornar NULL, significa que o arquivo n�o pode ser aberto
     if(fp==NULL)
        printf("\nO arquivo n�o pode ser aberto corretamente.\n");

     printf("\nEstes s�o os dados presentes no arquivo: \n\n");

     //inicializa ch com o primeiro caractere do arquivo
     ch=getc(fp);

     //a fun��o feof retorna verdadeiro quando o ponteiro se localizar no fim do arquivo
     //portant, o programa s� sai do la�o quando todos os caracteres do arquivo forem impressos
     while(!feof(fp))
     {
          putchar(ch);   //exibe ch
          ch=getc(fp);   //atribui a ch o pr�ximo caractere do arquivo
          //(o ponteiro do arquivo incrementa a posi��o automaticamente)
     }

     //fechando o arquivo
     fclose(fp);

     //finalizando o programa
     printf("\n\n");
     system("pause");
     return 0;
 }
