/************************************************************************************
 1. O programa deve armazenar em arquivo no formato texto as palavras digitadas pelo
 usuário. O usuario entra com uma palavra por vez. O programa é encerrado ao entrar
 com a palavra “telos”, sem que esta seja gravada em arquivo. A escolha do nome pelo
 usuário é opcional. Não esqueça de fechar o arquivo.
 ************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>
 #include<string.h>

 int main ()
 {
   setlocale(LC_ALL,"");

   char string[30];
   int aux;

   FILE *fp;
   //abrindo um arquivo de texto para escrita
   fp=fopen("arquivo_ex1.txt","wt");

   do
   {
         scanf("%s",string);

         //a função string compare compara as duas strings, se elas forem iguais, a função devolve 0
         aux=strcmp(string,"telos");

         if(aux!=0)
             //printa no arquivo a string
             fprintf(fp,"%s ",string);

   } while(aux!=0);

   fclose(fp);

   system("pause");
   return 0;
 }
