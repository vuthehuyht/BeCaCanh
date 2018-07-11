#include "SpecimenTank.h"

SpecimenTank::SpecimenTank(Fish::Salt salt, Fish::Temperature temperature, float ph) {
	tank_size_ = 1;
	salt_ = salt;
	temperature_ = temperature;
	ph_ = ph;
}

SpecimenTank::~SpecimenTank() {
}

void SpecimenTank::Display() {
	cout << "==================" << endl;
	cout << "SpecimenTank: " << fishes_.size() << endl;
	for (int i = 0; i < fishes_.size(); i++) {
		cout << fishes_[i].ToString() << endl;
	}
}

bool SpecimenTank::CheckFishSuitability(Fish fish) {
	// If tank is full, return false.
	if (fishes_.size() == tank_size_)
		return false;

	return fish.CheckEnvironment(ph_, salt_, temperature_);
}

bool SpecimenTank::AddFish(Fish fish) {
	// If tank is suitable for fish, add fish to tank.
	if (CheckFishSuitability(fish)) {
		fishes_.push_back(fish);
		return true;
	}

	return false;
}

void SpecimenTank::RemoveFish(string name) {
	for (vector<Fish>::iterator it = fishes_.begin(); it != fishes_.end();) {
		if (it->GetName().compare(name) == 0) {
			fishes_.erase(it);
		}
		else {
			it++;
		}
	}
}
