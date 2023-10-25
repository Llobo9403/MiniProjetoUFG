#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

char username[65], password[10], user[20];
double balance = 0;
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
        printf("\n\nBem-vindo a sua conta bancaria, %s",username);
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

    printf("\nShow! Aguarde um momento, o sistema esta iniciando...\n\n");

    //Isso e possivel pois a função login retorna um numero inteiro
    play(login());
}






//*******************************************    Banco    *******************************************

void investment();
int deposit();
int saque();

//onde vai ficar o layout, scanf e chamar as funcoes
int banco() {
	int opcao;

	printf("========================================================");
	printf("\n*                    BANCO UFG                       *\n");
	printf("========================================================\n");
    printf("1. Saque\n\n");
    printf("2. Depósito\n\n");
    printf("3. Investimento\n\n");
    printf("4. Conversor de Moedas\n\n");
    printf("=========================================================\n");
    printf("Escolha uma opção: ");

	while((scanf("%d",&opcao))!=EOF){

		if(opcao==1) saque();

		if(opcao==2) deposit();

		if(opcao==3) investment();
		
		//if(opcao==4) Conversor();
		
		//if(opcao==5) TelaInicial();

    }
return 0;
}

// SAQUE --------------------------------------------------------------


int saque()
{
    double quantia;
    printf("informe a quantia desejada para o saque: ");
    scanf("%lf", &quantia);
        
    if(quantia <= 0)
    {
        
        printf("A quantia deve ser maior que zero e positiva\n");
        
    } else if (quantia > balance)
    {
        
          printf("Saldo insuficiente!\n");
    } else
    {
          
          balance -= quantia;
          printf("Saque de %.2lf realizado com sucesso!\nSaldo Atual: %.2lf\n", quantia, balance);   
    }

    banco();    
    return 0;

}





// DEPOSITO ------------------------------------------------------------



#define MAX_DEPOSIT 1000 // Definindo o valor máximo para depósito
#define NUM_CONTAS 10 // Número de contas no banco

// Estrutura para representar uma conta bancária
typedef struct {
    int numero_conta;
    double saldo;
    char nome_usuario[50];
} Conta;

// Lista de contas
Conta contas[NUM_CONTAS];

// Função para verificar se a conta existe
int conta_existe(int numero_conta) {
    for (int i = 0; i < NUM_CONTAS; i++) {
        if (contas[i].numero_conta == numero_conta) {
            return i; // Retorna o índice da conta se ela existir
        }
    }
    return -1; // Retorna -1 se a conta não existir
}

// Função para realizar o depósito
double deposito(double saldo, double valor) {
    return saldo + valor; // Adiciona o valor ao saldo e retorna o novo saldo
}

// Função para gerar um código de verificação aleatório
int gerar_codigo_verificacao() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    return rand() % 9000 + 1000; // Gera um número aleatório entre 1000 e 9999
}

// Função para imprimir o recibo do depósito
void imprimir_recibo(int numero_conta, double valor, double saldo, int codigo_verificacao) {
    printf("Comprovante de Depósito:\n");
    printf("Número da Conta: %d\n", numero_conta);
    printf("Valor Depositado: %.2f\n", valor);
    printf("Saldo Atual: %.2f\n", saldo);
    printf("Código de Verificação: %d\n", codigo_verificacao);
}

int deposit() {
    int numero_conta; // Número da conta
    double valor; // Valor a ser depositado
    int indice_conta; // Índice da conta na lista de contas
    int codigo_verificacao; // Código de verificação
    int check = 0;

    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    indice_conta = conta_existe(numero_conta); // Verifica se a conta existe

    if (indice_conta != -1) 
    { // Se a conta existir...

        do {
            printf("Digite o valor a ser depositado: ");
            scanf("%lf", &valor);

            if (valor <= MAX_DEPOSIT) 
            { 
                contas[indice_conta].saldo = deposito(contas[indice_conta].saldo, valor);
                balance += valor;
                codigo_verificacao = gerar_codigo_verificacao();
                imprimir_recibo(numero_conta, balance, contas[indice_conta].saldo, codigo_verificacao);
                check = 0;
            } else 
            {
                printf("O valor informado é maior que o limite máximo de %d reais.\n", MAX_DEPOSIT);
                printf("Por favor, digite outro valor ou divida o depósito em partes menores.\n");
                check = 1;
            }
        }while(check == 1);
    } else 
    {
        printf("A conta informada não existe.\n");
        printf("Por favor, digite outro número ou crie uma nova conta.\n");
        deposit();
    }

    banco();
    return 0;
}








// INVESTIMENTO --------------------------------------------------------



/*------    FUNCTIONS OF CASE ONE  ------
Fução que calcula o valor com juros nominal desconsiderando a inflação*/
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



//-------- CASE ONE --------


void caseOneInvestment()
{
    double time = 0, value = 0, rate = 0, contribution = 0, inflation = 0;
    double nominalValue, realValue, inflationValueMoney;
    
    printf("\n\n\n-------------------   Investimento c/ prazo   -------------------");

    //Validação de inputs
    do {
        printf("\n\nInsira o periodo: ");
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
    printf("_________________________________________________________");

    if(value == balance)
        balance = nominalValue;

    //Ajeitar bug do numero não arredondado
    printf("\n%f",balance);
}



/*------    FUNCTIONS OF CASE TWO    ------*/

int dreamInvestment(double value, double contribution, double rate)
{
    int time = 0;
    while(balance <= value)
    {
        balance = balance*(1+(rate/100)/12) + contribution;
        time++;
    }

    return time;
}


//-------- CASE TWO --------

void caseTwoInvestment()
{
    double value, rate, contribution, inflation = 0;
    int time, answer;

    printf("\n\n\n-------------------   Investimento sonhador   -------------------");

    printf("\n\n\nInsira o valor voce deseja alcançar: ");
    scanf("%lf",&value);

    printf("Insira o valor que deseja investir: ");
    scanf("%lf",&contribution);

    printf("Insira a taxa de juros: ");
    scanf("%lf",&rate);

    printf("\n\nDeseja calcular a inflação(0/1)? ");
    scanf("%d",&answer);

    if(answer == 0)
    {
        printf("\n\nInforme a taxa da inflação: ");
        scanf("%lf",&inflation);
    }

    double newBalance = balance;

    time = dreamInvestment(value, contribution, rate);
    inflation = balance - inflationValue(time,newBalance,contribution, inflation, rate);
    printf("\n\n\n###################   RESULTADOS   #####################\n\n");
    printf("%d meses seriam necessarios para alcançar a quantia desejada.\n", time);
    printf("Ao final desse periodo você estara com R$ %.2f.\n",balance);
    
    if(answer == 0)
        printf("Ou R$ %.2f ajustando com a inflação.\n", inflation);
    
    printf("\n\n_________________________________________________________");

}

void caseTreeInvestment()
{
    double finalValue = balance;

    printf("\n\n\n-------------------   Investimento generico   -------------------\n\n\n");

    for(int i = 1; i <= 1200; i++)
    {
        finalValue *= 1+ 0.08/12;

        if(i%10 == 0 && i%12 == 0)
        {
            printf("%d anos = R$ %.2f\n",(i/12), finalValue);
        }
    }

    printf("\n\nCom base no seu dinheiro em conta e levando em consideração\na taxa de juros real atualmente '8%% ao ano', esses serão seus\nresultados nos proximos anos.\n");
    printf("\n\n_________________________________________________________");
}

int visit = 0;
void investment() 
{
    int option, back = 0;
  
    if(visit == 0)    
    {
        printf("\n_________________________________________________________\n\n");
        printf("Ola, %s\nEsta e a nossa area de investimento.\nAqui voce podera simular diversos investimentos a depender da sua necessidade.\n\nLogo abaixo estão algumas opções, por favor escolha alguma que te satisfaça.", username);
        visit = 1;
    }
    printf("\n\n\n-------------------   Investimentos   -------------------");

    printf("\n\n\n1 - Investimento c/ prazo.              |  Saldo Atual: R$ %.2f  |\n\n2 - Investimento sonhador.\n\n3 - Investimento generico.\n\n4 - Voltar.\n\n\n",balance);

    do {
        printf("Digite o numero da opção: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: 
                caseOneInvestment();
                break;
            case 2: 
                caseTwoInvestment();
                break;
            case 3: 
                caseTreeInvestment();
                break;
            case 4: 
                //Volta para o menu inicial
                printf("\nVoltando ao menu inicial...\n\n\n");
                back = 1;
                banco();
                break;
            default: 
                printf("Opção não valida!\n");
                break;
        }
    } while(!(option == 1 || option == 2 || option == 3 || option == 4));

    if(back == 0)
        investment();

}



//***************************************************************************************************




//*******************************************    Conversor   ****************************************

















//***************************************************************************************************




int main()
{
    //Chamando minha função para criar um usuario.
    //createUser();
    banco();
    return 0;
}
