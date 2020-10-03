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
	void displayDataCar(); //display
	void addBenzine(int liters);
	void startEngine();
	void stopEngine();
	void addSpeed(int speed);
	void reduceSpeed(int speed);
private:
	char* name;
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

void Car::displayDataCar()
{
	std::cout << "\t" << "Car data" << std::endl;
	std::cout << "\t\tName:\t"<< this->name << std::endl;
	std::cout << "\t\tPrice:\t" << this->price << std::endl;
	std::cout << "\t\tColor:\t" << this->color << std::endl;
	std::cout << "\t\tEngineRPM:\t" << this->engineRPM << std::endl;
	std::cout << "\t\tBenzine:\t" << this->benzine << std::endl;
	std::cout << "\t\tSpeed:\t" << this->speed << std::endl;
}

void Car::addBenzine(int liters)
{
	std::cout << liters << "lit. benzine added!" << std::endl;
	car->benzine += liters;
}

void Car::startEngine()
{
	//work here
}

void Car::stopEngine()
{
}

void Car::addSpeed(int speed)
{
}

void Car::reduceSpeed(int speed)
{
}

int main()
{
	char name[] = "", color[] = "";
	strcat(name,"BMW");
	strcat(color, "red");
	car->init(name, 100, color, 0, 0, 0);
	car->displayDataCar();
	car->addBenzine(10);
	car->displayDataCar();
	
	_getch();
	return 0;
}

