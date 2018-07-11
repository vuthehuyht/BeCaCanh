#include "SpeciesTank.h"

SpeciesTank::SpeciesTank(Fish::Salt salt, Fish::Temperature temperature, float ph) {
	tank_size_ = 20;
	fish_name_ = "";
	salt_ = salt;
	temperature_ = temperature;
	ph_ = ph;
}


SpeciesTank::~SpeciesTank() {
}

void SpeciesTank::Display() {
	cout << "==================" << endl;
	cout << "SpeciesTank: " << fishes_.size() << endl;
	for (int i = 0; i < fishes_.size(); i++) {
		cout << fishes_[i].ToString() << endl;
	}
}

bool SpeciesTank::CheckFishSuitability(Fish fish) {
	// If tank is full, return false.
	if (fishes_.size() == tank_size_)
		return false;

	// If tank is empty, check the environment of tank is suitable fo fish.
	// Otherwise, check fish name is same with the name of fishes in tank,
	// then check the environment of tank is suitable fo fish.
	if (fishes_.empty()) {
		return fish.CheckEnvironment(ph_, salt_, temperature_);
	}
	else {
		return fish.GetName().compare(fish_name_) && fish.CheckEnvironment(ph_, salt_, temperature_);
	}

	return false;
}

bool SpeciesTank::AddFish(Fish fish) {
	// If tank is suitable for fish, add fish to tank.
	if (CheckFishSuitability(fish))
	{
		// If tank is empty, set fish's name of this tank.
		if (fishes_.empty())
		{
			fish_name_ = fish.GetName();
		}
		fishes_.push_back(fish);

		return true;
	}

	return false;
}

void SpeciesTank::RemoveFish(string name) {
	for (vector<Fish>::iterator it = fishes_.begin(); it != fishes_.end();) {
		if (it->GetName().compare(name) == 0) {
			fishes_.erase(it);
		}
		else {
			it++;
		}
	}

	// If tank is empty, clear fish's name of this tank.
	if (fishes_.empty()) {
		fish_name_ = "";
	}
}