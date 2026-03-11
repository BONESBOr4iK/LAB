#include <iostream>
#include <string>

class Virus
{
private:
    double Death_percent;       // Процент летальности
    std::string Carrier;        // Главный переносчик вируса
    unsigned int Count_victims; // Кол-во жертв

protected:
    bool VaccineIsTrue; // Есть ли вакцина

public:
    std::string GetCarrier() const { return Carrier; }; // Геттер
    Virus(double death_percent, std::string carrier, unsigned int count_victims, bool vaccineIsTrue);
    virtual ~Virus();
    virtual double GetDeath_percent() const { return Death_percent; };
    virtual int GetCount_victims() const { return Count_victims; };
    virtual bool Win() const { return VaccineIsTrue; };
    virtual void Print() const;
};

Virus::Virus(double death_percent, std::string carrier, unsigned int count_victims, bool vaccineIsTrue)
    : Death_percent(death_percent), Carrier(carrier), Count_victims(count_victims), VaccineIsTrue(vaccineIsTrue)
{
    std::cout << "Создание вируса в биолаборатории" << std::endl;
}

Virus::~Virus()
{
    std::cout << "Конец эксперимента" << std::endl;
}

void Virus::Print() const
{
    std::cout << "Статистика эксперимента по вирусу: " << std::endl
              << "Летальность вируса: "
              << GetDeath_percent() << "%" << std::endl
              << "Количество жертв: "
              << GetCount_victims() << " человек" << std::endl;
}

class Plague : public Virus
{
private:
    std::string Vaccine;

public:
    Plague();
    ~Plague();
    bool Win() const override;
    void Print() const override;
    std::string GetVaccine() const { return Vaccine; };
};

Plague::Plague()
    : Virus(98.5, "Rats", 100000000, true),
      Vaccine("Penicillium")
{
    std::cout << "Создание чумы" << std::endl;
}

Plague::~Plague()
{
    std::cout << "Исчезновение чумы" << std::endl;
}

bool Plague::Win() const
{
    return Virus::Win();
}

void Plague::Print() const
{
    Virus::Print();
    if (Win())
    {
        std::cout << "Вирус побежден, с помощью вакцины: " << GetVaccine() << std::endl;
    }
    else
        std::cout << "Вакцина не была создана, эпидемия продолжается" << std::endl;
}

class EX201000CF : public Virus
{
private:
    std::string Symptoms;

public:
    EX201000CF();
    ~EX201000CF();
    int Count_dead_cityes() const;
    void Print() const override;
    bool Win() const override;
    int GetCount_victims() const override;
    double GetDeath_percent() const override;
};

EX201000CF::EX201000CF()
    : Virus(48.6, "Pigeons", 52679780, false),
      Symptoms("Кровавый кашель, пневмония, слабость, слабый стул")
{
    std::cout << "Создание вируса EX201000CF" << std::endl;
}

EX201000CF::~EX201000CF()
{
    std::cout << "Ликвидация EX201000CF" << std::endl;
}

int EX201000CF::GetCount_victims() const
{
    return Virus::GetCount_victims();
}

double EX201000CF::GetDeath_percent() const
{
    return Virus::GetDeath_percent();
}

int EX201000CF::Count_dead_cityes() const
{
    const int average_city = 700000;
    int dead_cityes = (GetCount_victims() / average_city);
    return dead_cityes;
}

bool EX201000CF::Win() const
{
    return Virus::Win();
}

void EX201000CF::Print() const
{
    Virus::Print();
    std::cout << "Городов уничтожено: " << Count_dead_cityes() << std::endl;
    if (Win())
    {
        std::cout << "Вирус побежден, с помощью вакцины: " << std::endl;
    }
    else
        std::cout << "Вакцина не была создана, эпидемия продолжается" << std::endl;
}

class Umbrella : public Virus
{
public:
    Umbrella(std::string carrier);
    ~Umbrella();
    void Print() const override;
    int GetCount_victims() const override;
    double GetDeath_percent() const override;
    bool Win() const override;
    double Zombie_percent() const;
};

Umbrella::Umbrella(std::string carrier)
    : Virus(95.0, carrier, 5500000000, false)
{
    std::cout << "Выпуск вируса в Racoon city" << std::endl;
}

Umbrella::~Umbrella()
{
    std::cout << "Вирус выбрался за пределы" << std::endl;
}

int Umbrella::GetCount_victims() const
{
    return Virus::GetCount_victims();
}

double Umbrella::GetDeath_percent() const
{
    return Virus::GetDeath_percent();
}

bool Umbrella::Win() const
{
    return Virus::Win();
}

double Umbrella::Zombie_percent() const
{
    std::string carrier = GetCarrier();
    if (carrier == "Human")
    {
        std::cout << " Высокий риск зомбификации" << std::endl;
        return 97.0;
    }
    else if (carrier == "Pet")
    {
        std::cout << " Большой риск зомбификации" << std::endl;
        return 76.0;
    }
    else if (carrier == "Rat")
    {
        std::cout << " Средний риск зомбификации" << std::endl;
        return 55.0;
    }
    else if (carrier == "Bird")
    {
        std::cout << " Низкий риск зомбификации" << std::endl;
        return 25.0;
    }
    else
    {
        std::cout << " Неизвестный носитель, информация неизвестна. Риск зомбификации" << std::endl;
        return GetDeath_percent() * 0.5;
        ;
    }
}
void Umbrella::Print() const
{
    Virus::Print();
    std::cout << "Переносчик: " << GetCarrier() << Zombie_percent() << "%" << std::endl;
    if (Win())
    {
        std::cout << "Вирус побежден, с помощью вакцины: " << std::endl;
    }
    else
        std::cout << "Вакцина не была создана, эпидемия продолжается" << std::endl;
}

int main()
{
    {
        Virus *NewVirus1 = new Plague;
        NewVirus1->Print();
        delete NewVirus1;
    }
    std::cout << "=---------------------------------------------------=" << std::endl;
    {
        Virus *NewVirus2 = new EX201000CF;
        NewVirus2->Print();
        delete NewVirus2;
    }
    std::cout << "=---------------------------------------------------=" << std::endl;
    {
        Virus *T_Virus = new Umbrella("Pigeon");
        T_Virus->Print();
        delete T_Virus;
    }
    return 0;
}