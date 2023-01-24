/**************************************************************************************************
 5. O programa deve abrir um arquivo no formato texto selecionado pelo usu�rio. A seguir :
 a. Contabilizar a ocorr�ncia de cada letra (n�o considerar diferen�as de maiusculas/minusculas)
 e digito presente no arquivo. N�o considerar espa�o ou caracteres de pontua��o. (contar quantas
 letras a, quantas letras b, etc�)
 b. Abrir um arquivo formato texto com nome identico ao original, acrescentado de �rpt_� no
 inicio.
 c. Escrever neste arquivo o resultado da analise feita. Organizar as informa��es em 3 colunas,
 na primeira o caracter (letra ou digito), na segunda o numero de ocorr�ncias em valor
 absoluto e na terceira o percentual de ocorr�ncias em rela��o ao total.
 d. Acrescente ao arquivo informa��es que entenderem como necess�rias para facilitar a
 compreens�o deste relat�rio.
 *************************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>
 #include<string.h>

 int main ()
 {
     setlocale(LC_ALL,"");

     FILE *fp;

     char caracteres[36]= "abcdefghijklmnopqrstuvwxyz0123456789";
     int count[36]={};    //vetor que armazena a qtd de ocorrencias de cada caractere
     char namefile[50];   //armazena o endere�o do arquivo
     char newnamefile[53]="rpt_";
     char ch;             //variavel para auxiliar nos la�os
     int i,total_carac=0;
     float porcentagem;

     printf("Digite o endere�o do arquivo de texto que voc� quer contar os caracteres: ");
     gets(namefile);

    //abre  o arquivo com o endere�o que o usu�rio digitou (apenas para leitura)
     fp=fopen(namefile,"rt");

    //se a fun��o fopen retornar NULL, significa que o arquivo n�o pode ser aberto
     if(fp==NULL)
        printf("\nO arquivo n�o pode ser aberto corretamente.\n");

     //================================ CONTANDO AS OCORR�NCIAS DE CADA CARACTERE ==================================//
     //inicializa ch com o primeiro caractere do arquivo
     ch=getc(fp);

     while(!feof(fp))
     {
		 if ( ch != ' ' && ch != '\n' ) //se esse cractere n�o for espa�o ou nova linha
		 {
            for(i=0; i<26; i++)         //passa por todos os caracteres do vetor de caracteres e confere se algum � igual a ch
            {
                if(ch==caracteres[i])   //se for igual
                {
                   count[i]++;         //incrementa o vetor count na posi��o referente ao caractere
                   total_carac++;      //incrementa o total de caracteres
                }
            }
		 }
         ch = getc(fp);     //atribui o proximo caractere do fluxo a ch
     }

    //=======================================================================================================//

    //fechando o arquivo de leitura
    fclose(fp);

    //=============================== EXIBINDO OS RESULTADOS EM OUTRO ARQUIVO ===============================//

    strcat(newnamefile,namefile);     //fun��o que concatena a primeira e a segunda string (adiciona "rpt_" no inicio do arquivo)

    //criando um arquivo para escrita
    fp=fopen(newnamefile,"wt");

    fprintf(fp,"\t\t\tRELATORIO DA CONTAGEM\n\n");
    fprintf(fp,"\tNa tabela abaixo est�o descriminadas as seguintes informa��es: \n" );
    fprintf(fp,"\tNa coluna 1, todos os caracteres que apareceram no arquivo indicado;\n");
    fprintf(fp,"\tNa coluna 2, a quantidade de apari��es do respectivo caractere;\n");
    fprintf(fp,"\tNa coluna 3, o percentual de ocorr�ncias do caractere em rela��o ao total.\n\n" );

    for(i=0; i<36; i++)
    {
        if(count[i]>0) //se existe apari��es do caractere respectivo
        {
            porcentagem=(((float)count[i]*100)/(float)total_carac);   //a cast se torna necess�ria por conta dos tipos de dados da conta serem incompativeis
            fprintf(fp,"\t\t\t     | %c | %d | %.2f %%| \n",caracteres[i],count[i],porcentagem);
            fprintf(fp,"\t\t\t     --------------------------\n");
        }
    }

    fprintf(fp,"\n\n\tQuantidade total de caracteres presentes no arquivo: %d",total_carac);

    fclose(fp);

    //=======================================================================================================//

    printf("O relat�rio da contagem foi enviado no mesmo diret�rio do arquivo indicado ! \n");
    printf("O arquivo do relat�rio ter� o mesmo nome do seu arquivo, por�m, com o prefixo 'rpt_'. \n\n");

    system("pause");
    return 0;
 }
