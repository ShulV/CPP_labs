// lab work ¹2 Shulpov Victor PI-92
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_BUFF_SIZE 50
#define N 10

typedef struct car {
	char* name;
	int price;
	char* color;
	int engineRPM;
	int speed;
	int benzine;
};

struct car* init(char* name); //init
struct car* setDataCar(struct car* car);
void displayDataCar(struct car* car);
struct car* addBenzine(struct car* car, int liters);
struct car* startEngine(struct car* car);
struct car* stopEngine(struct car* car);
struct car* addSpeed(struct car* car);
struct car* reduceSpeed(struct car* car);

int main(void)
{
	int n;
	struct car* car;
	car = init("BMW");
	free(car);
	car = init("AUDI");
	free(car);
	car = init("VOLVO");
	displayDataCar(car);
	setDataCar(car);
	displayDataCar(car);
	free(car);

	return 0;
}
	/*
	displayDataCar(car);
	*car = setDataCar(*car);
	displayDataCar(*car);
	*car = startEngine(*car);
	displayDataCar(*car);
	car = addBenzine(car, 10);
	displayDataCar(car);
	car = startEngine(car);
	displayDataCar(car);
	for(int i=0; i<4; i++) {
		car = addSpeed(car);
		displayDataCar(car);
	}
	for (int i = 0; i < 5; i++) {
		car = reduceSpeed(car);
		displayDataCar(car);
	}
	car = stopEngine(car);
	displayDataCar(car);
	*/
	



struct car* init(char* name) {
	struct car* car;
	car = (struct car_stack*)malloc(sizeof(struct car)); // גûהוכÿול ןאלÿעü
	car->name = name;
	car->price = 0;
	car->color = "0";
	car->engineRPM = 0;
	car->benzine = 0;
	car->speed = 0;
	printf("Car initialized!\n");
	return car;

}

struct car* setDataCar(struct car* car) {
	printf("Car parameters set!\n");
	printf("\tEnter a car name: ");
	char *name = (char*)malloc(sizeof(char));
	scanf("%s", name);
	car->name = name;
	printf("\tEnter a car price: ");
	while (getchar() != '\n');
	int num = 0;
	scanf("%d", &num);
	car->price = num;
	printf("\tEnter a car color: ");
	while (getchar() != '\n');
	char* color = (char*)malloc(sizeof(char));
	scanf("%s", color);
	car->color = color;
	return car;
}

void displayDataCar(struct car* car) {
	puts("\tCar data");
	char* str = car->name;
	printf("\t\tName:\t%s\n", str);
	int num = (*car).price;
	printf("\t\tPrice:\t%d\n", num);
	str = car->color;
	printf("\t\tColor:\t%s\n", str);
	num = (*car).engineRPM;
	printf("\t\tEngine RPM:\t%d\n", num);
	num = (*car).speed;
	printf("\t\tSpeed:\t%d\n", num);
	num = (*car).benzine;
	printf("\t\tBenzine:\t%d\n", num);
}
/*
struct car_stack* addBenzine(struct car_stack* car, int liters) {
	printf("%d lit. benzine added!\n", liters);
	car.benzine += liters;
	return *car;
}

struct car_stack* startEngine(struct car_stack* car) {
	if (car.benzine > 0) {
		car.engineRPM = 800;
		printf("Engine started!\n");
	}
	else {
		printf("No benzine. Engine didn't start!\n");
	}
	return *car;
}

struct car_stack* stopEngine(struct car_stack* car) {
	if (car.engineRPM > 0) {
		car.engineRPM = 0;
		printf("Engine stopped!\n");
	}
	else {
		printf("Engine stopped already!\n");
	}
	return *car;
}

struct car_stack* addSpeed(struct car_stack* car) {
	int speed = 20;
	if (car.engineRPM > 0) {
		car.speed += speed;
		printf("Car speeded up!\n");
	}
	else {
		printf("Engine isn't starting. Car didn't speed up!\n");
	}
	return *car;
}

struct car_stack* reduceSpeed(struct car_stack* car) {
	int speed = 20;
	if (car.speed > 0) {
		car.speed -= speed;
		printf("Car speeded down!\n");
	}
	else {
		printf("Car is parking. Car didn't speed down!\n");
	}
	return *car;
}


*/
