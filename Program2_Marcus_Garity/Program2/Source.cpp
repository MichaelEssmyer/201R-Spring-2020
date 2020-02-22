//Marcus Garity
//Program 2
//CS201R
//Creation Date 2/16/2020
//Due Date 2/20/2020




#include <iostream>
#include <string>
#include <vector>
#include <cctype>

//Function that takes inputs for wall Length and Width
//Caculates Area and then returns amount of cans of paint
//needed to do the job.
int cansOfPaint();
//takes in a string and checks if string contains a valid integer
bool checkValidInteger(const std::string);
//Prints the menu
void printMenu();
//takes in a string and checks if string is a valid float
bool checkValidFloat(const std::string);
//takes in amount of cans of paint and outputs cost for interior paint
int interiorCost(int cans);
//takes in amount of cans of paint and outputs cost for exterior paint
int exteriorCost(int cans);


int main() {
	bool invalid = true;
	std::string userInput;
	int TotalCost=0;
	printMenu();
	
	// Main While loop  of program.
	while (invalid) {
	
		std::cin >> userInput;
		
		if (userInput == "1" || userInput == "2" || userInput == "3")
			invalid = false;
		else
			std::cout << "Please input a valid number.(1, 2, or 3)" << std::endl;
		
	}
	// Main switch of program that relays to applicable functions
	switch (userInput[0]) {
	
		case '1':
			interiorCost(cansOfPaint());
			break;
		case '2':
			exteriorCost(cansOfPaint());
			break;
		case '3':
			std::cout << "Interior Walls First" << std::endl;
			TotalCost += interiorCost(cansOfPaint());
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Now Exterior Walls" << std::endl;
			TotalCost += exteriorCost(cansOfPaint());
			std::cout<<std::endl;
			std::cout<<std::endl;
			std::cout << "TOTAL COST: $" << TotalCost << ".00" << std::endl;
			break;
		default:
			break;
	
	}

	// Exit code with pause.
	std::cout << std::endl;
	std::cout << "Press Enter to exit Program." << std::endl;
	std::cin.get();
	std::cin.get();
	return 0;

}




int cansOfPaint() {
	std::string UserInput;
	int wall_count;
	std::vector<float> length;
	std::vector<float> width;
	std::vector<float> subarea;
	bool invalid = true;
	float userFloat=0.00f;
	const float PaintCover = 400.00f;
	float paintCans;
	float totalArea=0.0f;

	std::cout << "Now, how many walls do you want to paint?" << std::endl;
	while (invalid) {
		std::cin >> UserInput;
		invalid = checkValidInteger(UserInput);
		if (invalid)
			std::cout << "Please enter an integer" << std::endl;
	}

	wall_count = int(std::stoi(UserInput));

	for (int i = 1; i <= wall_count; i++) {
		
		std::cout << "What is the length of Wall " << i << std::endl;
		invalid = true;//reset true bollean
		while (invalid) {
			
			std::cin>>UserInput;
			invalid = checkValidFloat(UserInput);
			if (invalid) {
				std::cout << "Try again" << std::endl;
			}

		}
			userFloat = std::stof(UserInput);
			length.push_back(userFloat);

		std::cout << "What is the width of Wall " << i << std::endl;
		invalid = true; // return true bollean
		while (invalid) {

			std::cin >> UserInput;
			invalid = checkValidFloat(UserInput);
			if (invalid) {
				std::cout << "Try again" << std::endl;
			}

		}
		userFloat = std::stof(UserInput);
		width.push_back(userFloat);

	}
	for (int i = 0; i < wall_count; i++) {

		subarea.push_back(length.at(i) * width.at(i));
	}

	for (int i = 0; i < wall_count; i++) {
		totalArea += subarea.at(i);
	}

	paintCans = totalArea / PaintCover;
	std::cout << "As each can cover 400 square feet" << std::endl;
	std::cout << "With area = " << totalArea<< " square feet, you will need to get " << paintCans << " cans of paint." << std::endl;
	paintCans = ceil(paintCans);
	std::cout << "So in total we need " << paintCans << " cans of paint." << std::endl;

	return paintCans;
	 

}

bool checkValidInteger(const std::string UserInput) {

	bool invalid;
	int sizeOfInput;
	std::vector<char> Input;

	invalid = false;
	
	sizeOfInput = int(UserInput.size());
	for (int i = 0; i < sizeOfInput; i++) {
		Input.push_back(UserInput[i]);
	}
	for (int i = 0; i < sizeOfInput; i++) {
		if (!(isdigit(Input.at(i)))) {
			invalid = true;
			break;
		}
	}
	return invalid;
}

bool checkValidFloat(const std::string UserInput) {
	bool invalid;
	int sizeOfInput;
	std::vector<char> Input;
	int count=0;
	invalid = false;

	sizeOfInput = int(UserInput.size());
	for (int i = 0; i < sizeOfInput; i++) {
		Input.push_back(UserInput[i]);
	}
	for (int i = 0; i < sizeOfInput; i++) {
		if (!(isdigit(Input.at(i)))) {
			if (Input.at(i) == '.') {
				if (count < 1) {
					count++;
					continue;
				}
				
			}
			invalid = true;
			break;
		}
	}
	return invalid;
	

}

void printMenu() {

	
	std::cout << "Welcome to Paint Shop!" << std::endl;
	std::cout << "We have couple of options that you can choose from:" << std::endl;
	std::cout << "1 - Paint the interior of a house" << std::endl;
	std::cout << "2 - Paint the exterior of a house" << std::endl;
	std::cout << "3 - Paint both interior and exterior of a house" << std::endl;
	std::cout << "What option fits you more?" << std::endl;



}

int interiorCost(int cans) {
	
	const int paintCost = 100;
	int totalInteriorCost;
	std::cout << "Now lets calculate the cost to paint the interior of the house" << std::endl;
	std::cout << "The price of the can is $" << paintCost << ".00" << std::endl;
	totalInteriorCost = cans * paintCost;
	std::cout << "Total Interior is $" << totalInteriorCost << ".00" << std::endl;
	return totalInteriorCost;


}

int exteriorCost(int cans) {
	const int paintCost = 100;
	int totalExteriorCost;
	std::cout << "Now lets calculate the cost to paint the exterior of the house" << std::endl;
	std::cout << "The price of the can is $" << paintCost << ".00" << std::endl;
	totalExteriorCost = cans * paintCost;
	std::cout << "Total exterior is $" << totalExteriorCost << ".00" << std::endl;
	return totalExteriorCost;
}