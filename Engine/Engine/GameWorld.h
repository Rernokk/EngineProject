#ifndef GAMEWORLD
#define GAMEWORLD
#define WIDTH 37
#define HEIGHT 12

#include "MonoBehaviour.h"

#include <thread>
#include <vector>
#include <random>
#include <functional>
#include <conio.h>
#include <sstream>
#include <mutex>

using namespace std;

class GameWorld : public MonoBehaviour
{
public:
	struct Enemy {
		int x = 0;
		int y = 0;
		int dir = 1;
		int speed = 1;
		int animState = 0;
		double tickState = 0.0;
		char symbol = 'M';
		bool drop = false;
		bool dead = false;

		void SetEnemy(int ix, int iy) {
			x = ix;
			y = iy;
		}

		void Move(char worldState[HEIGHT][WIDTH]) {
			if (tickState < 1000.0 / speed) {
				return;
			}
			tickState -= 1000.0 / speed;
			animState = abs(animState - 1);
			switch (animState) {
			case(0):
				symbol = 'W';
				break;
			case(1):
				symbol = 'M';
				break;
			}

			if (drop) {
				char temp = worldState[y][x + 1];
				worldState[y][x] = temp;
				y += 1;
				worldState[y][x] = symbol;
				drop = false;
			}
			else {
				char temp = worldState[y + dir][x];
				worldState[y][x] = temp;
				x += dir;
				worldState[y][x] = symbol;
			}

		}

		void Reverse() {
			dir *= -1;
		}

		void Dropdown() {
			drop = true;
			speed++;
		}
	};

	struct projectile {
		int x;
		int y;
		char symbol = '*';
		bool fin = false;

		projectile() {
			x = HEIGHT - 3;
			y = floor(WIDTH/2);
		}

		projectile(int yPos) {
			x = HEIGHT - 3;
			y = yPos;
		}

		void Update(char worldState[HEIGHT][WIDTH]) {
			worldState[x][y] = ' ';
			x -= 1;
			if (worldState[x][y] != '#'){
				worldState[x][y] = symbol;
			}
			else {
				fin = true;
			}
		}
	};

	struct player {
		int x;
		int y;
		char symbol;
		double tickState = 0.0;
		double speed = 6;
		int dir = 1;

		player() {
			x = HEIGHT - 2;
			y = floor(WIDTH / 2);
			symbol = '^';
			tickState = 0;
		}

		void Move(char worldState[HEIGHT][WIDTH], char * input, vector<projectile> * projectiles) {
			if (tickState < 1000.0 / speed) {
				return;
			}
			tickState -= 1000.0 / speed;
			switch (*input) {
				case('a'):
					dir = -1;
					break;
				case('d'):
					dir = 1;
					break;
				case(' '):
					if ((*projectiles).size() < 2){
						(*projectiles).push_back(projectile(y));
					}
					break;
				default:
					dir = 0;
					break;
			}

			*input = 'z';
			char temp = worldState[x][y + dir];
			if (temp != '#') {
				worldState[x][y] = temp;
				y += dir;
				worldState[x][y] = symbol;
			}
		}
	};

public:
	void Start();
	void Update();
	void Shutdown();
	void Render(char inWorld[HEIGHT][WIDTH], double MS_PER_FRAME);
	void InputHandler(char * c, double MS_PER_FRAME);
	void SetDeltaTime(double t);
	char renderState[HEIGHT][WIDTH];
	player playerObj;
	char * input;

private:
	char updateState[HEIGHT][WIDTH];
	double deltaTime = 0.0;
	vector<Enemy> enemyObjects;
	vector<projectile> projectiles;
};

#endif