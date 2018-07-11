#pragma once
#include "Fish.h"
#include <vector>

using namespace std;

class FishTank {
public:
	FishTank();
	~FishTank();

	// Display all fishes of tank.
	virtual void Display() = 0;

	// Check tank is suitable for fish.
	virtual bool CheckFishSuitability(Fish fish) = 0;

	// Add a fish to tank
	virtual bool AddFish(Fish fish) = 0;

	// Remove all fishes with name from tank
	virtual void RemoveFish(string name) = 0;

protected:
	vector<Fish> fishes_;
	int tank_size_;
	Fish::Salt salt_;
	Fish::Temperature temperature_;
	float ph_;
};

