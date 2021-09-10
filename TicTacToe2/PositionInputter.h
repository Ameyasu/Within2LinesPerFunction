#pragma once

#include "Board.h"
#include <cstdio>

class PositionInputter {
public:
	PositionInputter();

	void execute();
	int getX();
	int getY();

private:
	void inputInBound();
	void inputRaw();
	bool isOutBound();
	void adjust();

	int x;
	int y;
};


inline PositionInputter::PositionInputter() : x(), y() {
}

inline void PositionInputter::execute() {
	inputInBound();
	adjust();
}

inline int PositionInputter::getX() {
	return x;
}

inline int PositionInputter::getY() {
	return y;
}

inline void PositionInputter::inputInBound() {
	do inputRaw();
	while (isOutBound());
}

inline void PositionInputter::inputRaw() {
	printf("x[1-%d] y[1-%d] > ", Board::X_SIZE, Board::Y_SIZE);
	if (scanf_s("%d %d", &x, &y) != 2)
		scanf_s("%*[^\n]%*c");
}

inline bool PositionInputter::isOutBound() {
	bool out = x < 1 || Board::X_SIZE < x || y < 1 || Board::Y_SIZE < y;
	if (out)
		puts("invalid value");
	return out;
}

inline void PositionInputter::adjust() {
	--x;
	--y;
}

