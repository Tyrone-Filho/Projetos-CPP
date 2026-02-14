#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    //  Este programa mostra a piramide de pascal ate o numero Expoente_A_B;
    std::vector<int> array{1};

    int Expoente_A_B = 15; // faixa de existencia de 1 a 24
    if (Expoente_A_B<0 || Expoente_A_B>24){
        std::cout << "Valor Expoente menor que 0 ou maior que 24\n" << "Definindo Valor Base Como 5" << "\n\n";
        Expoente_A_B = 5;
    }

    std::cout << std::string(Expoente_A_B * 2 + 1, '*') << "PIRAMIDE DE PASCAL" << std::string(Expoente_A_B * 2 + 1, '*') << "\n\n"; // logica para o DE ficar alinhado com o 1 abaixo
    std::cout << std::string((Expoente_A_B * 2 + ((int)(Expoente_A_B / 5) + 6)), ' ') << 1 << "\n";                                  // logica para alinhar o 1 com base no tamanho da piramide

    for (int i = 0; i < Expoente_A_B; i++)
    {
        int tamanho = array.size();
        std::vector<int> arr_troca;
        arr_troca.push_back(1);

        for (int j = 0; j < (tamanho - 1); j++)
        {
            arr_troca.push_back(array[j] + array[j + 1]);
        }

        arr_troca.push_back(1);

        array = arr_troca;

        std::cout << std::string((((Expoente_A_B * 2) + 2) - (array.size() + i)), ' '); // logica para nao dar 'std::length_error'
        for (const int &valor : array)
        {
            std::cout << std::setw((array.size() - i) * ((int)(Expoente_A_B / 10) + 2)) << valor;
        }
        std::cout << "\n";
    }
    return 1;
}