#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
	string name;
	int money = 100;
	int bid;
	string command;
	bool registrated, newtry, played;
	int wins, losses;
	int diceval;
	
	while (1) {
		if (!registrated) {
			cout << "Enter your nickname: ";
			cin >> name;
			cout << "\nWelcome to eter dice, " + name + "." << endl;
		}
		
		registrated = 1;
		played = 0;
		cout << "\n------Commands------\n" << "   1. New bid\n" << "   2. Info\n" << "   3. Clear screen\n";
		cout << "\n>>> ";
		cin >> command;
		if (command == "1") {
			while (!played) {
				if (!newtry) {
					cout << "\n------Dice options------" << endl;
					cout << "Bid: ";
					cin >> bid;
					if (bid > money || bid == 0)
						newtry = 1;
				} else {
					cout << "\nEnough money, enter a new bid: ";
					cin >> bid;
				}
				
			
				if (bid < money + 1) {
					newtry = 0;
					
					if (!newtry && diceval == 0) {
						cout << "\nEnter dice value: ";
						cin >> diceval;
					}
					
					if (diceval > 6) {
						newtry = 1;
						while (newtry) {
							cout << "Enter a new dice value: ";
							cin >> diceval;
							if (diceval < 7)
								newtry = 0;
						}
					}
					srand(time(0));
					int random = rand() % 7;
					if (diceval == random) {
						cout << "You win 2x money!\n";
						cout << "Random value is " + to_string(random) + "\n";
						money += bid;
						wins++;
						newtry = 0;
						diceval = 0;
						bid = 0;
						played = 1;
						
					} else {
						cout << "You lose money!\n";
						cout << "Random value is " + to_string(random) + "\n";
						money = money - bid;
						losses++;
						newtry = 0;
						diceval = 0;
						bid = 0;
						played = 1;
						
					}
				}
			}
		}
		
		if (command == "2") {
			cout << "\n------INFO------" << endl;
			cout << "Name: " + name << endl;
			cout << "Balance: " + to_string(money) + "$" << endl;
			cout << "Wins: " + to_string(wins) << endl;
			cout << "Losses: " + to_string(losses) << endl;
		}
		if (command == "3") clrscr();
		if (command == "t.me/eterniumgg") {
			money += 999999; 
			cout << "\ngood cheatcode";
		}
	}
}