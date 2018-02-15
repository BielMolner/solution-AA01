#include <iostream>
#include<string>
#include<ctime>

const int nameSize = 7;
const int maxEnemies = 5;

std::string ranName[nameSize] = {"ignasi","biel", "gerard","victor","arnau","ares","toni"};



enum EnemyType {zombie,vampire,ghost,witch};

struct Enemy {

	EnemyType type;
	std::string name;
	int health;

};

bool equalEnemies(Enemy a, Enemy b){

	if (a.health == b.health&&a.name == b.name&& a.type == b.type) {
		return true;
	}
	else{
		return false;
	}
}

Enemy createRandomEnemy() {

	Enemy randomEnemy;

	srand(time(NULL));

	randomEnemy.type = EnemyType (rand()%sizeof(EnemyType));
	
	randomEnemy.name = ranName[rand() % nameSize];

	randomEnemy.health = rand()%500;

	
}

std::string getEnemyString(EnemyType enemy) {

	switch (enemy)
	{
	case zombie:
		return "zombie";
		break;
	case vampire:
		return "vampire";
		break;
	case ghost:
		return "ghost";
		break;
	case witch:
		return "which";
		break;
	}
}

int main() {

	Enemy arrEnemies[maxEnemies];

	Enemy diferent;

	bool duplicatedEnemy;

	for (int i = 0; i < maxEnemies; i++)
	{
		if (i = 0)
			arrEnemies[i] = createRandomEnemy();
		else {
			
			do {
				arrEnemies[i] = createRandomEnemy();
				for (int j = i - 1; i >= 0 || !duplicatedEnemy; j--)
				{
					duplicatedEnemy = equalEnemies(arrEnemies[i], arrEnemies[j]);
				}

			} while (!duplicatedEnemy);
		}
	}
}
