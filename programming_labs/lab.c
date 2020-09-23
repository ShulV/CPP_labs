// lab work �2 Shulpov Victor PI-92
/*
����������� ������ ���������� �� ������� ������������ ���������.
���� ���������:
�	�������� (������)
�	���� (�����)
�	���� (������)
�	���������� �������� ��������� � ������ (�����)
�	�������� (�����)
�	���������� ������� (�����)
�������:
�	�������������
�	��������� ���������� ����������
�	����� ������ ������
�	������ ���������
�	��������� ���������
�	���������� ��������
�	��������� ��������
*/
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

void init(struct car* car, char* name, int price, char* color, int engineRPM, int speed, int benzine); //init
void displayDataCar(struct car car);
struct car* addBenzine(struct car* car, int liters);
int startEngine(struct car* car);
int stopEngine(struct car* car);
int addSpeed(struct car* car);
int reduceSpeed(struct car* car);

int main(void)
{
	int n;
	struct car* pCar1;
	pCar1 = (struct car*)malloc(sizeof(struct car));
	init(pCar1, 1200000, "BMW", "red", 0, 0, 0); //�������������� ������1 (�������� ��� ��� ������, ��������� ������������ ����������)
	free(pCar1); //������� ������, ���������� ��� ������1
	struct car* car1;
	car1 = (struct car*)malloc(sizeof(struct car));
	init(car1, 1200000, "AUDI", "red", 0, 0, 0); //�������������� ������2
	free(car1);//������� ������, ���������� ��� ������2
	//���������� ��� ������� �� ������� ������
	//struct car car3 = { " ", 0, " ", 0, 0, 0 };
	struct car* pCar3;// = &car3;
	pCar3 = (struct car*)malloc(sizeof(struct car));
	init(pCar3, "VOLVO", 1299999, "blue", 0, 0, 10); //�������������� ������3
	displayDataCar(*pCar3); //���������� ��������� ������3
	startEngine(pCar3); //�������� ������� ���������
	displayDataCar(*pCar3);
	addBenzine(pCar3, 10); //��������� ������
	displayDataCar(*pCar3);
	startEngine(pCar3); //����� �������� ������� ���������
	displayDataCar(*pCar3);
	for (int i = 0; i < 4; i++) {
		addSpeed(pCar3); //��������� �������� �� 20 ��/� 4 ����
	}
	displayDataCar(*pCar3);
	for (int i = 0; i < 4; i++) {
		reduceSpeed(pCar3); //�������� �������� �� 20 ��/� 4 ����
	}
	displayDataCar(*pCar3);
	stopEngine(pCar3); //������������� ���������
	displayDataCar(*pCar3);
	free(pCar3); //������� ������, ���������� ��� ������3
	return 0;
}

void init(struct car* car, char* name, int price, char* color, int engineRPM, int speed, int benzine) {
	car->name = name;
	car->price = price;
	car->color = color;
	car->engineRPM = engineRPM;
	car->benzine = benzine;
	car->speed = speed;
	printf("Car initialized!\n");
	return car;

}

void displayDataCar(struct car car) {
	puts("\tCar data");
	char* str = car.name;
	printf("\t\tName:\t%s\n", str);
	int num = car.price;
	printf("\t\tPrice:\t%d\n", num);
	str = car.color;
	printf("\t\tColor:\t%s\n", str);
	num = car.engineRPM;
	printf("\t\tEngine RPM:\t%d\n", num);
	num = car.speed;
	printf("\t\tSpeed:\t%d\n", num);
	num = car.benzine;
	printf("\t\tBenzine:\t%d\n", num);
	
}
	
	

struct car* addBenzine(struct car* car, int liters) {
	printf("%d lit. benzine added!\n", liters);
	car->benzine += liters;
	return car;
}

int startEngine(struct car* car) {
	if (car->benzine > 0) {
		car->engineRPM = 800;
		printf("Engine started!\n");
		return 0;
	}
	else {
		printf("No benzine. Engine didn't start!\n");
		return 1;
	}
	
	
}

int stopEngine(struct car* car) {
	if (car->engineRPM > 0) {
		car->engineRPM = 0;
		printf("Engine stopped!\n");
		return 0;
	}
	else {
		printf("Engine stopped already!\n");
		return 1;
	}
}

int addSpeed(struct car* car) {
	int speed = 20;
	if (car->engineRPM > 0) {
		car->speed += speed;
		printf("Car speeded up!\n");
		return 0;
	}
	else {
		printf("Engine isn't starting. Car didn't speed up!\n");
		return 1;
	}
}

int reduceSpeed(struct car* car) {
	int speed = 20;
	if (car->speed > 0) {
		car->speed -= speed;
		printf("Car speeded down!\n");
		return 0;
	}
	else {
		printf("Car is parking. Car didn't speed down!\n");
		return 1;
	}
}

/*
��� ��� ������
*/