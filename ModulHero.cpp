#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <stdexcept>
#include <fstream>
#include <cstdlib>



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

void saveToFile(const Specifications* objects, int n, const string& filename) {
    ofstream outFile(filename); // открываем файл для записи

    if (outFile.is_open()) { // проверяем, удалось ли открыть файл
        for (int i = 0; i < n; i++) {
            outFile << "Игрок " << i + 1 << ":" << std::endl;
            outFile << "HP: " << objects[i].gethp() << std::endl;
            outFile << "Урон: " << objects[i].getdamage() << std::endl;
            outFile << "Броня: " << objects[i].getarmor() << std::endl;
            outFile << "Шанс уворота: " << (objects[i].getevaсh() * 100) << "%" << std::endl;
            outFile << std::endl;
        }

        outFile.close(); // закрываем файл
        std::cout << "Состояние объектов успешно записано в файл " << filename << std::endl;
    }
    else {
        std::cout << "Не удалось открыть файл " << filename << " для записи" << std::endl;
    }
}