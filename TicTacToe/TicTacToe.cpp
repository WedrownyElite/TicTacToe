#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <vector>
#include <string>

//THIS IS WRITTEN USING OLC GPE, CHECK OUT onelonecoder.com
//Or else
class TicTacToe : public olc::PixelGameEngine
{
public:
	TicTacToe()
	{
		sAppName = "TicTacToe";
	}

private:
	//Square occupied bools
	bool SquareOne = false;
	bool SquareTwo = false;
	bool SquareThree = false;
	bool SquareFour = false;
	bool SquareFive = false;
	bool SquareSix = false;
	bool SquareSeven = false;
	bool SquareEight = false;
	bool SquareNine = false;

	int menu = 0;

	std::string State;

	//True = X False = O
	bool Turn = false;

	int c = 1;

	enum TurnResult { Player1_Win, Player2_Win, No_Win };

	enum Squares { Cross, Circle, Blank };
	std::vector<Squares> SquareVec = { Blank, Blank, Blank, Blank, Blank, Blank, Blank, Blank, Blank };
	enum game { MAIN, PVP, PVM, EXIT, PVB };
	game mode = game::MAIN;

public:
	int RowCheck(int i) {
		if (SquareVec[0] == Squares::Circle) {
			i++;
		}
		if (SquareVec[1] == Squares::Circle) {
			i++;
		}
		if (SquareVec[2] == Squares::Circle) {
			i++;
		}
		return i;
	}
	bool FuckMe(std::vector<int> Num, Squares CheckSquare) {
		for (int i = 0; i < Num.size(); i++) {
			if (SquareVec[Num[i]] == CheckSquare) {
				return true;
			}
		}
		return false;
	}
	void Bot() {
		int i = 0;
		RowCheck(i);
		if (Turn == true && c == 1) {
			SquareVec[4] = Squares::Cross;
			Turn = false;
			c++;
		}
		if (i == 2) {
			for (int fuck = 0; fuck < 2; fuck++) {
				if (SquareVec[fuck] == Squares::Blank) {
					SquareVec[fuck] = Squares::Cross;
					Turn = false;
				}
			}
		}

	}
	void MainMenu() {
		Clear(olc::BLACK);
		SquareVec = { Blank, Blank, Blank, Blank, Blank, Blank, Blank, Blank, Blank };
		Turn = false;
		if (menu == 0) {
			DrawString(10, 30, ">> Player vs Player", olc::WHITE, 1);
			DrawString(10, 50, "Player vs Machine (Hard)", olc::WHITE, 1);
			DrawString(10, 70, "Player vs Machine (Random)", olc::WHITE, 1);
			DrawString(50, 90, "Exit", olc::RED, 1);
		}
		else if (menu == 1) {
			DrawString(10, 30, "Player vs Player", olc::WHITE, 1);
			DrawString(10, 50, ">> Player vs Machine (Hard)", olc::WHITE, 1);
			DrawString(10, 70, "Player vs Machine (Random)", olc::WHITE, 1);
			DrawString(50, 90, "Exit", olc::RED, 1);
		}
		else if (menu == 2) {
			DrawString(10, 30, "Player vs Player", olc::WHITE, 1);
			DrawString(10, 50, "Player vs Machine (Hard)", olc::WHITE, 1);
			DrawString(10, 70, ">> Player vs Machine (Random)", olc::WHITE, 1);
			DrawString(50, 90, "Exit", olc::RED, 1);
		}
		else if (menu == 3) {
			DrawString(10, 30, "Player vs Player", olc::WHITE, 1);
			DrawString(10, 50, "Player vs Machine (Hard)", olc::WHITE, 1);
			DrawString(10, 70, "Player vs Machine (Random)", olc::WHITE, 1);
			DrawString(50, 90, ">> Exit", olc::RED, 1);
		}
		if (GetKey(olc::Key::DOWN).bPressed && menu < 3) {
			menu++;
		}
		else if (GetKey(olc::Key::DOWN).bPressed && menu == 3) {
			menu = 0;
		}
		else if (GetKey(olc::Key::UP).bPressed && menu > 0) {
			menu--;
		}
		else if (GetKey(olc::Key::UP).bPressed && menu == 0) {
			menu = 3;
		}
		if (GetKey(olc::Key::ENTER).bPressed && menu == 0) {
			mode = game::PVP;
		}
		else if (GetKey(olc::Key::ENTER).bPressed && menu == 1) {
			mode = game::PVB;
		}
		else if (GetKey(olc::Key::ENTER).bPressed && menu == 2) {
			mode = game::PVM;
		}
		else if (GetKey(olc::Key::ENTER).bPressed && menu == 3) {
			mode = game::EXIT;
		}
	}
	bool OnUserCreate() override {
		return true;
	}
	TurnResult WinCheck() {
		//O Win arguments
		//Horizontal wins
		if (SquareVec[0] == Squares::Circle && SquareVec[1] == Squares::Circle && SquareVec[2] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[3] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[5] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[6] == Squares::Circle && SquareVec[7] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//Vertical wins
		else if (SquareVec[0] == Squares::Circle && SquareVec[3] == Squares::Circle && SquareVec[6] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[1] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[7] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[2] == Squares::Circle && SquareVec[5] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//Angle wins
		else if (SquareVec[0] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[2] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[6] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//X Win arguments
		//Horizontal wins
		if (SquareVec[0] == Squares::Cross && SquareVec[1] == Squares::Cross && SquareVec[2] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[3] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[5] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[6] == Squares::Cross && SquareVec[7] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		//Vertical wins
		else if (SquareVec[0] == Squares::Cross && SquareVec[3] == Squares::Cross && SquareVec[6] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[1] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[7] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[2] == Squares::Cross && SquareVec[5] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		//Angle wins
		else if (SquareVec[0] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[2] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[6] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		return TurnResult::No_Win;
	}
	void PlayerVBot() {
		Clear(olc::BLACK);
		DrawLine(10, 60, ScreenWidth() - 10, 60, olc::WHITE);
		DrawLine(10, 120, ScreenWidth() - 10, 120, olc::WHITE);
		DrawLine(60, 10, 60, ScreenHeight() - 10, olc::WHITE);
		DrawLine(120, 10, 120, ScreenHeight() - 10, olc::WHITE);
		DrawString(5, 171, "Backspace = Main Menu", olc::WHITE, 1);

		if (GetKey(olc::Key::BACK).bPressed) {
			mode = game::MAIN;
		}

		//Circle Check
		//Square One
		if (GetMouse(0).bPressed && SquareVec[0] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[0] = Squares::Circle;
			Turn = true;
		}
		//Square Two
		if (GetMouse(0).bPressed && SquareVec[1] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[1] = Squares::Circle;
			Turn = true;
		}
		//Square Three
		if (GetMouse(0).bPressed && SquareVec[2] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[2] = Squares::Circle;
			Turn = true;
		}
		//Square Four
		if (GetMouse(0).bPressed && SquareVec[3] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[3] = Squares::Circle;
			Turn = true;
		}
		//Square Five
		if (GetMouse(0).bPressed && SquareVec[4] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[4] = Squares::Circle;
			Turn = true;
		}
		//Square Six
		if (GetMouse(0).bPressed && SquareVec[5] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[5] = Squares::Circle;
			Turn = true;
		}
		//Square Seven
		if (GetMouse(0).bPressed && SquareVec[6] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[6] = Squares::Circle;
			Turn = true;
		}
		//Square Eight
		if (GetMouse(0).bPressed && SquareVec[7] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[7] = Squares::Circle;
			Turn = true;
		}
		//Square Nine
		if (GetMouse(0).bPressed && SquareVec[8] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[8] = Squares::Circle;
			Turn = true;
		}

		Bot();

		//Draw O
		//Square One
		if (SquareVec[0] == Squares::Circle) {
			DrawCircle(30, 30, 20, olc::WHITE);
		}
		//Square Two
		if (SquareVec[1] == Squares::Circle) {
			DrawCircle(90, 30, 20, olc::WHITE);
		}
		//Square Three
		if (SquareVec[2] == Squares::Circle) {
			DrawCircle(150, 30, 20, olc::WHITE);
		}
		//Square Four
		if (SquareVec[3] == Squares::Circle) {
			DrawCircle(30, 90, 20, olc::WHITE);
		}
		//Square Five
		if (SquareVec[4] == Squares::Circle) {
			DrawCircle(90, 90, 20, olc::WHITE);
		}
		//Square Six
		if (SquareVec[5] == Squares::Circle) {
			DrawCircle(150, 90, 20, olc::WHITE);
		}
		//Square Seven
		if (SquareVec[6] == Squares::Circle) {
			DrawCircle(30, 150, 20, olc::WHITE);
		}
		//Square Eight
		if (SquareVec[7] == Squares::Circle) {
			DrawCircle(90, 150, 20, olc::WHITE);
		}
		//Square Nine
		if (SquareVec[8] == Squares::Circle) {
			DrawCircle(150, 150, 20, olc::WHITE);
		}

		//Draw X
		//Square One
		if (SquareVec[0] == Squares::Cross) {
			DrawLine(10, 10, 50, 50, olc::WHITE);
			DrawLine(50, 10, 10, 50, olc::WHITE);
		}
		//Square Two
		if (SquareVec[1] == Squares::Cross) {
			DrawLine(70, 10, 110, 50, olc::WHITE);
			DrawLine(110, 10, 70, 50, olc::WHITE);
		}
		//Square Three
		if (SquareVec[2] == Squares::Cross) {
			DrawLine(130, 10, 170, 50, olc::WHITE);
			DrawLine(170, 10, 130, 50, olc::WHITE);
		}
		//Square Four
		if (SquareVec[3] == Squares::Cross) {
			DrawLine(10, 70, 50, 110, olc::WHITE);
			DrawLine(50, 70, 10, 110, olc::WHITE);
		}
		//Square Five
		if (SquareVec[4] == Squares::Cross) {
			DrawLine(70, 70, 110, 110, olc::WHITE);
			DrawLine(110, 70, 70, 110, olc::WHITE);
		}
		//Square Six
		if (SquareVec[5] == Squares::Cross) {
			DrawLine(130, 70, 170, 110, olc::WHITE);
			DrawLine(170, 70, 130, 110, olc::WHITE);
		}
		//Square Seven
		if (SquareVec[6] == Squares::Cross) {
			DrawLine(10, 130, 50, 170, olc::WHITE);
			DrawLine(50, 130, 10, 170, olc::WHITE);
		}
		//Square Eight
		if (SquareVec[7] == Squares::Cross) {
			DrawLine(70, 130, 110, 170, olc::WHITE);
			DrawLine(110, 130, 70, 170, olc::WHITE);
		}
		//Square Nine
		if (SquareVec[8] == Squares::Cross) {
			DrawLine(130, 130, 170, 170, olc::WHITE);
			DrawLine(170, 130, 130, 170, olc::WHITE);
		}

		//Win check
		TurnResult Check = WinCheck();
		if (Check == TurnResult::Player2_Win) {
			Clear(olc::BLACK);
			DrawString(40, 80, "Player 2 Wins!", olc::GREEN, 1);
		}
		else if (Check == TurnResult::Player1_Win) {
			Clear(olc::BLACK);
			DrawString(40, 80, "Player 1 Wins!", olc::GREEN, 1);
		}
	}
	void PlayerVPlayer() {
		Clear(olc::BLACK);
		DrawLine(10, 60, ScreenWidth() - 10, 60, olc::WHITE);
		DrawLine(10, 120, ScreenWidth() - 10, 120, olc::WHITE);
		DrawLine(60, 10, 60, ScreenHeight() - 10, olc::WHITE);
		DrawLine(120, 10, 120, ScreenHeight() - 10, olc::WHITE);
		DrawString(5, 171, "Backspace = Main Menu", olc::WHITE, 1);

		if (GetKey(olc::Key::BACK).bPressed) {
			mode = game::MAIN;
		}

		//Circle Check
		//Square One
		if (GetMouse(0).bPressed && SquareVec[0] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[0] = Squares::Circle;
			Turn = true;
		}
		//Square Two
		if (GetMouse(0).bPressed && SquareVec[1] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[1] = Squares::Circle;
			Turn = true;
		}
		//Square Three
		if (GetMouse(0).bPressed && SquareVec[2] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[2] = Squares::Circle;
			Turn = true;
		}
		//Square Four
		if (GetMouse(0).bPressed && SquareVec[3] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[3] = Squares::Circle;
			Turn = true;
		}
		//Square Five
		if (GetMouse(0).bPressed && SquareVec[4] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[4] = Squares::Circle;
			Turn = true;
		}
		//Square Six
		if (GetMouse(0).bPressed && SquareVec[5] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[5] = Squares::Circle;
			Turn = true;
		}
		//Square Seven
		if (GetMouse(0).bPressed && SquareVec[6] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[6] = Squares::Circle;
			Turn = true;
		}
		//Square Eight
		if (GetMouse(0).bPressed && SquareVec[7] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[7] = Squares::Circle;
			Turn = true;
		}
		//Square Nine
		if (GetMouse(0).bPressed && SquareVec[8] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[8] = Squares::Circle;
			Turn = true;
		}

		//X Check
		//Square One
		if (GetMouse(1).bPressed && SquareVec[0] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) < 60 && Turn == true) {
			SquareVec[0] = Squares::Cross;
			Turn = false;
		}
		//Square Two
		if (GetMouse(1).bPressed && SquareVec[1] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == true) {
			SquareVec[1] = Squares::Cross;
			Turn = false;
		}
		//Square Three
		if (GetMouse(1).bPressed && SquareVec[2] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == true) {
			SquareVec[2] = Squares::Cross;
			Turn = false;
		}
		//Square Four
		if (GetMouse(1).bPressed && SquareVec[3] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == true) {
			SquareVec[3] = Squares::Cross;
			Turn = false;
		}
		//Square Five
		if (GetMouse(1).bPressed && SquareVec[4] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == true) {
			SquareVec[4] = Squares::Cross;
			Turn = false;
		}
		//Square Six
		if (GetMouse(1).bPressed && SquareVec[5] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == true) {
			SquareVec[5] = Squares::Cross;
			Turn = false;
		}
		//Square Seven
		if (GetMouse(1).bPressed && SquareVec[6] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 120 && Turn == true) {
			SquareVec[6] = Squares::Cross;
			Turn = false;
		}
		//Square Eight
		if (GetMouse(1).bPressed && SquareVec[7] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 120 && Turn == true) {
			SquareVec[7] = Squares::Cross;
			Turn = false;
		}
		//Square Nine
		if (GetMouse(1).bPressed && SquareVec[8] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseY()) > 120 && Turn == true) {
			SquareVec[8] = Squares::Cross;
			Turn = false;
		}

		//Draw O
		//Square One
		if (SquareVec[0] == Squares::Circle) {
			DrawCircle(30, 30, 20, olc::WHITE);
		}
		//Square Two
		if (SquareVec[1] == Squares::Circle) {
			DrawCircle(90, 30, 20, olc::WHITE);
		}
		//Square Three
		if (SquareVec[2] == Squares::Circle) {
			DrawCircle(150, 30, 20, olc::WHITE);
		}
		//Square Four
		if (SquareVec[3] == Squares::Circle) {
			DrawCircle(30, 90, 20, olc::WHITE);
		}
		//Square Five
		if (SquareVec[4] == Squares::Circle) {
			DrawCircle(90, 90, 20, olc::WHITE);
		}
		//Square Six
		if (SquareVec[5] == Squares::Circle) {
			DrawCircle(150, 90, 20, olc::WHITE);
		}
		//Square Seven
		if (SquareVec[6] == Squares::Circle) {
			DrawCircle(30, 150, 20, olc::WHITE);
		}
		//Square Eight
		if (SquareVec[7] == Squares::Circle) {
			DrawCircle(90, 150, 20, olc::WHITE);
		}
		//Square Nine
		if (SquareVec[8] == Squares::Circle) {
			DrawCircle(150, 150, 20, olc::WHITE);
		}

		//Draw X
		//Square One
		if (SquareVec[0] == Squares::Cross) {
			DrawLine(10, 10, 50, 50, olc::WHITE);
			DrawLine(50, 10, 10, 50, olc::WHITE);
		}
		//Square Two
		if (SquareVec[1] == Squares::Cross) {
			DrawLine(70, 10, 110, 50, olc::WHITE);
			DrawLine(110, 10, 70, 50, olc::WHITE);
		}
		//Square Three
		if (SquareVec[2] == Squares::Cross) {
			DrawLine(130, 10, 170, 50, olc::WHITE);
			DrawLine(170, 10, 130, 50, olc::WHITE);
		}
		//Square Four
		if (SquareVec[3] == Squares::Cross) {
			DrawLine(10, 70, 50, 110, olc::WHITE);
			DrawLine(50, 70, 10, 110, olc::WHITE);
		}
		//Square Five
		if (SquareVec[4] == Squares::Cross) {
			DrawLine(70, 70, 110, 110, olc::WHITE);
			DrawLine(110, 70, 70, 110, olc::WHITE);
		}
		//Square Six
		if (SquareVec[5] == Squares::Cross) {
			DrawLine(130, 70, 170, 110, olc::WHITE);
			DrawLine(170, 70, 130, 110, olc::WHITE);
		}
		//Square Seven
		if (SquareVec[6] == Squares::Cross) {
			DrawLine(10, 130, 50, 170, olc::WHITE);
			DrawLine(50, 130, 10, 170, olc::WHITE);
		}
		//Square Eight
		if (SquareVec[7] == Squares::Cross) {
			DrawLine(70, 130, 110, 170, olc::WHITE);
			DrawLine(110, 130, 70, 170, olc::WHITE);
		}
		//Square Nine
		if (SquareVec[8] == Squares::Cross) {
			DrawLine(130, 130, 170, 170, olc::WHITE);
			DrawLine(170, 130, 130, 170, olc::WHITE);
		}

		//Win check
		TurnResult Check = WinCheck();
		if (Check == TurnResult::Player2_Win) {
			Clear(olc::BLACK);
			DrawString(40, 80, "Player 2 Wins!", olc::GREEN, 1);
		}
		else if (Check == TurnResult::Player1_Win) {
			Clear(olc::BLACK);
			DrawString(40, 80, "Player 1 Wins!", olc::GREEN, 1);
		}
	}
	void PlayerVMachine() {
		Clear(olc::BLACK);
		DrawLine(10, 60, ScreenWidth() - 10, 60, olc::WHITE);
		DrawLine(10, 120, ScreenWidth() - 10, 120, olc::WHITE);
		DrawLine(60, 10, 60, ScreenHeight() - 10, olc::WHITE);
		DrawLine(120, 10, 120, ScreenHeight() - 10, olc::WHITE);
		DrawString(5, 171, "Backspace = Main Menu", olc::WHITE, 1);

		if (GetKey(olc::Key::BACK).bPressed) {
			mode = game::MAIN;
		}
		int Bot = rand() % 9;
		while (true) {
			if (Bot == 0 && SquareVec[0] == Squares::Cross && SquareVec[0] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 1 && SquareVec[1] == Squares::Cross && SquareVec[1] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 2 && SquareVec[2] == Squares::Cross && SquareVec[2] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 3 && SquareVec[3] == Squares::Cross && SquareVec[3] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 4 && SquareVec[4] == Squares::Cross && SquareVec[4] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 5 && SquareVec[5] == Squares::Cross && SquareVec[5] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 6 && SquareVec[6] == Squares::Cross && SquareVec[6] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 7 && SquareVec[7] == Squares::Cross && SquareVec[7] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else if (Bot == 8 && SquareVec[8] == Squares::Cross && SquareVec[8] == Squares::Circle) {
				int Bot = rand() % 9;
			}
			else {
				break;
			}
		}

		//Circle Check
		//Square One
		if (GetMouse(0).bPressed && SquareVec[0] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[0] = Squares::Circle;
			Turn = true;
		}
		//Square Two
		if (GetMouse(0).bPressed && SquareVec[1] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[1] = Squares::Circle;
			Turn = true;
		}
		//Square Three
		if (GetMouse(0).bPressed && SquareVec[2] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
			SquareVec[2] = Squares::Circle;
			Turn = true;
		}
		//Square Four
		if (GetMouse(0).bPressed && SquareVec[3] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[3] = Squares::Circle;
			Turn = true;
		}
		//Square Five
		if (GetMouse(0).bPressed && SquareVec[4] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[4] = Squares::Circle;
			Turn = true;
		}
		//Square Six
		if (GetMouse(0).bPressed && SquareVec[5] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
			SquareVec[5] = Squares::Circle;
			Turn = true;
		}
		//Square Seven
		if (GetMouse(0).bPressed && SquareVec[6] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[6] = Squares::Circle;
			Turn = true;
		}
		//Square Eight
		if (GetMouse(0).bPressed && SquareVec[7] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[7] = Squares::Circle;
			Turn = true;
		}
		//Square Nine
		if (GetMouse(0).bPressed && SquareVec[8] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseY()) > 120 && Turn == false) {
			SquareVec[8] = Squares::Circle;
			Turn = true;
		}

		//X Check
		//Square One
		if (Bot == 0 && SquareVec[0] == Squares::Blank && Turn == true) {
			SquareVec[0] = Squares::Cross;
			Turn = false;
		}
		//Square Two
		if (Bot == 1 && SquareVec[1] == Squares::Blank && Turn == true) {
			SquareVec[1] = Squares::Cross;
			Turn = false;
		}
		//Square Three
		if (Bot == 2 && SquareVec[2] == Squares::Blank && Turn == true) {
			SquareVec[2] = Squares::Cross;
			Turn = false;
		}
		//Square Four
		if (Bot == 3 && SquareVec[3] == Squares::Blank && Turn == true) {
			SquareVec[3] = Squares::Cross;
			Turn = false;
		}
		//Square Five
		if (Bot == 4 && SquareVec[4] == Squares::Blank && Turn == true) {
			SquareVec[4] = Squares::Cross;
			Turn = false;
		}
		//Square Six
		if (Bot == 5 && SquareVec[5] == Squares::Blank && Turn == true) {
			SquareVec[5] = Squares::Cross;
			Turn = false;
		}
		//Square Seven
		if (Bot == 6 && SquareVec[6] == Squares::Blank && Turn == true) {
			SquareVec[6] = Squares::Cross;
			Turn = false;
		}
		//Square Eight
		if (Bot == 7 && SquareVec[7] == Squares::Blank && Turn == true) {
			SquareVec[7] = Squares::Cross;
			Turn = false;
		}
		//Square Nine
		if (Bot == 8 && SquareVec[8] == Squares::Blank && Turn == true) {
			SquareVec[8] = Squares::Cross;
			Turn = false;
		}

		//Draw O
		//Square One
		if (SquareVec[0] == Squares::Circle) {
			DrawCircle(30, 30, 20, olc::WHITE);
		}
		//Square Two
		if (SquareVec[1] == Squares::Circle) {
			DrawCircle(90, 30, 20, olc::WHITE);
		}
		//Square Three
		if (SquareVec[2] == Squares::Circle) {
			DrawCircle(150, 30, 20, olc::WHITE);
		}
		//Square Four
		if (SquareVec[3] == Squares::Circle) {
			DrawCircle(30, 90, 20, olc::WHITE);
		}
		//Square Five
		if (SquareVec[4] == Squares::Circle) {
			DrawCircle(90, 90, 20, olc::WHITE);
		}
		//Square Six
		if (SquareVec[5] == Squares::Circle) {
			DrawCircle(150, 90, 20, olc::WHITE);
		}
		//Square Seven
		if (SquareVec[6] == Squares::Circle) {
			DrawCircle(30, 150, 20, olc::WHITE);
		}
		//Square Eight
		if (SquareVec[7] == Squares::Circle) {
			DrawCircle(90, 150, 20, olc::WHITE);
		}
		//Square Nine
		if (SquareVec[8] == Squares::Circle) {
			DrawCircle(150, 150, 20, olc::WHITE);
		}

		//Draw X
		//Square One
		if (SquareVec[0] == Squares::Cross) {
			DrawLine(10, 10, 50, 50, olc::WHITE);
			DrawLine(50, 10, 10, 50, olc::WHITE);
		}
		//Square Two
		if (SquareVec[1] == Squares::Cross) {
			DrawLine(70, 10, 110, 50, olc::WHITE);
			DrawLine(110, 10, 70, 50, olc::WHITE);
		}
		//Square Three
		if (SquareVec[2] == Squares::Cross) {
			DrawLine(130, 10, 170, 50, olc::WHITE);
			DrawLine(170, 10, 130, 50, olc::WHITE);
		}
		//Square Four
		if (SquareVec[3] == Squares::Cross) {
			DrawLine(10, 70, 50, 110, olc::WHITE);
			DrawLine(50, 70, 10, 110, olc::WHITE);
		}
		//Square Five
		if (SquareVec[4] == Squares::Cross) {
			DrawLine(70, 70, 110, 110, olc::WHITE);
			DrawLine(110, 70, 70, 110, olc::WHITE);
		}
		//Square Six
		if (SquareVec[5] == Squares::Cross) {
			DrawLine(130, 70, 170, 110, olc::WHITE);
			DrawLine(170, 70, 130, 110, olc::WHITE);
		}
		//Square Seven
		if (SquareVec[6] == Squares::Cross) {
			DrawLine(10, 130, 50, 170, olc::WHITE);
			DrawLine(50, 130, 10, 170, olc::WHITE);
		}
		//Square Eight
		if (SquareVec[7] == Squares::Cross) {
			DrawLine(70, 130, 110, 170, olc::WHITE);
			DrawLine(110, 130, 70, 170, olc::WHITE);
		}
		//Square Nine
		if (SquareVec[8] == Squares::Cross) {
			DrawLine(130, 130, 170, 170, olc::WHITE);
			DrawLine(170, 130, 130, 170, olc::WHITE);
		}

		//Win check
		TurnResult Check = WinCheck();
		if (Check == TurnResult::Player2_Win) {
			Clear(olc::BLACK);
			DrawString(40, 80, "Player 2 Wins!", olc::GREEN, 1);
		}
		else if (Check == TurnResult::Player1_Win) {
			Clear(olc::BLACK);
			DrawString(40, 80, "Player 1 Wins!", olc::GREEN, 1);
		}
	}
	bool OnUserUpdate(float fElapsedTime) override {
		// Draw Boundary
		if (mode == game::MAIN) {
			MainMenu();
		}
		if (mode == game::PVP) {
			PlayerVPlayer();
		}
		if (mode == game::PVM) {
			PlayerVMachine();
		}
		if (mode == game::PVB) {
			PlayerVBot();
		}
		if (mode != game::EXIT) {
			return true;
		}
		else if (mode == game::EXIT) {
			return false;
		}
	}
};

int main()
{
	TicTacToe demo;
	if (demo.Construct(180, 180, 2, 2))
		demo.Start();
	return 0;
}