
#include <iostream>
#include <string>
using namespace std;




class Animal {
private :
    string name = "Animal";
protected:
    int size, age;
public:

    Animal() {                        // Создание Конструктора без параметров 
        cout<<"Базовый конструктор Animal()\n";
        size = 0;
        age = 0;
    }
    Animal(int size, int age) {            // Создание Конструктора с параметрами
        cout<<"Конструктор с параметрами Animal(int size, int age)\n";
        this->size = size;
        this->age = age;
    }
    Animal( Animal& Animal) {                  // Создание Конструктора копирования
        cout<<"Копирующий конуструктор Animal(const Animal &a)\n";
        size = Animal.size;
        age = Animal.age;
    }
    virtual ~Animal() {                      // Создание деструктора
        cout << "Вертуальный деструктор Animal";
    }
    virtual string ClassName() {
        cout << "Виртуальный метод ClassName(Animal)\n";
        return name;
    }
    virtual bool isA(string proverka) {
        cout << "Виртуальный метод isA Animal\n";
        if (name == proverka)
            return true;
        else
            return false;
    }
    void NoVirtual()
    {
        cout << "Невертуальный метод для Animal\n";
    }
    void show()
    {
        cout << "Наследуемый метод\n";
    }

};
class Birds : public Animal { //Создание класса наследника
private:
    string name = "Birds";
public:
    Birds()  {                        // Создание Конструктора без параметров 
        cout<<"Базовый конструктор Birds()\n";
  
    }
    Birds(int size, int age) {            // Создание Конструктора с параметрами
        this->size = size;
        this->age = age;
        cout << "Конструктор с параметрами Birds\n";
    }
    Birds(Birds& Bird) {                  // Создание Конструктора копирования
        size = Bird.size;
        age = Bird.age;
        cout<<"Копирующий консруктор Birds (const Birds& Bird)\n";
    }
    ~Birds() {                      // Создание деструктора
       cout<<"Деструктор ~Birds()\n";
    }
    string ClassName() {
        cout << "Виртуальный метод ClassName(Birds)\n";
        return name;
    }

    bool isA(string proverka) {
        cout << "Виртуальный метод isA(Birds)\n";
        if (name == proverka)
            return true;
        else
            return false;
    }
    void NoVirtual()
    {
        cout << "Невертуальный метод для Birds\n";
    }

};
class Cats : public Animal {
private:
    string name = "Cats";
public:
    Cats() {
        size = 10;
        age = 0;
        cout << "Базовый конструктор Cats\n ";
    }
    Cats(int size1,int age1) {
        size = size1;
        age = age1;
        cout << "конструктор с параметрами Cats\n ";
    }
    Cats(Cats& cat) {
        size = cat.size;
        age = cat.size;
        cout << "Конструктор копирования Cats(Cat& cats)\n ";
    }
    string ClassName() {
        cout << "Виртуальный метод ClassName(Cats)\n";
        return name;
    }
    bool isA(string proverka) {
        cout << "Виртуальный метод isA(Cats)\n";
        if (name == proverka)
            return true;
        else
            return false;
    }
    ~Cats() {
        cout << "Деструктор Сats\n";
    }
    void NoVirtual()
    {
        cout << "Невертуальный метод для Cats\n";
    }

};
class Base {
public:
    Base() {
        cout << "Конструктор Base()\n";
    }
    Base(Base* obj) {
        cout << "Конструктор Base(Base* obj)\n";
    }
    Base(Base& obj) {
        cout << "Конструктор Base(Base& obj)\n";
    }
    ~Base() {
        cout << "Деструктор ~Base()\n";
    }
};

class Desc : public Base {
public:
    Desc() {
        cout << "Конструктор Desc()\n";
    }
    Desc(Desc* obj) {
        cout << "Конструктор Desc(Desc* obj)\n";
    }
    Desc(Desc& obj) {
        cout << "Конструктор Desc(Desc& obj)\n";
    }
    ~Desc() {
        cout << "Деструктор ~Desc()\n";
    }
};
void func1(Base obj) {
    cout << "***** func1 *****\n";
}

void func2(Base* obj) {
    cout << "***** func2 *****\n";
}

void func3(Base& obj) {
    cout << "***** func3 *****\n";
}
int main()
{
    setlocale(LC_CTYPE, "Rus");
    cout << "Создание объектов классов Animal, Birds и Cats:\n\n";
    Animal* ani1 = new Animal();
    cout << endl;
    Birds* ani2 = new Birds();
    cout << endl;
    Animal*ani3 = new Cats();
    cout << endl;
    system("pause");
    system("cls");
    cout << "Проверка на принадлежность к определенному классу:\n\n";

    cout << "Метод ClassName\n";
    cout << ani1->ClassName() << endl;
    cout << ani2->ClassName() << endl;
    cout << ani3->ClassName() << endl << endl;

    cout << "Метод isA\n";
    if (ani1->isA("Animal")) cout << "Да, это животное\n";
    else cout << "Нет, это не животное\n";
    if (ani2->isA("Animal")) cout << "Да, это животное\n";
    else cout << "Нет, это не животное\n";
    if (ani3->isA("Cats")) cout << "Да, это кот\n";
    else cout << "Нет, это не кот\n";

    ani1->show();
    ani2->show();
    ani3->show();

    cout << endl;
    system("pause");
    system("cls");

    cout << "Безопасное приведение типов (dynamic_cast):\n\n";

    Cats* ani4 = dynamic_cast<Cats*>(ani3);
    cout << ani3->ClassName() << endl;
    ani4->NoVirtual();
    ani3->NoVirtual();
    cout << "\n\n";
    cout << "\nОпасное приведение типов:\n";
    Cats* ani5 = new Cats;
    if (ani3->isA("Cats"))
        ani5 = (Cats*)ani3;
    cout << ani5->ClassName() << endl;
    cout << endl;
    system("pause");
    system("cls");

    cout << "Удаление объектов\n\n";
    cout << "Удаление объектов виртуальным деструктором\n";
    delete ani1;
    delete ani2;
    delete ani3;
    cout << endl << "Удаление объекта невиртуальным дескруктором";
    cout << endl << endl;
    Base* probnik = new Desc();
    delete probnik;
    cout << endl << endl;
    Base* probnik2 = new Base();
    delete probnik2;
    cout << endl << endl;
    Desc* probnik3 = new Desc();
    delete probnik3;
    cout << endl;
    system("pause");
    system("cls");
    cout << "Работа с передачей объектов в функцию\n\n";

    cout << "Работа с Base:\n";
    Base base1;
    func1(base1);
    cout << endl;
    Base* base2 = new Base();
    func2(base2);
    cout << endl;
    Base base3;
    func3(base3);
    cout << endl;

    cout << "Работа с Desc:\n";
    Desc Desc1;
    func1(Desc1);
    cout << endl;
    Desc* Desc2 = new Desc();
    func2(Desc2);
    cout << endl;
    Desc Desc3;
    func3(Desc3);
    cout << endl;

    Base* base4 = new Desc();
    func2(base2);
    cout << endl;
}


