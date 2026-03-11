#include <iostream>
#include <string>

class Virus
{
private:
    double Death_percent;       // Процент летальности
    std::string Carrier;        // Переносчик вируса
    unsigned int Count_victims; // Кол-во жертв

protected:
    bool VaccineIsTrue; // Есть ли вакцина

public:
    Virus(double death_percent, std::string carrier, unsigned int count_victims, bool vaccineIsTrue);
    virtual ~Virus();
    virtual double GetDeath_percent() const { return Death_percent; };
    virtual int GetCount_victims() const { return Count_victims; };
    void Print();
};

Virus::Virus(double death_percent, std::string carrier, unsigned int count_victims, bool vaccineIsTrue)
    : Death_percent(death_percent), Carrier(carrier), Count_victims(count_victims), VaccineIsTrue(vaccineIsTrue)
{
    std::cout << "Создание вируса в биолабаратории" << std::endl;
}

Virus::~Virus()
{
    std::cout << "Провальный штамм" << std::endl;
}

void Virus::Print()
{
    std::cout << "Статистика эксперимента по вирусу: " << std::endl
              << GetDeath_percent() << std::endl
              << GetCount_victims() << std::endl;
}

int main()
{
    Virus Virus1(16.7, "Rat", 15, true);
    Virus1.Print();
    return 0;
}