// Maze.cpp : This file contains the 'main' function.
#include <iostream>
using namespace std;

#include <Windows.h>;

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;


int nMapHeight = 16;
int nMapWidth  = 16;

float fFOV = 3.14159 / 4.0;
float fDepth = 16.0f;

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
			bool bHitWall = false;

			float fEyeX = sinf(fRayAngle);
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall)
			{

				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				{
					bHitWall = true;
					fDistanceToWall = fDepth;
				}
				else
				{
					if (map[nTestY * nMapWidth + nTestX] = '#')
					{
						bHitWall = true;
					}

				}
			}

			int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
			int nFloor = nScreenHeight - nCeiling;

			for (int y = 0; y < nScreenHeight; y++)
			{
				if (y < nCeiling)
					screen[y * nScreenWidth + x] = ' ';
				else if (y > nCeiling && y <= nFloor)
					screen[y * nScreenWidth + x] = '#';
				else
					screen[y * nScreenWidth + x] = '#';
			}
		}
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}
	



	return 0;
}

