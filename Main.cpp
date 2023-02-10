#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Printer.h"
#include <memory>
//в случае если фунция inline она встраивается в код на этапе компиляции на место вызова, в случае если функция слишком маленькая или слишком большая не часто встречающася(наприме 1 раз по коду)
using namespace Engine;
//merge - sort cортировка сли¤нием/quick sort скорость от nlog(n) до 2nlog(n)/ shake sort /разные сортировки предназначены дл¤ разных типов данных(почти отсортированные, сортированные в обратном пор¤дке и т.д.)
//функтор– -  это обьект (в нашем случае класс) у которго перегружен оператор круглые скобки()
//лямбда -         ||
//		   ||
//		  \  /
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
	
	return 0;
}
