#pragma once
#include "Printer.h"
class IVehicle
{
public:
	virtual ~IVehicle() {};
	virtual int getSpeed()const = 0;
	virtual void printType() const = 0;
private:

};