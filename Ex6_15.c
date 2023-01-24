/*********************************************************************************
 6. O programa deve abrir um arquivo no formato texto selecionado pelo usuário.
 Contar a quantidade de ocorrências de cada palavra neste arquivo.
 Escrever o resultado obtido em um arquivo formato texto, em ordem alfabética.
 Considerar valores numéricos como sendo palavras.
 *********************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<locale.h>

 //!PROTÓTIPOS DAS FUNÇÕES
 int countWords (FILE *fp);

 //! CRIANDO UM NOVO TIPO DE DADOS "string_t"

 typedef struct {

  char str[30];       //string
  int count;        //quantidade de vezes que a string apareceu

 } string_t;



 int main ()
 {
   setlocale(LC_ALL,"");

   //declarando variáveis
   FILE *fp;            //ponteiro para o arquivo
   int qtd=0;           //armazena quantas palavras existem no arquivo
   char namefile[50];   //armazena o endereço do arquivo que o usuário digitou
   int i=0,j=0,flag;
   char ch;

   //abrindo o arquivo desejado pelo usuário em forma de leitura
   printf("Digite o endereço do arquivo de texto que você deseja contar as palavras:  ");
   gets(namefile);

   //abre  o arquivo com o endereço que o usuário digitou (apenas para leitura)
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
       if( ch == ' ' || ch == '\n' ) //se chegou no fim da palavra(foi encontrado um espaço ou nova linha )
       {
          vet[j].str[i]='\0';        //coloca o marcador de fim da string
          i=0;                       //zera o indice da string para começar a copiar em outra
          j++;                       //incrementa o indice do vetor

       }else{                 //enquanto não chegar no fim da palavra (não encontrou o espaço)

          vet[j].str[i]=ch;   //continua passando os caracteres para a string
          i++;                //incremeneta o indice de posição da string
       }
       ch=getc(fp);
   }

   vet[j].str[i]='\0'; //adiciona o marcador de fim na ultima string, que não será colocado dentro do laço while

   // ======================================================================================================== //

   //================================ CONTANDO AS OCORRÊNCIAS DE CADA PALAVRA ================================ //

   /* setando todos os valores "count" do vetor em 1, pois, no trecho de código abaixo, contamos
      apenas as repetições da palavra e não somamos a aparição da mesma */

   for(i=0; i<qtd; i++)
       vet[i].count=1;

   for (i=0; i<qtd; i++)
 {
       for(j=1; j<(qtd-i); j++)
       {
        /* compara a string atual (de indidce i) com todos as outras strings do vetor,
           se achou uma string igual, incrementamos o contador da string de indice i
           e copiamos a string "z" para a string que é igual a ela */

           if(strcmp(vet[i].str,vet[i+j].str)==0)
           {
               vet[i].count++;
               strcpy(vet[i+j].str, "z");
           }
       }
   }
   // ======================================================================================================== //

   // ===================================== ORDENANDO EM ORDEM ALFABÈTICA ==================================== //

   /* para esta ordenação foi utilizado como base o algoritmo de ordenação bubble sort */

   //declarando uma nova variavel do tipo 'string_t' apenas para auxilio
   string_t aux;

   aux.count=0;
   flag =1;

   while (flag == 1)
   {
       flag = 0;

       for (i = 0; i < (qtd-1); i++)
        {
            /* se a string da proxima posição for menor que a string atual, ou seja,
               em ordem alfabetica a string da proxima posição vem antes da atual */
            if (strcmp(vet[i].str,vet[i+1].str)>0)
            {
                /*a flag é setada indicando que houve uma troca, o programa deverá testar
                  novamente na próxima passagem pelo laço */
                flag = 1;

                /*ocorre a troca da string atual com a string da próxima posição, por meio
                  da função strcpy que copia uma string para outra */
                strcpy(aux.str,vet[i].str);
                strcpy(vet[i].str,vet[i+1].str);
                strcpy(vet[i+1].str,aux.str);

                /* da mesma forma, trocamos o valor encontrado de repetições em cada string */
                aux.count=vet[i].count;
                vet[i].count=vet[i+1].count;
                vet[i+1].count=aux.count;

                aux.count=0;
            }
        }

        /* a flag só continuará em zero, se durante a passagem pelo for, não ocorrer
           nenhuma troca, ou seja, o vetor está ordenado */
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
   fprintf(fp,"Palavra/Ocorrências\n");

   i=0;

   //exibindo as palavras e suas ocorrências no arquivo
   while(strcmp(vet[i].str,"z") != 0)
   {
       fprintf(fp,"%s - %d \n", vet[i].str, vet[i].count);
       i++;
   }

   //fechando o arquivo de resultados
   fclose(fp);

   // ======================================================================================================== //

   printf("\nO resultado da contagem será enviado para você em um arquivo de texto, que estará  no mesmo diretório do arquivo indicado para contagem. Até a próxima ! \n\n");

   system("pause");
   return 0;
 }

 //! FUNÇÃO QUE CONTA A QUANTIDADE DE PALAVRAS PRESENTES NO ARQUIVO

 int countWords (FILE *fp)
 {
    char ch;
    int flag=0, count_w=0;

    //inicializa ch com o primeiro caractere do arquivo
    ch=getc(fp);

    while(!feof(fp))
    {
     if ( ch == ' ' || ch == '\n' )     //se esse cractere for espaço ou nova linha
         {
            if (flag == 0)              //se houver 2 ou mais espaços juntos, o código não entra neste if
            {                           //(quem controla é a flag)
                count_w++;              //incrementa o contador de palavras
                flag = 1;               //seta a flag, indicando que passou por um espaço
            }                           //(se o próximo caractere for espaço tbm, a flag continua em 1)
         }
     else                               //se não é espaço ou nova linha
         {
            if ( flag == 1 )            //se a flag for 1, zera ela novamente
                flag = 0;
         }

     ch = getc(fp); //atribui o proximo caractere do fluxo a ch
    }
    count_w++;  //incrementa a ultima palavra do arquivo, que não será contabilizada no laço while

    return count_w;
 }

