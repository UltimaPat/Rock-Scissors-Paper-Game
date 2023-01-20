#pragma once
#include <iostream>

#ifndef comp
#define comp
#endif comp

using namespace std;

class compAI {
private:
	//compAI();
	int aiScore = 0;
	string aiName = "Computer";
	//~compAI();

public:
	void setcompAIScore(int s) {
		aiScore = s;
	}

	int getcompAIScore() {
		return aiScore;
	}

	void setcompAIName(string n) {
		aiName = n;
	}

	string getcompAIName() {
		return aiName;
	}

	void addAIScore() {
		aiScore++;
	}
};