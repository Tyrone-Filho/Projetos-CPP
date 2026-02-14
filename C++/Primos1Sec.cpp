#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>
#include <numeric>
#include <algorithm>

int main()
{
    /*          Projetinho bem simples de calculador de numeros primos            */
    // Sieve of Erastotenes é melhor mais vou fazer esse so depois pois nao entendo a matematica por tras ainda
    std::vector<int> array_primos{2};
    std::vector<int> quantidade_primos;
    std::vector<int> numeros_percorridos;

    float segundos_a_ser_rodado = 2;
    int vezes_a_ser_rodado = 3;

    if (vezes_a_ser_rodado < 1)
    {
        vezes_a_ser_rodado = 1;
    }
    if (segundos_a_ser_rodado <= 0)
    {
        segundos_a_ser_rodado = 1;
    }

    int vezes_rodadas = 0;
    int maior_primo_achado;

    int num = 3;

    std::cout << "\n\n\n"
              << std::string(25, '*') << "ACHADOR DE NUMEROS PRIMOS" << std::string(25, '*') << "\n\n";
    std::cout << "O Programa Ira Procurar Primos Por: " << segundos_a_ser_rodado << " Segundos \n";
    std::cout << "O Programa Ira Simular A Procura De Primos " << vezes_a_ser_rodado << " Vezes \n\n";
    std::cout << "O Programa Ira Demorar " << segundos_a_ser_rodado * vezes_a_ser_rodado << " Segundos Para Concluir As Simulacoes Espere Atenciosamente. \n\n";

    auto tempo_agora = std::chrono::steady_clock::now();
    while (vezes_rodadas < vezes_a_ser_rodado)
    {
        bool adicionar_lista = true;

        double limite = sqrt(num);
        for (unsigned int index = 1; index < array_primos.size(); index++)
        {
            int i = array_primos[index];
            if (i > limite)
            {
                break;
            }

            else if ((num % i) == 0)
            {
                adicionar_lista = false;
                break;
            } // Logica de checagem pra ver se e primo, ele testa ate a raiz do numero
        }
        if (adicionar_lista && (num >= 2))
        {
            array_primos.push_back(num);
        }

        auto tempo_fim_exec = std::chrono::steady_clock::now();

        auto tempo_passado = std::chrono::duration_cast<std::chrono::duration<double>>(tempo_fim_exec - tempo_agora); // magia negra

        if (tempo_passado.count() >= segundos_a_ser_rodado)
        {
            vezes_rodadas++;
            tempo_agora = std::chrono::steady_clock::now();

            quantidade_primos.push_back(array_primos.size());
            maior_primo_achado = array_primos[(array_primos.size() - 1)];

            numeros_percorridos.push_back(num);

            array_primos.clear();
            array_primos.push_back(2);
            num = 3;
            /* essas linhas sao resets pra consiguir recalcular denovo e ter resultados mais parecidos
             *  se quiser pode comentar a linha 47 para consiguir numeros primos enormes
             */
        }

        num += 2;
    }

    int media = std::accumulate(quantidade_primos.begin(), quantidade_primos.end(), 0);
    media /= quantidade_primos.size();

    std::cout << "O Maior Primo Achado Foi: " << maior_primo_achado << "\n";
    std::cout << "A Media De Primos Achados Nas Simulacoes Foi: " << media << "\n";
    std::cout << "A Quantidade Maxima De Primos Achados Em Uma Das Simulacoes Foi: " << *std::max_element(quantidade_primos.begin(), quantidade_primos.end()) << "\n";
    std::cout << "A Quantidade De Numeros Procurados Ao Decorrer Das Simulacoes Foi: " << std::accumulate(numeros_percorridos.begin(), numeros_percorridos.end(), 0) << "\n";

    /* Nessas ultimas linhas usei a bibliotecas <algorithm> e <numeric>
     *  De primeiro nao entendi muito o *max_element e o accumulate mas agora entendi e planejo continuar usando essa bilioteca
     *  Eu acho C++ uma linguagem com muita Abstracao mas tentarei entender-la melhor
     *  Existe uma biblioteca que importa tudo ela se chama <bits/stdc++.h> eu usei ela de primeiro mas percebi que pode consumir muita memoria
     *  E tambem nao e adequado importar tudo pra poucas coisas entao a retirei
     */

    return 1;
}