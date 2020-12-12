
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
        cout << "Тут животное\n";
    }

};
class Birds : public Animal { //Создание класса наследника
private:
    string name = "Birds";
public:
    Birds()  {                        // Создание Конструктора без параметров 
        cout<<"Базовый конструктор Birds()\n";
  
    }
    Birds(int size, int age, int SizeWings) : Animal(size, age) {            // Создание Конструктора с параметрами
        printf("Birds(int size, int age,int SizeWings)\n");
        this->SizeWings = SizeWings;
    }
    Birds(Birds& Bird) {                  // Создание Конструктора копирования
        size = Bird.size;
        age = Bird.age;
        cout<<"Копирующий консруктор Birds (const Birds& Bird)\n";
    }
    ~Birds() {                      // Создание деструктора
       cout<<"Деструктор ~Birds()\n";
    }
    void train_fly() {
    }
    void show()
    {
        cout << "Тут птица";
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
    Cats() {
        size = 10;
        age = 0;
        cout << "Базовый конструктор Cats\n ";
    }
    Cats(Cats& cat) {
        size = cat.size;
        age = cat.size;
        cout << "Конструктор копирования Cats(Cat& cats)\n ";
    }
    ~Cats() {
        cout << "Деструктор Сats\n";
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


