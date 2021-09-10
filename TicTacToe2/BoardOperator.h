#pragma once

#include "Board.h"
#include "BoardShower.h"

class BoardOperator {
public:
	BoardOperator(Board& board);

	void initialize();
	void show() const;
	bool put(int x, int y, Board::Cell cell);

private:
	Board& board;
	BoardShower shower;
};

inline BoardOperator::BoardOperator(Board& board) : board(board), shower(board) {
}

inline void BoardOperator::initialize() {
	for (int y = 0; y < Board::Y_SIZE; ++y)
		for (int x = 0; x < Board::X_SIZE; ++x)
			board.set(x, y, Board::Cell::EMPTY);
}

inline void BoardOperator::show() const {
	shower.execute();
}

inline bool BoardOperator::put(int x, int y, Board::Cell cell) {
	if (board.exist(x, y))
		return false;
	board.set(x, y, cell);
	return true;
}

