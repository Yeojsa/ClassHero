#include <iostream> 

using namespace std;

///����� ������������� ���������
class Specifications {
private:
    double hp; // ��������
    double damage; // ����
    int armor; // �����
    double eva�h; // ������� �������
public:
    Specifications() {
        hp = 0;
        damage = 0;
        armor = 0;
        eva�h = 0;
    }
    ///����������� ������
    Specifications(int starthp, int startdmg, int startarm, double starteva) {
        sethp(starthp);
        setdamage(startdmg);
        setarmor(startarm);
        seteva�h(starteva);
    }
    ///��������� �������� �������� 
    double gethp() const {
        return hp;
    }
    ///���������� �������� ��
    void sethp(double newhp) {
        if (newhp >= 50 && newhp <= 100) {
            hp = newhp;
        }
        else {
            throw invalid_argument("������������ �������� ��������!");
        }
    }
    ///��������� �������� �����
    int getdamage() const {
        return damage;
    }
    ///���������� �������� �����
    void setdamage(int newdamage) {
        if (newdamage >= 1 && newdamage <= 20) {
            damage = newdamage;
        }
        else {
            throw invalid_argument("������������ �������� �����!");
        }
    }
    ///��������� ������� �����
    int getarmor() const {
        return armor;
    }
    ///���������� �������� �����
    void setarmor(int newarmor) {
        if (newarmor >= 0 && newarmor <= 20) {
            armor = newarmor;
        }
        else {
            throw invalid_argument("������������ �������� �����!");
        }
    }
    ///��������� �������� �������� �������
    double geteva�h() const {
        return eva�h;
    }
    ///���������� �������� �������� �������
    void seteva�h(double neweva�h) {
        if (neweva�h >= 0 && neweva�h <= 0.8) {
            eva�h = neweva�h;
        }
        else {
            throw invalid_argument("������������ �������� ����� �������!");
        }
    }

    ///��������� �����
    void takeDamage(double getdmg) {
        double block = 1 - (armor * 0.05); //���� �����
        double incdmg = getdmg * block; //���� ����� �����
        if (incdmg > 0) {
            double evar = (double)rand() / RAND_MAX; //��������� �� 0 �� 1   
            //�������� �� ������
            if (evar > eva�h) {
                hp -= incdmg;
            }
            else {
                cout << "�����: ���������." << endl;
            }
        }
    }
    ///�����
    void attack(Specifications& bot) {
        double block = 1 - (bot.armor * 0.05); //���� �����
        double incdmg = damage * block;  //���� ����� �����
        if (incdmg > 0) {
            double evar = (double)rand() / RAND_MAX; //��������� �� 0 �� 1   
            //�������� �� ������
            if (evar > bot.eva�h) {
                bot.takeDamage(incdmg);
                bot.hp -= incdmg;
            }
            else {
                cout << "����: ���������." << endl;
            }
        }
    }
};
void characteristic(Specifications& hero);
void print(const Specifications& hero);
void createobj(Specifications* hero, Specifications** enemy, int n);
void printobj(Specifications* hero, Specifications** enemy, int n);
void saveToFile(const Specifications* objects, int n, const string& filename);