/*
 * main.c
 *
 *  Created on: 31 Mar 2017
 *      Author: vikin
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "crossfireOperations.h"

int main(void)
{
	time_t t;
	srand((unsigned) time(&t));

	int row, column, boardSize=7;

	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downLeft;
	struct slot *downRight;

	printf("\n\nPlease enter the number of players you would like to enter into the game (Maximum 6) : ");
	scanf("%d", &numplayers);

	struct player players[numplayers];

	int i;
	int invalid=0, invalid1=0; //checking variable to make sure user inputs are valid

	while(invalid==0)
	{
		if(numplayers>=0 && numplayers<=6)
		{
			while(invalid1==0)
			{
				for(i=0; i<numplayers; i++)
				{
					//For each playerNumber, we ask for the the type and name.
					printf("\nPlease enter the name and player type (elf, human, ogre or wizard) for player %d (in lowercase letters and in the format: player name, player type) :\n", i+1);
					scanf("%s, %s", players[i].name, players[i].player_type);

					//check if what the user inputed is valid
					if(strcmp(players[i].player_type, "elf") == 0 || strcmp(players[i].player_type, "human") == 0 || strcmp(players[i].player_type, "ogre") == 0 || strcmp(players[i].player_type, "wizard") == 0)
					{
						invalid1 = 1;
					}
					else
					{
						printf("Invalid player type.\n");
						i--;
					}
				}
			}
			invalid = 1;
		}
		else
		{
			printf("Invalid number of players\n");
		}
	}

	//initialise all players life points to 100
	for(i=0; i<numplayers; i++)
	{
		players[i].life_pts = 100;
	}

	//call capability functions
	pointsHuman(players);
	pointsOgre(players);
	pointsElf(players);
	pointsWizard(players);

	createBoard(boardSize, &upLeft, &upRight, &downLeft, &downRight);

	int k, n;
	for(i=0; i<numplayers; i++)
	{
		k = rand()%(boardSize);
		n = rand()%(boardSize);

		players[i].positionRow = k;
		players[i].positionColumn = n;
	}

	if(row >= boardSize/2){
		if(column >= boardSize/2){
			reachDesiredElement(row,column,downRight);
		}
		else{
			reachDesiredElement(row,column,downLeft);
		}
	}
	else{
		if(column >= boardSize/2){
			reachDesiredElement(row,column, upRight);
		}
		else{
			reachDesiredElement(row,column,upLeft);
		}
	}



	return 0;
}
