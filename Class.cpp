#include <iostream>
#include <time.h>

#include "Class.h"

using namespace std;

Bus_Traffic::Bus_Traffic()
{
	price_per_10kms = 0;
	min_people = 0;
	people_count = 0;
}

Bus_Traffic::Bus_Traffic(int number, string name, int age, int price, int people, int people_real) : Car_Traffic(number, name, age)
{
	price_per_10kms = price;
	min_people = people;
	people_count = people_real;
}

int Bus_Traffic::Get_price_per_10kms()
{
	return price_per_10kms;
}

int Bus_Traffic::Get_min_people()
{
	return min_people;
}

int Bus_Traffic::Get_people_count()
{
	return people_count;
}

void Bus_Traffic::Set_price_per_10kms(int value)
{
	if (value < 0)
	{
		throw ("Incorrect value of price transportation 1 person per 10 kilometres");
	}
	price_per_10kms = value;
}

void Bus_Traffic::Set_min_people(int value)
{
	if (value < 0)
	{
		throw ("Incorrect count of people");
	}
	min_people = value;
}

void Bus_Traffic::Set_people_count(int value)
{
	people_count = value;
}



Bus_Traffic::~Bus_Traffic()
{
}

Car_Traffic::Car_Traffic()
{
	car_number = 0;
	driver_name = "";
	driver_age = 0;
}

Car_Traffic::Car_Traffic(int number, string name, int age)
{
	car_number = number;
	driver_name = name;
	driver_age = age;
}

int Car_Traffic::Get_car_number()
{
	return car_number;
}

string Car_Traffic::Get_driver_name()
{
	return driver_name;
}

int Car_Traffic::Get_driver_age()
{
	return driver_age;
}

void Car_Traffic::Set_car_numb(int number)
{
	if (number > 9999 && number < 1000)
	{
		throw ("Incorrect value of car number!");
	}
	car_number = number;
}

void Car_Traffic::Set_driver_name(string name)
{
	driver_name = name;
}

void Car_Traffic::Set_driver_age(int age)
{
	driver_age = age;
}

int Car_Traffic::Price_of_traffic()
{
	return 0;
}

ostream& operator<<(ostream& out, const Car_Traffic& obj)
{
	out << obj.car_number << ", " << obj.driver_name << ", " << obj.driver_age;
	return out;
}

istream& operator>>(istream& in, Car_Traffic& obj)
{
	cout << "Car number: ";
	in >> obj.car_number;
	cout << "Driver name: ";
	in >> obj.driver_name;
	cout << "Driver age: ";
	in >> obj.driver_age;
	return in;
}


Freight_Transportation::Freight_Transportation() : Car_Traffic() {}

Freight_Transportation::Freight_Transportation(int number, string name, int age, int tons_count, int price, int kms) : Car_Traffic(number, name, age)
{
	this->mass = tons_count;
	this->price_ton_per_km = price;
	this->km_count = kms;
}


int Freight_Transportation::Get_mass()
{
	return mass;
}

int Freight_Transportation::Get_price_ton_per_km()
{
	return price_ton_per_km;
}

int Freight_Transportation::Get_km_count()
{
	return km_count;
}

void Freight_Transportation::Set_mass(int mass)
{
	mass = mass;
}

void Freight_Transportation::Set_price_ton_per_km(int price)
{
	price_ton_per_km = price;
}

void Freight_Transportation::Set_km_count(int kms)
{
	km_count = kms;
}

Freight_Transportation::~Freight_Transportation()
{
}

int Freight_Transportation::Price_of_traffic()
{
	return (mass + km_count) * price_ton_per_km;
}

int Bus_Traffic::Price_of_traffic()
{
	if (people_count < min_people)
	{
		return 0;
	}
	return price_per_10kms * people_count;
}