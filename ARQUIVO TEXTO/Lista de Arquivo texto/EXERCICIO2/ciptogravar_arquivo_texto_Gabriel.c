#include <stdio.h>
#include <stdlib.h>

///Funcao para criptografar arquivo
void criptografar_arquivo()
{
    FILE*dados,*dados_crip;
    char car;
    dados = fopen("dados.txt", "r");
    dados_crip = fopen("dados_cript.txt", "w");

    if(dados!=NULL && dados_crip!=NULL)
    {
        while(!feof(dados))
        {
            car = fgetc(dados)+1;
            fprintf(dados_crip,"%c", car);
        }
        fclose(dados);
        fclose(dados_crip);
    }
    else
    {
        printf("Erro no sistema\n");
    }
}

///Funcao para descriptografar um arquivo
void descriptografar_arquivo()
{
    FILE*dados_crip,*dados_descrip;
    char caracter;
    dados_crip = fopen("dados_cript.txt", "r");
    dados_descrip = fopen("dados_descrip.txt", "w");
    if(dados_crip!=NULL && dados_descrip!=NULL)
    {
        while(!feof(dados_crip))
        {
            caracter = fgetc(dados_crip)-1;
            fprintf(dados_descrip,"%c", caracter);
        }
        fclose(dados_crip);
        fclose(dados_descrip);
    }
    else
    {
        printf("Erro no sistema\n");
    }
}


void main()
{
    criptografar_arquivo();
    descriptografar_arquivo();
}
