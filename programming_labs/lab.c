// lab work ¹2 Shulpov Victor PI-92
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <malloc.h>

#define MAX_BUFF_SIZE 50

typedef struct car_type {
	char name[MAX_BUFF_SIZE];
	int price;
	char color[MAX_BUFF_SIZE];
	int engineRPM;
	int speed;
	int benzine;
};

struct car_type init(); //init
struct car_type setDataCar(struct car_type car);
void displayDataCar(struct car_type car);
struct car_type addBenzine(struct car_type car, int liters);
struct car_type startEngine(struct car_type car);
struct car_type stopEngine(struct car_type car);
struct car_type addSpeed(struct car_type car);
struct car_type reduceSpeed(struct car_type car);

int main(void)
{
	struct car_type car = init();
	displayDataCar(car);
	car = setDataCar(car);
	displayDataCar(car);
	car = startEngine(car);
	displayDataCar(car);
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


	return 0;
}

struct car_type init() {
	struct car_type car = { "0", 0, "0", 0, 0, 0 };
	printf("Car initialized!\n");
	return car;

}

struct car_type setDataCar(struct car_type car) {
	printf("Car parameters set!\n");
	printf("\tEnter a car name: ");
	fflush(stdin);
	scanf("%s", &car.name);
	printf("\tEnter a car price: ");
	while (getchar() != '\n');
	scanf("%d", &car.price);
	printf("\tEnter a car color: ");
	while (getchar() != '\n');
	scanf("%s", car.color);
	return car;
}

void displayDataCar(struct car_type car) {
	puts("\tCar data");
	printf("\t\tName:\t%s\n", car.name);
	printf("\t\tPrice:\t%d\n", car.price);
	printf("\t\tColor:\t%s\n", car.color);
	printf("\t\tEngine RPM:\t%d\n", car.engineRPM);
	printf("\t\tSpeed:\t%d\n", car.speed);
	printf("\t\tBenzine:\t%d\n", car.benzine);
}

struct car_type addBenzine(struct car_type car, int liters) {
	printf("%d lit. benzine added!\n", liters);
	car.benzine += liters;
	return car;
}

struct car_type startEngine(struct car_type car) {
	if (car.benzine > 0) {
		car.engineRPM = 800;
		printf("Engine started!\n");
	}
	else {
		printf("No benzine. Engine didn't start!\n");
	}
	return car;
}

struct car_type stopEngine(struct car_type car) {
	if (car.engineRPM > 0) {
		car.engineRPM = 0;
		printf("Engine stopped!\n");
	}
	else {
		printf("Engine stopped already!\n");
	}
	return car;
}

struct car_type addSpeed(struct car_type car) {
	int speed = 20;
	if (car.engineRPM > 0) {
		car.speed += speed;
		printf("Car speeded up!\n");
	}
	else {
		printf("Engine isn't starting. Car didn't speed up!\n");
	}
	return car;
}

struct car_type reduceSpeed(struct car_type car) {
	int speed = 20;
	if (car.speed > 0) {
		car.speed -= speed;
		printf("Car speeded down!\n");
	}
	else {
		printf("Car is parking. Car didn't speed down!\n");
	}
	return car;
}

