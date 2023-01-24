/*******************************************************************************************
 2. Solicite ao usuario uma palavra ou frase que será armazenada em uma string.. Escrever em
 arquivo formato texto as seguintes informações:
 a) A string original
 b) A string invertida;
 c) A string toda em caracteres maiúsculos
 d) A string toda em caracteres minusculos
 e) Se houver mais de uma palavra na string, escrever uma palavra por linha.
 f) A quantidade de caracteres da string.
 Cada um dos itens deve estar separado por uma linha em branco
 *******************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>
 #include<string.h>
 #include<ctype.h>

 //função que coloca uma linha em branco entre os itens np arquivo
 void nl(FILE *arquivo);

 int main ()
 {
   setlocale(LC_ALL,"");

   char string[100];
   int tam,i;

   FILE *fp;
   //abrindo um arquivo de texto para escrita
   fp=fopen("arquivo_ex2.txt","wt");

   printf("Digite a palavra ou frase que será colocada no arquivo: ");
   gets(string);

   //definindo o tamanho da sting
   tam=strlen(string);

   //exibindo no arquivo a string original
   fprintf(fp,"a) %s\n\n",string);

   //exibindo a string invertida no arquivo
   fprintf(fp,"b) ");

   for(i=tam; i>=0; i--)
    fprintf(fp,"%c",string[i]);

   nl(fp);

   //exibindo a string toda em caracteres maiusculos
   fprintf(fp,"c) ");

   for(i=0; i<tam; i++)
   {
       string[i]=toupper(string[i]); //converte o caractere para maiusculo antes de exibir
       fprintf(fp,"%c",string[i]);
   }
   nl(fp);

   //exibindo a string toda em caracteres minusculos
   fprintf(fp,"d) ");

   for(i=0; i<tam; i++)
   {
       string[i]=tolower(string[i]); //converte o caractere para maiusculo antes de exibir
       fprintf(fp,"%c",string[i]);
   }
   nl(fp);

   //exibindo uma palavra por linha
   fprintf(fp,"e) ");

   for(i=0; i<tam; i++)
   {
       if(string[i]==' ') //quando o caractere for igual ao espaço
        fprintf(fp,"\n    ");
       else
        fprintf(fp,"%c",string[i]);
   }
   nl(fp);

   //exibindo a qtd de caracteres da string
   fprintf(fp,"f) Quantidade de caracteres: %d",tam);

   //finalizando o programa
   system("pause");
   return 0;
 }

  void nl(FILE *arquivo)
 {
    fprintf(arquivo,"\n\n");
 }


