/*
 * boardOperations.c
 *
 *  Created on: 31 Mar 2017
 *      Author: vikin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "crossfireOperations.h"

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot **board)
{
	**board = malloc(boardSize *sizeof(struct slot));

	int i, j;

	for(i=0; i<boardSize; i++)
	{
		board[i] = malloc(boardSize *sizeof(struct slot));
	}

	for(j=0; j<boardSize; j++)
	{
		for(i=0; i<boardSize; i++)
		{
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	for(i=1; i<boardSize-1; i++){
		for(j=1;j<boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			board[i][j].right = &board[i][j+1];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
		}
	}

	for(int j=1; j<boardSize-1; j++){
		board[0][j].right = &board[0][j+1];
		board[0][j].left = &board[0][j-1];
		board[0][j].down = &board[1][j];
		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
	}

	for(int i=1; i<boardSize-1; i++){
		board[i][0].right = &board[i][1];
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];
		board[i][boardSize-1].left = &board[boardSize - 1][boardSize-2];
		board[i][boardSize -1].up = &board[i -1][boardSize-1];
		board[i][boardSize -1].down = &board[i+1][boardSize -1];
	}

	board[0][0].right = &board[0][1];
	board[0][0].down = &board[1][0];
	board[0][boardSize-1].left = &board[0][boardSize-2];
	board[0][boardSize -1].down = &board[1][boardSize -1];
	board[boardSize -1][0].right = &board[boardSize -1][1];
	board[boardSize -1][0].up = &board[boardSize -2][0];
	board[boardSize - 1][boardSize-1].up = &board[boardSize-2][boardSize-1];
	board[boardSize - 1][boardSize -1].left = &board[boardSize -1][boardSize -2];

	*upLeft = &board[0][0];
	*upRight = &board[0][boardSize -1];
	*downLeft = &board[boardSize -1][0];
	*downRight = &board[boardSize -1][boardSize -1];

	int d;
	for(i=0; i < boardSize; i++)
	{
		for(d=0; d < boardSize; i++)
		{
			j = 1 + rand() % 3; //j selects a random position between 1 and 3.

			if(j==1)
			{
				strcpy(board[i][d].type, "Level Ground");
			}

			else if(j==2)
			{
				strcpy(board[i][d].type, "Hill");
			}

			else
			{
				strcpy(board[i][d].type, "City");
			}
		}
	}
}






