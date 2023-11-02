#include <iostream> 

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
void characteristic(Specifications& hero);
void print(const Specifications& hero);
void createobj(Specifications* hero, Specifications** enemy, int n);
void printobj(Specifications* hero, Specifications** enemy, int n);
void saveToFile(const Specifications* objects, int n, const string& filename);