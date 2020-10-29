// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <array>
#include <iostream>



int* allocateArray(int size)
//функция выделения памяти (возврат значения по адресу(указателю))
{
    return new int[size];
}


int& getElement(int& array, int index)
// Возвращаем ссылку на индекс элемента массива
{
    // мы знаем, что array[index] не уничтожится, когда мы будем возвращать данные в caller (так как caller сам передал этот array в функцию!)
    // так что здесь не должно быть никаких проблем с возвратом по ссылке 
    return *(&array + index);
}

class Player
{
public:
    Player();
    ~Player();
    void setPosition(int x, int y);

private:
    int x = 0;
    int y = 0;
};

Player::Player()
{
}

Player::~Player()
{
}

void Player::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}
int main()
{
    /* =================================== 1 =================================== */
    //возврат значения из метода через указатель(*)
    int* myArray = allocateArray(20);
    // делаем что-нибудь с array
    delete[] myArray;
    //возврат значения из метода через ссылку(&)
    int myArray2[5] = {1,2,3,4,5};
    int &linkMyArray = myArray2[0];
    // присваиваем элементу массива с индексом 15 значение 7
    getElement(linkMyArray, 3) = 7;//содержимое myArray2 : {1,2,3,7,5};
    /* =================================== 2 =================================== */
    //разумное использование this;
    Player *player = new Player;
    player->setPosition(10, 20);//в функции setPosition this указывает на тот объект, у которого мы вызываем метод
    /* =================================== 3 =================================== */
    return 0;
}
