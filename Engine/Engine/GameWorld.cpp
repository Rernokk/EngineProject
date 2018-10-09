#include "GameWorld.h"

void GameWorld::Start() {
	//Defining Bounds
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
				updateState[i][j] = '#';
			}
			else {
				updateState[i][j] = ' ';
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
		updateState[enemyObjects[i].y][enemyObjects[i].x] = enemyObjects[i].symbol;
	}

	playerObj = player();
	updateState[playerObj.x][playerObj.y] = playerObj.symbol;

	memcpy(renderState, updateState, (sizeof(updateState)));
}

void GameWorld::Update() {
	//Move Enemies
	for (int i = 0; i < size(enemyObjects); i++) {
		if (enemyObjects[i].dead == false){
			enemyObjects[i].tickState += deltaTime;
			enemyObjects[i].Move(updateState);
		}
		else {
			enemyObjects[i].symbol = ' ';
			enemyObjects.erase(enemyObjects.begin() + i);
		}
	}

	//Move Player
	playerObj.tickState += deltaTime;
	playerObj.Move(updateState, input, &projectiles);

	//Move Projectiles
	for (int i = 0; i < size(projectiles); i++) {
		if (projectiles[i].fin) {
			projectiles.erase(projectiles.begin() + i);
		} else {
			projectiles[i].Update(updateState);
			for (int j = 0; j < size(enemyObjects); j++) {
				if (projectiles[i].y == enemyObjects[j].x && projectiles[i].x == enemyObjects[j].y) {
					enemyObjects[j].dead = true;
				}
			}
		}
	}

	//Check for wall collisions.
	for (int i = 0; i < size(enemyObjects); i++) {
		if (enemyObjects[i].x + enemyObjects[i].dir == 0 || enemyObjects[i].x + enemyObjects[i].dir == WIDTH - 1) {
			for (int j = 0; j < size(enemyObjects); j++) {
				enemyObjects[j].Reverse();
				if (enemyObjects[i].x == 1) {
					enemyObjects[j].Dropdown();
				}
			}
			break;
		}
	}
	
	memcpy(renderState, updateState, (sizeof(updateState)));
}

void GameWorld::Render(char inWorld[HEIGHT][WIDTH], double MS_PER_FRAME) {
	auto prev = chrono::high_resolution_clock::now();
	while (true) {
		auto current = chrono::high_resolution_clock::now();
		system("cls");
		//Draw World
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				cout << inWorld[i][j];
			}
			//cout << endl;
			cout << '\n';
		}
		prev = chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds((int)((MS_PER_FRAME * 1000 - chrono::duration_cast<chrono::milliseconds>(current - prev).count()))));
	}
}

void GameWorld::InputHandler(char * str, double MS_PER_FRAME)
{
	while (true){
		if (*str == 'z'){
			*str = _getch();
		}
	}
}

void GameWorld::Shutdown() {
	cout << "Shutdown Gameworld" << endl;
}

void GameWorld::SetDeltaTime(double t) {
	deltaTime = t;
}