### Инкапсуляция, наследование, полиморфизм в C++

Эти три концепции являются основными принципами объектно-ориентированного программирования (ООП). Разберём их подробно.

---

## **1. Инкапсуляция**
Инкапсуляция — это механизм, который скрывает внутреннюю реализацию класса и предоставляет доступ к данным через интерфейс (методы). Это достигается с помощью модификаторов доступа:  
- `private` — доступен только внутри класса.  
- `protected` — доступен внутри класса и его наследников.  
- `public` — доступен извне.  

### Пример инкапсуляции:
```cpp
#include <iostream>

class BankAccount {
private:
    double balance;  // Закрытая переменная, доступна только внутри класса

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    double getBalance() const {  // Открытый метод для доступа к данным
        return balance;
    }
};

int main() {
    BankAccount account(1000);
    account.deposit(500);
    account.withdraw(200);
    std::cout << "Баланс: " << account.getBalance() << std::endl;
    return 0;
}
```
**Вывод:** `Баланс: 1300`  
В этом примере `balance` скрыт от внешнего кода, и доступ к нему возможен только через методы `deposit`, `withdraw`, `getBalance`.

---

## **2. Наследование**
Наследование позволяет создавать новый класс на основе существующего. Базовый класс передает дочерним классам свойства и методы.

### Пример наследования:
```cpp
#include <iostream>

// Базовый класс
class Animal {
protected:
    std::string name;

public:
    Animal(std::string n) : name(n) {}

    void speak() const {
        std::cout << name << " издаёт звук" << std::endl;
    }
};

// Производный класс (наследник)
class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}

    void bark() const {
        std::cout << name << " лает" << std::endl;
    }
};

int main() {
    Dog myDog("Шарик");
    myDog.speak(); // Наследованный метод
    myDog.bark();  // Собственный метод класса Dog
    return 0;
}
```
**Вывод:**  
```
Шарик издаёт звук
Шарик лает
```
Класс `Dog` унаследовал `speak()` из `Animal`, но добавил свой метод `bark()`.

---

## **3. Полиморфизм**
Полиморфизм позволяет работать с разными объектами через единый интерфейс. Он бывает:
1. **Компиляторный (статический)** — перегрузка функций и операторов.
2. **Рантаймовый (динамический)** — использование виртуальных функций.

### **3.1. Статический полиморфизм (перегрузка)**
```cpp
#include <iostream>

class MathUtils {
public:
    static int sum(int a, int b) {
        return a + b;
    }

    static double sum(double a, double b) {
        return a + b;
    }
};

int main() {
    std::cout << MathUtils::sum(2, 3) << std::endl;   // Вызывает int sum
    std::cout << MathUtils::sum(2.5, 3.5) << std::endl; // Вызывает double sum
    return 0;
}
```
**Вывод:**
```
5
6
```
Метод `sum()` перегружен — компилятор сам выбирает подходящую версию.

---

### **3.2. Динамический полиморфизм (виртуальные функции)**
```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() const { // Виртуальная функция
        std::cout << "Животное издаёт звук" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override { // Переопределение метода
        std::cout << "Собака лает" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Кошка мяукает" << std::endl;
    }
};

void makeSound(const Animal& animal) { // Принимаем объект базового класса
    animal.speak(); // Вызывается метод конкретного объекта
}

int main() {
    Dog dog;
    Cat cat;

    makeSound(dog); // Собака лает
    makeSound(cat); // Кошка мяукает

    return 0;
}
```
**Вывод:**
```
Собака лает
Кошка мяукает
```
Здесь `speak()` — виртуальная функция. Вызов зависит от типа объекта в `makeSound()`.

---

## **Вывод**
- **Инкапсуляция** защищает данные и обеспечивает контроль доступа.
- **Наследование** позволяет создавать новые классы на основе существующих.
- **Полиморфизм** позволяет работать с объектами через единый интерфейс.

Эти принципы помогают писать гибкий и расширяемый код.

# Свойства и методы

В контексте объектно-ориентированного программирования (ООП) **свойства и методы** — это основные составляющие классов.

### **1. Свойства (атрибуты, поля класса)**  
**Свойства** — это переменные, хранящие состояние объекта. Они могут быть **публичными**, **защищёнными** или **приватными**.  

Пример в C++:
```cpp
class Car {
public:
    std::string brand; // Свойство (публичное)
    int speed;

    Car(std::string b, int s) : brand(b), speed(s) {} // Конструктор
};
```
Здесь `brand` и `speed` — **свойства** объекта класса `Car`.

---

### **2. Методы (функции класса)**  
**Методы** — это функции, принадлежащие классу. Они позволяют работать с данными объекта.

Пример:
```cpp
class Car {
public:
    std::string brand;
    int speed;

    Car(std::string b, int s) : brand(b), speed(s) {}

    void accelerate(int amount) { // Метод
        speed += amount;
    }

    void showInfo() const { // Метод
        std::cout << "Марка: " << brand << ", Скорость: " << speed << " км/ч" << std::endl;
    }
};

int main() {
    Car myCar("Toyota", 100);
    myCar.accelerate(20); // Вызов метода
    myCar.showInfo();     // Вызов метода
}
```
**Вывод:**
```
Марка: Toyota, Скорость: 120 км/ч
```
Здесь `accelerate()` и `showInfo()` — **методы**.

### **Вывод**
- **Свойства (переменные класса)** хранят данные объекта.
- **Методы (функции класса)** выполняют действия над объектом.



### **1. `private`: недоступно в наследниках**
Если свойство объявлено как `private`, то оно **недоступно напрямую** в наследниках.

```cpp
#include <iostream>

class Parent {
private:
    int value = 10; // Приватное свойство

public:
    int getValue() const { return value; } // Доступ через метод
};

class Child : public Parent {
public:
    void showValue() {
        // std::cout << value; // Ошибка! value — private
        std::cout << getValue() << std::endl; // Доступ через public-метод
    }
};

int main() {
    Child obj;
    obj.showValue(); // Выведет: 10
}
```
Здесь `value` **недоступен** в `Child`, но можно обратиться к нему через `getValue()`.

---

### **2. `protected`: доступно в наследниках**
Если свойство объявлено как `protected`, оно **недоступно извне, но доступно внутри наследников**.

```cpp
#include <iostream>

class Parent {
protected:
    int value = 20; // Защищённое свойство
};

class Child : public Parent {
public:
    void showValue() {
        std::cout << value << std::endl; // Доступ разрешён
    }
};

int main() {
    Child obj;
    obj.showValue(); // Выведет: 20
}
```
Здесь `value` **доступен** в `Child`, так как он `protected`.

---

### **Вывод**
| Модификатор  | Доступ в родительском классе | Доступ в наследниках | Доступ извне |
|-------------|-------------------|----------------|------------|
| `private`   | ✅ Да              | ❌ Нет         | ❌ Нет     |
| `protected` | ✅ Да              | ✅ Да          | ❌ Нет     |
| `public`    | ✅ Да              | ✅ Да          | ✅ Да      |

Таким образом, **если свойство `private`, то напрямую работать с ним в наследнике невозможно**. Если оно `protected`, то его можно использовать в наследниках.
