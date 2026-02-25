#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>

int main(){   

	srand(time(NULL));
    
	const int field = '*';
    const int size = 4;

	std::vector<std::vector<char>> map(size, std::vector<char>(size, field));

	int random_x;
	int random_y;
	int four_or_two;
	char choose;
	while (true){

		system("cls");

		int i = 0;
		
		while (i != 2) {

			random_x = rand() % size;
			random_y = rand() % size;

			if (map[random_x][random_y] == field) {

				four_or_two = rand() % 9;

				if (four_or_two == 0) {
					map[random_x][random_y] = '4';
				}
				else {
					map[random_x][random_y] = '2';
				}

				i++;
			}

		}

		for (int y = 0; y < size; y++) {
			for (int x = 0; x < size; x++) {
				std::cout << map[y][x] << "  ";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}


		choose = _getch();

		switch (choose)
		{
		case 'w':

			break;
		case 'a':
			break;
		case 's':
			for(int i = 0; i < 2; i++){
				for (int x = 0; x < size; x++){
					for (int y = 0; y < size - 1; y++){
						if (map[y][x] == map[y + 1][x] && map[y][x] != field){

							map[y + 1][x] = static_cast<int>(map[y + 1][x] * 2); //mistake static_cast
							map[y][x] = field;
							
						}
						else if (map[y][x] != field && map[y + 1][x] == field){
							map[y + 1][x] = map[y][x];
							map[y][x] = field;
						}


					}
				}

			}
			break;
		case 'd':
			break;

		default:
			break;
		}
		
	}
	
}

//for(int y = 0; y < size; y++)
//{
//	for(int x = 0; x < size; x++)
//	{
//		if(map[y][x]) {
//
//		}
//		if else(){
//
//		}
//	}
//}
