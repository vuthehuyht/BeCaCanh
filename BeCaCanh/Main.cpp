#include "CommunityTank.h"
#include "SpeciesTank.h"
#include "SpecimenTank.h"

int main(int argc, char* argv[]) {

	CommunityTank community_tank(10, Fish::Salt::B, Fish::Temperature::COLD, 6.7);
	SpeciesTank species_tank(Fish::Salt::S, Fish::Temperature::COLD, 8);
	SpecimenTank speciment_tank(Fish::Salt::F, Fish::Temperature::WARM, 10);

	Fish fish_1("1", 5, 7, Fish::Salt::B, Fish::Temperature::COLD, false);
	Fish fish_2("2", 5, 7, Fish::Salt::B, Fish::Temperature::COLD, true);
	Fish fish_3("3", 10, 12, Fish::Salt::S, Fish::Temperature::COLD, false);
	Fish fish_4("4", 6, 12, Fish::Salt::S, Fish::Temperature::COLD, false);
	Fish fish_5("5", 6, 12, Fish::Salt::F, Fish::Temperature::WARM, true);

	community_tank.AddFish(fish_1);
	community_tank.AddFish(fish_2);
	community_tank.AddFish(fish_3);
	community_tank.AddFish(fish_4);
	community_tank.AddFish(fish_5);

	species_tank.AddFish(fish_1);
	species_tank.AddFish(fish_2);
	species_tank.AddFish(fish_3);
	species_tank.AddFish(fish_4);
	species_tank.AddFish(fish_5);

	community_tank.Display();
	species_tank.Display();
	speciment_tank.Display();

	system("pause");

	return 0;
}