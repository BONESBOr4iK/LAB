#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Calculator
{
    я очивку хочу

        std::string name;
    double cost;
    int number;
    std::string colour;
};
int main()
{
    setlocale(LC_ALL, " ");
    std::vector<Calculator> Array;
    std::ifstream file("constructor.txt");
    if (!file.is_open())
    {
        std::cout << "Ошибка открытии файла" << std::endl;
        return 1;
    }
    Calculator current;

    while (file >> current.name >> current.cost >> current.number >> current.colour)
    {
        Array.push_back(current);
    }

    file.close();

    std::cout << "=========================================" << std::endl;
    std::cout << "|\t\t\t Серийный\t|" << std::endl;
    std::cout << "| Название\tЦена\t номер\t  Цвет\t|" << std::endl;
    std::cout << "=========================================" << std::endl;
    for (auto &file : Array)
    {
        std::cout << "| " << file.name << "\t|" << file.cost << "$\t| " << file.number << " \t|" << file.colour << "\t"
                  << "|" << std::endl;
    }
    std::cout << "=========================================" << std::endl;
    std::stringstream strm;
    for (auto &file : Array)
    {
        strm << "Название: " << file.name << "\n";
        strm << "Цена: " << file.cost << "$" << "\n";
        strm << "Серийный номер: " << file.number << "\n";
        strm << "Цвет: " << file.colour << "\n";
        strm << "\n";
    }
    std::ofstream fileb("calc.bin", std::ios::binary);
    std::string strok = strm.str();
    fileb.write(strok.c_str(), strok.size());
    fileb.close();

    return 0;
}
