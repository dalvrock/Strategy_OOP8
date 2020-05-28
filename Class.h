#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car_Traffic
{
private:
	int car_number;
	string driver_name;
	int driver_age;
public:
	virtual ~Car_Traffic() {}
	Car_Traffic();
	Car_Traffic(int, string, int);
	friend ostream& operator<<(ostream& out, const Car_Traffic&);
	friend istream& operator>>(istream& in, Car_Traffic&);

	int Get_car_number();
	string Get_driver_name();
	int Get_driver_age();

	void Set_car_numb(int numb);
	void Set_driver_name(string name);
	void Set_driver_age(int age);

	virtual int Price_of_traffic();

};


class Context
{
private:
	Car_Traffic* strategy_;
public:
	Context(Car_Traffic* strategy = nullptr) : strategy_(strategy)
	{
	}
	~Context()
	{
		delete this->strategy_;
	}

	void set_strategy(Car_Traffic* strategy)
	{
		delete this->strategy_;
		this->strategy_ = strategy;
	}

	void DoSomeBusinessLogic() const
	{
		int result = this->strategy_->Price_of_traffic();
		std::cout << result << "\n";
	}
};

class Bus_Traffic : public Car_Traffic
{
private:
	int price_per_10kms;
	int min_people;
	int people_count;
public:
	Bus_Traffic();
	Bus_Traffic(int, string, int, int, int, int);

	int Get_price_per_10kms();
	int Get_min_people();
	int Get_people_count();

	void Set_price_per_10kms(int value);
	void Set_min_people(int value);
	void Set_people_count(int value);


	int Price_of_traffic() override;

	~Bus_Traffic();

};


class Freight_Transportation : public Car_Traffic
{
private:
	int mass = 0;
	int price_ton_per_km = 0;
	int km_count = 0;
public:
	Freight_Transportation();
	Freight_Transportation(int, string, int, int, int, int);

	int Price_of_traffic() override;

	int Get_mass();
	int Get_price_ton_per_km();
	int Get_km_count();

	void Set_mass(int tons_count);
	void Set_price_ton_per_km(int price);
	void Set_km_count(int kms);

	~Freight_Transportation();
};

