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

void createBoard(int boardSize, struct slot **board)
{
	int i, j, k, t, d;

	for(i=0; i<boardSize; i++)
	{
		board[i] = malloc(boardSize *sizeof(struct slot));

		for(j=0; j<boardSize; j++)
		{
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	for(i=1; i< boardSize-1; i++){
		for(j=1;j < boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			board[i][j].right = &board[i][j+1];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
		}
	}

	for(j = 1; j < boardSize -1; j++){
		board[0][j].right = &board[0][j+1];
		board[0][j].left = &board[0][j-1];
		board[0][j].down = &board[1][j];

		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
	}

	for(i = 1; i < boardSize -1; i++){
		board[i][0].right = &board[i][1];
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];

		board[i][boardSize-1].left = &board[boardSize-1][boardSize-2];
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

	for(k=0; k < boardSize; k++)
	{
		for(d=0; d < boardSize; d++)
		{
			t = 1 + rand() % 3; //j selects a random position between 1 and 3.

			if(t==1)
			{
				strcpy(board[k][d].type, "Level Ground");
			}

			else if(t==2)
			{
				strcpy(board[k][d].type, "Hill");
			}

			else
			{
				strcpy(board[k][d].type, "City");
			}
		}
	}
}

void type_of_slot(struct slot **board, struct player players[], int pcounter)
{
	int nothing=0;
	if(strcmp(board[players[pcounter].positionRow][players[pcounter].positionColumn].type, "Hill") == 0)
	{
		if(players[pcounter].dexterity < 50)
		{
			players[pcounter].strength -=10;
		}
		else if(players[pcounter].dexterity >= 60)
		{
			players[pcounter].strength +=10;
		}
	}
	else if(strcmp(board[players[pcounter].positionRow][players[pcounter].positionColumn].type, "City") == 0)
	{
		if(players[pcounter].smartness > 60)
		{
			players[pcounter].skill +=10;
		}
		else if(players[pcounter].smartness <= 50)
		{
			players[pcounter].dexterity -=10;
		}
	}
	else
	{
		nothing++;
	}
}





