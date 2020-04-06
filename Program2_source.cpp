//Morgan Rogers
//CS 201R Program 2
#include <iostream>
#include <cmath>

using namespace std;

int calcWallArea(int l, int h);
int numPaintCans(int totArea);
int calcPriceInterior(int numcan);
int calcPriceExterior(int numcan);
int calcPriceIntExt(int numcanInt, int numcanExt);

int main() {
	int userInput;
	int wallsToPaint;
	int lengthWall;
	int heightWall;
	int areaSum = 0;
	int totareaSum = 0;
	int wallArea;
	int numCans;
	int numCans2;
	int totCans;
	int priceofCans;
	int totalPrice;

	cout << "Welcome to Morgan's Paint Shop" << endl;
	cout << "We have a couple options that you can choose from:" << endl;
	
	cout << "1- Paint the interior of a house" << endl;
	cout << "2- Paint the exterior of a house" << endl;		
	cout << "3- Paint both the interior and exterior of a house" << endl;
	cout << "What option fits you best? " << endl;
	cin >> userInput;
	while (true) {
		if (userInput == 1) {
			cout << "How many walls do you want to paint?" << endl;
			cin >> wallsToPaint;
			for (int i = 1; i <= wallsToPaint; ++i) {
				cout << "What is the length and height of wall " << i << "?" << endl;
				cout << "Length?" << endl;
				cin >> lengthWall;
				cout << "Height?" << endl;
				cin >> heightWall;
				wallArea = calcWallArea(lengthWall, heightWall);
				areaSum += wallArea;
			}
			numCans = numPaintCans(areaSum);
			totCans = numCans;
			totareaSum = areaSum;
			totalPrice = calcPriceInterior(numCans);
			break;
		
		}
		else if (userInput == 2) {
			cout << "How many walls do you want to paint?" << endl;
			cin >> wallsToPaint;
			for (int i = 1; i <= wallsToPaint; ++i) {
				cout << "What is the length and height of wall " << i << "?" << endl;
				cout << "Length?" << endl;
				cin >> lengthWall;
				cout << "Height?" << endl;
				cin >> heightWall;
				wallArea = calcWallArea(lengthWall, heightWall);
				areaSum += wallArea;
			}
			numCans = numPaintCans(areaSum);
			totCans = numCans;
			totareaSum = areaSum;
			totalPrice = calcPriceExterior(numCans);
			break;
		}
		else if (userInput == 3) {
			cout << "How many walls do you want to paint the exterior?" << endl;
			cin >> wallsToPaint;
			for (int i = 1; i <= wallsToPaint; ++i) {
				cout << "What is the length and height of wall " << i << "?" << endl;
				cout << "Length?" << endl;
				cin >> lengthWall;
				cout << "Height?" << endl;
				cin >> heightWall;
				wallArea = calcWallArea(lengthWall, heightWall);
				areaSum += wallArea;
			}
			totareaSum += areaSum;
			numCans = numPaintCans(areaSum);
			areaSum = 0;
			cout << "How many walls do you want to paint the interior?" << endl;
			cin >> wallsToPaint;
			for (int i = 1; i <= wallsToPaint; ++i) {
				cout << "What is the length and height of wall " << i << "?" << endl;
				cout << "Length?" << endl;
				cin >> lengthWall;
				cout << "Height?" << endl;
				cin >> heightWall;
				wallArea = calcWallArea(lengthWall, heightWall);
				areaSum += wallArea;
			}
			totareaSum += areaSum;
			numCans2 = numPaintCans(areaSum);
			totCans = numCans + numCans2;
			totalPrice = calcPriceIntExt(numCans2, numCans);
			break;
		}
		else {
			cout << "Please input a valid number" << endl;
			cin >> userInput;
			continue;
		}

	}
	cout << "As each can covers 400 feet" << endl;
	cout << "With area = " << totareaSum << " feet, you will need to get "<< totareaSum / 400.0 << " cans" << endl;
	cout << "So in total we need " << totCans << " cans" << endl;
	cout << "Lets calculate the cost to paint the house: " << endl;
	cout << "The total cost is $" << totalPrice << endl;
	return 0;
}
int calcPriceInterior(int numcan) {
	return numcan * 100;
}
int calcPriceExterior(int numcan) {
	return numcan * 150;
}
int calcPriceIntExt(int numcanInt, int numcanExt) {
	return (numcanInt * 100) + (numcanExt * 150);
}

int calcWallArea(int l, int h) {
	return l * h;
}

int numPaintCans(int totArea) {
	return ceil(totArea / 400.0);
}