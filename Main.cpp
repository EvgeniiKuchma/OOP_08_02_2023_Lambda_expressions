#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Printer.h"
#include <memory>
using namespace Engine;
//merge - sort cортировка сли¤нием/quick sort скорость от nlog(n) до 2nlog(n)/ shake sort /разные сортировки предназначены дл¤ разных типов данных(почти отсортированные, сортированные в обратном пор¤дке и т.д.)
//‘”Ќ “ќ– -  это обьект (в нашем случае класс) у которго перегружен оператор круглые скобки()
//ЋяћЅƒј - ||
//		   ||
//		  \	 /
//		   \/
class Incrementer {
public:
	Incrementer(int x ) : _x(x){}
 
	int operator()(int y) {
	 return _x + y;
	}
	int myFunc(int y) {
		const auto add = [this,y](int a) {//дл¤ вызова приватного пол¤ this 
			//(передача по указателю на  адрес класса, по ссылке )
			return _x + y + a;
		};
		return add(5);
	}
private:
	int _x;
};


class Car : public IVehicle
{
public:
	Car(int speed) : _speed(speed){}
	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Car " << std::endl;
	}
	
private:
	int _speed;
};
class Moto : public IVehicle
{
public:
	Moto(int speed) : _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Car " << std::endl;
	}

private:
	int _speed;
};
class Van : public IVehicle
{
public:
	Van(int speed) : _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Car " << std::endl;
	}

private:
	int _speed;
};


int main() {
	setlocale(LC_ALL, "Rus");
	Incrementer inc(1);
	int a = inc(5);//каждый раз когда после создани¤ класса обьекта вызываем оператор круглые скобки 
	//он ведет себ¤ как вызов фукции фунци¤
	std::cout << a << std::endl;

	const auto myinc = [a](int a1) -> int // ¤вное преобразование возвращаемого типа данных в int ,mutable модификаторы
	{
		//копи¤ а сохран¤етс¤ в переменной (л¤бда фунци¤)
		//(в ее зоне [] capture clause и в дальнейшем припробрасывании myinc будет знать о существовании a
		//зачват производитс¤ из зоны видимости все что выше л¤мбды функции (зон¤ видимости определ¤етс¤ {}) 
		//const auto myinc = [=, &a](int a1) все перменные которые видит myinc захватить копированием(инициализаци¤ по умолчанию)
		//через зап¤тую после по умолчанию перечисленны все что нужно захватить по ссылке
		//const auto myinc = [&,a](int a1) все беретс¤ по ссылке. перменна¤ а копированием
		return  a1 + 5 + a;
	};
	//[&total, factor]
	//[total, &factor]
	//[&, factor]
	//[=, &factor]
	std::cout << myinc(6) <<std::endl;

	std::cout << inc.myFunc(3) << std::endl;
	std::cout << "+++++++++++++++++++" << std::endl;
	std::vector<int> vec{ 1,2,3,4 };//лист инициализации наиболее предпочтительный способ инициализации stl контейнеров
	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end(), [](int a, int b){ //[] л¤мбда фунци¤
		return std::abs(a) > std::abs(b);//abs берет число по модулю
	});
	for (const auto el : vec) {
		std::cout << el << " ";
	}

	//Engine::Printer p; при подключение using namespace Engine данную конструкцию можно не использовать можно не использовать
	
	Printer p;
	std::shared_ptr<IVehicle> c = std::make_shared<Car>(50);
	std::shared_ptr<IVehicle> v = std::make_shared<Van>(50);
	std::shared_ptr<IVehicle> m = std::make_shared<Moto>(50);
	p.getVehicle(c);
	p.getVehicle(v);
	p.getVehicle(m);
	return 0;
}