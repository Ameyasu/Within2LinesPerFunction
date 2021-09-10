#pragma once

struct Board {
public:
	enum class Cell {
		EMPTY,
		NOUGHT,
		CROSS,
		WALL
		// modify the followings together
		// * getCellCount
		// * ShowBoard::CELL_MARK
		// * Turn::convertToCell
	};

	static constexpr int X_SIZE = 3;
	static constexpr int Y_SIZE = 3;

	static bool isInBound(Cell cell);
	static constexpr int getCellCount();

	static bool isInBoard(int x, int y);

	Board();

	Cell get(int x, int y) const;
	void set(int x, int y, Cell cell);
	bool exist(int x, int y) const;
	bool empty(int x, int y) const;

private:
	Cell cells[Y_SIZE][X_SIZE];
};


inline bool Board::isInBound(Cell cell) {
	return Cell::EMPTY <= cell && cell < Cell(getCellCount());
}

inline constexpr int Board::getCellCount() {
	return static_cast<int>(Cell::WALL) + 1;
}

inline bool Board::isInBoard(int x, int y) {
	return 0 <= x && x < X_SIZE && 0 <= y && y < Y_SIZE;
}

inline Board::Board() : cells() {
}

inline Board::Cell Board::get(int x, int y) const {
	if (isInBoard(x, y))
		return cells[y][x];
	return Cell::WALL;
}

inline void Board::set(int x, int y, Cell cell) {
	if (isInBoard(x, y))
		cells[y][x] = cell;
}

inline bool Board::exist(int x, int y) const {
	return get(x, y) != Cell::EMPTY;
}

inline bool Board::empty(int x, int y) const {
	return get(x, y) == Cell::EMPTY;
}

