#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

struct caca
{
    int posicaoCacaY;
    int posicaoCacaX;
    bool foco = false;

};

struct s_cacador
{
    int posicaoCacadorY;
    int posicaoCacadorX;
    int alcance = 5;
    bool cacando = false;
};





int const linhas = 30;
int const colunas = 30;

int matriz[linhas][colunas] ;

vector <caca> cacas;
s_cacador cacador;





void CriaMatriz()
{
    for (int i = 0; i < linhas ; i++)
    {
        for (int j = 0; j < colunas; j++)
        {        

            matriz[i][j] = 0;

            //cout << matriz[i][j] << " "; 
        }
        //cout << endl;
    }
}

void ImprimeMatriz()
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

void CriaPosicoes()
{
    srand(time(NULL));
    cacador.posicaoCacadorX = rand() % 30;
    cacador.posicaoCacadorY = rand() % 30;
    matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

    for (int i = 0; i < 5; i++)
    {
        caca temp;
        temp.posicaoCacaX = rand() % 30;
        temp.posicaoCacaY = rand() % 30;       

        while(cacador.posicaoCacadorX == temp.posicaoCacaX & cacador.posicaoCacadorY == temp.posicaoCacaY)
        {
            temp.posicaoCacaX = rand() % 30;
            temp.posicaoCacaY = rand() % 30;
        }

        cacas.push_back(temp);       
        
        matriz[cacas[i].posicaoCacaX][cacas[i].posicaoCacaY] = i + 1;

        cout << cacas[i].posicaoCacaY << " ";
        cout << cacas[i].posicaoCacaX << " " << endl ;


    }
    
    
}

void MovimentaCacador(int choose)
{

    if (choose==9)
    {
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

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << " n eh possivel";
        }
        break;
    case 1:
        // anda para cima
        if (cacador.posicaoCacadorX > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;
            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "nao eh possivel";
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
            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "nao eh possivel";
        }


        break;
    case 3:
        // anda para direita
        if (cacador.posicaoCacadorY < 29)
        {

            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
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

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }
        break;
    case 5:
        // anda para baixo

        if (cacador.posicaoCacadorX < 29)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
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

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }
        break;
    case 7:
        // anda para esquerda
        if (cacador.posicaoCacadorY > 0)
        {
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 7;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;

        }
        else
        {
            cout << "n eh possivel";
        }
        break;

    default:
        break;
    }

    cout << "------------------------------" << endl;
    ImprimeMatriz();
}

void Cacar(int foco)
{
    int quadrado1, quadrado2, maisProximo;
    float distancia;
    float menorDistancia= 1000;    

    int possibilidadeX[8];
    int possibilidadeY[8];

    //diagonal superior esquerda
    possibilidadeX[0] = cacador.posicaoCacadorX - 1;
    possibilidadeY[0] = cacador.posicaoCacadorY - 1;

    //cima
    possibilidadeX[1] = cacador.posicaoCacadorX - 1;
    possibilidadeY[1] = cacador.posicaoCacadorY;

    //diagonal superior direita
    possibilidadeX[2] = cacador.posicaoCacadorX - 1;
    possibilidadeY[2] = cacador.posicaoCacadorY + 1;

    // direita
    possibilidadeX[3] = cacador.posicaoCacadorX;
    possibilidadeY[3] = cacador.posicaoCacadorY + 1;

    // diagonal inferior direita
    possibilidadeX[4] = cacador.posicaoCacadorX + 1;
    possibilidadeY[4] = cacador.posicaoCacadorY + 1;

    // baixo
    possibilidadeX[5] = cacador.posicaoCacadorX + 1;
    possibilidadeY[5] = cacador.posicaoCacadorY;

    // diagonal inferior esquerda
    possibilidadeX[6] = cacador.posicaoCacadorX + 1;
    possibilidadeY[6] = cacador.posicaoCacadorY - 1;

    // esquerda
    possibilidadeX[7] = cacador.posicaoCacadorX;
    possibilidadeY[7] = cacador.posicaoCacadorY - 1;



    for (int i = 0; i < 8; i++)
    {
        quadrado1 = (possibilidadeX[i] - cacas[foco -1].posicaoCacaX) * (possibilidadeX[i] - cacas[foco -1].posicaoCacaX);
        quadrado2 = (possibilidadeY[i] - cacas[foco -1].posicaoCacaY) * (possibilidadeY[i] - cacas[foco -1].posicaoCacaY);

        distancia = sqrt(quadrado1 + quadrado2);

        if (distancia < menorDistancia)
        {
            menorDistancia = distancia;
            maisProximo = i;
        }
    }
    MovimentaCacador(maisProximo);
}



void Varredura()
{
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
                foco[encontrados] = matriz[alcanceX][alcanceY]; // guarda qual eh a caca
                encontrados++;

                /* desta forma eu nao sei qual eh a caca.
                posicaoAchadoX[encontrados]= cacador.posicaoCacadorX - cacador.alcance + i;
                posicaoAchadoY[encontrados] = cacador.posicaoCacadorY - cacador.alcance + j;
                encontrados++;
                */
            }
        }      
    }
    cout << "encontrados: " << encontrados << endl;



    if (encontrados == 1)
    {
        Cacar(foco[0]);
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

        Cacar(maisProximo);
    }
    else
    {
        MovimentaCacador(9);
    }


  
}






int main()
{
    CriaMatriz();
    CriaPosicoes();

    int escolha;

    cout << "digite a quantidade de turnos " << endl;
    cin >> escolha;

    while(escolha!=0)
    {    

    for (int i = 0; i < escolha; i++)
    {
        Varredura();
    }
    cout << "digite a quantidade de turnos " << endl;
    cin >> escolha;
    }
}