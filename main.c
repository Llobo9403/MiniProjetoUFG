#include<stdio.h>
#include<string.h>
#include<math.h>
char username[65], password[10], user[20];
double balance;
double totalContribution = 0, totalIncome = 0;

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






//*******************************************    Banco    *******************************************












//Fução que calcula o valor com juros nominal desconsiderando a inflação
double nominalInterest(double time, double value, double contribution, double rate)
{
    double income = 0, amount = 0;
    totalContribution = 0;
    totalIncome = 0;

    for(int i = 1; i <= time; i++)
    {
        income = value*((rate/100)/12);
        amount = value + income + contribution;
        totalIncome += income;
        totalContribution += contribution;
        value = amount;
    }

    return value;
}

//Função que calcula o valor com juros sob efeito da inflação 
double inflationValue(double time, double value, double contribution, double inflation, double rate)
{
    double income = 0, amount = 0, totalInflation = 0;

    for(int i = 1; i <= time; i++)
    {
        income = value*((rate/100)/12);
        totalInflation += value*(inflation/100);
        amount = value + income + contribution;
        value = amount;
    }

    return totalInflation;
}


// Lembrar de criar uma validação para os valores
void investment() 
{
    double time = 0, value = 0, rate = 0, contribution = 0, inflation = 0;
    double nominalValue, realValue, inflationValueMoney;
    
    //Validação de inputs
    do {
        printf("Insira o periodo: ");
        scanf("%lf", &time);
    } while(time <= 0 || time != (int)time);

    do {
        printf("Insira o montante inicial: ");
        scanf("%lf", &value);
    } while(value < 0);

    do {
        printf("Insira o valor de aporte mensal: ");
        scanf("%lf", &contribution);
    } while(contribution < 0);

    do {
        printf("Insira a taxa de juros: ");
        scanf("%lf", &rate);
    } while(rate <= 0);

        printf("Insira a taxa de inflação mensal: ");
        scanf("%lf", &inflation); 

    inflationValueMoney = inflationValue(time,value,contribution, inflation, rate);
    nominalValue =  nominalInterest(time,value,contribution, rate);
    realValue = nominalValue - inflationValueMoney;

    printf("\n\n\n###################   RESULTADOS   #####################\n\n");
    printf("Montante inicial: R$ %.2f", value);
    printf("\nTotal investido: R$ %.2f", totalContribution);
    printf("\nTotal de Rendimentos: R$ %.2f\n\n", totalIncome);
    printf("Montante final: R$ %.2f", nominalValue);
    printf("\nValor reajustado: R$ %.2f\n\n", realValue);
    
}


//***************************************************************************************************




//*******************************************    Conversor   ****************************************

















//***************************************************************************************************




int main()
{
    //Chamando minha função para criar um usuario.
    //createUser();
    investment();
    return 0;
}
