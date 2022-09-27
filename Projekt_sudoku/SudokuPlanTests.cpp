#include <iostream>
#include "gtest/gtest.h"
#include "Game.h"

using namespace ::testing;

// 1. cast Kontrola sudoku
TEST(SudokuPlan, Dimensions_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int expectedTotalColumns = 9;
    int expectedTotalLines = 9;
    int expectedTotalBoxesInColumn = 3;
    int expectedTotalBoxesInLine = 3;
    int expectedTotalBoxes = 9;
    int expectedTotalLinesInBox = 3;
    int expectedTotalColumnsInBox = 3;

    ASSERT_EQ(sudokuPlan.TotalColumns(), expectedTotalColumns);
    ASSERT_EQ(sudokuPlan.TotalLines(), expectedTotalLines);
    ASSERT_EQ(sudokuPlan.TotalBoxesInColumn(), expectedTotalBoxesInColumn);
    ASSERT_EQ(sudokuPlan.TotalBoxesInLine(), expectedTotalBoxesInLine);
    ASSERT_EQ(sudokuPlan.TotalBoxes(), expectedTotalBoxes);
    ASSERT_EQ(sudokuPlan.TotalLinesInBox(), expectedTotalLinesInBox);
    ASSERT_EQ(sudokuPlan.TotalColumnsInBox(), expectedTotalColumnsInBox);
}

TEST(SudokuPlan, Dimensions_Sudoku6x6Vertical) {
    SudokuType type = SudokuType::Sudoku6x6Vertical;
    SudokuPlan sudokuPlan(type);

    int expectedTotalColumns = 6;
    int expectedTotalLines = 6;
    int expectedTotalBoxesInColumn = 3;
    int expectedTotalBoxesInLine = 2;
    int expectedTotalBoxes = 6;
    int expectedTotalLinesInBox = 2;
    int expectedTotalColumnsInBox = 3;

    ASSERT_EQ(sudokuPlan.TotalColumns(), expectedTotalColumns);
    ASSERT_EQ(sudokuPlan.TotalLines(), expectedTotalLines);
    ASSERT_EQ(sudokuPlan.TotalBoxesInColumn(), expectedTotalBoxesInColumn);
    ASSERT_EQ(sudokuPlan.TotalBoxesInLine(), expectedTotalBoxesInLine);
    ASSERT_EQ(sudokuPlan.TotalBoxes(), expectedTotalBoxes);
    ASSERT_EQ(sudokuPlan.TotalLinesInBox(), expectedTotalLinesInBox);
    ASSERT_EQ(sudokuPlan.TotalColumnsInBox(), expectedTotalColumnsInBox);
}

TEST(SudokuPlan, Dimensions_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int expectedTotalColumns = 6;
    int expectedTotalLines = 6;
    int expectedTotalBoxesInColumn = 2;
    int expectedTotalBoxesInLine = 3;
    int expectedTotalBoxes = 6;
    int expectedTotalLinesInBox = 3;
    int expectedTotalColumnsInBox = 2;

    ASSERT_EQ(sudokuPlan.TotalColumns(), expectedTotalColumns);
    ASSERT_EQ(sudokuPlan.TotalLines(), expectedTotalLines);
    ASSERT_EQ(sudokuPlan.TotalBoxesInColumn(), expectedTotalBoxesInColumn);
    ASSERT_EQ(sudokuPlan.TotalBoxesInLine(), expectedTotalBoxesInLine);
    ASSERT_EQ(sudokuPlan.TotalBoxes(), expectedTotalBoxes);
    ASSERT_EQ(sudokuPlan.TotalLinesInBox(), expectedTotalLinesInBox);
    ASSERT_EQ(sudokuPlan.TotalColumnsInBox(), expectedTotalColumnsInBox);
}

TEST(SudokuPlan, GetBoxLineIndex_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int boxNumber_0 = 0;
    int boxNumber_1 = 1;
    int boxNumber_2 = 2;
    int boxNumber_3 = 3;
    int boxNumber_4 = 4;
    int boxNumber_5 = 5;
    int boxNumber_6 = 6;
    int boxNumber_7 = 7;
    int boxNumber_8 = 8;

    int expectedBoxLineIndex_0 = 0;
    int expectedBoxLineIndex_1 = 0;
    int expectedBoxLineIndex_2 = 0;
    int expectedBoxLineIndex_3 = 3;
    int expectedBoxLineIndex_4 = 3;
    int expectedBoxLineIndex_5 = 3;
    int expectedBoxLineIndex_6 = 6;
    int expectedBoxLineIndex_7 = 6;
    int expectedBoxLineIndex_8 = 6;

    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_0), expectedBoxLineIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_1), expectedBoxLineIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_2), expectedBoxLineIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_3), expectedBoxLineIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_4), expectedBoxLineIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_5), expectedBoxLineIndex_5);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_6), expectedBoxLineIndex_6);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_7), expectedBoxLineIndex_7);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_8), expectedBoxLineIndex_8);
}

TEST(SudokuPlan, GetBoxLineIndex_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int boxNumber_0 = 0;
    int boxNumber_1 = 1;
    int boxNumber_2 = 2;
    int boxNumber_3 = 3;
    int boxNumber_4 = 4;
    int boxNumber_5 = 5;

    int expectedBoxLineIndex_0 = 0;
    int expectedBoxLineIndex_1 = 0;
    int expectedBoxLineIndex_2 = 2;
    int expectedBoxLineIndex_3 = 2;
    int expectedBoxLineIndex_4 = 4;
    int expectedBoxLineIndex_5 = 4;

    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_0), expectedBoxLineIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_1), expectedBoxLineIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_2), expectedBoxLineIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_3), expectedBoxLineIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_4), expectedBoxLineIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_5), expectedBoxLineIndex_5);
}

TEST(SudokuPlan, GetBoxLineIndex_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int boxNumber_0 = 0;
    int boxNumber_1 = 1;
    int boxNumber_2 = 2;
    int boxNumber_3 = 3;
    int boxNumber_4 = 4;
    int boxNumber_5 = 5;

    int expectedBoxLineIndex_0 = 0;
    int expectedBoxLineIndex_1 = 0;
    int expectedBoxLineIndex_2 = 0;
    int expectedBoxLineIndex_3 = 3;
    int expectedBoxLineIndex_4 = 3;
    int expectedBoxLineIndex_5 = 3;

    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_0), expectedBoxLineIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_1), expectedBoxLineIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_2), expectedBoxLineIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_3), expectedBoxLineIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_4), expectedBoxLineIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxLineIndex(boxNumber_5), expectedBoxLineIndex_5);
}

TEST(SudokuPlan, GetBoxColumnIndex_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int boxNumber_0 = 0;
    int boxNumber_1 = 1;
    int boxNumber_2 = 2;
    int boxNumber_3 = 3;
    int boxNumber_4 = 4;
    int boxNumber_5 = 5;
    int boxNumber_6 = 6;
    int boxNumber_7 = 7;
    int boxNumber_8 = 8;

    int expectedBoxLineIndex_0 = 0;
    int expectedBoxLineIndex_1 = 3;
    int expectedBoxLineIndex_2 = 6;
    int expectedBoxLineIndex_3 = 0;
    int expectedBoxLineIndex_4 = 3;
    int expectedBoxLineIndex_5 = 6;
    int expectedBoxLineIndex_6 = 0;
    int expectedBoxLineIndex_7 = 3;
    int expectedBoxLineIndex_8 = 6;

    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_0), expectedBoxLineIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_1), expectedBoxLineIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_2), expectedBoxLineIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_3), expectedBoxLineIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_4), expectedBoxLineIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_5), expectedBoxLineIndex_5);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_6), expectedBoxLineIndex_6);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_7), expectedBoxLineIndex_7);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_8), expectedBoxLineIndex_8);
}

TEST(SudokuPlan, GetBoxColumnIndex_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int boxNumber_0 = 0;
    int boxNumber_1 = 1;
    int boxNumber_2 = 2;
    int boxNumber_3 = 3;
    int boxNumber_4 = 4;
    int boxNumber_5 = 5;

    int expectedBoxLineIndex_0 = 0;
    int expectedBoxLineIndex_1 = 3;
    int expectedBoxLineIndex_2 = 0;
    int expectedBoxLineIndex_3 = 3;
    int expectedBoxLineIndex_4 = 0;
    int expectedBoxLineIndex_5 = 3;

    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_0), expectedBoxLineIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_1), expectedBoxLineIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_2), expectedBoxLineIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_3), expectedBoxLineIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_4), expectedBoxLineIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_5), expectedBoxLineIndex_5);
}

TEST(SudokuPlan, GetBoxColumnIndex_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int boxNumber_0 = 0;
    int boxNumber_1 = 1;
    int boxNumber_2 = 2;
    int boxNumber_3 = 3;
    int boxNumber_4 = 4;
    int boxNumber_5 = 5;

    int expectedBoxLineIndex_0 = 0;
    int expectedBoxLineIndex_1 = 2;
    int expectedBoxLineIndex_2 = 4;
    int expectedBoxLineIndex_3 = 0;
    int expectedBoxLineIndex_4 = 2;
    int expectedBoxLineIndex_5 = 4;

    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_0), expectedBoxLineIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_1), expectedBoxLineIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_2), expectedBoxLineIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_3), expectedBoxLineIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_4), expectedBoxLineIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxColumnIndex(boxNumber_5), expectedBoxLineIndex_5);
}

TEST(SudokuPlan, GetBoxIndex_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int lineIndex_0 = 0;
    int columnIndex_0 = 2;
    int expectedBoxIndex_0 = 0;

    int lineIndex_1 = 1;
    int columnIndex_1 = 5;
    int expectedBoxIndex_1 = 1;

    int lineIndex_2 = 2;
    int columnIndex_2 = 8;
    int expectedBoxIndex_2 = 2;

    int lineIndex_3 = 3;
    int columnIndex_3 = 2;
    int expectedBoxIndex_3 = 3;

    int lineIndex_4 = 4;
    int columnIndex_4 = 5;
    int expectedBoxIndex_4 = 4;

    int lineIndex_5 = 5;
    int columnIndex_5 = 8;
    int expectedBoxIndex_5 = 5;

    int lineIndex_6 = 6;
    int columnIndex_6 = 2;
    int expectedBoxIndex_6 = 6;

    int lineIndex_7 = 7;
    int columnIndex_7 = 5;
    int expectedBoxIndex_7 = 7;

    int lineIndex_8 = 8;
    int columnIndex_8 = 8;
    int expectedBoxIndex_8 = 8;

    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_0, columnIndex_0), expectedBoxIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_1, columnIndex_1), expectedBoxIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_2, columnIndex_2), expectedBoxIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_3, columnIndex_3), expectedBoxIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_4, columnIndex_4), expectedBoxIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_5, columnIndex_5), expectedBoxIndex_5);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_6, columnIndex_6), expectedBoxIndex_6);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_7, columnIndex_7), expectedBoxIndex_7);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_8, columnIndex_8), expectedBoxIndex_8);
}

TEST(SudokuPlan, GetBoxIndex_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int lineIndex_0 = 1;
    int columnIndex_0 = 2;
    int expectedBoxIndex_0 = 0;

    int lineIndex_1 = 1;
    int columnIndex_1 = 5;
    int expectedBoxIndex_1 = 1;

    int lineIndex_2 = 2;
    int columnIndex_2 = 1;
    int expectedBoxIndex_2 = 2;

    int lineIndex_3 = 2;
    int columnIndex_3 = 4;
    int expectedBoxIndex_3 = 3;

    int lineIndex_4 = 5;
    int columnIndex_4 = 2;
    int expectedBoxIndex_4 = 4;

    int lineIndex_5 = 5;
    int columnIndex_5 = 5;
    int expectedBoxIndex_5 = 5;

    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_0, columnIndex_0), expectedBoxIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_1, columnIndex_1), expectedBoxIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_2, columnIndex_2), expectedBoxIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_3, columnIndex_3), expectedBoxIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_4, columnIndex_4), expectedBoxIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_5, columnIndex_5), expectedBoxIndex_5);
}

TEST(SudokuPlan, GetBoxIndex_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int lineIndex_0 = 1;
    int columnIndex_0 = 1;
    int expectedBoxIndex_0 = 0;

    int lineIndex_1 = 1;
    int columnIndex_1 = 3;
    int expectedBoxIndex_1 = 1;

    int lineIndex_2 = 1;
    int columnIndex_2 = 4;
    int expectedBoxIndex_2 = 2;

    int lineIndex_3 = 3;
    int columnIndex_3 = 0;
    int expectedBoxIndex_3 = 3;

    int lineIndex_4 = 5;
    int columnIndex_4 = 2;
    int expectedBoxIndex_4 = 4;

    int lineIndex_5 = 5;
    int columnIndex_5 = 5;
    int expectedBoxIndex_5 = 5;

    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_0, columnIndex_0), expectedBoxIndex_0);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_1, columnIndex_1), expectedBoxIndex_1);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_2, columnIndex_2), expectedBoxIndex_2);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_3, columnIndex_3), expectedBoxIndex_3);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_4, columnIndex_4), expectedBoxIndex_4);
    ASSERT_EQ(sudokuPlan.GetBoxIndex(lineIndex_5, columnIndex_5), expectedBoxIndex_5);
}

// 2. cast Generovanie noveho sudoku
TEST(SudokuPlan, SwitchLines_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int lineToChange = 0;
    sudokuPlan.SetValueTo(1, lineToChange, 0);
    sudokuPlan.SetValueTo(2, lineToChange, 1);
    sudokuPlan.SetValueTo(3, lineToChange, 2);
    sudokuPlan.SetValueTo(4, lineToChange, 3);
    sudokuPlan.SetValueTo(5, lineToChange, 4);
    sudokuPlan.SetValueTo(6, lineToChange, 5);
    sudokuPlan.SetValueTo(7, lineToChange, 6);
    sudokuPlan.SetValueTo(8, lineToChange, 7);
    sudokuPlan.SetValueTo(9, lineToChange, 8);

    int lineToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;
    int expectedValueOnIndex_6 = 3;
    int expectedValueOnIndex_7 = 2;
    int expectedValueOnIndex_8 = 1;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, lineToBeChangedWith, 0);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, lineToBeChangedWith, 1);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, lineToBeChangedWith, 2);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, lineToBeChangedWith, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, lineToBeChangedWith, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, lineToBeChangedWith, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_6, lineToBeChangedWith, 6);
    sudokuPlan.SetValueTo(expectedValueOnIndex_7, lineToBeChangedWith, 7);
    sudokuPlan.SetValueTo(expectedValueOnIndex_8, lineToBeChangedWith, 8);

    sudokuPlan.SwitchLines(lineToChange, lineToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 0), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 1), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 2), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 3), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 4), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 5), expectedValueOnIndex_5);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 6), expectedValueOnIndex_6);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 7), expectedValueOnIndex_7);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 8), expectedValueOnIndex_8);
}

TEST(SudokuPlan, SwitchLines_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int lineToChange = 0;
    sudokuPlan.SetValueTo(1, lineToChange, 0);
    sudokuPlan.SetValueTo(2, lineToChange, 1);
    sudokuPlan.SetValueTo(3, lineToChange, 2);
    sudokuPlan.SetValueTo(4, lineToChange, 3);
    sudokuPlan.SetValueTo(5, lineToChange, 4);
    sudokuPlan.SetValueTo(6, lineToChange, 5);

    int lineToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, lineToBeChangedWith, 0);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, lineToBeChangedWith, 1);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, lineToBeChangedWith, 2);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, lineToBeChangedWith, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, lineToBeChangedWith, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, lineToBeChangedWith, 5);

    sudokuPlan.SwitchLines(lineToChange, lineToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 0), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 1), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 2), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 3), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 4), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 5), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchLines_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int lineToChange = 0;
    sudokuPlan.SetValueTo(1, lineToChange, 0);
    sudokuPlan.SetValueTo(2, lineToChange, 1);
    sudokuPlan.SetValueTo(3, lineToChange, 2);
    sudokuPlan.SetValueTo(4, lineToChange, 3);
    sudokuPlan.SetValueTo(5, lineToChange, 4);
    sudokuPlan.SetValueTo(6, lineToChange, 5);

    int lineToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, lineToBeChangedWith, 0);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, lineToBeChangedWith, 1);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, lineToBeChangedWith, 2);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, lineToBeChangedWith, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, lineToBeChangedWith, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, lineToBeChangedWith, 5);

    sudokuPlan.SwitchLines(lineToChange, lineToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 0), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 1), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 2), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 3), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 4), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 5), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchLinesInBox_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int lineToChange = 7;
    sudokuPlan.SetValueTo(1, lineToChange, 0);
    sudokuPlan.SetValueTo(2, lineToChange, 1);
    sudokuPlan.SetValueTo(3, lineToChange, 2);
    sudokuPlan.SetValueTo(4, lineToChange, 3);
    sudokuPlan.SetValueTo(5, lineToChange, 4);
    sudokuPlan.SetValueTo(6, lineToChange, 5);
    sudokuPlan.SetValueTo(7, lineToChange, 6);
    sudokuPlan.SetValueTo(8, lineToChange, 7);
    sudokuPlan.SetValueTo(9, lineToChange, 8);

    int lineToBeChangedWith = 6;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;
    int expectedValueOnIndex_6 = 3;
    int expectedValueOnIndex_7 = 2;
    int expectedValueOnIndex_8 = 1;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, lineToBeChangedWith, 0);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, lineToBeChangedWith, 1);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, lineToBeChangedWith, 2);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, lineToBeChangedWith, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, lineToBeChangedWith, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, lineToBeChangedWith, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_6, lineToBeChangedWith, 6);
    sudokuPlan.SetValueTo(expectedValueOnIndex_7, lineToBeChangedWith, 7);
    sudokuPlan.SetValueTo(expectedValueOnIndex_8, lineToBeChangedWith, 8);

    sudokuPlan.SwitchLinesInBox(7, 0, 1);

    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 0), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 1), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 2), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 3), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 4), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 5), expectedValueOnIndex_5);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 6), expectedValueOnIndex_6);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 7), expectedValueOnIndex_7);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 8), expectedValueOnIndex_8);
}

TEST(SudokuPlan, SwitchLinesInBox_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int lineToChange = 5;
    sudokuPlan.SetValueTo(1, lineToChange, 0);
    sudokuPlan.SetValueTo(2, lineToChange, 1);
    sudokuPlan.SetValueTo(3, lineToChange, 2);
    sudokuPlan.SetValueTo(4, lineToChange, 3);
    sudokuPlan.SetValueTo(5, lineToChange, 4);
    sudokuPlan.SetValueTo(6, lineToChange, 5);

    int lineToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, lineToBeChangedWith, 0);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, lineToBeChangedWith, 1);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, lineToBeChangedWith, 2);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, lineToBeChangedWith, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, lineToBeChangedWith, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, lineToBeChangedWith, 5);

    sudokuPlan.SwitchLinesInBox(5, 1, 0);

    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 0), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 1), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 2), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 3), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 4), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 5), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchLinesInBox_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int lineToChange = 2;
    sudokuPlan.SetValueTo(1, lineToChange, 0);
    sudokuPlan.SetValueTo(2, lineToChange, 1);
    sudokuPlan.SetValueTo(3, lineToChange, 2);
    sudokuPlan.SetValueTo(4, lineToChange, 3);
    sudokuPlan.SetValueTo(5, lineToChange, 4);
    sudokuPlan.SetValueTo(6, lineToChange, 5);

    int lineToBeChangedWith = 1;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, lineToBeChangedWith, 0);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, lineToBeChangedWith, 1);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, lineToBeChangedWith, 2);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, lineToBeChangedWith, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, lineToBeChangedWith, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, lineToBeChangedWith, 5);

    sudokuPlan.SwitchLinesInBox(1, 1, 2);

    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 0), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 1), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 2), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 3), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 4), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(lineToChange, 5), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchColumns_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int columnToChange = 0;
    sudokuPlan.SetValueTo(1, 0, columnToChange);
    sudokuPlan.SetValueTo(2, 1, columnToChange);
    sudokuPlan.SetValueTo(3, 2, columnToChange);
    sudokuPlan.SetValueTo(4, 3, columnToChange);
    sudokuPlan.SetValueTo(5, 4, columnToChange);
    sudokuPlan.SetValueTo(6, 5, columnToChange);
    sudokuPlan.SetValueTo(7, 6, columnToChange);
    sudokuPlan.SetValueTo(8, 7, columnToChange);
    sudokuPlan.SetValueTo(9, 8, columnToChange);

    int columnToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;
    int expectedValueOnIndex_6 = 3;
    int expectedValueOnIndex_7 = 2;
    int expectedValueOnIndex_8 = 1;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, 0, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, 1, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, 2, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, 3, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, 4, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, 5, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_6, 6, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_7, 7, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_8, 8, columnToBeChangedWith);

    sudokuPlan.SwitchColumns(columnToChange, columnToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, columnToChange), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, columnToChange), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, columnToChange), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(3, columnToChange), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(4, columnToChange), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(5, columnToChange), expectedValueOnIndex_5);
    ASSERT_EQ(sudokuPlan.GetValueOf(6, columnToChange), expectedValueOnIndex_6);
    ASSERT_EQ(sudokuPlan.GetValueOf(7, columnToChange), expectedValueOnIndex_7);
    ASSERT_EQ(sudokuPlan.GetValueOf(8, columnToChange), expectedValueOnIndex_8);
}

TEST(SudokuPlan, SwitchColumns_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int columnToChange = 0;
    sudokuPlan.SetValueTo(1, 0, columnToChange);
    sudokuPlan.SetValueTo(2, 1, columnToChange);
    sudokuPlan.SetValueTo(3, 2, columnToChange);
    sudokuPlan.SetValueTo(4, 3, columnToChange);
    sudokuPlan.SetValueTo(5, 4, columnToChange);
    sudokuPlan.SetValueTo(6, 5, columnToChange);

    int columnToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, 0, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, 1, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, 2, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, 3, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, 4, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, 5, columnToBeChangedWith);

    sudokuPlan.SwitchColumns(columnToChange, columnToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, columnToChange), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, columnToChange), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, columnToChange), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(3, columnToChange), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(4, columnToChange), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(5, columnToChange), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchColumns_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int columnToChange = 0;
    sudokuPlan.SetValueTo(1, 0, columnToChange);
    sudokuPlan.SetValueTo(2, 1, columnToChange);
    sudokuPlan.SetValueTo(3, 2, columnToChange);
    sudokuPlan.SetValueTo(4, 3, columnToChange);
    sudokuPlan.SetValueTo(5, 4, columnToChange);
    sudokuPlan.SetValueTo(6, 5, columnToChange);

    int columnToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, 0, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, 1, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, 2, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, 3, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, 4, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, 5, columnToBeChangedWith);

    sudokuPlan.SwitchColumns(columnToChange, columnToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, columnToChange), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, columnToChange), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, columnToChange), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(3, columnToChange), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(4, columnToChange), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(5, columnToChange), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchColumnsInBox_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int columnToChange = 6;
    sudokuPlan.SetValueTo(1, 0, columnToChange);
    sudokuPlan.SetValueTo(2, 1, columnToChange);
    sudokuPlan.SetValueTo(3, 2, columnToChange);
    sudokuPlan.SetValueTo(4, 3, columnToChange);
    sudokuPlan.SetValueTo(5, 4, columnToChange);
    sudokuPlan.SetValueTo(6, 5, columnToChange);
    sudokuPlan.SetValueTo(7, 6, columnToChange);
    sudokuPlan.SetValueTo(8, 7, columnToChange);
    sudokuPlan.SetValueTo(9, 8, columnToChange);

    int columnToBeChangedWith = 8;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;
    int expectedValueOnIndex_6 = 3;
    int expectedValueOnIndex_7 = 2;
    int expectedValueOnIndex_8 = 1;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, 0, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, 1, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, 2, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, 3, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, 4, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, 5, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_6, 6, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_7, 7, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_8, 8, columnToBeChangedWith);

    sudokuPlan.SwitchColumnsInBox(8, 0, 2);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, columnToChange), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, columnToChange), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, columnToChange), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(3, columnToChange), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(4, columnToChange), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(5, columnToChange), expectedValueOnIndex_5);
    ASSERT_EQ(sudokuPlan.GetValueOf(6, columnToChange), expectedValueOnIndex_6);
    ASSERT_EQ(sudokuPlan.GetValueOf(7, columnToChange), expectedValueOnIndex_7);
    ASSERT_EQ(sudokuPlan.GetValueOf(8, columnToChange), expectedValueOnIndex_8);
}

TEST(SudokuPlan, SwitchColumnsInBox_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int columnToChange = 5;
    sudokuPlan.SetValueTo(1, 0, columnToChange);
    sudokuPlan.SetValueTo(2, 1, columnToChange);
    sudokuPlan.SetValueTo(3, 2, columnToChange);
    sudokuPlan.SetValueTo(4, 3, columnToChange);
    sudokuPlan.SetValueTo(5, 4, columnToChange);
    sudokuPlan.SetValueTo(6, 5, columnToChange);

    int columnToBeChangedWith = 4;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, 0, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, 1, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, 2, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, 3, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, 4, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, 5, columnToBeChangedWith);

    sudokuPlan.SwitchColumnsInBox(3, 1, 2);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, columnToChange), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, columnToChange), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, columnToChange), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(3, columnToChange), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(4, columnToChange), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(5, columnToChange), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchColumnsInBox_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int columnToChange = 2;
    sudokuPlan.SetValueTo(1, 0, columnToChange);
    sudokuPlan.SetValueTo(2, 1, columnToChange);
    sudokuPlan.SetValueTo(3, 2, columnToChange);
    sudokuPlan.SetValueTo(4, 3, columnToChange);
    sudokuPlan.SetValueTo(5, 4, columnToChange);
    sudokuPlan.SetValueTo(6, 5, columnToChange);

    int columnToBeChangedWith = 3;
    int expectedValueOnIndex_0 = 9;
    int expectedValueOnIndex_1 = 8;
    int expectedValueOnIndex_2 = 7;
    int expectedValueOnIndex_3 = 6;
    int expectedValueOnIndex_4 = 5;
    int expectedValueOnIndex_5 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_0, 0, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_1, 1, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_2, 2, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_3, 3, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_4, 4, columnToBeChangedWith);
    sudokuPlan.SetValueTo(expectedValueOnIndex_5, 5, columnToBeChangedWith);

    sudokuPlan.SwitchColumnsInBox(4, 0, 1);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, columnToChange), expectedValueOnIndex_0);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, columnToChange), expectedValueOnIndex_1);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, columnToChange), expectedValueOnIndex_2);
    ASSERT_EQ(sudokuPlan.GetValueOf(3, columnToChange), expectedValueOnIndex_3);
    ASSERT_EQ(sudokuPlan.GetValueOf(4, columnToChange), expectedValueOnIndex_4);
    ASSERT_EQ(sudokuPlan.GetValueOf(5, columnToChange), expectedValueOnIndex_5);
}

TEST(SudokuPlan, SwitchBoxes_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int boxToChange = 0;
    sudokuPlan.SetValueTo(1, 0, 0);
    sudokuPlan.SetValueTo(2, 0, 1);
    sudokuPlan.SetValueTo(3, 0, 2);
    sudokuPlan.SetValueTo(4, 1, 0);
    sudokuPlan.SetValueTo(5, 1, 1);
    sudokuPlan.SetValueTo(6, 1, 2);
    sudokuPlan.SetValueTo(7, 2, 0);
    sudokuPlan.SetValueTo(8, 2, 1);
    sudokuPlan.SetValueTo(9, 2, 2);

    int boxToBeChangedWith = 4;
    int expectedValueOnIndex_33 = 9;
    int expectedValueOnIndex_34 = 8;
    int expectedValueOnIndex_35 = 7;
    int expectedValueOnIndex_43 = 6;
    int expectedValueOnIndex_44 = 5;
    int expectedValueOnIndex_45 = 4;
    int expectedValueOnIndex_53 = 3;
    int expectedValueOnIndex_54 = 2;
    int expectedValueOnIndex_55 = 1;

    sudokuPlan.SetValueTo(expectedValueOnIndex_33, 3, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_34, 3, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_35, 3, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_43, 4, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_44, 4, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_45, 4, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_53, 5, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_54, 5, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_55, 5, 5);

    sudokuPlan.SwitchBoxes(boxToChange, boxToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, 0), expectedValueOnIndex_33);
    ASSERT_EQ(sudokuPlan.GetValueOf(0, 1), expectedValueOnIndex_34);
    ASSERT_EQ(sudokuPlan.GetValueOf(0, 2), expectedValueOnIndex_35);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 0), expectedValueOnIndex_43);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 1), expectedValueOnIndex_44);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 2), expectedValueOnIndex_45);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, 0), expectedValueOnIndex_53);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, 1), expectedValueOnIndex_54);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, 2), expectedValueOnIndex_55);
}

TEST(SudokuPlan, SwitchBoxes_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int boxToChange = 0;
    sudokuPlan.SetValueTo(1, 0, 0);
    sudokuPlan.SetValueTo(2, 0, 1);
    sudokuPlan.SetValueTo(3, 0, 2);
    sudokuPlan.SetValueTo(4, 1, 0);
    sudokuPlan.SetValueTo(5, 1, 1);
    sudokuPlan.SetValueTo(6, 1, 2);

    int boxToBeChangedWith = 3;
    int expectedValueOnIndex_23 = 9;
    int expectedValueOnIndex_24 = 8;
    int expectedValueOnIndex_25 = 7;
    int expectedValueOnIndex_33 = 6;
    int expectedValueOnIndex_34 = 5;
    int expectedValueOnIndex_35 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_23, 2, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_24, 2, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_25, 2, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_33, 3, 3);
    sudokuPlan.SetValueTo(expectedValueOnIndex_34, 3, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_35, 3, 5);

    sudokuPlan.SwitchBoxes(boxToChange, boxToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, 0), expectedValueOnIndex_23);
    ASSERT_EQ(sudokuPlan.GetValueOf(0, 1), expectedValueOnIndex_24);
    ASSERT_EQ(sudokuPlan.GetValueOf(0, 2), expectedValueOnIndex_25);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 0), expectedValueOnIndex_33);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 1), expectedValueOnIndex_34);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 2), expectedValueOnIndex_35);
}

TEST(SudokuPlan, SwitchBoxes_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int boxToChange = 0;
    sudokuPlan.SetValueTo(1, 0, 0);
    sudokuPlan.SetValueTo(2, 0, 1);
    sudokuPlan.SetValueTo(3, 1, 0);
    sudokuPlan.SetValueTo(4, 1, 1);
    sudokuPlan.SetValueTo(5, 2, 0);
    sudokuPlan.SetValueTo(6, 2, 1);

    int boxToBeChangedWith = 5;
    int expectedValueOnIndex_34 = 9;
    int expectedValueOnIndex_35 = 8;
    int expectedValueOnIndex_44 = 7;
    int expectedValueOnIndex_45 = 6;
    int expectedValueOnIndex_54 = 5;
    int expectedValueOnIndex_55 = 4;

    sudokuPlan.SetValueTo(expectedValueOnIndex_34, 3, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_35, 3, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_44, 4, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_45, 4, 5);
    sudokuPlan.SetValueTo(expectedValueOnIndex_54, 5, 4);
    sudokuPlan.SetValueTo(expectedValueOnIndex_55, 5, 5);

    sudokuPlan.SwitchBoxes(boxToChange, boxToBeChangedWith);

    ASSERT_EQ(sudokuPlan.GetValueOf(0, 0), expectedValueOnIndex_34);
    ASSERT_EQ(sudokuPlan.GetValueOf(0, 1), expectedValueOnIndex_35);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 0), expectedValueOnIndex_44);
    ASSERT_EQ(sudokuPlan.GetValueOf(1, 1), expectedValueOnIndex_45);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, 0), expectedValueOnIndex_54);
    ASSERT_EQ(sudokuPlan.GetValueOf(2, 1), expectedValueOnIndex_55);
}

// 1. cast Kontrola sudoku
TEST(SudokuPlan, IsLineValid_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int lineIndex = 0;
    bool expected = true;
    sudokuPlan.SetValueTo(1, lineIndex, 0);
    sudokuPlan.SetValueTo(2, lineIndex, 1);
    sudokuPlan.SetValueTo(3, lineIndex, 2);
    sudokuPlan.SetValueTo(4, lineIndex, 3);
    sudokuPlan.SetValueTo(5, lineIndex, 4);
    sudokuPlan.SetValueTo(6, lineIndex, 5);
    sudokuPlan.SetValueTo(7, lineIndex, 6);
    sudokuPlan.SetValueTo(8, lineIndex, 7);
    sudokuPlan.SetValueTo(9, lineIndex, 8);

    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
}

TEST(SudokuPlan, IsLineValid_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int lineIndex = 0;
    bool expected = true;
    sudokuPlan.SetValueTo(1, lineIndex, 0);
    sudokuPlan.SetValueTo(2, lineIndex, 1);
    sudokuPlan.SetValueTo(3, lineIndex, 2);
    sudokuPlan.SetValueTo(4, lineIndex, 3);
    sudokuPlan.SetValueTo(5, lineIndex, 4);
    sudokuPlan.SetValueTo(6, lineIndex, 5);

    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
}

TEST(SudokuPlan, IsLineValid_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int lineIndex = 0;
    bool expected = true;
    sudokuPlan.SetValueTo(1, lineIndex, 0);
    sudokuPlan.SetValueTo(2, lineIndex, 1);
    sudokuPlan.SetValueTo(3, lineIndex, 2);
    sudokuPlan.SetValueTo(4, lineIndex, 3);
    sudokuPlan.SetValueTo(5, lineIndex, 4);
    sudokuPlan.SetValueTo(6, lineIndex, 5);

    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
}

TEST(SudokuPlan, IsLineValid_Sudoku9x9_False) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int lineIndex = 0;
    bool expected = false;
    sudokuPlan.SetValueTo(1, lineIndex, 0);
    sudokuPlan.SetValueTo(2, lineIndex, 1);
    sudokuPlan.SetValueTo(3, lineIndex, 2);
    sudokuPlan.SetValueTo(3, lineIndex, 3);
    sudokuPlan.SetValueTo(5, lineIndex, 4);
    sudokuPlan.SetValueTo(6, lineIndex, 5);
    sudokuPlan.SetValueTo(7, lineIndex, 6);
    sudokuPlan.SetValueTo(8, lineIndex, 7);
    sudokuPlan.SetValueTo(9, lineIndex, 8);

    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
}

TEST(SudokuPlan, IsLineValid_Sudoku6x6Horizontal_False) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int lineIndex = 0;
    bool expected = false;
    sudokuPlan.SetValueTo(1, lineIndex, 0);
    sudokuPlan.SetValueTo(2, lineIndex, 1);
    sudokuPlan.SetValueTo(2, lineIndex, 2);
    sudokuPlan.SetValueTo(4, lineIndex, 3);
    sudokuPlan.SetValueTo(5, lineIndex, 4);
    sudokuPlan.SetValueTo(6, lineIndex, 5);

    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
}

TEST(SudokuPlan, IsLineValid_Sudoku6x6Vertical_False) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int lineIndex = 0;
    bool expected = false;
    sudokuPlan.SetValueTo(1, lineIndex, 0);
    sudokuPlan.SetValueTo(2, lineIndex, 1);
    sudokuPlan.SetValueTo(3, lineIndex, 2);
    sudokuPlan.SetValueTo(4, lineIndex, 3);
    sudokuPlan.SetValueTo(4, lineIndex, 4);
    sudokuPlan.SetValueTo(6, lineIndex, 5);

    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
}

TEST(SudokuPlan, IsValid_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int boxIndex = 0;
    int lineIndex = 0;
    int columnIndex = 0;
    bool expected = true;

    ASSERT_EQ(sudokuPlan.IsBoxValid(boxIndex), expected);
    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
    ASSERT_EQ(sudokuPlan.IsColumnValid(columnIndex), expected);
    ASSERT_EQ(sudokuPlan.IsValid(), expected);
}

TEST(SudokuPlan, IsValid_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int boxIndex = 0;
    int lineIndex = 0;
    int columnIndex = 0;
    bool expected = true;

    ASSERT_EQ(sudokuPlan.IsBoxValid(boxIndex), expected);
    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
    ASSERT_EQ(sudokuPlan.IsColumnValid(columnIndex), expected);
    ASSERT_EQ(sudokuPlan.IsValid(), expected);
}

TEST(SudokuPlan, IsValid_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int boxIndex = 0;
    int lineIndex = 0;
    int columnIndex = 0;
    bool expected = true;

    ASSERT_EQ(sudokuPlan.IsBoxValid(boxIndex), expected);
    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
    ASSERT_EQ(sudokuPlan.IsColumnValid(columnIndex), expected);
    ASSERT_EQ(sudokuPlan.IsValid(), expected);
}

TEST(SudokuPlan, IsValid_Sudoku9x9_False) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    int boxIndex = 0;
    int lineIndex = 0;
    int columnIndex = 0;
    bool expected = false;

    sudokuPlan.SetValueTo(1, 0, 0);
    sudokuPlan.SetValueTo(1, 1, 0);
    sudokuPlan.SetValueTo(1, 0, 1);
    sudokuPlan.SetValueTo(1, 1, 1);

    ASSERT_EQ(sudokuPlan.IsBoxValid(boxIndex), expected);
    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
    ASSERT_EQ(sudokuPlan.IsColumnValid(columnIndex), expected);
    ASSERT_EQ(sudokuPlan.IsValid(), expected);
}

TEST(SudokuPlan, IsValid_Sudoku6x6Vertical_False) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    int boxIndex = 0;
    int lineIndex = 0;
    int columnIndex = 0;
    bool expected = false;

    sudokuPlan.SetValueTo(1, 0, 0);
    sudokuPlan.SetValueTo(1, 1, 0);
    sudokuPlan.SetValueTo(1, 0, 1);
    sudokuPlan.SetValueTo(1, 1, 1);

    ASSERT_EQ(sudokuPlan.IsBoxValid(boxIndex), expected);
    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
    ASSERT_EQ(sudokuPlan.IsColumnValid(columnIndex), expected);
    ASSERT_EQ(sudokuPlan.IsValid(), expected);
}

TEST(SudokuPlan, IsValid_Sudoku6x6Horizontal_False) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    int boxIndex = 0;
    int lineIndex = 0;
    int columnIndex = 0;
    bool expected = false;

    sudokuPlan.SetValueTo(1, 0, 0);
    sudokuPlan.SetValueTo(1, 1, 0);
    sudokuPlan.SetValueTo(1, 0, 1);
    sudokuPlan.SetValueTo(1, 1, 1);

    ASSERT_EQ(sudokuPlan.IsBoxValid(boxIndex), expected);
    ASSERT_EQ(sudokuPlan.IsLineValid(lineIndex), expected);
    ASSERT_EQ(sudokuPlan.IsColumnValid(columnIndex), expected);
    ASSERT_EQ(sudokuPlan.IsValid(), expected);
}

// 2. cast Generovanie noveho sudoku
TEST(SudokuPlan, ShakeExistingSudoku_Sudoku9x9) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku9x9);

    for (int seed = 0; seed < 200; ++seed) {
        sudokuPlan.ShakeExistingSudoku(seed);
        ASSERT_TRUE(sudokuPlan.IsValid());
    }
}

TEST(SudokuPlan, ShakeExistingSudoku_Sudoku6x6Vertical) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Vertical);

    for (int seed = 0; seed < 200; ++seed) {
        sudokuPlan.ShakeExistingSudoku(seed);
        ASSERT_TRUE(sudokuPlan.IsValid());
    }
}

TEST(SudokuPlan, ShakeExistingSudoku_Sudoku6x6Horizontal) {
    SudokuPlan sudokuPlan(SudokuType::Sudoku6x6Horizontal);

    for (int seed = 0; seed < 200; ++seed) {
        sudokuPlan.ShakeExistingSudoku(seed);
        ASSERT_TRUE(sudokuPlan.IsValid());
    }
}