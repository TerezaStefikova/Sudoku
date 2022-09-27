#include <iostream>
#include "gtest/gtest.h"

using namespace std;

#include "Game.h"

using namespace ::testing;

/* Kombinuju sa tu testy 4. casti s ostatnymi castami. */

TEST(Game, IsValid) {
    Game game(SudokuType::Sudoku9x9);
    int columnIndex = 0;
    int lineIndex = 0;
    int newNumber = 0;
    int expectedNumber = 0;
    int result = game.FillNumber(newNumber, columnIndex, lineIndex);
    ASSERT_EQ(result, expectedNumber);
}

TEST(Game, Show_Sudoku9x9) {
    Game game(SudokuType::Sudoku9x9);

    for (int i = 1; i < 3; i++) {
        game.Show();
        cout << endl;
        cout << "------------------------------------------" << endl;
        cout << endl;
        game.NextGame(i);
    }

    game.Show();
    ASSERT_EQ(1, 1);
}
TEST(Game, Show_Sudoku6x6Horizontal) {
    Game game(SudokuType::Sudoku6x6Horizontal);

    game.Show();
    ASSERT_EQ(1,1);
}
TEST(Game, Show_Sudoku6x6Vertical) {
    Game game(SudokuType::Sudoku6x6Vertical);

    game.Show();
    ASSERT_EQ(1,1);
}
// 2. cast Generovanie noveho sudoku
TEST(Game, Show_Next_SwitchBox_Sudoku9x9) {
    Game game(SudokuType::Sudoku9x9);

    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    game.NextGame(2);
    game.Show();
    ASSERT_EQ(1, 1);
}

TEST(Game, Show_Next_SwitchColumn_Sudoku9x9) {
    Game game(SudokuType::Sudoku9x9);

    //game.Show();
    game.NextGame(3);
    game.Show();
    ASSERT_EQ(1, 1);
}

TEST(Game, Show_Next_SwitchLines_Sudoku9x9) {
    Game game(SudokuType::Sudoku9x9);

    //game.Show();
    game.NextGame(1);
    game.Show();
    ASSERT_EQ(1, 1);
}

// Tu kontrolujem 3. cast (Priprava na hru)
TEST(Game, Show_All_Difficulties_Sudoku9x9) {
    Game game(SudokuType::Sudoku9x9);

    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    game.SetDifficulty(SudokuDifficulty::Medium);
    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    game.SetDifficulty(SudokuDifficulty::Hard);
    game.Show();
    ASSERT_EQ(1, 1);
}
TEST(Game, Show_All_Difficulties_Sudoku6x6Vertical) {
    Game game(SudokuType::Sudoku6x6Vertical);

    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    game.SetDifficulty(SudokuDifficulty::Medium);
    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    game.SetDifficulty(SudokuDifficulty::Hard);
    game.Show();
    ASSERT_EQ(1, 1);
}
TEST(Game, Show_All_Difficulties_Sudoku6x6Horizontal) {
    Game game(SudokuType::Sudoku6x6Horizontal);

    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    game.SetDifficulty(SudokuDifficulty::Medium);
    game.Show();
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;

    game.SetDifficulty(SudokuDifficulty::Hard);
    game.Show();
    ASSERT_EQ(1, 1);
}

// 4. cast Game
TEST(Game, Show_FillNumber_Sudoku6x6Horizontal) {
    Game game(SudokuType::Sudoku6x6Horizontal);

    int line_1 = 0; int column_1 = 0;
    int line_2 = 1; int column_2 = 1;
    int line_3 = 2; int column_3 = 2;
    int line_4 = 3; int column_4 = 3;
    int line_5 = 4; int column_5 = 4;
    int line_6 = 5; int column_6 = 5;

    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(2, line_2, column_6), 2);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(5, line_3, column_1 ), 5);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(6, line_5, column_3 ), 6);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(1, line_3, column_3 ), 1);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(5, line_5, column_2 ), 5);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(4, line_2, column_2 ), 4);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(6, line_3, column_2 ), 6);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(6, line_3, column_4 ), -1);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(2, line_3, column_4 ), 2);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(6, line_2, column_4 ), 6);
    game.Show();
    cout << "------------------------------------------" << endl;

}
TEST(Game, Show_FillNumberSeed1_GameFailed_Sudoku6x6Horizontal) {
    Game game(SudokuType::Sudoku6x6Horizontal);

    int line_1 = 0; int column_1 = 0;
    int line_2 = 1; int column_2 = 1;
    int line_3 = 2; int column_3 = 2;
    int line_4 = 3; int column_4 = 3;
    int line_5 = 4; int column_5 = 4;
    int line_6 = 5; int column_6 = 5;

    game.NextGame(1);
    game.Show();
    cout << "------------------------------------------" << endl;


    ASSERT_EQ(game.FillNumber(6, line_2, column_4 ), 6);
    game.Show();
    cout << "------------------------------------------" << endl;

    ASSERT_EQ(game.FillNumber(2, line_2, column_2 ), -1);
    game.Show();
    cout << "------------------------------------------" << endl;
    ASSERT_EQ(game.FillNumber(2, line_2, column_6 ), -1);
    game.Show();
    cout << "-----------------GAME OVER---------------" << endl;

}