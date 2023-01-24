/***************************************************************************************

 4. O usuário seleciona um arquivo no formato texto. Contar o número de palavras e a
    quantidade total de caracteres presentes neste arquivo. Exibir o resultado na tela.

 ***************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>

 int main ()
 {
     setlocale(LC_ALL,"");

     FILE *fp;            //ponteiro para o arquivo
     char namefile[50];   //armazena o endereço do arquivo
     char ch;             //variavel para auxiliar na contagem
     int count_char=0, count_words=0,flag=0;

     printf("Digite o endereço do arquivo de texto que você quer contar os caracteres: ");
     gets(namefile);

     //abre  o arquivo com o endereço que o usuário digitou (apenas para leitura)
     fp=fopen(namefile,"rt");

     //se a função fopen retornar NULL, significa que o arquivo não pode ser aberto
     if(fp==NULL)
        printf("\nO arquivo não pode ser aberto corretamente.\n");

     //================================= EXIBINDO O ARQUIVO ==================================//
     printf("\nEste é o conteúdo presente no arquivo que você indicou:\n\n");

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
     //======================================================================================//


     //================================CONTANDO AS PALAVRAS E OS CARACTERES ==================================//
     rewind(fp);  //reposiciona o ponteiro para o inicio do arquivo

     //inicializa ch com o primeiro caractere do arquivo
     ch=getc(fp);

     while(!feof(fp))
     {
		 if ( ch == ' ' || ch == '\n' ) //se esse cractere for espaço ou nova linha
		 {
			if (flag == 0)              //se houver 2 ou mais espaços juntos, o código não entra neste if
			{                           //(quem controla é a flag)
				count_words++;          //incrementa o contador de palavras
				flag = 1;               //seta a flag, indicando que passou por um espaço
			}                           //(se o próximo caractere for espaço tbm, a flag continua em 1)
		 }
		 else                           //se não é espaço ou nova linha
		 {
		     count_char++;              //incrementa o contador de caracteres

			 if ( flag == 1 )           //se a flag for 1, zera ela novamente
                flag = 0;
		 }

         ch = getc(fp);     //atribui um caractere do fluxo a ch
     }
     count_words++; //incrementa a ultima palavra do arquivo, que não será contabilizada no laço while

    //=======================================================================================================//

    //========================================= EXIBINDO RESULTADOS =========================================//
     printf("\n\nNúmero de palavras presentes no arquivo: %d\n",count_words);
     printf("Número de caracteres presentes no arquivo: %d \n\n",count_char);

     //======================================================================================================//
     //fechando o arquivo
     fclose(fp);

     //finalizando o programa
     system("pause");
     return 0;
 }
