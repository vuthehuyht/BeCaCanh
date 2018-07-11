#pragma once
#include "FishTank.h"
#include <iostream>

class SpeciesTank : FishTank {
public:
	SpeciesTank(Fish::Salt salt, Fish::Temperature temperature, float ph);
	~SpeciesTank();

	void Display() override;
	bool CheckFishSuitability(Fish fish) override;
	bool AddFish(Fish fish) override;
	void RemoveFish(string name) override;

private:
	string fish_name_;
};

