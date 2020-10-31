
/*
// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>






class Player
{
public:
	Player();
	~Player();
	void setPosition(int x, int y, int z);
	friend void setStartPosition(Player *player);
	void displayPosition();
	Player operator + (Player b); // сложение двух объектов operator +

private:
	int x = 0;
	int y = 0;
	int z = 0;
	int money = 0;
};

Player::Player()
{
}

Player::~Player()
{
}

void Player::setPosition(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Player::displayPosition()
{
	std::cout << "x = " << this->x << ", y = " << this->y << ", z = " << this->z << std::endl;
}
Player Player::operator+(Player b)
{
	return Player();
}
void setStartPosition(Player *player) {
	player->x = 0;
	player->y = 0;
	player->z = 0;
}
int main()
{

//разумное использование this;
Player* player = new Player;
player->setPosition(10, 20, 150);//в функции setPosition this указывает на тот объект, у которого мы вызываем метод
std::cout << delimiter;
// =================================== 3 ===================================
//Дружественная функция
std::cout << "параметры ДО использования дружесетвенной функции" << std::endl;
player->displayPosition();
setStartPosition(player);
std::cout << "параметры ПОСЛЕ использования дружесетвенной функции" << std::endl;
player->displayPosition();
std::cout << delimiter;
// =================================== 4 =================================== 
// =================================== 5 =================================== 
// ========================================================================= 
return 0;
}




*/
// lab work №7 Shulpov Victor PI-92
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
#include <string.h>

#define clear(stream) rewind((stream)) //очистка потока
const int CAR_NUMBERS = 10;

class Car;
int* allocateArray(int size);
int& getCallNumber();
void setStartPosition(Car* car);

class Engine
{
public:
	void init(int engineRPM, int capacity, int enginePower, int quantityOfCylinders);

	void setEngineRPM(int engineRPM);
	void setCapacity(int capacity);
	void setEnginePower(int enginePower);
	void setQuantityOfCylinders(int quantityOfCylinders);

	int getEngineRPM();
	int getCapacity();
	int getEnginePower();
	int getQuantityOfCylinders();
private:
	int engineRPM; //количество оборотов в минуту
	int capacity; //объем см куб
	int enginePower; //мощность Л.С.
	int quantityOfCylinders; //количество цилиндров
};

class Car
{
public:
	Car();
	~Car();
	void init(std::string name, int price, std::string color, int speed, int benzine, Engine* engine);
	void readCarData();
	void displayDataCar();
	void addBenzine(int liters);
	void startEngine();
	void stopEngine();
	void addSpeed(int speed);
	void reduceSpeed(int speed);
	friend void setStartPosition(Car* car);
	Car operator+(int benzine);//перегрузка оператора +
	Car& operator++ ();//префиксная
	Car operator++ (int unused);
private:
	int x=0;
	int y=0;

	std::string name;
	int price;
	std::string color;
	int speed;
	int benzine;
	Engine* engine;
};

Car::Car()
{
	this->x = 0;
	this->y = 0;
	this->name = "";
	this->price = 0;
	this->color = "";
	this->speed = 0;
	this->benzine = 0;
	this->engine = NULL;
}

Car::~Car()
{
}

void Car::init(std::string name, int price, std::string color, int speed, int benzine, Engine* engine)
{
	this->name = name;
	this->price = price;
	this->color = color;
	this->benzine = benzine;
	this->speed = speed;
	this->engine = engine;
	printf("Car initialized!\n");
}

void Car::readCarData() {
	int number;
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
	std::cin >> number;
	this->engine->setEngineRPM(number);
	clear(stdin);
	std::cout << "\tcapacity:\t";
	std::cin >> number;
	this->engine->setCapacity(number);
	clear(stdin);
	std::cout << "\tengine power:\t";
	std::cin >> number;
	this->engine->setEnginePower(number);
	clear(stdin);
	std::cout << "\tquantity of cylinders:\t";
	std::cin >> number;
	this->engine->setQuantityOfCylinders(number);
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
	std::cout << "\t\tEngineRPM:\t" << this->engine->getEngineRPM() << std::endl;
	std::cout << "\t\tCapacity:\t" << this->engine->getCapacity() << std::endl;
	std::cout << "\t\tEngine Power:\t" << this->engine->getEnginePower() << std::endl;
	std::cout << "\t\tQuanity of cylinders:\t" << this->engine->getQuantityOfCylinders() << std::endl;
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
		this->engine->setEngineRPM(800);
		std::cout << "Engine started!" << std::endl;
	}
	else {
		std::cout << "No benzine. Engine didn't start!" << std::endl;
	}
}

void Car::stopEngine()
{
	if (this->engine->getEngineRPM() > 0) {
		this->engine->setEngineRPM(0);
		std::cout << "Engine stopped!" << std::endl;
	}
	else {
		std::cout << "Engine stopped already!" << std::endl;
	}
}

void Car::addSpeed(int speed)
{
	if (this->engine->getEngineRPM() > 0) {
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

Car Car::operator+(int benzine)
{
	Car new_car = *this;
	new_car.benzine = this->benzine + benzine;
	return new_car;
}

Car& Car::operator++()
{
	this->benzine++;
	return *this;
}

Car Car::operator++(int unused)
{
	Car car = *this;
	++this->benzine;
	return car;
}

void Engine::init(int engineRPM, int capacity, int enginePower, int quantityOfCylinders)
{
	this->engineRPM = engineRPM;
	this->capacity = capacity;
	this->enginePower = enginePower;
	this->quantityOfCylinders = quantityOfCylinders;
}

void Engine::setEngineRPM(int engineRPM)
{
	this->engineRPM = engineRPM;
}

void Engine::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void Engine::setEnginePower(int enginePower)
{
	this->enginePower = enginePower;
}

void Engine::setQuantityOfCylinders(int quantityOfCylinders)
{
	this->quantityOfCylinders = quantityOfCylinders;
}

int Engine::getEngineRPM()
{
	return this->engineRPM;
}

int Engine::getCapacity()
{
	return this->capacity;
}

int Engine::getEnginePower()
{
	return this->enginePower;
}

int Engine::getQuantityOfCylinders()
{
	return this->quantityOfCylinders;
}

int main()

{
	setlocale(LC_ALL, "Russian");
	int choice=1;
	while (choice!=0){
		std::cout << "\n\nВведите 1 - ПОКАЗАТЬ 4 ЛАБУ\n" << "Введите 2 - ПОКАЗАТЬ 7 ЛАБУ\n" << "Введите 0 - ВЫХОД\n" << "ваш выбор: ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 0) { break; }
		if (choice == 1) {
			//////////////////////////////////////STATIC OBJECT////////
			std::cout << "\n\nSTATIC OBJECT\n\n";
			Engine* bmw_engine = new Engine;
			bmw_engine->init(0, 4395, 625, 8);
			Car bmw_x6;
			bmw_x6.init("BMW_X6", 3500000, "black", 0, 0, bmw_engine); //инициализируем поля объекта
			bmw_x6.displayDataCar();
			//bmw_x6.readCarData();
			bmw_x6.displayDataCar();
			bmw_x6.startEngine(); //пытаемся завести двигатель
			bmw_x6.displayDataCar();
			bmw_x6.addBenzine(10); //добавляем бензин
			bmw_x6.displayDataCar();
			bmw_x6.startEngine(); //снова пытаемся завести двигатель
			bmw_x6.displayDataCar();
			for (int i = 0; i < 4; i++) {
				bmw_x6.addSpeed(i * 5); //добавляем скорость
				bmw_x6.displayDataCar();
			}
			for (int i = 0; i < 4; i++) {
				bmw_x6.reduceSpeed(i * 5); //убавляем скорость
				bmw_x6.displayDataCar();
			}

			bmw_x6.stopEngine(); //останавливаем двигатель
			bmw_x6.displayDataCar();

			std::cout << "\n\nPress key to continue!\n\n";
			_getch();
			std::system("cls");
			////////////////////////////////////DYNAMIC OBJECT/////
			std::cout << "\n\nDYNAMIC OBJECT\n\n";
			Car* audi_a7 = new Car;
			Engine* audi_engine = new Engine;
			audi_engine->init(0, 2995, 340, 6);
			audi_a7->init("audi", 2000000, "blue", 0, 0, audi_engine); //инициализируем поля объекта
			audi_a7->displayDataCar();
			//audi_a7->readCarData();
			audi_a7->displayDataCar();
			audi_a7->startEngine(); //пытаемся завести двигатель
			audi_a7->displayDataCar();
			audi_a7->addBenzine(10); //добавляем бензин
			audi_a7->displayDataCar();
			audi_a7->startEngine(); //снова пытаемся завести двигатель
			audi_a7->displayDataCar();
			for (int i = 0; i < 4; i++) {
				audi_a7->addSpeed(i * 5); //добавляем скорость
				audi_a7->displayDataCar();
			}
			for (int i = 0; i < 4; i++) {
				audi_a7->reduceSpeed(i * 5); //убавляем скорость
				audi_a7->displayDataCar();
			}

			audi_a7->stopEngine(); //останавливаем двигатель
			audi_a7->displayDataCar();

			delete audi_a7;


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
		}
		if (choice == 2) {
			//возврат значения из метода через указатель(*)
			int* myArray = allocateArray(20);
			// делаем что-нибудь с array
			delete[] myArray;

			//возврат значения из метода через ссылку(&)
			std::cout << "Количество вызовов функции: " << getCallNumber() << "\n";
			//перегрузка
			Engine* bmw_engine = new Engine;
			bmw_engine->init(0, 4395, 625, 8);
			Car bmw_x6;
			bmw_x6.init("BMW_X6", 3500000, "black", 0, 10, bmw_engine); //инициализируем поля объекта
			bmw_x6.displayDataCar();
			bmw_x6 = bmw_x6 + 10;//перегрузка оператора + (добавляем бензин)
			bmw_x6.displayDataCar();
			bmw_x6 = ++bmw_x6; //(добавляем бензин)
			bmw_x6.displayDataCar();
			bmw_x6 = bmw_x6++; //(добавляем бензин)
			bmw_x6.displayDataCar();
			

		}




	}
	std::cout << "Вы вышли\n";
}

void setStartPosition(Car* car)
{
	car->x = 0;
	car->y = 0;
}

int& getCallNumber()
// Возвращаем ссылку на индекс элемента массива
{
	static int number;
	if (number == NULL) number = 1;
	else number++;
	return number;
}

int* allocateArray(int size)
//функция выделения памяти (возврат значения по адресу(указателю))
{
	return new int[size];
}