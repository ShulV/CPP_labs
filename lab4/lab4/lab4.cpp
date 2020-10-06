// lab work №4 Shulpov Victor PI-92
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
#include <malloc.h>
#include <conio.h>

#define clear(stream) rewind((stream)) //очистка потока
#define CAR_NUMBERS 10


class Car
{
public:
	void init(char* name, int price, char* color, int engineRPM, int speed, int benzine);
	void readCarData();
	void displayDataCar();
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

void Car::readCarData() {
	std::cout << "ENTER CAR DATA:" << std::endl;
	std::cout << "\tname:\t";
	std::cin >> this->name;
	clear(stdin);
	std::cout << "\tprice:\t";
	std::cin >> this->price;
	clear(stdin);
	std::cout << "\tcolor:\t";
	std::cin >> this->color;
	clear(stdin);
	std::cout << "\tengineRPM:\t";
	std::cin >> this->engineRPM;
	clear(stdin);
	std::cout << "\tspeed:\t";
	std::cin >> this->speed;
	clear(stdin);
	std::cout << "\tbenzine:\t";
	std::cin >> this->benzine;
	clear(stdin);
}

void Car::displayDataCar()
{
	std::cout << "\t" << "Car data" << std::endl;
	std::cout << "\t\tName:\t" << this->name << std::endl;
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
	//////////////////////////////////////STATIC OBJECT////////
	std::cout << "\n\nSTATIC OBJECT\n\n";
	Car static_obj_car;
	char name[100] = "", color[100] = "";
	static_obj_car.init(name, 0, color, 0, 0, 0); //инициализируем поля объекта
	static_obj_car.displayDataCar();
	static_obj_car.readCarData();
	static_obj_car.displayDataCar();
	static_obj_car.startEngine(); //пытаемся завести двигатель
	static_obj_car.displayDataCar();
	static_obj_car.addBenzine(10); //добавляем бензин
	static_obj_car.displayDataCar();
	static_obj_car.startEngine(); //снова пытаемся завести двигатель
	static_obj_car.displayDataCar();
	for (int i = 0; i < 4; i++) {
		static_obj_car.addSpeed(i * 5); //добавляем скорость
		static_obj_car.displayDataCar();
	}
	for (int i = 0; i < 4; i++) {
		static_obj_car.reduceSpeed(i * 5); //убавляем скорость
		static_obj_car.displayDataCar();
	}

	static_obj_car.stopEngine(); //останавливаем двигатель
	static_obj_car.displayDataCar();

	std::cout << "\n\nPress key to continue!\n\n";
	_getch();
	std::system("cls");
	////////////////////////////////////DYNAMIC OBJECT/////
	std::cout << "\n\nDYNAMIC OBJECT\n\n";
	Car* dynamic_obj_car = new Car;
	char name2[100] = "", color2[100] = "";
	dynamic_obj_car->init(name2, 0, color2, 0, 0, 0); //инициализируем поля объекта
	dynamic_obj_car->displayDataCar();
	dynamic_obj_car->readCarData();
	dynamic_obj_car->displayDataCar();
	dynamic_obj_car->startEngine(); //пытаемся завести двигатель
	dynamic_obj_car->displayDataCar();
	dynamic_obj_car->addBenzine(10); //добавляем бензин
	dynamic_obj_car->displayDataCar();
	dynamic_obj_car->startEngine(); //снова пытаемся завести двигатель
	dynamic_obj_car->displayDataCar();
	for (int i = 0; i < 4; i++) {
		dynamic_obj_car->addSpeed(i * 5); //добавляем скорость
		dynamic_obj_car->displayDataCar();
	}
	for (int i = 0; i < 4; i++) {
		dynamic_obj_car->reduceSpeed(i * 5); //убавляем скорость
		dynamic_obj_car->displayDataCar();
	}

	dynamic_obj_car->stopEngine(); //останавливаем двигатель
	dynamic_obj_car->displayDataCar();

	delete dynamic_obj_car;


	///////////////////////////////////DYNAMIC OBJECTS ARRAY///
	Car* dynamic_obj_cars;
	dynamic_obj_cars = new Car[5];
	delete[] dynamic_obj_cars;
	///////////////////////////////////MALLOC ///
	Car* dynamic_obj_car2;
	dynamic_obj_car2 = (Car*)malloc(CAR_NUMBERS * sizeof(Car));
	free(dynamic_obj_car2);
	//////////////////////////////////CALLOC /////
	Car* dynamic_obj_car3;
	dynamic_obj_car3 = (Car*)calloc(CAR_NUMBERS, sizeof(Car));
	free(dynamic_obj_car3);
	//////////////////////////////////REALOC - change current allocated memory
	Car* dynamic_obj_car4 = (Car*)calloc(2, sizeof(Car));
	Car* tmp;
	if (dynamic_obj_car4 != NULL)
	{
		tmp = (Car*)realloc(dynamic_obj_car4, CAR_NUMBERS * sizeof(Car));
		if (tmp != NULL)
		{
			dynamic_obj_car4 = tmp;
		}
		free(dynamic_obj_car4);
	}
	return 0;
}


