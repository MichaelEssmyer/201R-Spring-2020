
#define RUN 0
#define TEST 1
#if RUN

#include "Test.h"



int main() {
	const int size = 9;
	Tile * Tile_array[size];

	int testfailure_count;
	/* Start: Initiation TEST for Tile Struct*/
	std::cout << "Test Start for Tile Struct Initiation" << std::endl;
	testfailure_count = 0;
	for (int row = 1; row <= 3; row++) {
		for (int col = 1; col <= 3; col++) {

			Tile_array[((row + 1) * (row - 1)) + (col - 1) - (row / 3 * 2)] = new Tile(row, col);


		}
	}
	for (int i = 0; i < 9; i++) {
		std::cout << Tile_array[i]->mark << std::endl;
		std::cout << Tile_array[i]->row << std::endl;
		std::cout << Tile_array[i]->col << std::endl;

	}
	std::cout << "Test End: " << testfailure_count << " failures" << std::endl;
	/* End: Initiation TEST for Tile Struct*/
	/* Display Board test*/
	char mark = 'X';
	for (int i = 0; i < 9; i++) {
		Tile_array[i]->mark = mark;
	}
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setfill(' ')<< std::setw(4) << Tile_array[0]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[1]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[2]->mark << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setw(6) << std::setfill('_') <<'_'<<"||"<<std::setw(6) << std::setfill('_')<<'_'<< "||" << std::setw(6) << '_' << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setfill(' ') << std::setw(4) << Tile_array[3]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[4]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[5]->mark << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << '_' << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setfill(' ') << std::setw(4) << Tile_array[6]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[7]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[8]->mark << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;

	
	for (int i = 0; i < 9; i++) {
		delete Tile_array[i];
		Tile_array[i] = nullptr;
	}
	

	std::cin.get();
	
	
	return 0;

}


#endif