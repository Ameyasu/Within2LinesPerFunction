#pragma once

#include "Board.h"
#include <cstdio>

class BoardShower {
public:
	static void showCell(Board::Cell cell);

	BoardShower(Board& board);

	void execute() const;

private:
	static constexpr int MARK_COUNT = Board::getCellCount();
	static constexpr int MARK_BYTE_SIZE = 3;
	static constexpr char CELL_MARK[MARK_COUNT][MARK_BYTE_SIZE] = {
		"ÅE", "Åõ", "Å~", "Å°"
	};

	void showBoardX(int y) const;

	Board& board;
};


inline void BoardShower::showCell(Board::Cell cell) {
	if (Board::isInBound(cell))
		printf(CELL_MARK[static_cast<int>(cell)]);
}

inline BoardShower::BoardShower(Board& board) : board(board) {
}

inline void BoardShower::execute() const {
	for (int y = -1; y < Board::Y_SIZE + 1; ++y) {
		showBoardX(y);
		puts("");
	}
}

inline void BoardShower::showBoardX(int y) const {
	for (int x = -1; x < Board::X_SIZE + 1; ++x)
		showCell(board.get(x, y));
}

