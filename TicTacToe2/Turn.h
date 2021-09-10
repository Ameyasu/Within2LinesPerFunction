#pragma once

#include "BoardShower.h"
#include <cstdio>

class Turn {
public:
	enum class Element {
		NOUGHT,
		CROSS
	};

	static Board::Cell convertToCell(Element element);

	Turn();

	Element get() const;
	Board::Cell getAsCell() const;
	void set(Element element);
	void rotate();
	void show() const;

private:
	Element element;
};


inline Board::Cell Turn::convertToCell(Element element) {
	return (element == Element::NOUGHT) ? Board::Cell::NOUGHT : Board::Cell::CROSS;
}

inline Turn::Turn() : element() {
}

inline Turn::Element Turn::get() const {
	return element;
}

inline Board::Cell Turn::getAsCell() const {
	return convertToCell(element);
}

inline void Turn::set(Element element) {
	this->element = element;
}

inline void Turn::rotate() {
	element = (element == Element::NOUGHT) ? Element::CROSS : Element::NOUGHT;
}

inline void Turn::show() const {
	BoardShower::showCell(getAsCell());
	puts("'s turn");
}
