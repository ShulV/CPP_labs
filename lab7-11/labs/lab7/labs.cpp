// lab work №7,8,9,10 Shulpov Victor PI-92
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
#include <fstream>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include <exception> // для std::exception
#include <string>

#define clear(stream) rewind((stream)) //очистка потока
const int CAR_NUMBERS = 10;
class Car;

int* allocateArray(int size);
int& getCallNumber();
void setStartPosition(Car* car);


class BigSpeedException : public std::exception
{
private:
	std::string m_error;

public:
	BigSpeedException(std::string error) : m_error(error)
	{
		std::cout << "\t" << "Была совершена попытка разгона автомобиля выше максимальной скорости" << std::endl;
	}
	const char* what() const noexcept { return m_error.c_str(); } // C++11 и выше
};

class ZeroDivisionException : public std::exception
{
private:
	std::string m_error;

public:
	ZeroDivisionException(std::string error) : m_error(error)
	{
		std::cout << "\t" << "Исключение! Деление на нуль!" << std::endl;
	}
	const char* what() const noexcept { return m_error.c_str(); } // C++11 и выше
};

class OneException : public std::exception
{
private:
	std::string m_error;

public:
	OneException(std::string error) : m_error(error)
	{
		std::cout << "\t" << "Исключение! Получено значение 1!" << std::endl;
	}
	const char* what() const noexcept { return m_error.c_str(); } // C++11 и выше
};

class Engine
{
public:
	Engine(int engineRPM, int capacity, int enginePower, int quantityOfCylinders);
	Engine(int engineRPM);
	Engine();

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
protected:
	std::string name;
	int benzine;
private:
	int* p;//для демонстрации глубокого копирования
	int size;//для демонстрации глубокого копирования
	
	int x = 0;
	int y = 0;
	int price;
	std::string color;
	int speed;
	int max_speed;
	
	Engine* engine;
	static int count;
public:
	Car();
	Car(std::string name, int price, std::string color, int speed, int benzine, Engine* engine);
	Car(std::string name, int price, std::string color, int speed, int benzine, int max_speed, Engine* engine);
	Car(std::string name);
	~Car();
	
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
	Car& operator= (const Car& other_car);//перегрузка оператора присваивания
	static int getCount();
	Car(const Car& other_car);

};

Car::Car(const Car& other_car)
{
	//ГЛУБОКОЕ КОПИРОВАНИЕ
	p = new int[other_car.size];
	if (!p) exit(1);
	for (int i = 0; i < other_car.size; i++) p[i] = other_car.p[i];

	this->benzine = other_car.benzine;
	this->color = other_car.color;
	this->name = other_car.name;
	this->price = other_car.price;
	this->engine = new Engine(*(other_car.engine));
	this->max_speed = other_car.max_speed;
	if (count != NULL) count++;
	else count = 1;
	std::cout << "\t\t\t" << "ВЫЗВАЛСЯ КОНСТРУКТОР КОПИРОВАНИЯ : " << this << std::endl;
}

Car::Car()
{
	this->size = 10;//для демонстрации глубокого копирования
	p = new int[size];//для демонстрации глубокого копирования
	
	this->x = 0;
	this->y = 0;
	this->name = "";
	this->price = 0;
	this->color = "";
	this->speed = 0;
	this->benzine = 0;
	this->engine = NULL;
	this->max_speed = 0;
	if (count != NULL) count++;
	else count = 1;
	std::cout << "\t\t\t" << "ВЫЗВАЛСЯ КОНСТРУКТОР БЕЗ ПАРАМЕТРОВ : " << this << std::endl;

}

Car::Car(std::string name)
{
	this->size = 10;//для демонстрации глубокого копирования
	p = new int[size];//для демонстрации глубокого копирования

	this->x = 0;
	this->y = 0;
	this->name = name;
	this->price = 0;
	this->color = "";
	this->speed = 0;
	this->benzine = 0;
	this->engine = NULL;
	this->max_speed = 0;
	if (count != NULL) count++;
	else count = 1;
	std::cout << "\t\t\t" << "ВЫЗВАЛСЯ КОНСТРУКТОР С ОДНИМ ПАРАМЕТРОМ : " << this << std::endl;
}

Car::Car(std::string name, int price, std::string color, int speed, int benzine, Engine* engine)
{
	this->size = 10;//для демонстрации глубокого копирования
	p = new int[size];//для демонстрации глубокого копирования

	this->name = name;
	this->price = price;
	this->color = color;
	this->benzine = benzine;
	this->speed = speed;
	this->engine = engine;
	this->max_speed = 0;
	if (count != NULL) count++;
	else count = 1;
	std::cout << "\t\t\t" << "ВЫЗВАЛСЯ КОНСТРУКТОР С ПОЧТИ ВСЕМИ ПАРАМЕТРАМИ : " << this << std::endl;
}

Car::Car(std::string name, int price, std::string color, int speed, int benzine, int max_speed, Engine* engine)
{
	this->size = 10;//для демонстрации глубокого копирования
	p = new int[size];//для демонстрации глубокого копирования
	this->name = name;
	this->price = price;
	this->color = color;
	this->benzine = benzine;
	this->speed = speed;
	this->engine = engine;
	this->max_speed = max_speed;
	if (count != NULL) count++;
	else count = 1;
	std::cout << "\t\t\t" << "ВЫЗВАЛСЯ КОНСТРУКТОР СО ВСЕМИ ПАРАМЕТРАМИ : " << this << std::endl;
}

Car::~Car()
{
	delete[] p;//для демонстрации глубокого копирования

	count--;
	std::cout << "\t\t\t" << "ВЫЗВАЛСЯ ДЕКОНСТРУКТОР : " << this << std::endl;
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
	std::cout << "\t\tBenzine:\t" << this->benzine << std::endl;
	std::cout << "\t\tSpeed:\t" << this->speed << std::endl;
	//ENGINE
	//std::cout << "\t\tEngineRPM:\t" << this->engine->getEngineRPM() << std::endl;
	//std::cout << "\t\tCapacity:\t" << this->engine->getCapacity() << std::endl;
	//std::cout << "\t\tEngine Power:\t" << this->engine->getEnginePower() << std::endl;
	//std::cout << "\t\tQuanity of cylinders:\t" << this->engine->getQuantityOfCylinders() << std::endl;
	

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
		if (this->speed + speed > this->max_speed) { throw BigSpeedException("Брошено исключение: Слишком большая скорость!\n"); }
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
		if (this->speed < speed) { this->speed = 0; }
		else { this->speed -= speed; }
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

Car& Car::operator=(const Car& other_car)
{
	if (this->engine != nullptr) {
		delete[] this->engine;
	}
	this->benzine = other_car.benzine;
	this->color = other_car.color;
	this->name = other_car.name;
	this->price = other_car.price;
	this->engine = new Engine();
	this->engine = other_car.engine;
	return *this;
}

int Car::getCount()
{
	return count;
}

int Car::count = 0; // определение статической переменной-члена класса
Engine::Engine(int engineRPM, int capacity, int enginePower, int quantityOfCylinders)
{
	this->engineRPM = engineRPM;
	this->capacity = capacity;
	this->enginePower = enginePower;
	this->quantityOfCylinders = quantityOfCylinders;
}

Engine::Engine(int engineRPM)
{
	this->engineRPM = engineRPM;
	this->capacity = 0;
	this->enginePower = 0;
	this->quantityOfCylinders = 0;
}

Engine::Engine()
{
	this->engineRPM = 0;
	this->capacity = 0;
	this->enginePower = 0;
	this->quantityOfCylinders = 0;
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

void Foo(Car car) {
	std::cout << "вызвана функция с параметром-объектом класса Car. Адрес переданного объекта : " << &car << "\n";
}

int func3(int num1, int num2) {
	if (num2 == 0) throw ZeroDivisionException("Деление на нуль");
	return num1 / num2;
}

int func2(int num1, int num2) {
	int num = func3(num1, num2);
	if (num == 1) throw OneException("Получена единица");
	return num - num2;
}

int func1(int num1, int num2) {
	int num = func2(num1, num2);
	return num - num2;
}

//производный класс
class TaxiCar : public Car {
private:
	int code_name;
public:
	//вызов конструктора базового класса
	TaxiCar(std::string name) : Car(name) {}
	//перегрузка метода базового класса (с вызовом базового класса)
	TaxiCar(std::string name, int code_name) : Car(name) {
		code_name = code_name;
	}

	//перегрузка метода базового класса (без вызова базового класса)
	void addBenzine(int liters, int work_bonus) {
		std::cout << liters + work_bonus + "lit. benzine added!";
		benzine += liters + work_bonus;
	}
	void callTaxi(std::string address) {
		std::cout << "По адресу " << address << " приехала машина " << name << std::endl;
	}
};

int main()

{
	setlocale(LC_ALL, "Russian");
	int choice = 1;
	while (choice != 0) {
		std::cout
			<< "\n\nВведите 1 - ПОКАЗАТЬ 4 ЛАБУ\n"
			<< "Введите 2 - ПОКАЗАТЬ 7 ЛАБУ\n"
			<< "Введите 3 - ПОКАЗАТЬ 8 ЛАБУ\n"
			<< "Введите 4 - ПОКАЗАТЬ 9 ЛАБУ\n"
			<< "Введите 5 - ПОКАЗАТЬ 10 ЛАБУ\n"
			<< "Введите 6 - ПОКАЗАТЬ 11 ЛАБУ\n"
			<< "Введите 7 - ПОКАЗАТЬ 12 ЛАБУ\n"
			<< "Введите 0 - ВЫХОД\n" << "ваш выбор: ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 0) { break; }
		if (choice == 1) {
			//////////////////////////////////////STATIC OBJECT////////
			std::cout << "\n\nSTATIC OBJECT\n\n";
			Engine* bmw_engine = new Engine(0, 4395, 625, 8);
			Car bmw_x6("BMW_X6", 3500000, "black", 0, 0, bmw_engine);//инициализируем поля объекта в конструкторе

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
			Engine* audi_engine = new Engine(0, 2995, 340, 6);
			Car* audi_a7 = new Car("audi", 2000000, "blue", 0, 0, audi_engine);//инициализируем поля объекта


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
			Engine* bmw_engine = new Engine(0, 4395, 625, 8);
			Car bmw_x6("BMW_X6", 3500000, "black", 0, 10, bmw_engine); //инициализируем поля объекта
			Car test_car;
			bmw_x6.displayDataCar();
			bmw_x6 = bmw_x6 + 10;//перегрузка оператора + (добавляем бензин)
			std::cout << "BMW" << "\n";
			bmw_x6.displayDataCar();

			test_car = ++bmw_x6;
			std::cout << "BMW" << "\n";
			bmw_x6.displayDataCar();
			std::cout << "TEST_CAR" << "\n";
			test_car.displayDataCar();
			test_car = bmw_x6++; //(добавляем бензин)
			std::cout << "BMW" << "\n";
			bmw_x6.displayDataCar();
			std::cout << "TEST_CAR" << "\n";
			test_car.displayDataCar();

		}
		if (choice == 3) {
			std::cout << "count =" << Car::getCount() << "\n";
			Car car1;
			std::cout << "После создания одного статического объекта Car\ncount =" << Car::getCount() << "\n";
			Car* car2 = new Car();
			std::cout << "После создания одного динамического объекта Car\ncount =" << Car::getCount() << "\n";
			Car car[5];
			std::cout << "После создания массива из 5 статических объектов Car\ncount =" << Car::getCount() << "\n";
		}
		if (choice == 4) {
			//////////////////////////////////////STATIC OBJECT////////
			std::cout << "\n\nSTATIC OBJECT\n\n";
			Engine* bmw_engine = new Engine(0, 4395, 625, 8);
			Car bmw_x6("BMW_X6", 3500000, "black", 0, 0, bmw_engine);//инициализируем поля объекта в конструкторе со всеми параметрами
			Car some_car("volvo");//инициализируем поля объекта в конструкторе с 1 параметром
			Car empty_car;//без параметров
			std::cout << "инициализировано всеми параметрами\n";
			//bmw_x6.displayDataCar();
			std::cout << "инициализировано только одним параметром - двигатель\n";
			//some_car.displayDataCar();
			std::cout << "инициализировано без параметров\n";
			//empty_car.displayDataCar();

			std::cout << "\n\nDYNAMIC OBJECT\n\n";
			Engine* audi_engine = new Engine(0, 2995, 340, 6);
			Car* audi_a7 = new Car("audi", 2000000, "blue", 0, 0, audi_engine);//инициализируем поля объекта в конструкторе со всеми параметрами
			Car* some_car_dynamic = new Car("KIA");
			Car* empty_car_dynamic = new Car();//без параметров
			std::cout << "инициализировано всеми параметрами\n";
			//audi_a7->displayDataCar();
			std::cout << "инициализировано только одним параметром - двигатель\n";
			//some_car_dynamic->displayDataCar();
			std::cout << "инициализировано без параметров\n";
			delete audi_a7;
			delete some_car_dynamic;
			delete empty_car_dynamic;
			//empty_car_dynamic->displayDataCar();

			std::cout << "массив объектов\n";
			Car* car_array = new Car[3];
			for (int i = 0; i < 3; i++) {

				//car_array[i] = Car("Car");
				//car_array[i]->displayDataCar();
			}
			delete[] car_array;

			std::cout << "вызывается конструктор копирования\n";
			Car copy_car1(bmw_x6);//глубокое копирование
			//у Car объекта есть динамическое поле, поэтому с помощью конструктора копирования обеспеивается 
			//поле-указатель получает новое место в памяти (реализовано в конструкторе копирования)
			Foo(bmw_x6);//глубокое копирвоание

			*bmw_engine = Engine(*audi_engine);//мелкое копирование
			//у Engine объекта нет динамических полей, поэтому его копирование может быть только мелким (битовая копия)




			//copy_car1.displayDataCar();
			//bmw_x6.addBenzine(25);
			//Car copy_car2 = bmw_x6;
			//copy_car2.displayDataCar();

			//Глубокая копия копирует все поля и создает копии динамически выделенной памяти, на которую указывают поля.
			//Глубокое копирование происходит, когда объект копируется вместе с объектами, на которые он ссылается.
			//Мелкая копия - это битовая копия объекта.Создается новый объект, который имеет точную копию значений в исходном объекте.
			//Если какие - либо поля объекта являются ссылками на другие объекты, копируются только ссылочные адреса, т.е.копируется только адрес памяти, а не фактические объекты.

			//мелкое копирование работает хорошо, когда не заимодействована динамическая память
			//глубокое копирование нужно для того, чтобы поля-указатели объектов не ссылались на одно и то же место в памяте (куче)
			//при глубоком копировании поля=указатели нового объекта получают новое место другое место в памяти
			//иначе поле одного объекта изменялось при изменении поля другого объекта
			std::cout << "выход из функции\n";
		}
		if (choice == 5) {
			//Обработка исключений (exception handling) позволяет упорядочить обработку ошибок времени исполнения.
			//Используя обработку исключений С++, программа может автоматически вызвать функцию-обработчик ошибок тогда, когда такая ошибка возникает.
			//Принципиальным достоин­ством обработки исключений служит то, 
			//что она позволяет автоматизировать большую часть кода для обработки ошибок, для чего раньше требовалось ручное кодирование.

			Engine* bmw_engine = new Engine(0, 4395, 625, 8);
			Car bmw_x6("BMW_X6", 3500000, "black", 0, 20, 300, bmw_engine);//инициализируем поля объекта в конструкторе со всеми параметрами
			try
			{
				bmw_x6.startEngine();
				for (int i = 0; i < 10; i++) {
					bmw_x6.addSpeed(40);
				}

			}
			catch (const BigSpeedException& ex) {
				std::cout << "Поймали исключение NegativeNumberException : слишком большая скорость!\n\tex.what() = " << ex.what() << "\n";
			}
			catch (const std::exception& ex)
			{
				std::cout << "Поймали исключение exception " << ex.what() << "\n";
			}

			int number_c = 0;
			try {
				number_c = func1(20, 20);
			}
			catch (const OneException& ex) {
				std::cout << "Вызвано исключение! " << ex.what() << "\n";
			}
			catch (const ZeroDivisionException& ex) {
				std::cout << "Вызвано исключение! " << ex.what() << "\n";
			}
			try {
				number_c = func1(10, 0);
			}
			catch (const OneException& ex) {
				std::cout << "Вызвано исключение! " << ex.what() << "\n";
			}
			catch (const ZeroDivisionException& ex) {
				std::cout << "Вызвано исключение! " << ex.what() << "\n";
			}

		}
		if (choice == 6) {
			const int N = 4, M = 3;
			////////////////////////////////////////////////
			Engine* bmw_engine = new Engine(0, 4395, 625, 8);
			Car car_array[N];
			for (int i = 0; i < N; i++) {
				car_array[i] = Car("car" + std::to_string(i));
			}
			Car car_darray[N][M];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					car_darray[i][j] = Car("car" + std::to_string(i * M + j));
				}

			}
			Car* d_car_array[N];
			for (int i = 0; i < N; i++) {
				d_car_array[i] = new Car("car" + std::to_string(i));
			}
			
			//////////////////////////////////////////////////////////
			Car* d_car_darray[N][M];


			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					d_car_darray[i][j] = new Car("car" + std::to_string(i * M + j));
				}

			}

			Car* d_car_darray2 = new Car[N, M];//только прямоугольный массив
			//Car cars[N, M]; --- error
			/////////////////////////////////////////////////////////////
			Car* cars[N];

		}
		if (choice == 7) {
			TaxiCar taxi_car = TaxiCar("Solaris");
			taxi_car.displayDataCar();
			taxi_car.callTaxi("Красноармейский 69Б");
			TaxiCar taxi_car2 = TaxiCar("Solaris", 777);
			taxi_car2.addBenzine(10, 2);
			taxi_car2.displayDataCar();
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