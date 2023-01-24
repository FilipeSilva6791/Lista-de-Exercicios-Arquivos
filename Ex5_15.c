/**************************************************************************************************
 5. O programa deve abrir um arquivo no formato texto selecionado pelo usuário. A seguir :
 a. Contabilizar a ocorrência de cada letra (não considerar diferenças de maiusculas/minusculas)
 e digito presente no arquivo. Não considerar espaço ou caracteres de pontuação. (contar quantas
 letras a, quantas letras b, etc…)
 b. Abrir um arquivo formato texto com nome identico ao original, acrescentado de “rpt_” no
 inicio.
 c. Escrever neste arquivo o resultado da analise feita. Organizar as informações em 3 colunas,
 na primeira o caracter (letra ou digito), na segunda o numero de ocorrências em valor
 absoluto e na terceira o percentual de ocorrências em relação ao total.
 d. Acrescente ao arquivo informações que entenderem como necessárias para facilitar a
 compreensão deste relatório.
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
     char namefile[50];   //armazena o endereço do arquivo
     char newnamefile[53]="rpt_";
     char ch;             //variavel para auxiliar nos laços
     int i,total_carac=0;
     float porcentagem;

     printf("Digite o endereço do arquivo de texto que você quer contar os caracteres: ");
     gets(namefile);

    //abre  o arquivo com o endereço que o usuário digitou (apenas para leitura)
     fp=fopen(namefile,"rt");

    //se a função fopen retornar NULL, significa que o arquivo não pode ser aberto
     if(fp==NULL)
        printf("\nO arquivo não pode ser aberto corretamente.\n");

     //================================ CONTANDO AS OCORRÊNCIAS DE CADA CARACTERE ==================================//
     //inicializa ch com o primeiro caractere do arquivo
     ch=getc(fp);

     while(!feof(fp))
     {
		 if ( ch != ' ' && ch != '\n' ) //se esse cractere não for espaço ou nova linha
		 {
            for(i=0; i<26; i++)         //passa por todos os caracteres do vetor de caracteres e confere se algum é igual a ch
            {
                if(ch==caracteres[i])   //se for igual
                {
                   count[i]++;         //incrementa o vetor count na posição referente ao caractere
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

    strcat(newnamefile,namefile);     //função que concatena a primeira e a segunda string (adiciona "rpt_" no inicio do arquivo)

    //criando um arquivo para escrita
    fp=fopen(newnamefile,"wt");

    fprintf(fp,"\t\t\tRELATORIO DA CONTAGEM\n\n");
    fprintf(fp,"\tNa tabela abaixo estão descriminadas as seguintes informações: \n" );
    fprintf(fp,"\tNa coluna 1, todos os caracteres que apareceram no arquivo indicado;\n");
    fprintf(fp,"\tNa coluna 2, a quantidade de aparições do respectivo caractere;\n");
    fprintf(fp,"\tNa coluna 3, o percentual de ocorrências do caractere em relação ao total.\n\n" );

    for(i=0; i<36; i++)
    {
        if(count[i]>0) //se existe aparições do caractere respectivo
        {
            porcentagem=(((float)count[i]*100)/(float)total_carac);   //a cast se torna necessária por conta dos tipos de dados da conta serem incompativeis
            fprintf(fp,"\t\t\t     | %c | %d | %.2f %%| \n",caracteres[i],count[i],porcentagem);
            fprintf(fp,"\t\t\t     --------------------------\n");
        }
    }

    fprintf(fp,"\n\n\tQuantidade total de caracteres presentes no arquivo: %d",total_carac);

    fclose(fp);

    //=======================================================================================================//

    printf("O relatório da contagem foi enviado no mesmo diretório do arquivo indicado ! \n");
    printf("O arquivo do relatório terá o mesmo nome do seu arquivo, porém, com o prefixo 'rpt_'. \n\n");

    system("pause");
    return 0;
 }
