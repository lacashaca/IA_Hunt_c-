#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct caca
{
    int posicaoCacaY;
    int posicaoCacaX;
    bool encontrada;

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

int matriz[linhas][colunas];

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
    matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

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
   // while (!cacador.cacando)
   // {
        
        
        switch (choose)
        {
        case 0:
            if (cacador.posicaoCacadorX != 0 && cacador.posicaoCacadorY != 0)
            {
                // anda para vertical superior esquerda
                matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
                cacador.posicaoCacadorX--;
                cacador.posicaoCacadorY--;
                matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

                cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            }
            else
            {
                cout << " n eh possivel";
            }
            break;
        case 1:
            // anda para cima
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;            
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;
        case 2:
            // anda para vertical superior direita
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;
        case 3:
            // anda para direita
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;            
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;
        case 4:
            // anda para vertical inferior direita
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            cacador.posicaoCacadorY++;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;
        case 5:
            // anda para baixo
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX--;            
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;
        case 6:
            // anda para vertical inferior esquerda
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            cacador.posicaoCacadorX++;
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;
        case 7:
            // anda para esquerda
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 0;
            
            cacador.posicaoCacadorY--;
            matriz[cacador.posicaoCacadorX][cacador.posicaoCacadorY] = 8;

            cout << cacador.posicaoCacadorX << " - " << cacador.posicaoCacadorY << "andou " << choose << endl;
            break;

        default:
            break;
        }

        cout << "------------------------------" << endl;
        ImprimeMatriz();

   // }
}

int main()
{
    CriaMatriz();
    CriaPosicoes();
    ImprimeMatriz();
    int escolha;
    cin >> escolha;
    while (escolha !=9)
    {
        
        MovimentaCacador(escolha);
        cin >> escolha;
    }
   
}
