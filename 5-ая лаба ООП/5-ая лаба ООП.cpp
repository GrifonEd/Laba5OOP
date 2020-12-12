
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

};
class Cats : Animal {
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

};
int main()
{
    setlocale(LC_CTYPE, "Rus");
    
    
    
}


