#pragma once
#include <iostream>

#ifndef player
#define player
#endif player

using namespace std;

class Player {
private:
	//Player();
	int playerScore = 0;
	string playerName;
	//~Player();

public:

	void setPlayerScore(int s) {
		playerScore = s;
	}
	
	int getPlayerScore() {
		return playerScore;
	}
	
	void setPlayerName(string n) {
		playerName = n;
	}

	string getPlayerName() {
		return playerName;
	}

	void addPlayerScore() {
		playerScore++;
	}

};
