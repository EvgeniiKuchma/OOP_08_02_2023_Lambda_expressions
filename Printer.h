#pragma once
#include "IVehicle.h"
#include <vector>
#include <iostream>
#include <memory>
namespace Engine {
	class Printer
	{
	public:
		void printDefult();
		void getVehicle(std::shared_ptr<IVehicle> c);
	private:
		std::vector<std::shared_ptr<IVehicle>> s_ptr_vec;
	};
};
