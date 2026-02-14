#include <iostream>
#include "SortingFunctions.h"

int main()
{
    int arr[125];
    for (unsigned int pos = 0; pos < 125; pos++)
    {
        arr[pos] = std::rand() % 101;
    }
    unsigned int tamanho = sizeof(arr) / sizeof(int);
    bubble(arr, tamanho);
    for (unsigned int i = 0; i < tamanho; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 1;
}