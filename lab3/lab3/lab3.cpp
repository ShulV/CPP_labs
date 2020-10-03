// lab work №2 Shulpov Victor PI-92
/*
Реализовать работу автомобиля на примере динамической структуры.
Поля структуры:
•	Название (строка)
•	Цена (целое)
•	Цвет (строка)
•	Количество оборотов двигателя в минуту (целое)
•	Скорость (целое)
•	Количество бензина (целое)
Функции:
•	Инициализация
•	Установка параметров автомобиля
•	Вывод данных машины
•	Запуск двигателя
•	Остановка двигателя
•	Добавление скорости
•	Уменьшить скорость
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

#define CAR_NUMBERS 100


class Car
{
public:
	void init(char* name, int price, char* color, int engineRPM, int speed, int benzine); //init
	char* name;

private:
	
	int price;
	char* color;
	int engineRPM;
	int speed;
	int benzine;
};

Car* car = new Car;

void Car::init(char* name, int price, char* color, int engineRPM, int speed, int benzine)
{
	this->name = name;
	this->price = price;
	this->color = color;
	this->engineRPM = engineRPM;
	this->benzine = benzine;
	this->speed = speed;
	printf("Car initialized!\n");
}


int main()
{
	char name[] = "", color[] = "";
	strcat(name,"BMW");
	strcat(color, "red");
	car->init(name, 100, color, 0, 0, 0);

    std::cout << car[0].name <<"\n";

	_getch();
	return 0;
}

