#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

struct caca
{
    int posicaoCacaY;
    int posicaoCacaX;
    bool viva;
};

struct s_cacador
{
    int posicaoCacadorY;
    int posicaoCacadorX;
    int alcance = 5;    
};

int const linhas = 30;
int const colunas = 30;


int matriz[linhas][colunas];

int possibilidadeCacadorX[8], possibilidadeCacadorY[8];
int possibilidadeCacaX[8], possibilidadeCacaY[8];

vector <caca> cacas;
s_cacador cacador;

void CriaMatriz()
{
    for (int i = 0; i < linhas ; i++)
    {
        for (int j = 0; j < colunas; j++)
        {        

            matriz[i][j] = 0;

            
        }
       
    }
}



void ImprimeMatriz() // Preenche Matriz com 0
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void CriaPosicoes() // Gera numeros aleatorios e salva na struct do Caçador e das Caças
{
    srand(time(NULL));
    cacador.posicaoCacadorX = rand() % 29;
    cacador.posicaoCacadorY = rand() % 29;
    matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

    for (int i = 0; i < 5; i++)
    {
        caca temp;
        temp.posicaoCacaX = rand() % 29;
        temp.posicaoCacaY = rand() % 29;       

        while(cacador.posicaoCacadorX == temp.posicaoCacaX & cacador.posicaoCacadorY == temp.posicaoCacaY) // Impede as caças ocuparem
        {                                                                                                  // o mesmo lugar do caçador
            temp.posicaoCacaX = rand() % 29;
            temp.posicaoCacaY = rand() % 29;
        }

        cacas.push_back(temp);       
        
        matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;
    }
}


void MovimentaCaca() // É gerado um numero aleatorio que é utilizado no switch
{                    // para movimentar a Caça aleatoriamente
    int random =0;   // a caça so se movera se houver espaço
    int i = 0;       // e não esteja ocupado por outra caça ou caçador
    while (i < 5)
    {
        if (cacas[i].viva) // verifica se a caça esta viva
        {
            random = rand() % 7;
            switch (random)
            {
            case 0:
                // anda para vertical superior esquerda
                if (cacas[i].posicaoCacaX > 0 && cacas[i].posicaoCacaY > 0
                    && matriz[cacas[i].posicaoCacaX - 1][cacas[i].posicaoCacaY - 1] == 0) 
                {                                                                        
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX--;
                    cacas[i].posicaoCacaY--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;                    
                    i++;
                }
                break;

            case 1:
                // anda para cima
                if (cacas[i].posicaoCacaX > 0 && matriz[cacas[i].posicaoCacaX - 1][cacas[i].posicaoCacaY] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;                    
                    i++;

                }
                break;

            case 2:
                // anda para vertical superior direita
                if (cacas[i].posicaoCacaX > 0 && cacas[i].posicaoCacaY < 29
                    && matriz[cacas[i].posicaoCacaX - 1][cacas[i].posicaoCacaY + 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX--;
                    cacas[i].posicaoCacaY++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;                   
                    i++;
                }
                break;

            case 3:
                // anda para direita
                if (cacas[i].posicaoCacaY < 29 && matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY + 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaY++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;
                    i++;
                }
                break;

            case 4:
                // anda para vertical inferior direita
                if (cacas[i].posicaoCacaX < 29 && cacas[i].posicaoCacaY < 29
                    && matriz[cacas[i].posicaoCacaX + 1][cacas[i].posicaoCacaY + 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX++;
                    cacas[i].posicaoCacaY++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;
                }
                break;

            case 5:
                // anda para baixo
                if (cacas[i].posicaoCacaX < 29 && matriz[cacas[i].posicaoCacaX + 1][cacas[i].posicaoCacaY] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX++;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;                    
                    i++;
                }
                break;

            case 6:
                // anda para vertical inferior esquerda
                if (cacas[i].posicaoCacaX < 29 && cacas[i].posicaoCacaY > 0
                    && matriz[cacas[i].posicaoCacaX + 1][cacas[i].posicaoCacaY - 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaX++;
                    cacas[i].posicaoCacaY--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;                    
                    i++;
                }
                break;

            case 7:
                // anda para esquerda
                if (cacas[i].posicaoCacaY > 0 && matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY - 1] == 0)
                {
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = 0;
                    cacas[i].posicaoCacaY--;
                    matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;                   
                    i++;
                }
            default:
                break;
            }
        }
        else
        {
             i++;
        }
    }
}

void MovimentaCacador(int choose)
{
    //diagonal superior esquerda
    possibilidadeCacadorX[0] = cacador.posicaoCacadorX - 1;
    possibilidadeCacadorY[0] = cacador.posicaoCacadorY - 1;

    //cima
    possibilidadeCacadorX[1] = cacador.posicaoCacadorX - 1;
    possibilidadeCacadorY[1] = cacador.posicaoCacadorY;

    //diagonal superior direita
    possibilidadeCacadorX[2] = cacador.posicaoCacadorX - 1;
    possibilidadeCacadorY[2] = cacador.posicaoCacadorY + 1;

    // direita
    possibilidadeCacadorX[3] = cacador.posicaoCacadorX;
    possibilidadeCacadorY[3] = cacador.posicaoCacadorY + 1;

    // diagonal inferior direita
    possibilidadeCacadorX[4] = cacador.posicaoCacadorX + 1;
    possibilidadeCacadorY[4] = cacador.posicaoCacadorY + 1;

    // baixo
    possibilidadeCacadorX[5] = cacador.posicaoCacadorX + 1;
    possibilidadeCacadorY[5] = cacador.posicaoCacadorY;

    // diagonal inferior esquerda
    possibilidadeCacadorX[6] = cacador.posicaoCacadorX + 1;
    possibilidadeCacadorY[6] = cacador.posicaoCacadorY - 1;

    // esquerda
    possibilidadeCacadorX[7] = cacador.posicaoCacadorX;
    possibilidadeCacadorY[7] = cacador.posicaoCacadorY - 1;


    if (choose==9) // o numero nove é retornado pela funcao Varredura
    {              // quando nao ha nenhuma caça no perimetro, logo ele anda aleatoriamente
        choose = rand() % 7;
    }
    switch (choose)
    {
    case 0:
        if (cacador.posicaoCacadorX != 0 && cacador.posicaoCacadorY != 0)
        {
            // anda para vertical superior esquerda
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }        
        break;

    case 1:
        // anda para cima
        if (cacador.posicaoCacadorX > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;     
        }
        break;

    case 2:
        // anda para vertical superior direita
        if (cacador.posicaoCacadorX > 0 && cacador.posicaoCacadorY < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }     
        break;

    case 3:
        // anda para direita
        if (cacador.posicaoCacadorY < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }       
        break;

    case 4:
        // anda para vertical inferior direita
        if (cacador.posicaoCacadorX < 29 && cacador.posicaoCacadorY < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }
        break;

    case 5:
        // anda para baixo
        if (cacador.posicaoCacadorX < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }               
        break;

    case 6:
        // anda para vertical inferior esquerda
        if (cacador.posicaoCacadorX < 29 && cacador.posicaoCacadorY > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }        
        break;

    case 7:
        // anda para esquerda
        if (cacador.posicaoCacadorY > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
        }        
        break;
        
    default:
        break;
    }   
}


void Atacar(int focoAtc) // preenche a celula que a caça foco está com zero
{
    matriz[cacas[focoAtc].posicaoCacaX][cacas[focoAtc].posicaoCacaY] = 0;
    cacas[focoAtc].viva = false;
}


void Cacar(int focoCacar)// nesta função é calculado qual possibilidade de movimentação do caçador
{                        // deixará ele mais proximo da caça alvo.
    int quadrado1, quadrado2, maisProximo;
    float distancia;
    float menorDistancia= 1000;    

    for (int i = 0; i < 8; i++)
    {
        quadrado1 = (possibilidadeCacadorX[i] - cacas[focoCacar].posicaoCacaX) * (possibilidadeCacadorX[i] - cacas[focoCacar].posicaoCacaX);
        quadrado2 = (possibilidadeCacadorY[i] - cacas[focoCacar].posicaoCacaY) * (possibilidadeCacadorY[i] - cacas[focoCacar].posicaoCacaY);

        distancia = sqrt(quadrado1 + quadrado2);

        if (distancia < menorDistancia)
        {
            menorDistancia = distancia;
            maisProximo = i;
        }         
    }
    if (menorDistancia == 1) // caso a caça esteja do lado do caçador, ela é atacada.
    {
        Atacar(focoCacar);
    }
    else
    {
        MovimentaCacador(maisProximo);
    }  
}


void Varredura() // nesta função é vericado se há uma caça no perimetro do caçador
{                // caso haja mais de uma, é passado a posição da caça mais proxima do caçador
    int foco[5];
    int encontrados = 0;
    int posicaoAchadoX[5];
    int posicaoAchadoY[5];

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            int alcanceX = cacador.posicaoCacadorX - cacador.alcance + i;
            int alcanceY = cacador.posicaoCacadorY - cacador.alcance + j;

            if (matriz[alcanceX][alcanceY] == 1 || matriz[alcanceX][alcanceY] == 2                  
                || matriz[alcanceX][alcanceY] == 3 || matriz[alcanceX][alcanceY] == 4               
                   || matriz[alcanceX][alcanceY] == 5 && matriz[alcanceX][alcanceY] != 7)           
            {                
                posicaoAchadoX[encontrados] = alcanceX;
                posicaoAchadoY[encontrados] = alcanceY;
                foco[encontrados] = matriz[alcanceX][alcanceY]; // guarda qual é a caça (1,2,3,,4,5)
                encontrados++;
            }
        }      
    }
    if (encontrados == 1)
    {
        Cacar(foco[0] -1);     // este "-1" é utilizado pois a caça de numero qualquer, ocupa na verdade a posição anterior no vetor
    }
    else if (encontrados > 1)
    {
        int maisProximo;
        float menorDistancia= 300;
        int quadrado1, quadrado2; // variaveis para calcular qual a caca esta mais proxima
        float distancia;          // variaveis para calcular qual a caca esta mais proxima
        for (int k = 0; k < encontrados; k++)
        {
            quadrado1 = (cacador.posicaoCacadorX - posicaoAchadoX[k]) * (cacador.posicaoCacadorX - posicaoAchadoX[k]);
            quadrado2 = (cacador.posicaoCacadorY - posicaoAchadoY[k]) * (cacador.posicaoCacadorY - posicaoAchadoY[k]);
            distancia = sqrt(quadrado1 + quadrado2);

            if (distancia < menorDistancia)
            {
                menorDistancia = distancia;
                maisProximo = foco[k];
            }
        }
        Cacar(maisProximo -1);
    }
    else
    {
        MovimentaCacador(9);
    }  
}

void Simulacao(int escolha)
{
    CriaMatriz();
    CriaPosicoes();   
    int vivos = 1;
    for (int i = 0; i < 5; i++)
    {
        cacas[i].viva = true;
    }
    int turnos = 0;
    while (vivos != 0)
    {
        vivos = 0;
        for (int i = 0; i < 5; i++)
        {
            if (cacas[i].viva)
                vivos++;
        }
        Varredura();
        MovimentaCaca();
        if (escolha == 1)
        {
            system("pause");
            system("cls");
            ImprimeMatriz();
        }
        turnos++;
    }
    cout << "O cacador demorou " << turnos << " turnos para matar todas as cacas." << endl;
}

int main()
{
    int escolha = 1;
    while (escolha !=0)
    {
     
        cout << "-- Bem vindo a simulacao do Jogo: Cacador VS Caca --" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "-- Digite 1: Para realizar a simulacao"<< endl << "com a impressao de matriz a cada turno." << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "-- Digite 2: Para realizar a simulacao "<< endl<< "e apenas mostrar ao final o numero de turnos." << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "-- Digite 0: Para finalizar a simulacao." << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> escolha;
        if (escolha != 0)
            Simulacao(escolha);
        system("pause");
        system("cls");
      
    }
}
