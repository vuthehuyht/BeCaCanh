#include "CommunityTank.h"


CommunityTank::CommunityTank(int tank_size, Fish::Salt salt, Fish::Temperature temperature, float ph)
	:FishTank() {
	tank_size_ = tank_size;
	salt_ = salt;
	temperature_ = temperature;
	ph_ = ph;
}


CommunityTank::~CommunityTank() {
}

void CommunityTank::Display() {
	cout << "==================" << endl;
	cout << "CommunityTank: " << fishes_.size() << endl;
	for (int i = 0; i < fishes_.size(); i++) {
		cout << fishes_[i].ToString() << endl;
	}
}

bool CommunityTank::CheckFishSuitability(Fish fish) {
	// If tank is full, return false.
	if (fishes_.size() == tank_size_)
		return false;

	// If fish is not aggressive, check the environment of tank is suitable for fish.
	if (!fish.GetAggressive()) {
		return fish.CheckEnvironment(ph_, salt_, temperature_);
	}

	return false;
}

bool CommunityTank::AddFish(Fish fish) {
	// If tank is suitable for fish, add fish to tank.
	if (CheckFishSuitability(fish))
	{
		fishes_.push_back(fish);
		return true;
	}

	return false;
}

void CommunityTank::RemoveFish(string name) {
	for (vector<Fish>::iterator it = fishes_.begin(); it != fishes_.end();) {
		if (it->GetName().compare(name) == 0) {
			fishes_.erase(it);
		}
		else {
			it++;
		}
	}
}
