#pragma once
#include "FishTank.h"
#include <vector>
#include <iostream>

class CommunityTank : FishTank
{
public:
	CommunityTank(int tank_size, Fish::Salt salt, Fish::Temperature temperature, float ph);
	~CommunityTank();

	void Display() override;
	bool CheckFishSuitability(Fish fish) override;
	bool AddFish(Fish fish) override;
	void RemoveFish(string name) override;
};

