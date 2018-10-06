#ifndef GAMEWORLD
#define GAMEWORLD
#define WIDTH 37
#define HEIGHT 12

#include "MonoBehaviour.h"
#include "Singleton.h"

#include <thread>
#include <vector>
#include <random>
#include <functional>

using namespace std;

class GameWorld : public MonoBehaviour
{
	struct Enemy {
		int x = 0;
		int y = 0;
		int dir = 1;
		int speed = 1;
		int animState = 0;
		double tickState = 0.0;
		char symbol = 'M';
		bool drop = false;

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
			speed ++;
		}
	};

	public:
		void Start();
		void Update();
		void Shutdown();
		void Render();
		void SetDeltaTime(double t);

	private:
		char worldState[HEIGHT][WIDTH];
		vector<Enemy> enemyObjects;
		double deltaTime = 0.0;
};

#endif