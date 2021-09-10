#pragma once

#include "Board.h"
#include "Turn.h"
#include "Result.h"

struct GameState {
	Board board;
	Turn turn;
	Result result;
};
