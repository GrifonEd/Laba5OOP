
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
        printf("Animal()\n");
        size = 0;
        age = 0;
    }
    Animal(int size, int age) {            // Создание Конструктора с параметрами
        printf("Animal(int size, int age)\n");
        this->size = size;
        this->age = age;
    }
    Animal(const Animal& a) {                  // Создание Конструктора копирования
        printf("Animal(const Animal &a)\n");
        size = a.size;
        age = a.age;
    }
    ~Animal() {                      // Создание деструктора
        printf("%d, %d \n", size, age);
        printf("~Animal()\n");
    }
    void train(int time, int strength) {
        size = size + time * strength;
        age = age + time * strength;
    }
    int recreation()
    {
        return size;
    }
    virtual void show()
    {
        cout << "Тут животное";
    }

};
class Birds : public Animal { //Создание класса наследника
protected:
    int SizeWings;                        //Создание атрибутов наследования 
public:
    Birds() : Animal() {                        // Создание Конструктора без параметров 
        printf("Birds()\n");
        SizeWings = 0;
    }
    Birds(int size, int age, int SizeWings) : Animal(size, age) {            // Создание Конструктора с параметрами
        printf("Birds(int size, int age,int SizeWings)\n");
        this->SizeWings = SizeWings;
    }
    Birds(const Birds& a) {                  // Создание Конструктора копирования
        printf("Birds(const Birds& a)\n");
        size = a.size;
        age = a.age;
        SizeWings = a.SizeWings;
    }
    ~Birds() {                      // Создание деструктора
        printf("%d, %d, %d\n", size, age, SizeWings);
        printf("~Birds()\n");
    }
    void train_fly(int new_SizeWings) {
        SizeWings = new_SizeWings;
    }
    void show()
    {
        cout << "Тут птица";
    }

};
int main()
{
    setlocale(LC_CTYPE, "Rus");
    Animal* Ani = new Animal(50, 60);
    Ani->show();
    //delete Ani;
    Birds *Milky = new Birds(10, 20, 30);
    Milky->recreation();
    //delete Milky;
    
    
}


