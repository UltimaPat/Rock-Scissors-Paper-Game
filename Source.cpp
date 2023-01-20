//Rock Scissors Paper Game by Patrick Chu December 2022
#include <iostream>
#include <string>

#include "player.h"
#include "comp.h"

using namespace std;

//One round of Rock Scissor Paper
void playRSP(Player &A, compAI &B, int ai, int p, int r, int s, int pa, int t) {
	/*	ai = computer choice
	*	p = player choice
	*	r = rock
	*	s = scissor
	*	pa = paper
	*	t = total score
	*/

	//Player wins, updating player score
	//rock beats scissors
	if (p == r && ai == s) {
		cout << A.getPlayerName() <<" wins this round!" << endl;
		A.addPlayerScore();
	}
	//scissors beat paper
	else if (p == s && ai == pa) {
		cout << A.getPlayerName() << " wins this round!" << endl;
		A.addPlayerScore();
	}
	//paper beats rock
	else if (p == pa && ai == r) {
		cout << A.getPlayerName() << " wins this round!" << endl;
		A.addPlayerScore();
	}
	else {
		cout << " " << endl;
	}

	//AI wins, updating computer score
	//rock beats scissor
	if (ai == r && p == s) {
		cout << "The Computer wins this round!" << endl;
		B.addAIScore();
	}
	//scissors beat paper
	else if (ai == s && p == pa) {
		cout << "The Computer wins this round!" << endl;
		B.addAIScore();
	}
	//paper beats rock
	else if (ai == pa && p == r) {
		cout << "The Computer wins this round!" << endl;
		B.addAIScore();
	}
	else {
		cout << " " << endl;
	}

	//tie
	//both players pick rock
	if (ai == r && p == r) {
		cout << "Both player's hands result in a tie!" << endl;
	}
	//both players pick scissor
	else if (ai == s && p == s) {
		cout << "Both player's hands result in a tie!" << endl;
	}
	//both players pick paper
	else if (ai == pa && p == pa) {
		cout << "Both player's hands result in a tie!" << endl;
	}
	//throws invalid message
	else {
		cout << " " << endl;
	}

	//Check if either players' score match up to the required amount
	if (A.getPlayerScore() == t) {
		cout << "The winner is " << A.getPlayerName() << '!' << endl;
		return;
	}
	else if (B.getcompAIScore() == t) {
		cout << "The winner is the computer!" << endl;
		return;
	}
}
	
int main() {
//these values are the hands both players play with
	int rock = 1;
	int scissor = 2;
	int paper = 3;
	// Starting Values
	int playerChoice = 0;
	int aiChoice = 0;
	string playerName1;
	Player A;
	compAI B;

//Score needed to win
	int totalScore;
	
	cout << "Enter your name: " << endl;
	cin >> playerName1;
	A.setPlayerName(playerName1);

	//Player inputs required amount of wins needed
	cout << "Enter the total score needed to win." << endl;
	cin >> totalScore;
	//Instructions for the player
	cout << "The hand choices correspond to each number." << endl;
	cout << "The rock corresponds to the number 1." << endl;
	cout << "The scissor corresponds to the number 2." << endl;
	cout << "The paper corresponds to the number 3." << endl;
	cout << "Any other number and you will have to choose again." << endl;

	//Gameplay Loop
	while (A.getPlayerScore() != totalScore || B.getcompAIScore() != totalScore) {
		//Player is choosing
		if (A.getPlayerScore() == totalScore || B.getcompAIScore() == totalScore) {
			break;
		}
		cout << "Choose which hand you are going to play?" << endl;
		cin >> playerChoice;
		if (playerChoice > 3 || playerChoice < 1) {
			cout << "Invalid choice, try again." << '\n';
			playerChoice = 0;
		}
		//Computer is choosing from 1 to 3
		//initializing random seed generator
		srand(time(NULL));
		aiChoice = rand() % 4 + 1;

		//Actual Gameplay
		playRSP(A, B, aiChoice, playerChoice, rock, scissor, paper, totalScore);

		//reset choices
		playerChoice = 0;
		aiChoice = 0;
	}
	

	return 0;
}