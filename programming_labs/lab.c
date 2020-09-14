// лабораторная работа №2 Шульпов Виктор ПИ-92
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <malloc.h>
#define MAX_BUFF_SIZE 50

struct car_type {
	char name[MAX_BUFF_SIZE];
	int price;
	char color[MAX_BUFF_SIZE];
	int engineRPM;
	int speed;
	int benzine;
} car;
//typedef struct car_type car;

void init();
void setDataCar();

int main(void)
{
	init();
	printf("%s", car.name);
	setDataCar();
	printf("%s", car.name);

	return 0;
}

void init() {
	printf("Car initialized\n");
	printf("Enter a car name: ");
	fflush(stdin);
	scanf("%s", &car.name);
}

void setDataCar() {
	printf("Car parameters set!\n");
}

