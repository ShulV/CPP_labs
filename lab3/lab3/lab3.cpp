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
	this->benzine += liters;
}

void Car::startEngine()
{
	if (this->benzine > 0) {
		this->engineRPM = 800;
		std::cout << "Engine started!" << std::endl;
	}
	else {
		std::cout << "No benzine. Engine didn't start!" << std::endl;
	}
}

void Car::stopEngine()
{
	if (this->engineRPM > 0) {
		this->engineRPM = 0;
		std::cout << "Engine stopped!" << std::endl;
	}
	else {
		std::cout << "Engine stopped already!" << std::endl;
	}
}

void Car::addSpeed(int speed)
{
	if (this->engineRPM > 0) {
		this->speed += speed;
		std::cout << "Car speeded up!" << std::endl;
	}
	else {
		std::cout << "Engine isn't starting. Car didn't speed up!" << std::endl;
	}
}

void Car::reduceSpeed(int speed)
{
	if (this->speed > 0) {
		this->speed -= speed;
		std::cout << "Car speeded down!" << std::endl;
	}
	else {
		std::cout << "Car is parking. Car didn't speed down!" << std::endl;
	}
}

int main()

{
	Car* car;
	car = new Car; // выделение памяти для объекта

	char name[100] = "", color[100] = "";
	strcat(name,"BMW");
	strcat(color, "red");
	car->init(name, 100, color, 0, 0, 0); //инициализируем поля объекта
	car->displayDataCar();
	car->startEngine(); //пытаемся завести двигатель
	car->displayDataCar();
	car->addBenzine(10); //добавляем бензин
	car->displayDataCar();
	car->startEngine(); //снова пытаемся завести двигатель
	car->displayDataCar();
	for (int i = 0; i < 4; i++) {
		car->addSpeed(i*5); //добавляем скорость
		car->displayDataCar();
	}
	for (int i = 0; i < 4; i++) {
		car->reduceSpeed(i*5); //убавляем скорость
		car->displayDataCar();
	}

	car->stopEngine(); //останавливаем двигатель
	car->displayDataCar();
	
	delete car;

	return 0;
}

