#include <iostream>
#include "SortingFunctions.h"

int main()
{
    int tamanho = 50;
    int arr[tamanho];
    std::cout << "LISTA DESORGANIZADA\n\n[";
    for (int pos = 0; pos < tamanho; pos++)
    {
        arr[pos] = std::rand() % (tamanho+1);
        std::cout << arr[pos] << (pos==(tamanho-1) ? "]" : ",");
    }
    bubble(arr, tamanho);
    std::cout << "\n\nLISTA ORGANIZADA\n\n[";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << arr[i] << (i==(tamanho-1) ? "]" : ",");
    }
    return 1;
}