#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

int main()
{
     SetConsoleOutputCP(CP_UTF8);

     std::string itens[4] = {"♠", "♦", "♥", "♣"};
     std::vector<std::string> escolhidos;
     std::string continuar;

     const int slots = 3;

     do
     {
          for (int idx = 0; idx < slots; idx++)
          {
               int num;

               for (int x = 0; x < 20; x++)
               {
                    srand(time(0) * rand()); // MAGIA NEGRA
                    num = rand() % 4;
                    std::cout << std::string((6 * idx) + 7, '-') << "\n";

                    for (std::string valor : escolhidos)
                    {
                         std::cout << "|  " << valor << "  ";
                    }

                    std::cout << "|  " << itens[num] << "  |\n";

                    std::cout << std::string((6 * idx) + 7, '-') << "\n";
                    Sleep(x*10);
                    system("cls");
               }

               escolhidos.push_back(itens[num]);
               std::cout << std::string((6 * idx) + 7, '-') << "\n";
               for (std::string valor : escolhidos)
               {
                    std::cout << "|  " << valor << "  ";
               }

               std::cout << "|\n"
                         << std::string((6 * idx) + 7, '-');
          }

          std::sort(escolhidos.begin(), escolhidos.end());
          auto iterador = std::unique(escolhidos.begin(), escolhidos.end());
          escolhidos.erase(iterador, escolhidos.end());
          std::cout << "\n";
          if (escolhidos.size() == 3)
          {
               std::cout << "Boa sorte na proxima";
          }
          else if (escolhidos.size() == 1)
          {
               std::cout << "VOCE GANHOU PARABENS";
          }
          else
          {
               std::cout << "Foi quase";
          }

          std::cout << "\n";

          do
          {
               std::cout << "Voce deseja continuar? [S]/[N]: ";
               std::cin >> continuar;

          } while ((continuar != "N") && (continuar != "S"));

          if (continuar == "S")
          {
               escolhidos.clear();
          }
     } while (continuar != "N");
     // system("cls");
     return 1;
}