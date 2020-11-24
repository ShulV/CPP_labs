// lab work №7,8,9 Shulpov Victor PI-92
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
private:
	int x = 0;
	int y = 0;
	std::string name;
	int price;
	std::string color;
	int speed;
	int benzine;
	Engine* engine;
	static int count;
public:
	Car();
	Car(std::string name, int price, std::string color, int speed, int benzine, Engine* engine);
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
	if (count != NULL) count++;
	else count = 1;
	

}
Car::Car(std::string name)
{
	this->x = 0;
	this->y = 0;
	this->name = name;
	this->price = 0;
	this->color = "";
	this->speed = 0;
	this->benzine = 0;
	this->engine = NULL;
	if (count != NULL) count++;
	else count = 1;
}
Car::Car(std::string name, int price, std::string color, int speed, int benzine, Engine* engine)
{
	this->name = name;
	this->price = price;
	this->color = color;
	this->benzine = benzine;
	this->speed = speed;
	this->engine = engine;
	if (count != NULL) count++;
	else count = 1;
	printf("Car initialized!\n");
}
Car::~Car()
{
	count--;
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

Car::Car(const Car& other_car)
{
	this->benzine = other_car.benzine;
	this->color = other_car.color;
	this->name = other_car.name;
	this->price = other_car.price;
	this->engine = new Engine();
	this->engine = other_car.engine;
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

int main()

{
	setlocale(LC_ALL, "Russian");
	int choice=1;
	while (choice!=0){
		std::cout << "\n\nВведите 1 - ПОКАЗАТЬ 4 ЛАБУ\n" << "Введите 2 - ПОКАЗАТЬ 7 ЛАБУ\n" << "Введите 3 - ПОКАЗАТЬ 8 ЛАБУ\n" << "Введите 4 - ПОКАЗАТЬ 9 ЛАБУ\n" << "Введите 0 - ВЫХОД\n" << "ваш выбор: ";
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
			Car *car2 = new Car();
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
			bmw_x6.displayDataCar();
			std::cout << "инициализировано только одним параметром - двигатель\n";
			some_car.displayDataCar();
			std::cout << "инициализировано без параметров\n";
			empty_car.displayDataCar();

			std::cout << "\n\nDYNAMIC OBJECT\n\n";
			Engine* audi_engine = new Engine(0, 2995, 340, 6);
			Car* audi_a7 = new Car("audi", 2000000, "blue", 0, 0, audi_engine);//инициализируем поля объекта в конструкторе со всеми параметрами
			Car* some_car_dynamic = new Car("KIA");
			Car* empty_car_dynamic = new Car();//без параметров
			std::cout << "инициализировано всеми параметрами\n";
			audi_a7->displayDataCar();
			std::cout << "инициализировано только одним параметром - двигатель\n";
			some_car_dynamic->displayDataCar();
			std::cout << "инициализировано без параметров\n";
			empty_car_dynamic->displayDataCar();

			std::cout << "массив объектов\n";
			Car* car_array[3];
			for (int i = 0; i < 3; i++) {
				
				car_array[i] = new Car("Car");
				car_array[i]->displayDataCar();
			}
			std::cout << "конструтор копирования\n";
			Car copy_car1(bmw_x6);
			copy_car1.displayDataCar();
			bmw_x6.addBenzine(25);
			Car copy_car2 = bmw_x6;
			copy_car2.displayDataCar();
			//мелкое копирование работает хорошо, когда не заимодействована динамическая память
			//глубокое копирование нужно для того, чтобы поля-указатели объектов не ссылались на одно и то же место в памяте (куче)
			//при глубоком копировании поля=указатели нового объекта получают новое место другое место в памяти
			//иначе поле одного объекта изменялось при изменении поля другого объекта

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