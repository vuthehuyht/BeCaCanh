#pragma once
#include <string>

using namespace std;

class Fish {
public:
	enum Salt
	{
		F = 0, // Salt in water is less than 0.5%
		B, // Salt in water is between 0.5% and 5%
		S, // Salt in water is between 5% and 18%
	};

	enum Temperature
	{
		WARM = 0,
		COLD,
	};

	Fish();
	Fish(string name, float min_ph, float max_ph, Salt salt, Temperature temperature, bool aggressive);
	~Fish();

	// Return fish's information.
	string ToString();

	// Check the environment is suitable for fish.
	bool CheckEnvironment(float ph, Salt salt, Temperature temperature);

	// Return fish's name.
	string GetName();

	// Return fish's aggressive.
	bool GetAggressive();

private:
	string name_;
	float min_ph_;
	float max_ph_;
	Salt salt_;
	Temperature temperature_;
	bool aggressive_;
};

