/*********************************************************************************
 6. O programa deve abrir um arquivo no formato texto selecionado pelo usu�rio.
 Contar a quantidade de ocorr�ncias de cada palavra neste arquivo.
 Escrever o resultado obtido em um arquivo formato texto, em ordem alfab�tica.
 Considerar valores num�ricos como sendo palavras.
 *********************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<locale.h>

 //!PROT�TIPOS DAS FUN��ES
 int countWords (FILE *fp);

 //! CRIANDO UM NOVO TIPO DE DADOS "string_t"

 typedef struct {

  char str[30];       //string
  int count;        //quantidade de vezes que a string apareceu

 } string_t;



 int main ()
 {
   setlocale(LC_ALL,"");

   //declarando vari�veis
   FILE *fp;            //ponteiro para o arquivo
   int qtd=0;           //armazena quantas palavras existem no arquivo
   char namefile[50];   //armazena o endere�o do arquivo que o usu�rio digitou
   int i=0,j=0,flag;
   char ch;

   //abrindo o arquivo desejado pelo usu�rio em forma de leitura
   printf("Digite o endere�o do arquivo de texto que voc� deseja contar as palavras:  ");
   gets(namefile);

   //abre  o arquivo com o endere�o que o usu�rio digitou (apenas para leitura)
   fp=fopen(namefile,"rt");

   //contando a quantidade de palavras presentes no arquivo
   qtd=countWords(fp);

   /* vetor de dados do tipo 'string_t' com tamanho definido pela
      quantidade de palavras encontradas no arquivo.  */

   string_t vet[qtd];

   // =================== ARMAZENANDO AS PALAVRAS DO ARQUIVO NO VETOR DE STRINGS 'VET' ======================= //

   rewind(fp);       //reposicionando o ponteiro para o inicio do arquivo
   ch=getc(fp);      //inicializando ch com o primeiro caractere do fluxo

   while(!feof(fp))
   {
       if( ch == ' ' || ch == '\n' ) //se chegou no fim da palavra(foi encontrado um espa�o ou nova linha )
       {
          vet[j].str[i]='\0';        //coloca o marcador de fim da string
          i=0;                       //zera o indice da string para come�ar a copiar em outra
          j++;                       //incrementa o indice do vetor

       }else{                 //enquanto n�o chegar no fim da palavra (n�o encontrou o espa�o)

          vet[j].str[i]=ch;   //continua passando os caracteres para a string
          i++;                //incremeneta o indice de posi��o da string
       }
       ch=getc(fp);
   }

   vet[j].str[i]='\0'; //adiciona o marcador de fim na ultima string, que n�o ser� colocado dentro do la�o while

   // ======================================================================================================== //

   //================================ CONTANDO AS OCORR�NCIAS DE CADA PALAVRA ================================ //

   /* setando todos os valores "count" do vetor em 1, pois, no trecho de c�digo abaixo, contamos
      apenas as repeti��es da palavra e n�o somamos a apari��o da mesma */

   for(i=0; i<qtd; i++)
       vet[i].count=1;

   for (i=0; i<qtd; i++)
 {
       for(j=1; j<(qtd-i); j++)
       {
        /* compara a string atual (de indidce i) com todos as outras strings do vetor,
           se achou uma string igual, incrementamos o contador da string de indice i
           e copiamos a string "z" para a string que � igual a ela */

           if(strcmp(vet[i].str,vet[i+j].str)==0)
           {
               vet[i].count++;
               strcpy(vet[i+j].str, "z");
           }
       }
   }
   // ======================================================================================================== //

   // ===================================== ORDENANDO EM ORDEM ALFAB�TICA ==================================== //

   /* para esta ordena��o foi utilizado como base o algoritmo de ordena��o bubble sort */

   //declarando uma nova variavel do tipo 'string_t' apenas para auxilio
   string_t aux;

   aux.count=0;
   flag =1;

   while (flag == 1)
   {
       flag = 0;

       for (i = 0; i < (qtd-1); i++)
        {
            /* se a string da proxima posi��o for menor que a string atual, ou seja,
               em ordem alfabetica a string da proxima posi��o vem antes da atual */
            if (strcmp(vet[i].str,vet[i+1].str)>0)
            {
                /*a flag � setada indicando que houve uma troca, o programa dever� testar
                  novamente na pr�xima passagem pelo la�o */
                flag = 1;

                /*ocorre a troca da string atual com a string da pr�xima posi��o, por meio
                  da fun��o strcpy que copia uma string para outra */
                strcpy(aux.str,vet[i].str);
                strcpy(vet[i].str,vet[i+1].str);
                strcpy(vet[i+1].str,aux.str);

                /* da mesma forma, trocamos o valor encontrado de repeti��es em cada string */
                aux.count=vet[i].count;
                vet[i].count=vet[i+1].count;
                vet[i+1].count=aux.count;

                aux.count=0;
            }
        }

        /* a flag s� continuar� em zero, se durante a passagem pelo for, n�o ocorrer
           nenhuma troca, ou seja, o vetor est� ordenado */
    }

   // ======================================================================================================== //

   // =============================== ABRINDO UM NOVO ARQUIVO PARA O RESULTADO =============================== //

   //fechando o arquivo atual
   fclose(fp);

   //abrindo um novo arquivo para escrita
   fp=fopen("resultado.txt","wt");

   // ======================================================================================================== //

   // ======================================== EXIBINDO OS RESULTADOS ======================================== //
   fprintf(fp,"Resultados da contagem: \n\n");
   fprintf(fp,"Palavra/Ocorr�ncias\n");

   i=0;

   //exibindo as palavras e suas ocorr�ncias no arquivo
   while(strcmp(vet[i].str,"z") != 0)
   {
       fprintf(fp,"%s - %d \n", vet[i].str, vet[i].count);
       i++;
   }

   //fechando o arquivo de resultados
   fclose(fp);

   // ======================================================================================================== //

   printf("\nO resultado da contagem ser� enviado para voc� em um arquivo de texto, que estar�  no mesmo diret�rio do arquivo indicado para contagem. At� a pr�xima ! \n\n");

   system("pause");
   return 0;
 }

 //! FUN��O QUE CONTA A QUANTIDADE DE PALAVRAS PRESENTES NO ARQUIVO

 int countWords (FILE *fp)
 {
    char ch;
    int flag=0, count_w=0;

    //inicializa ch com o primeiro caractere do arquivo
    ch=getc(fp);

    while(!feof(fp))
    {
     if ( ch == ' ' || ch == '\n' )     //se esse cractere for espa�o ou nova linha
         {
            if (flag == 0)              //se houver 2 ou mais espa�os juntos, o c�digo n�o entra neste if
            {                           //(quem controla � a flag)
                count_w++;              //incrementa o contador de palavras
                flag = 1;               //seta a flag, indicando que passou por um espa�o
            }                           //(se o pr�ximo caractere for espa�o tbm, a flag continua em 1)
         }
     else                               //se n�o � espa�o ou nova linha
         {
            if ( flag == 1 )            //se a flag for 1, zera ela novamente
                flag = 0;
         }

     ch = getc(fp); //atribui o proximo caractere do fluxo a ch
    }
    count_w++;  //incrementa a ultima palavra do arquivo, que n�o ser� contabilizada no la�o while

    return count_w;
 }

