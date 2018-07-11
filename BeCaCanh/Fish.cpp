#include "Fish.h"

Fish::Fish() {
}

Fish::Fish(string name, float min_ph, float max_ph, Salt salt, Temperature temperature, bool aggressive) {
	// Set properties of object
	name_ = name;
	min_ph_ = min_ph;
	max_ph_ = max_ph;
	salt_ = salt;
	temperature_ = temperature;
	aggressive_ = aggressive;
}


Fish::~Fish() {
}

string Fish::ToString() {
	return "Fish: " + name_;
}

bool Fish::CheckEnvironment(float ph, Salt salt, Temperature temperature) {
	if (min_ph_ < ph && ph < max_ph_ && temperature_ == temperature && salt_ == salt)
		return true;

	return false;
}

string Fish::GetName() {
	return name_;
}

bool Fish::GetAggressive() {
	return aggressive_;
}