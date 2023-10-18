#include<stdio.h>
#include<string.h>
char username[65], password[10], user[20];


int login () 
{
    int response = 0;
    char userT[20], passwordT[10];
    printf("Digite seu nome de usuario: ");
    fgets(userT,20,stdin);

    printf("Digite sua Senha: ");
    fgets(passwordT,10,stdin);

    if(strcmp(userT, user) == 0 && strcmp(passwordT, password) == 0)
        response = 1;

    return response;
}

void play(int check)
{
    if(check == 0)
    {
        do
        {
            printf("\nUsuario ou senha incorretos!\n\n");
            check = login();
        }while(check != 1);
    } 
    else 
    {
        printf("Conta Bancaria*\n");
    }
}

void createUser() 
{
    printf("Ola!\nBem-vindo ao nosso programinha extremamente util.\nPrepare-se para uma experiencia totalmente imersiva e divertia!(confia)\n");

    printf("\nPrimeiramente, informe seu primeiro e segundo nome: ");
    fgets(username,65,stdin);
    printf("Para dar continuidade, por favor crie um nome de usuario para que seja feito o login: ");
    fgets(user,20,stdin);
    printf("Perfeito! Agora crie uma senha para que você possa acessar a sua conta: ");
    fgets(password,10,stdin);

    printf("\nShow! Aguarde um momento, o sistema esta iniciando...\n");

    play(login());
}

int main()
{
    createUser();
    return 0;
}
