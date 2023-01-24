/***************************************************************************************

 4. O usu�rio seleciona um arquivo no formato texto. Contar o n�mero de palavras e a
    quantidade total de caracteres presentes neste arquivo. Exibir o resultado na tela.

 ***************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>

 int main ()
 {
     setlocale(LC_ALL,"");

     FILE *fp;            //ponteiro para o arquivo
     char namefile[50];   //armazena o endere�o do arquivo
     char ch;             //variavel para auxiliar na contagem
     int count_char=0, count_words=0,flag=0;

     printf("Digite o endere�o do arquivo de texto que voc� quer contar os caracteres: ");
     gets(namefile);

     //abre  o arquivo com o endere�o que o usu�rio digitou (apenas para leitura)
     fp=fopen(namefile,"rt");

     //se a fun��o fopen retornar NULL, significa que o arquivo n�o pode ser aberto
     if(fp==NULL)
        printf("\nO arquivo n�o pode ser aberto corretamente.\n");

     //================================= EXIBINDO O ARQUIVO ==================================//
     printf("\nEste � o conte�do presente no arquivo que voc� indicou:\n\n");

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
     //======================================================================================//


     //================================CONTANDO AS PALAVRAS E OS CARACTERES ==================================//
     rewind(fp);  //reposiciona o ponteiro para o inicio do arquivo

     //inicializa ch com o primeiro caractere do arquivo
     ch=getc(fp);

     while(!feof(fp))
     {
		 if ( ch == ' ' || ch == '\n' ) //se esse cractere for espa�o ou nova linha
		 {
			if (flag == 0)              //se houver 2 ou mais espa�os juntos, o c�digo n�o entra neste if
			{                           //(quem controla � a flag)
				count_words++;          //incrementa o contador de palavras
				flag = 1;               //seta a flag, indicando que passou por um espa�o
			}                           //(se o pr�ximo caractere for espa�o tbm, a flag continua em 1)
		 }
		 else                           //se n�o � espa�o ou nova linha
		 {
		     count_char++;              //incrementa o contador de caracteres

			 if ( flag == 1 )           //se a flag for 1, zera ela novamente
                flag = 0;
		 }

         ch = getc(fp);     //atribui um caractere do fluxo a ch
     }
     count_words++; //incrementa a ultima palavra do arquivo, que n�o ser� contabilizada no la�o while

    //=======================================================================================================//

    //========================================= EXIBINDO RESULTADOS =========================================//
     printf("\n\nN�mero de palavras presentes no arquivo: %d\n",count_words);
     printf("N�mero de caracteres presentes no arquivo: %d \n\n",count_char);

     //======================================================================================================//
     //fechando o arquivo
     fclose(fp);

     //finalizando o programa
     system("pause");
     return 0;
 }
