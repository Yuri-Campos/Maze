// Maze.cpp : This file contains the 'main' function.
#include <iostream>
using namespace std;

#include <Windows.h>;

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 0.0f;
float fPlayerY = 0.0f;
float fPlayerA = 0.0f;


int nMapHeight = 16;
int nMapWidth  = 16;

float fFOV = 3.14159 / 4.0;

int main()
{
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;

	map += L"################";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"##...........###";
	map += L"################";
	map += L"################";
	map += L"################";

	while (1)
	{
		for (int i = 0; i < nScreenWidth; i++)
		{
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)i / (float)nScreenWidth) * fFOV;

			float fDistanceToWall = 0;
		}
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}



	return 0;
}

