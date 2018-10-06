#include "GameWorld.h"

void GameWorld::Start() {
	//Defining Bounds
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
				worldState[i][j] = '*';
			}
			else {
				worldState[i][j] = ' ';
			}
		}
	}

	
	//Defining Enemies
	srand(time(NULL));
	for (int i = 0; i < 8; i++) {
		enemyObjects.push_back(Enemy());
		enemyObjects[i].SetEnemy(4 + (4 * i), 3);
		enemyObjects[i].animState = rand() % 2;
		enemyObjects[i].symbol = (enemyObjects[i].animState == 0 ? 'W' : 'M');
	}

	for (int i = 0; i < 8; i++) {
		worldState[enemyObjects[i].y][enemyObjects[i].x] = enemyObjects[i].symbol;
	}

	//thread f (Render);
}

void GameWorld::Update() {
	for (int i = 0; i < size(enemyObjects); i++) {
		enemyObjects[i].tickState += deltaTime;
		enemyObjects[i].Move(worldState);
	}

	//Check for wall collisions.
	for (int i = 0; i < size(enemyObjects); i++) {
		if (enemyObjects[i].x + enemyObjects[i].dir == 0 || enemyObjects[i].x + enemyObjects[i].dir == WIDTH - 1) {
			for (int j = 0; j < size(enemyObjects); j++) {
					enemyObjects[j].Reverse();
				if (i == 0) {
					enemyObjects[j].Dropdown();
				}
			}
			break;
		}
	}
}

void GameWorld::Render() {
	system("cls");
	//Draw World
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << worldState[i][j];
		}
		cout << endl;
	}
}

void GameWorld::Shutdown() {
	cout << "Shutdown Gameworld" << endl;
}

void GameWorld::SetDeltaTime(double t) {
	deltaTime = t;
}