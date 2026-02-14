#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    //  Este programa mostra a piramide de pascal ate o numero Expoente_A_B;
    std::vector<int> array{1};

    int Expoente_A_B = 11;
    std::cout << std::string(19, '*') << "PIRAMIDE DE PASCAL" << std::string(19, '*') << "\n\n";
    std::cout << std::string(28, ' ') << 1 << "\n";

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

        std::cout << std::string(25 - (array.size() + i), ' ');
        for (int valor : array)
        {
            std::cout << std::setw((array.size() - i) * 2) << valor;
        }
        std::cout << "\n";
    }
    return 1;
}