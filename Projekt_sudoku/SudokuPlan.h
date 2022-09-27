#ifndef CVICENIE5_SUDOKUPLAN_H
#define CVICENIE5_SUDOKUPLAN_H

enum class SudokuDifficulty {
    Easy,
    Medium,
    Hard
};

enum class SudokuType {
    Sudoku6x6Horizontal,
    Sudoku6x6Vertical,
    Sudoku9x9
};

class SudokuPlan {
private:
    int** sudoku;
    SudokuType sudokuType;
    SudokuDifficulty sudokuDifficulty;
public:
    SudokuPlan();
    SudokuPlan(SudokuType type);
    //~SudokuPlan();

    int GetBoxIndex(int lineIndex, int columnIndex);
    int GetBoxLineIndex(int index);
    int GetBoxColumnIndex(int index);
    bool ContainsAnyDuplicates(int *index, int size);
    bool IsColumnValid(int &index);
    bool IsLineValid(int &index);
    bool IsBoxValid(int &index);

    int TotalLinesInBox();
    int TotalColumnsInBox();
    int TotalBoxesInLine();
    int TotalBoxesInColumn();

    int TotalBoxes();
    int TotalLines();
    int TotalColumns();

    int GetNextNumberFromCirle(int min, int current, int max);

    void SwitchLines(int line1Index, int line2Index);
    void SwitchLinesInBox(int boxIndex, int line1Index, int line2Index);
    void SwitchColumns(int column1Index, int column2Index);
    void SwitchColumnsInBox(int boxIndex, int column1Index, int column2Index);
    void SwitchBoxes(int box1Index, int box2Index);

    void SetDifficulty(SudokuDifficulty difficulty);
    void DropNumbers(int count);
    void ShakeExistingSudoku(int seed);
    void CreateNew(int seed);

    SudokuType Type();

    int GetValueOf(int lineIndex, int columnIndex);
    void SetValueTo(int value, int lineIndex, int columnIndex);

    bool IsValid();
};
#endif //CVICENIE5_SUDOKUPLAN_H
