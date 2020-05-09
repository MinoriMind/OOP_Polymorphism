#include <iostream>
#include <vector>

using namespace std;
/*Реализовать программу демонстрирующую предметную область "Пиццерия"

Заказ - это список из выбранных пользователем пицц.

Пицца - это блюдо, которое выбирает пользователь. Пицца обладает именем(текст),
описанием(текст), размером (один из вариантов 25, 30, 35, 40,
который выбирает пользователь), ценой(зависит от размера выбранной пиццы и ингредиентов).
Пользователь может подсолить любую пиццу N-раз или добавить сыра M-раз - это
увеличивает цену в зависимости от вида и размера пиццы
(формулу придумать на ваше усмотрение)

Заказ - формируется пользователем через консоль, возможность добавить пиццу,
 распечатать заказ в консоль.

Печать заказа - вывод всего списка выбранных пользователем пицц, с указанием
 названия, описания, N-соли и M-сыра, размера пиццы и стоимости пиццы с
 учётом всех параметров

В конце распечатанного заказа вывести итоговую сумму за заказ*/

enum PizzaSize
{
    smallest = 25,
    small = 30,
    big = 35,
    superBig = 40
};


class Pizza
{
    unsigned int saltiness = 0;
    unsigned int cheeseNum = 0;

protected:
    PizzaSize size;

    Pizza(PizzaSize _size, unsigned int _cheeseNum, unsigned int _saltiness)
    {
        size = _size;
        AddCheese(_cheeseNum);
        AddSalt(_saltiness);
    }

public:
    unsigned int GetSaltiness()
    {
        return saltiness;
    }

    void AddSalt(unsigned int value)
    {
        saltiness += value;
    }

    unsigned int GetCheeseNum()
    {
        return cheeseNum;
    }

    void AddCheese(unsigned int value)
    {
        cheeseNum += value;
    }

    unsigned int GetSize()
    {
        return size;
    }

    virtual void PrintDescription() = 0;
    virtual unsigned int TypeCost() = 0;
    virtual unsigned int SaltCost() = 0;
    virtual unsigned int CheeseCost() = 0;

    unsigned int PizzaCost()
    {
        unsigned int saltCost = saltiness*SaltCost();
        unsigned int cheeseCost = cheeseNum*CheeseCost();
        unsigned int result = TypeCost() + saltCost + cheeseCost;

        return result;
    }

    void PrintCost()
    {
        cout << PizzaCost() << endl;
    }

    unsigned int GetPizzaCost()
    {
        return PizzaCost();
    }
};

class CoolPizza: public Pizza
{
public:
    CoolPizza(PizzaSize _size, unsigned int _cheeseNum, unsigned int _saltiness) :
        Pizza(_size, _cheeseNum, _saltiness){};

    void PrintDescription()
    {
        cout << "This is a cool pizza. Buy it, plz" << endl;
    }

    unsigned int TypeCost()
    {
        return 99*size;
    }

    unsigned int CheeseCost()
    {
        return 0;
    }

    unsigned int SaltCost()
    {
        return 0;
    }
};

class NormiePizza: public Pizza
{
public:
    NormiePizza(PizzaSize _size, unsigned int _cheeseNum, unsigned int _saltiness) :
            Pizza(_size, _cheeseNum, _saltiness){};

    void PrintDescription()
    {
        cout << "Just a normal pizza for normies" << endl;
    }

    unsigned int TypeCost()
    {
        return 10*size;
    }

    unsigned int CheeseCost()
    {
        return 10;
    }

    unsigned int SaltCost()
    {
        return 3;
    }
};

class BestPizza: public Pizza
{
public:
    BestPizza(PizzaSize _size, unsigned int _cheeseNum, unsigned int _saltiness) :
            Pizza(_size, _cheeseNum, _saltiness){};

    void PrintDescription()
    {
        cout << "Worst pizza! Don't buy!!" << endl;
    }

    unsigned int TypeCost()
    {
        return 0*size;
    }

    unsigned int CheeseCost()
    {
        return 0;
    }

    unsigned int SaltCost()
    {
        return 0;
    }
};

class WorstPizza: public Pizza
{
public:
    WorstPizza(PizzaSize _size, unsigned int _cheeseNum, unsigned int _saltiness) :
            Pizza(_size, _cheeseNum, _saltiness){};

    void PrintDescription()
    {
        cout << "Buy it! Best with cheese and salt!!" << endl;
    }

    unsigned int TypeCost()
    {
        return 999*size;
    }

    unsigned int CheeseCost()
    {
        return 999;
    }

    unsigned int SaltCost()
    {
        return 999;
    }
};

class Order
{
    vector<Pizza *> pizzes;

public:

    void Add(Pizza *pizza)
    {
        pizzes.push_back(pizza);
    }

    void Print()
    {
        unsigned int fullCost = 0;
        int orderSize = pizzes.size();
        for(int i = 0; i < orderSize; i++)
        {
            pizzes[i]->PrintDescription();
            unsigned int pizza_cost = pizzes[i]->GetPizzaCost();
            cout << "Pizza cost: " << pizza_cost << endl;
            cout << "Cheeseness: " << pizzes[i]->GetCheeseNum() << endl;
            cout << "Saltiness: " << pizzes[i]->GetSaltiness() << endl;
            cout << "Size: " << pizzes[i]->GetSize() << endl;
            cout << endl;
            fullCost += pizza_cost;
        }
        cout << "Total cost for order: " << fullCost << endl;
    }

    void Interact()
    {
        cout << "Please, feel free to order something!" << endl;
        int running = 1;

        OrderNewItem:
        while(running) {
            cout << "Type number of pizza (or 0, if you done with your order)!" << endl;
            cout << "1. Cool Pizza" << endl;
            cout << "2. Normie Pizza" << endl;
            cout << "3. Best Pizza" << endl;
            cout << "4. Worst Pizza" << endl;
            int choice;
            unsigned int pizzaType = 0;

            cin >> choice;
            //TODO: switch case


        }
    }
};












int main() {
    return 0;
}
