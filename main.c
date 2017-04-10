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
	setbuf(stdout, NULL);

	time_t t;
	srand((unsigned) time(&t));

	int row=7, column=5, boardSize=7, choice;

	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downLeft;
	struct slot *downRight;

	struct player players[numplayers];

	int i;
	int invalid=0, invalid1=0; //checking variable to make sure user inputs are valid

	while(invalid==0)
	{
		printf("\n\nPlease input the number of players you would like to enter into the game (Maximum 6) : ");
		scanf("%d", &numplayers);

		if(numplayers>=2 && numplayers<=6)
		{
			while(invalid1==0)
			{
				i=0;
				while(i<numplayers)
				{
					//For each playerNumber, we ask for the the type and name.
					printf("\nPlease enter the name and player type (elf, human, ogre or wizard) for player %d (in lowercase letters and in the format: player name player type) :\n", i+1);
					scanf("%s %s", players[i].name, players[i].player_type);

					//check if what the user inputed is valid
					if(strcmp(players[i].player_type, "elf") == 0 || strcmp(players[i].player_type, "human") == 0 || strcmp(players[i].player_type, "ogre") == 0 || strcmp(players[i].player_type, "wizard") == 0)
					{
						invalid1 = 1;
						i++;
					}
					else
					{
						printf("Invalid player type.\n");
					}
				}
			}
			invalid = 1;
		}
		else
		{
			printf("Invalid number of players.\n");
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

	int pcounter;
	int invalid3 = 0, checker, rowChoice, columnChoice;

	for(pcounter=0; pcounter<numplayers; pcounter++)
	{
		printf("Enter 1 to move to an adjacent slot, 2 to attack another player, or 3 to exit the game.\n");
		scanf("%d", &choice);

		int invalid3 = 0, checker, rowChoice, columnChoice;

		while(invalid3 == 0);
		{
			if(choice == 1)
			{
				do
				{
					printf("You are currently in slot (%d, %d) of type %s", players[i].positionRow, players[i].positionColumn, slot[i].type);

					if(players[i].positionRow == 1 && players[i].positionColumn == 1)
					{
						printf("You can move to slot (1, 2) or (2, 1). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)" &rowChoice, &columnChoice);

						if(rowChoice == 1 && columnChoice == 2)
						{

							checker=1;
						}
						else if(rowChoice == 2 && columnChoice == 1)
						{

							checker=1;
						}
						else
						{
							checker=0;
						}
					}
					else if(players[i].positionRow == 1 && players[i].positionColumn == 7)
					{
						printf("You can move to slot (1, 6) or (2, 7). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)" &rowChoice, &columnChoice);

						if(rowChoice == 1 && columnChoice == 6)
						{

							checker=1;
						}
						else if(rowChoice == 2 && columnChoice == 7)
						{

							checker=1;
						}
						else
						{
							checker=0;
						}
					}
					else if(players[i].positionRow == 7 && players[i].positionColumn == 7)
					{
						printf("You can move to slot (7, 6) or (6, 7). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)" &rowChoice, &columnChoice);

						if((rowChoice == 7 && columnChoice == 6))
						{

							checker=1;
						}
						else if(rowChoice == 6 && columnChoice == 7)
						{

							checker=1;
						}
						else
						{
							checker=0;
						}
					}
					else if(players[i].positionRow == 7 && players[i].positionColumn == 1)
					{
						printf("You can move to slot (6, 1) or (7, 2). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)" &rowChoice, &columnChoice);

						if(rowChoice == 6 && columnChoice == 1)
						{

							checker=1;
						}
						else if(rowChoice == 7 && columnChoice == 2)
						{

							checker=1;
						}
						else
						{
							checker=0;
						}
					}
					else
					{
						printf("You can move to slot (%d, %d) or (%d, %d) or (%d, %d) or (%d, %d). Enter your choice in the form: (x, y)."
								, players[i].positionRow + 1, players[i].positionColumn, players[i].positionRow, players[i].positionColumn + 1
								, players[i].positionRow - 1, players[i].positionColumn, players[i].positionRow, players[i].positionColumn - 1);
						scanf("(%d, %d)" &rowChoice, &columnChoice);

						if(rowChoice == players[i].positionRow + 1 && columnChoice == players[i].positionColumn)
						{

							checker=1;
						}
						else if(rowChoice == players[i].positionRow && columnChoice == players[i].positionColumn + 1)
						{

							checker=1;
						}
						else if(rowChoice == players[i].positionRow - 1 && columnChoice == players[i].positionColumn)
						{

							checker=1;
						}
						else if(rowChoice == players[i].positionRow && columnChoice == players[i].positionColumn - 1)
						{

							checker=1;
						}
						else
						{
							checker=0;
						}
					}
				}while(checker == 0);

				invalid3 = 1;
			}
			else if(choice == 2)
			{

				invalid3 = 1;
			}
			else if(choice == 3)
			{

				invalid3 = 1;
			}
			else
			{
				printf("Invalid choice\n");
			}
		}
	}


	return 0;
}
