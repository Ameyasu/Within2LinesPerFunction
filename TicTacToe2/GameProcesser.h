#pragma once

#include "GameState.h"
#include "BoardOperator.h"
#include "WinLoseJudger.h"
#include "PositionInputter.h"
#include <cstdio>

class GameProcesser {
public:
	GameProcesser();

	void initialize();
	void update();
	bool isGaming() const;
	void end();

private:
	void show();
	void input();
	bool put();
	void judge();
	void showResult();

	GameState gameState;
	BoardOperator boardOperator;
	WinLoseJudger winLoseJudger;
	PositionInputter positionInputter;
};


inline GameProcesser::GameProcesser() : gameState(), boardOperator(gameState.board), winLoseJudger(gameState), positionInputter() {
	initialize();
}

inline void GameProcesser::initialize() {
	boardOperator.initialize();
	gameState.turn.set(Turn::Element::NOUGHT);
	gameState.result = Result::GAMING;
}

inline void GameProcesser::update() {
	show();
	input();
	judge();
}

inline bool GameProcesser::isGaming() const {
	return gameState.result == Result::GAMING;
}

inline void GameProcesser::end() {
	boardOperator.show();
	showResult();
}

inline void GameProcesser::show() {
	boardOperator.show();
	gameState.turn.show();
}

inline void GameProcesser::input() {
	do positionInputter.execute();
	while (!put());
}

inline bool GameProcesser::put() {
	bool success = boardOperator.put(positionInputter.getX(), positionInputter.getY(), gameState.turn.getAsCell());
	if (!success)
		puts("already exists");
	return success;
}

inline void GameProcesser::judge() {
	winLoseJudger.execute();
	gameState.turn.rotate();
}

inline void GameProcesser::showResult() {
	switch (gameState.result) {
	case Result::NOUGHT:
		BoardShower::showCell(Board::Cell::NOUGHT);
		break;
	case Result::CROSS:
		BoardShower::showCell(Board::Cell::CROSS);
		break;
	case Result::DRAW:
		puts("draw");
	default:
		return;
	}
	puts(" wins!");
}

