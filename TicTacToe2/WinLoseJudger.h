#pragma once

#include "GameState.h"

class WinLoseJudger {
public:
	WinLoseJudger(GameState& state);

	void execute();

private:
	static constexpr int WIN_LINE = 3;

	bool win();
	bool findLine();
	bool findLineFrom(int x, int y);
	int countLine(int x, int y, int dx, int dy);
	bool isMyCell(int x, int y);
	void setWinner();

	void draw();

	GameState& state;
};


inline WinLoseJudger::WinLoseJudger(GameState& state) : state(state) {
}

inline void WinLoseJudger::execute() {
	if (win())
		return;
	draw();
}

inline bool WinLoseJudger::win() {
	bool win = findLine();
	if (win)
		setWinner();
	return win;
}

inline bool WinLoseJudger::findLine() {
	for (int y = 0; y < Board::Y_SIZE; ++y)
		for (int x = 0; x < Board::X_SIZE; ++x)
			if (findLineFrom(x, y))
				return true;
	return false;
}

inline bool WinLoseJudger::findLineFrom(int x, int y) {
	for (int dy = -1; dy <= 1; ++dy)
		for (int dx = -1; dx <= 1; ++dx)
			if (dx != 0 || dy != 0)
				if (countLine(x, y, dx, dy) >= WIN_LINE)
					return true;
	return false;
}

inline int WinLoseJudger::countLine(int x, int y, int dx, int dy) {
	int count = 0;
	for (; state.board.isInBoard(x, y); x += dx, y += dy)
		if (isMyCell(x, y))
			++count;
	return count;
}

inline bool WinLoseJudger::isMyCell(int x, int y) {
	return state.board.get(x, y) == state.turn.getAsCell();
}

inline void WinLoseJudger::setWinner() {
	state.result = (state.turn.get() == Turn::Element::CROSS) ? Result::NOUGHT : Result::CROSS;
}

inline void WinLoseJudger::draw() {
	for (int y = 0; y < Board::Y_SIZE; ++y)
		for (int x = 0; x < Board::X_SIZE; ++x)
			if (state.board.empty(x, y))
				return;
	state.result = Result::DRAW;
}
