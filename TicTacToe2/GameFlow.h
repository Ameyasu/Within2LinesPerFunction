#pragma once

#include "GameProcesser.h"
#include <cstdlib>

class GameFlow {
public:
	GameFlow();

	void execute();

private:
	void preprocess();
	void processMain();
	void postproccess();

	GameProcesser processer;
};


inline GameFlow::GameFlow() : processer() {
}

inline void GameFlow::execute() {
	preprocess();
	processMain();
	postproccess();
}

inline void GameFlow::preprocess() {
	processer.initialize();
}

inline void GameFlow::processMain() {
	while (processer.isGaming()) {
		system("cls");
		processer.update();
	}
}

inline void GameFlow::postproccess() {
	system("cls");
	processer.end();
}
