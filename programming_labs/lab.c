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

struct car_type init();
struct car_type setDataCar(struct car_type car);

int main(void)
{
	struct car_type car = init();
	printf("%s\n", car.name);
	car = setDataCar(car);
	printf("%s\n", car.name);

	return 0;
}

struct car_type init() {
	struct car_type car = { "0", 0, "0", 0, 0, 0 };
	printf("Car initialized\n");
	return car;

}

struct car_type setDataCar(struct car_type car) {
	printf("Car parameters set!\n");
	printf("Enter a car name: ");
	fflush(stdin);
	scanf("%s", car.name);
	printf("Enter a car price: ");
	fflush(stdin);
	scanf("%d", car.price);
	printf("Enter a car color: ");
	fflush(stdin);
	scanf("%s", car.color);
	return car;
}

