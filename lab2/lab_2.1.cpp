#include <iostream>
#include <string>

struct Calculator
{

    std::string name;
    double cost;
    int number;
    std::string colour;
};
// Будем сравнивать по цене и находить самый дорогой калькулятор
int Sravn(const Calculator *Array, int array_size)
{
    int maxIndex = 0;
    for (int i = 1; i < array_size; i++)
    {
        if (Array[i].cost > Array[maxIndex].cost)
            maxIndex = i;
    }
    return maxIndex;
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int array_size = 4;
    Calculator *Array = new Calculator[array_size];
    Array[0].name = "Casio FX560";
    Array[0].cost = 5.0 + (rand() % 100) / 20.0;
    Array[0].number = 1001 + rand() % 9999;
    Array[0].colour = "Blue";

    Array[1].name = "Casio X70";
    Array[1].cost = 5.0 + (rand() % 100) / 20.0;
    Array[1].number = 1001 + rand() % 9999;
    Array[1].colour = "Yellow";

    Array[2].name = "Casio FS756";
    Array[2].cost = 5.0 + (rand() % 100) / 20.0;
    Array[2].number = 1001 + rand() % 9999;
    Array[2].colour = "Red";

    Array[3].name = "Casio S674";
    Array[3].cost = 5.0 + (rand() % 100) / 20.0;
    Array[3].number = 1001 + rand() % 9999;
    Array[3].colour = "Green";

    int maxIndex = Sravn(Array, array_size);
    std::cout << "Самый дорогой калькулятор под индексом: " << maxIndex << " С названием: "
              << Array[maxIndex].name << " Его цена - " << Array[maxIndex].cost << "$" << std::endl;
    delete[] Array;
    Array = nullptr;
    return 0;
}