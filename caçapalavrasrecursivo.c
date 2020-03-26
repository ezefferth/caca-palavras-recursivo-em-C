/*
	Ezefferth
	caça palavras recursivo
*/

#include <stdio.h>

int direita(int help, int ii, int jj, int i, int j, int size, int word, char matrix[size][size], char vector[word])
{
    if(help==word)
    {
        printf("(%d,%d) (%d,%d)\n",i,j,ii,jj-1);
    }
    if(jj==size)
    {
        help++;
        jj=0;
        direita(help, ii, jj, i, j, size, word, matrix, vector);
    }
    if(matrix[ii][jj]==vector[help])
    {
        help++;
        jj++;
        direita(help, ii, jj, i, j, size, word, matrix, vector);
    }
return 0;
}

int main()
{
    int i, j, size, word=0, help=0;; /* variaveis size para tamanho da matriz e word para tamanho da palavra a ser procurada */
    scanf("%d",&size); /* tamanho da matriz */
    char matrix[size][size]; /* declara a matriz size x size */
    char vector[101]; /* declara o vetor da palavra */
    for(i=0; i<size; i++)
    {
        scanf(" %[^\n]s", matrix[i]); /* armazena em cada posicao de i uma string de tamanho size */
    }
    scanf("%s",vector); /* recebe a palavra a ser procurada */
    for(i=0; vector[i] != '\0'; i++) /* contador para tamanho da palavra, qnd ela eh diferente de \0 ela conta o proximo */
    {
        word++;
    }
    for(i=0; i<size; i++)
    {/* for para poder verificar posicao 'I' e 'J' da matriz */
        for(j=0; j<size; j++)
        {
            direita(help, i, j, i , j, size, word, matrix, vector);
        }
    }

return 0;
}
