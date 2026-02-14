void bubble(int arr[], unsigned int tamanho)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < (tamanho - 1); i++)
    {
        for (j = 0; j < ((tamanho) - (i + 1)); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int var_troca = arr[j + 1]; // [2,1,3] t = 1
                arr[j + 1] = arr[j];        // [2,2,3] t = 1
                arr[j] = var_troca;         // [1,2,3] t = 1
            }
        }
    }
}