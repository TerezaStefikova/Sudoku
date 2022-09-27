#ifndef CVICENIE5_GAME_H
#define CVICENIE5_GAME_H

#include "SudokuPlan.h"

class Game {
private:
    SudokuPlan sudokuPlan;
public:
    Game(SudokuType type);
    void Show();
    void NextGame(int seed);
    void SetDifficulty(SudokuDifficulty difficulty);
    int FillNumber(int newNumber, int lineIndex, int columnIndex);
};

#endif //CVICENIE5_GAME_H
