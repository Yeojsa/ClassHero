#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <stdexcept>
#include <fstream>
#include <cstdlib>



// ��������� ��������������
void characteristic(Specifications& hero) {
    double hp, dmg, eva;
    int armor;

    cout << "������� ���������� �������� ������ (�� 50 �� 100): ";
    cin >> hp;
    hero.sethp(hp);

    cout << "������� ���������� ����� ������ (�� 1 �� 20): ";
    cin >> dmg;
    hero.setdamage(dmg);

    cout << "������� ���������� ����� ������ (�� 0 �� 20): ";
    cin >> armor;
    hero.setarmor(armor);

    cout << "������� ���� ������� ������ (�� 0 �� 80 � ���������): ";
    cin >> eva;
    hero.seteva�h(eva / 100.0);
}


//����� ��������� �������������
void print(const Specifications& hero) {
    cout << "HP: " << hero.gethp() << endl;
    cout << "����: " << hero.getdamage() << endl;
    cout << "�����: " << hero.getarmor() << endl;
    cout << "���� �������: " << hero.geteva�h() * 100 << "%" << endl;
}

void createobj(Specifications* hero, Specifications** enemy, int n) {
    for (int i = 0; i < n; i++) {
        double hp, dmg, eva;
        int armor;

        cout << "������� ���������� �������� ������ " << i + 1 << " (�� 50 �� 100): ";
        cin >> hp;
        hero[i].sethp(hp);

        cout << "������� ���������� ����� ������ " << i + 1 << " (�� 1 �� 20): ";
        cin >> dmg;
        hero[i].setdamage(dmg);

        cout << "������� ���������� ����� ������ " << i + 1 << " (�� 0 �� 20): ";
        cin >> armor;
        hero[i].setarmor(armor);

        cout << "������� ���� ������� ������ " << i + 1 << " (�� 0 �� 80 � ���������): ";
        cin >> eva;
        hero[i].seteva�h(eva / 100.0);

        // ��������� ������ ��� ��������� ������� ������
        enemy[i] = new Specifications();

        cout << "������� ���������� �������� ����� " << i + 1 << " (�� 50 �� 100): ";
        cin >> hp;
        enemy[i]->sethp(hp);

        cout << "������� ���������� ����� ����� " << i + 1 << " (�� 1 �� 20): ";
        cin >> dmg;
        enemy[i]->setdamage(dmg);

        cout << "������� ���������� ����� ����� " << i + 1 << " (�� 0 �� 20): ";
        cin >> armor;
        enemy[i]->setarmor(armor);

        cout << "������� ���� ������� ����� " << i + 1 << " (�� 0 �� 80 � ���������): ";
        cin >> eva;
        enemy[i]->seteva�h(eva / 100.0);
    }
}

void printobj(Specifications* hero, Specifications** enemy, int n) {
    for (int i = 0; i < n; i++) {
        cout << "����� " << i + 1 << ":" << endl;
        cout << "HP: " << hero[i].gethp() << endl;
        cout << "����: " << hero[i].getdamage() << endl;
        cout << "�����: " << hero[i].getarmor() << endl;
        cout << "���� �������: " << (hero[i].geteva�h() * 100) << "%" << endl;
        cout << endl;
        cout << "���� " << i + 1 << ":" << endl;
        cout << "HP: " << enemy[i]->gethp() << endl;
        cout << "����: " << enemy[i]->getdamage() << endl;
        cout << "�����: " << enemy[i]->getarmor() << endl;
        cout << "���� �������: " << (enemy[i]->geteva�h() * 100) << "%" << endl;
        cout << endl;
    }
}

void saveToFile(const Specifications* objects, int n, const string& filename) {
    ofstream outFile(filename); // ��������� ���� ��� ������

    if (outFile.is_open()) { // ���������, ������� �� ������� ����
        for (int i = 0; i < n; i++) {
            outFile << "����� " << i + 1 << ":" << std::endl;
            outFile << "HP: " << objects[i].gethp() << std::endl;
            outFile << "����: " << objects[i].getdamage() << std::endl;
            outFile << "�����: " << objects[i].getarmor() << std::endl;
            outFile << "���� �������: " << (objects[i].geteva�h() * 100) << "%" << std::endl;
            outFile << std::endl;
        }

        outFile.close(); // ��������� ����
        std::cout << "��������� �������� ������� �������� � ���� " << filename << std::endl;
    }
    else {
        std::cout << "�� ������� ������� ���� " << filename << " ��� ������" << std::endl;
    }
}