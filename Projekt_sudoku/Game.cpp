#include <iostream>
#include "Game.h"

using namespace std;

/*  POPIS:  */
/* Game je trieda, ktora zobrazuje hru a dovoluje interagovat s hracim planom
 * Vstupny argument je SudokuPlan, s ktorym chceme manipulovat.*/

// 4. cast
Game::Game(SudokuType type) {
    this->sudokuPlan = SudokuPlan(type);
    Game::SetDifficulty(SudokuDifficulty::Easy);
}

void Game::SetDifficulty(SudokuDifficulty difficulty){
    sudokuPlan.SetDifficulty(difficulty);
}

int Game::FillNumber(int newNumber, int lineIndex, int columnIndex) {
    int previousValue = sudokuPlan.GetValueOf(lineIndex, columnIndex);

    sudokuPlan.SetValueTo(newNumber, lineIndex, columnIndex);
    int boxIndex = sudokuPlan.GetBoxIndex(lineIndex, columnIndex);

    if (sudokuPlan.IsColumnValid(columnIndex)
        && sudokuPlan.IsLineValid(lineIndex)
        && sudokuPlan.IsBoxValid(boxIndex)) {

        return sudokuPlan.GetValueOf(lineIndex, columnIndex);
    } else {

        sudokuPlan.SetValueTo(previousValue, lineIndex, columnIndex);
        return sudokuPlan.GetValueOf(lineIndex, columnIndex);
    }
}

void Game::NextGame(int seed) {
    sudokuPlan.CreateNew(seed);
}

void Game::Show() {
    for (int line = 0; line < sudokuPlan.TotalLines(); line++) {
        if (line > 0 && line % sudokuPlan.TotalLinesInBox() == 0) {
            for (int column = 0; column < sudokuPlan.TotalColumns() + sudokuPlan.TotalBoxesInLine() - 1; column++) {
                cout << "-" << "  ";
            }
            cout << endl;
        }
        for (int column = 0; column < sudokuPlan.TotalColumns(); column++) {
            if (column > 0 && column % sudokuPlan.TotalBoxesInColumn() == 0) {
                cout << "|" << "  ";
            }
            int value = sudokuPlan.GetValueOf(line, column);
            if (value > 0) {
                cout << value << "  ";
            } else {
                cout << "X" << "  ";
            }
        }

        cout << endl;
    }
}