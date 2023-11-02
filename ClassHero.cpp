#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <stdexcept>
//#include "ModulHero.h"
#include <cassert>
using namespace std;

///класс характеристик персонажа
class Specifications {
private:
    double hp; // здоровье
    double damage; // урон
    int armor; // броня
    double evaсh; // процент уворота
public:
    Specifications() {
        hp = 0;
        damage = 0;
        armor = 0;
        evaсh = 0;
    }
    ///конструктор класса
    Specifications(int starthp, int startdmg, int startarm, double starteva) {
        sethp(starthp);
        setdamage(startdmg);
        setarmor(startarm);
        setevaсh(starteva);
    }
    ///получение текущего здоровья 
    double gethp() const {
        return hp;
    }
    ///присвоение значений хп
    void sethp(double newhp) {
        if (newhp >= 50 && newhp <= 100) {
            hp = newhp;
        }
        else {
            throw invalid_argument("Некорректное значение здоровья!");
        }
    }
    ///получение текущего урона
    int getdamage() const {
        return damage;
    }
    ///присвоение значений урона
    void setdamage(int newdamage) {
        if (newdamage >= 1 && newdamage <= 20) {
            damage = newdamage;
        }
        else {
            throw invalid_argument("Некорректное значение урона!");
        }
    }
    ///получение текущей брони
    int getarmor() const {
        return armor;
    }
    ///присвоение значений брони
    void setarmor(int newarmor) {
        if (newarmor >= 0 && newarmor <= 20) {
            armor = newarmor;
        }
        else {
            throw invalid_argument("Некорректное значение брони!");
        }
    }
    ///получение текущего процента уворота
    double getevaсh() const {
        return evaсh;
    }
    ///присвоение значений процента уворота
    void setevaсh(double newevaсh) {
        if (newevaсh >= 0 && newevaсh <= 0.8) {
            evaсh = newevaсh;
        }
        else {
            throw invalid_argument("Некорректное значение шанса уворота!");
        }
    }

    ///получение урона
    void takeDamage(double getdmg) {
        double block = 1 - (armor * 0.05); //блок урона
        double incdmg = getdmg * block; //урон после блока
        if (incdmg > 0) {
            double evar = (double)rand() / RAND_MAX; //генерация от 0 до 1   
            //проверка на уворот
            if (evar > evaсh) {
                hp -= incdmg;
            }
            else {
                cout << "Игрок: увернулся." << endl;
            }
        }
    }
    ///атака
    void attack(Specifications& bot) {
        double block = 1 - (bot.armor * 0.05); //блок урона
        double incdmg = damage * block;  //урон после блока
        if (incdmg > 0) {
            double evar = (double)rand() / RAND_MAX; //генерация от 0 до 1   
            //проверка на уворот
            if (evar > bot.evaсh) {
                bot.takeDamage(incdmg);
                bot.hp -= incdmg;
            }
            else {
                cout << "Враг: увернулся." << endl;
            }
        }
    }
}; 

// начальные характеристики
void characteristic(Specifications& hero) {
    double hp, dmg, eva;
    int armor;

    cout << "Введите количество здоровья игрока (от 50 до 100): ";
    cin >> hp;
    hero.sethp(hp);

    cout << "Введите количество урона игрока (от 1 до 20): ";
    cin >> dmg;
    hero.setdamage(dmg);

    cout << "Введите количество брони игрока (от 0 до 20): ";
    cin >> armor;
    hero.setarmor(armor);

    cout << "Введите шанс уворота игрока (от 0 до 80 в процентах): ";
    cin >> eva;
    hero.setevaсh(eva / 100.0);
}


//вывод начальных характеристик
void print(const Specifications& hero) {
    cout << "HP: " << hero.gethp() << endl;
    cout << "Урон: " << hero.getdamage() << endl;
    cout << "Броня: " << hero.getarmor() << endl;
    cout << "Шанс уворота: " << hero.getevaсh() * 100 << "%" << endl;
}

void createobj(Specifications* hero, Specifications** enemy, int n) {
    for (int i = 0; i < n; i++) {
        double hp, dmg, eva;
        int armor;

        cout << "Введите количество здоровья игрока " << i + 1 << " (от 50 до 100): ";
        cin >> hp;
        hero[i].sethp(hp);

        cout << "Введите количество урона игрока " << i + 1 << " (от 1 до 20): ";
        cin >> dmg;
        hero[i].setdamage(dmg);

        cout << "Введите количество брони игрока " << i + 1 << " (от 0 до 20): ";
        cin >> armor;
        hero[i].setarmor(armor);

        cout << "Введите шанс уворота игрока " << i + 1 << " (от 0 до 80 в процентах): ";
        cin >> eva;
        hero[i].setevaсh(eva / 100.0);

        // Выделение памяти для элементов массива врагов
        enemy[i] = new Specifications();

        cout << "Введите количество здоровья врага " << i + 1 << " (от 50 до 100): ";
        cin >> hp;
        enemy[i]->sethp(hp);

        cout << "Введите количество урона врага " << i + 1 << " (от 1 до 20): ";
        cin >> dmg;
        enemy[i]->setdamage(dmg);

        cout << "Введите количество брони врага " << i + 1 << " (от 0 до 20): ";
        cin >> armor;
        enemy[i]->setarmor(armor);

        cout << "Введите шанс уворота врага " << i + 1 << " (от 0 до 80 в процентах): ";
        cin >> eva;
        enemy[i]->setevaсh(eva / 100.0);
    }
}

void printobj(Specifications* hero, Specifications** enemy, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Игрок " << i + 1 << ":" << endl;
        cout << "HP: " << hero[i].gethp() << endl;
        cout << "Урон: " << hero[i].getdamage() << endl;
        cout << "Броня: " << hero[i].getarmor() << endl;
        cout << "Шанс уворота: " << (hero[i].getevaсh() * 100) << "%" << endl;
        cout << endl;
        cout << "Враг " << i + 1 << ":" << endl;
        cout << "HP: " << enemy[i]->gethp() << endl;
        cout << "Урон: " << enemy[i]->getdamage() << endl;
        cout << "Броня: " << enemy[i]->getarmor() << endl;
        cout << "Шанс уворота: " << (enemy[i]->getevaсh() * 100) << "%" << endl;
        cout << endl;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    srand(time(0));


    char S;
    cout << "Создать 1 объект? (y/n): ";
    cin >> S;
    if (S == 'y' || S == 'Y') {

        Specifications player;
        cout << "Характеристики игрока" << endl;
        try {
            characteristic(player);
            cout << endl;
            cout << "Характеристики игрока" << endl;
            print(player);
            cout << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
            exit(0);
        }

        Specifications* enemy = nullptr;

        cout << "Характеристики врага" << endl;
        try {
            enemy = new Specifications();
            characteristic(*enemy);
            cout << endl;
            cout << "Характеристики врага" << endl;
            print(*enemy);
            cout << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
            delete enemy;
            exit(0);
        }

        //сражение 
        while (player.gethp() > 0 && (*enemy).gethp() > 0) {
            player.attack(*enemy);
            cout << "HP врага: " << (*enemy).gethp() << endl;
            if ((*enemy).gethp() <= 0) {
                break;
            }
            (*enemy).attack(player);
            cout << "HP игрока: " << player.gethp() << endl;
            if (player.gethp() <= 0) {
                break;
            }
            cout << endl;
        }

        cout << endl;

        if (player.gethp() <= 0) {
            cout << "Игрок проиграл" << endl;
        }
        else if ((*enemy).gethp() <= 0) {
            cout << "Враг проиграл" << endl;
        }

        delete enemy;
        enemy = nullptr;
    }
    else {
        const int n = 3;
      
        Specifications players[n];
        Specifications** enemies = new Specifications * [n];
        try {
            createobj(players, enemies, n);
            cout << "Характеристики игроков и врагов:" << endl;
            printobj(players, enemies, n);
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
            for (int i = 0; i < n; i++) {
                delete enemies[i];
            }
            delete[] enemies;
            delete[] players;
            exit(0);
        }
        for (int i = 0; i < n; i++) {
            delete enemies[i];
        }
        delete[] enemies;
        delete[] players;
    }
    return 0;

}


