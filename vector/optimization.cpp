#include <iostream>
#include <vector>



struct Entity
{

	int x, y, z;

	Entity(int x, int y, int z)
		: x(x), y(y), z(z)
	{
	}

	Entity(const Entity& e)
		: x(e.x), y(e.y), z(e.z)
	{
		std::cout << "Copied!" << std::endl;
	}
	
};

int main(void)
{
	std::cout << "\n\nAppStart..........\n";
	std::vector<Entity> ent;


	// ent.push_back({1, 1, 1});
	// ent.push_back({2, 1, 1});
	// ent.push_back({3, 1, 1});
	// sme as bellow
	// ent.push_back(Entity(1, 1, 1));
	// ent.push_back(Entity(2, 1, 1));
	// ent.push_back(Entity(3, 1, 1));

	/*
	 *	if we use the code bellow 
	 * instead of the commented code above
	 * 	no copies of the class Entity are made, 
	 * thus better performance
	 */

	ent.reserve(3);
	ent.emplace_back(1, 1, 1);
	ent.emplace_back(2, 1, 1);
	ent.emplace_back(3, 1, 1);


	std::cout << "AppEnd............\n";
	return 0;
}