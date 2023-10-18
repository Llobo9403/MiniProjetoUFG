#include<stdio.h>
#include<string.h>
char username[65], password[10], user[20];


//Função responsavel por validar o login.
int login () 
{
    int response = 0;
    char userT[20], passwordT[10];

    printf("Digite seu nome de usuario: ");
    fgets(userT,20,stdin);

    printf("Digite sua Senha: ");
    fgets(passwordT,10,stdin);

    //A função strcmp faz parte da biblioteca <string.h> e permite fazer a comparação do conteudo de cada string
    if(strcmp(userT, user) == 0 && strcmp(passwordT, password) == 0)
        response = 1;

    return response;
}


//Função que de fato inicia o programa apos validar o login
void play(int check)
{
    if(check == 0)
    {       
        printf("\nUsuario ou senha incorretos!\n\n");
        //Uso de recurção 
        play(login());        
    } 
    else 
    {
        printf("Bem-vindo a sua conta bancaria, %s",username);
    }
}


//Função responsavel por criar um novo usuario.
void createUser() 
{
    printf("Ola!\nBem-vindo ao nosso programinha extremamente util.\nPrepare-se para uma experiencia totalmente imersiva e divertia!(confia)\n");

    printf("\nInicialmente, informe seu primeiro e segundo nome: ");
    //A função fgets faz a leitura da minha string sem problemas com espaços em branco.
    fgets(username,65,stdin);
    printf("Para dar continuidade, por favor crie um nome de usuario para que seja feito o login: ");
    fgets(user,20,stdin);
    printf("Perfeito! Agora crie uma senha para que você possa acessar a sua conta: ");
    fgets(password,10,stdin);

    printf("\nShow! Aguarde um momento, o sistema esta iniciando...\n");

    //Isso e possivel pois a função login retorna um numero inteiro
    play(login());
}

int main()
{
    //Chamando minha função para criar um usuario.
    createUser();
    return 0;
}
