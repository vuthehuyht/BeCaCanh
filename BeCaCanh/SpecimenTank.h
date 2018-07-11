#pragma once
#include "FishTank.h"
#include <iostream>

class SpecimenTank : FishTank {
public:
	SpecimenTank(Fish::Salt salt, Fish::Temperature temperature, float ph);
	~SpecimenTank();

	void Display() override;
	bool CheckFishSuitability(Fish fish) override;
	bool AddFish(Fish fish) override;
	void RemoveFish(string name) override;
};
