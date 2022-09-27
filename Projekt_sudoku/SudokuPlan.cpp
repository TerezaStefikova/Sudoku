#include "SudokuPlan.h"

using namespace std;

/*  POPIS:  */
/* SudokuPlan je trieda, ktora vytvara sudoku a kontroluje ho.*/

//1. cast Kontrola sudoku
SudokuPlan::SudokuPlan() : sudokuType(SudokuType::Sudoku9x9) {
    this->sudoku = new int *[SudokuPlan::TotalLines()];
    for (int i = 0; i < TotalLines(); ++i) {
        this->sudoku[i] = new int[TotalColumns()];
    }
    SudokuPlan::CreateNew(0);
}

SudokuPlan::SudokuPlan(SudokuType type) : sudokuType(type) {
    this->sudoku = new int *[TotalLines()];
    for (int i = 0; i < TotalLines(); ++i) {
        this->sudoku[i] = new int[TotalColumns()];
    }
    SudokuPlan::CreateNew(0);
}

SudokuType SudokuPlan::Type() {
    return this->sudokuType;
}

void SudokuPlan::SetValueTo(int value, int lineIndex, int columnIndex) {
    sudoku[lineIndex][columnIndex] = value;
}

int SudokuPlan::GetValueOf(int lineIndex, int columnIndex) {
    return sudoku[lineIndex][columnIndex];
}

int SudokuPlan::GetBoxIndex(int lineIndex, int columnIndex) {
    int boxLineIndex = lineIndex / TotalLinesInBox();
    int orderOfBox = columnIndex / TotalColumnsInBox();
    return boxLineIndex * TotalBoxesInLine() + orderOfBox;
}

int SudokuPlan::GetBoxLineIndex(int index) {
    return (index / TotalBoxesInLine()) * TotalLinesInBox();
}

int SudokuPlan::GetBoxColumnIndex(int index) {
    return (index % TotalBoxesInLine()) * TotalColumnsInBox();
}

int SudokuPlan::TotalBoxesInColumn() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 3;
        }
        case SudokuType::Sudoku6x6Vertical: {
            return 3;
        }
        case SudokuType::Sudoku6x6Horizontal: {
            return 2;
        }
        default: {
            return -1;
        }
    }
}

int SudokuPlan::TotalBoxesInLine() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 3;
        }
        case SudokuType::Sudoku6x6Vertical: {
            return 2;
        }
        case SudokuType::Sudoku6x6Horizontal: {
            return 3;
        }
        default: {
            return -1;
        }
    }
}

int SudokuPlan::TotalColumnsInBox() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 3;
        }
        case SudokuType::Sudoku6x6Vertical: {
            return 3;
        }
        case SudokuType::Sudoku6x6Horizontal: {
            return 2;
        }
        default: {
            return -1;
        }
    }
}

int SudokuPlan::TotalLinesInBox() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 3;
        }
        case SudokuType::Sudoku6x6Vertical: {
            return 2;
        }
        case SudokuType::Sudoku6x6Horizontal: {
            return 3;
        }
        default: {
            return -1;
        }
    }
}

int SudokuPlan::TotalLines() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 9;
        }
        case SudokuType::Sudoku6x6Vertical:
        case SudokuType::Sudoku6x6Horizontal: {
            return 6;
        }
        default: {
            return -1;
        }
    }
}

int SudokuPlan::TotalColumns() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 9;
        }
        case SudokuType::Sudoku6x6Horizontal:
        case SudokuType::Sudoku6x6Vertical: {
            return 6;
        }
        default: {
            return -1;
        }
    }
}

int SudokuPlan::TotalBoxes() {
    switch (Type()) {
        case SudokuType::Sudoku9x9: {
            return 9;
        }
        case SudokuType::Sudoku6x6Vertical:
        case SudokuType::Sudoku6x6Horizontal: {
            return 6;
        }
        default: {
            return -1;
        }
    }
}

bool SudokuPlan::ContainsAnyDuplicates(int *index, int size) {
    bool result = false;
    for (int number = 1; number <= size; ++number) {
        for (int i = 0; i < size; ++i) {
            if (result) {
                if (index[i] == number) {
                    return result;
                }
            } else {
                result = index[i] == number;
            }
        }
        result = false;
    }

    return result;
}

bool SudokuPlan::IsColumnValid(int &index) {
    int size = TotalLines();
    int numberStore[size];

    for (int i = 0; i < size; ++i) {
        numberStore[i] = GetValueOf(i, index);
    }

    return !ContainsAnyDuplicates(numberStore, size);
}

bool SudokuPlan::IsLineValid(int &index) {
    int size = TotalColumns();
    int numberStore[size];

    for (int i = 0; i < size; ++i) {
        numberStore[i] = GetValueOf(index, i);
    }

    return !ContainsAnyDuplicates(numberStore, size);
}

bool SudokuPlan::IsBoxValid(int &index) {
    int size = TotalLinesInBox() * TotalColumnsInBox();
    int numberStore[size];
    int numberStoreIndex = 0;

    int minLineBoxIndex = GetBoxLineIndex(index);
    int maxLineBoxIndex = minLineBoxIndex + TotalLinesInBox();
    int minColumnBoxIndex = GetBoxColumnIndex(index);
    int maxColumnBoxIndex = minColumnBoxIndex + TotalColumnsInBox();

    for (int i = minLineBoxIndex; i < maxLineBoxIndex; ++i) {
        for (int j = minColumnBoxIndex; j < maxColumnBoxIndex; ++j) {
            numberStore[numberStoreIndex] = GetValueOf(i, j);
            numberStoreIndex++;
        }
    }

    return !ContainsAnyDuplicates(numberStore, size);
}

bool SudokuPlan::IsValid() {
    bool result = true;

    for (int column = 0; column < TotalColumns(); ++column) {
        result &= IsColumnValid(column);
    }
    for (int line = 0; line < TotalLines(); ++line) {
        result &= IsLineValid(line);
    }
    for (int box = 0; box < TotalBoxes(); ++box) {
        result &= IsBoxValid(box);
    }

    return result;
}

//2. cast Generovanie noveho sudoku
void SudokuPlan::SwitchColumns(int column1Index, int column2Index) {
    if(column1Index == column2Index){
        return;
    }

    int size = TotalLines();
    int tempMemory, newValue;

    for (int i = 0; i < size; ++i) {
        tempMemory = GetValueOf(i, column1Index);
        newValue = GetValueOf(i, column2Index);
        SetValueTo(newValue, i, column1Index);
        SetValueTo(tempMemory, i, column2Index);
    }
}

void SudokuPlan::SwitchColumnsInBox(int boxIndex, int column1Index, int column2Index) {
    if(column1Index == column2Index){
        return;
    }

    int boxMinColumn = GetBoxColumnIndex(boxIndex);
    int boxMaxColumn = boxMinColumn + TotalColumnsInBox();

    int newColumn1Index = boxMinColumn + column1Index;
    int newColumn2Index = boxMinColumn + column2Index;

    if ((boxMinColumn <= newColumn1Index && newColumn1Index < boxMaxColumn)
        && (boxMinColumn <= newColumn2Index && newColumn2Index < boxMaxColumn)) {

        SwitchColumns(newColumn1Index, newColumn2Index);
    }
}

void SudokuPlan::SwitchLines(int line1Index, int line2Index) {
    if(line1Index == line2Index){
        return;
    }

    int size = TotalColumns();
    int tempMemory, newValue;

    for (int i = 0; i < size; ++i) {
        tempMemory = GetValueOf(line1Index, i);
        newValue = GetValueOf(line2Index, i);
        SetValueTo(newValue, line1Index, i);
        SetValueTo(tempMemory, line2Index, i);
    }
}

void SudokuPlan::SwitchLinesInBox(int boxIndex, int line1Index, int line2Index) {
    if(line1Index == line2Index){
        return;
    }

    int boxMinLine = GetBoxLineIndex(boxIndex);
    int boxMaxLine = boxMinLine + TotalLinesInBox();

    int newLine1Index = boxMinLine + line1Index;
    int newLine2Index = boxMinLine + line2Index;

    if ((boxMinLine <= newLine1Index && newLine1Index < boxMaxLine)
        && (boxMinLine <= newLine2Index && newLine2Index < boxMaxLine)) {

        SwitchLines(newLine1Index, newLine2Index);
    }
}

void SudokuPlan::SwitchBoxes(int box1Index, int box2Index) {
    if(box1Index == box2Index){
        return;
    }

    int box1MinLine = GetBoxLineIndex(box1Index);
    int box1MaxLine = box1MinLine + TotalLinesInBox();
    int box1MinColumn = GetBoxColumnIndex(box1Index);
    int box1MaxColumn = box1MinColumn + TotalColumnsInBox();

    int box2MinLine = GetBoxLineIndex(box2Index);
    int box2MinColumn = GetBoxColumnIndex(box2Index);

    for (int i = box1MinLine, j = box2MinLine; i < box1MaxLine; ++i, ++j) {
        SwitchLines(i, j);
    }
    for (int i = box1MinColumn, j = box2MinColumn; i < box1MaxColumn; ++i, ++j) {
        SwitchColumns(i, j);
    }
}

void SudokuPlan::CreateNew(int seed) {
    if (seed == 0) {
        int min = 1;
        int max = TotalLines();
        int sizeOfBox = TotalBoxesInLine();

        int initialValue = 0;
        int newValue = 0;
        for (int i = 0; i < max; ++i) {
            if ((i % sizeOfBox) == 0) {
                newValue = ++initialValue;
            } else {
                newValue += TotalBoxesInColumn();
            }

            for (int j = 0; j < max; ++j) {
                SetValueTo(newValue, i, j);
                newValue = GetNextNumberFromCirle(min, newValue, max);
            }
        }
    } else {
        CreateNew(0);
        ShakeExistingSudoku(seed);
        IsValid();
        SetDifficulty(sudokuDifficulty);
    }
}

//3. cast Priprava na hru
void SudokuPlan::SetDifficulty(SudokuDifficulty difficulty) {
    int count = TotalLines() *  TotalColumns();
    float coefficient = 0;
    switch (difficulty){
        case SudokuDifficulty::Easy:{
            coefficient = 0.25;
            break;
        }
        case SudokuDifficulty::Medium:{
            coefficient = 0.35;
            break;
        }
        case SudokuDifficulty::Hard:{
            coefficient = 0.45;
            break;
        }
        default:{
            coefficient = 0;
            break;
        }
    }
    int numberOfDropped = count * coefficient;
    DropNumbers(numberOfDropped);
}

void SudokuPlan::DropNumbers(int count) {
    int counter = 0;
    for (int lineIndex = 0; lineIndex < TotalLines(); ++lineIndex) {
        for (int columnIndex = 0; columnIndex < TotalColumns(); ++columnIndex) {
            if(counter % 2 == 0){
                if(columnIndex != 0 && columnIndex % 2 ==0 ){
                    SetValueTo(-1, columnIndex, lineIndex);
                    counter++;
                }
            }
            else if(counter % 2 != 0){
                if(lineIndex != 0 && columnIndex != 0 && columnIndex % 2 != 0){
                    SetValueTo(-1, lineIndex, columnIndex);
                    counter++;
                }
            }
            if(counter == count){
                return;
            }
        }
    }
}
// 2. cast Generovanie noveho sudoku
void SudokuPlan::ShakeExistingSudoku(int seed) {
    int min = 0;
    int boxIndex = min;

    int max = TotalBoxes() - 1;
    for (int i = 0; i < seed; ++i) {
        SwitchLinesInBox(0,0,1);

        SwitchBoxes(boxIndex, GetNextNumberFromCirle(min, boxIndex, max));
        boxIndex = GetNextNumberFromCirle(min, boxIndex, max);

        SwitchColumnsInBox(0, 0,1);
    }
}

int SudokuPlan::GetNextNumberFromCirle(int min, int current, int max) {
    if (min <= current && current < max) {
        return ++current;
    }
    return min;
}
