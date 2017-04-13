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
#include <math.h>

//Function Prototypes
void nearAttack(struct player players[], int attkPlyr);
void distantAttack(struct player players[], int pcounter, int attkPlyr);
void magicAttack(struct player players[], int pcounter, int attkPlyr);
int adjacentTest(struct player players[], int pcounter, int attkPlyr);
int distantTest(struct player players[], int pcounter, int attkPlyr);
void type_of_slot(struct slot **board, struct player players[], int pcounter);

int main(void)
{
	setbuf(stdout, NULL);

	time_t t;
	srand((unsigned) time(&t));

	int boardSize=7, choice;

	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downLeft;
	struct slot *downRight;

	struct player players[numplayers];
	struct slot **board = malloc(boardSize * sizeof(struct slot *));

	int i, h;
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

	createBoard(boardSize, &upLeft, &upRight, &downLeft, &downRight, &board);

	int k, n;
	for(i=0; i<numplayers; i++)
	{
		k = rand()%(boardSize);
		n = rand()%(boardSize);

		players[i].positionRow = k;
		players[i].positionColumn = n;
	}

	int pcounter;
	int invalid3 = 0, checker, rowChoice, columnChoice, attkType, attkPlyr;

	for(pcounter=0; pcounter<numplayers; pcounter++)
	{
		printf("Enter 1 to move to an adjacent slot, 2 to attack another player, or 3 to exit the game.\n");
		scanf("%d", &choice);

		while(invalid3 == 0);
		{
			if(choice == 1)
			{
				do
				{
					printf("You are currently in slot (%d, %d) of type %s", players[pcounter].positionRow, players[pcounter].positionColumn, board[players[pcounter].positionRow][players[pcounter].positionColumn].type);

					if(players[pcounter].positionRow == 1 && players[pcounter].positionColumn == 1)
					{
						printf("You can move to slot (1, 2) or (2, 1). Enter your choice in the form: x, y.");
						scanf("(%d, %d)", &rowChoice, &columnChoice);

						if(rowChoice == 1 && columnChoice == 2)
						{
							players[pcounter].positionRow = 1;
							players[pcounter].positionColumn = 2;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == 2 && columnChoice == 1)
						{
							players[pcounter].positionRow = 2;
							players[pcounter].positionColumn = 1;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else
						{
							printf("Invalid choice.\n");
							checker=0;
						}
					}
					else if(players[i].positionRow == 1 && players[i].positionColumn == 7)
					{
						printf("You can move to slot (1, 6) or (2, 7). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)", &rowChoice, &columnChoice);

						if(rowChoice == 1 && columnChoice == 6)
						{
							players[pcounter].positionRow = 1;
							players[pcounter].positionColumn = 6;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == 2 && columnChoice == 7)
						{
							players[pcounter].positionRow = 2;
							players[pcounter].positionColumn = 7;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else
						{
							printf("Invalid choice.\n");
							checker=0;
						}
					}
					else if(players[i].positionRow == 7 && players[i].positionColumn == 7)
					{
						printf("You can move to slot (7, 6) or (6, 7). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)", &rowChoice, &columnChoice);

						if((rowChoice == 7 && columnChoice == 6))
						{
							players[pcounter].positionRow = 7;
							players[pcounter].positionColumn = 6;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == 6 && columnChoice == 7)
						{
							players[pcounter].positionRow = 6;
							players[pcounter].positionColumn = 7;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else
						{
							printf("Invalid choice.\n");
							checker=0;
						}
					}
					else if(players[i].positionRow == 7 && players[i].positionColumn == 1)
					{
						printf("You can move to slot (6, 1) or (7, 2). Enter your choice in the form: (x, y).");
						scanf("(%d, %d)", &rowChoice, &columnChoice);

						if(rowChoice == 6 && columnChoice == 1)
						{
							players[pcounter].positionRow = 6;
							players[pcounter].positionColumn = 1;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == 7 && columnChoice == 2)
						{
							players[pcounter].positionRow = 7;
							players[pcounter].positionColumn = 2;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else
						{
							printf("Invalid choice.\n");
							checker=0;
						}
					}
					else
					{
						printf("You can move to slot (%d, %d) or (%d, %d) or (%d, %d) or (%d, %d). Enter your choice in the form: (x, y)."
								, players[pcounter].positionRow + 1, players[pcounter].positionColumn, players[pcounter].positionRow, players[pcounter].positionColumn + 1
								, players[pcounter].positionRow - 1, players[pcounter].positionColumn, players[pcounter].positionRow, players[pcounter].positionColumn - 1);
						scanf("(%d, %d)", &rowChoice, &columnChoice);

						if(rowChoice == players[pcounter].positionRow + 1 && columnChoice == players[pcounter].positionColumn)
						{
							players[pcounter].positionRow = players[pcounter].positionRow + 1;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == players[pcounter].positionRow && columnChoice == players[pcounter].positionColumn + 1)
						{
							players[pcounter].positionColumn = players[pcounter].positionColumn + 1;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == players[pcounter].positionRow - 1 && columnChoice == players[pcounter].positionColumn)
						{
							players[pcounter].positionRow = players[pcounter].positionRow - 1;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else if(rowChoice == players[pcounter].positionRow && columnChoice == players[pcounter].positionColumn - 1)
						{
							players[pcounter].positionColumn = players[pcounter].positionColumn - 1;
							type_of_slot(&board, players, pcounter);

							checker=1;
						}
						else
						{
							printf("Invalid choice.\n");
							checker=0;
						}
					}
				}while(checker == 0);

				invalid3 = 1;
			}
			else if(choice == 2)
			{
				printf("Please specify the number of the player you intend to attack");
				scanf("%d", &attkPlyr);
				printf("Please specify the type of attack: 1 for near, 2 for distant, 3 for magic");
				scanf("%d", &attkType);

				//the test for the near attack
				if(attkType == 1)
				{
					if(adjacentTest(players, pcounter, attkPlyr) == 0)//Call the test first to see if they are adjacent
					{
						printf("Attack not allowed: player not in range");//If they're not adjacent
					}
					else
					{
						nearAttack(players, attkPlyr);//Call the attack if they're adjacent
					}
				}

				//The test for the distant attack
				else if(attkType == 2)
				{
					if(distantTest(players, pcounter, attkPlyr) == 0) //Call the test for the distant attack
					{
						printf("Attack not allowed: player not in range");
					}
					else
					{
						distantAttack(players, pcounter, attkPlyr); //Call the attack if the distance is 2,3 or 4
					}
				}
					//Test for the magic attack
				else if(attkType == 3)
				{
					if(players[i].smartness + players[i].skill <= 150)
					{
						printf("Attack not allowed: points not sufficient");
					}
					else
					{
						magicAttack(players, pcounter, attkPlyr); // Call the attack if the attacker has more than 150.
					}
				}
				invalid3 = 1;
			}
			else if(choice == 3)
			{
				printf("\n%s has left the game.\n", players[pcounter].name);
				for(h=pcounter; h<numplayers; h++)
				{
					strcpy(players[h].name, players[h+1].name);
					strcpy(players[h].player_type, players[h+1].player_type);
					players[h].life_pts = players[h+1].life_pts;
					players[h].smartness = players[h+1].smartness;
					players[h].strength = players[h+1].strength;
					players[h].skill = players[h+1].skill;
					players[h].luck = players[h+1].luck;
					players[h].dexterity = players[h+1].dexterity;
					players[h].positionRow = players[h+1].positionRow;
					players[h].positionColumn = players[h+1].positionColumn;
				}
				numplayers--;

				invalid3 = 1;
			}
			else
			{
				printf("Invalid choice\n");
			}
		}
	}

	// Print player names, types and life points after each round and check if any player out of game
	printf("\n");
	for(i=0; i < numplayers; i++)
	{
		printf("%s (%s, %d)\n", players[i].name, players[i].player_type, players[i].life_pts);
	}

	//When a player’s life points become <= 0 that player has to leave the game.
	//Do this after each round to see if someone is down to 0 lift points
	for(i=0; i < numplayers; i++)
	{
		if(players[i].life_pts <= 0)
		{
			printf("Game over for player %d", i);
			for(k = i + 1; k < numplayers; k++)
			{
				players[i] = players[i + 1];
			}
				numplayers-=1;

		}
	}

	return 0;
}
void nearAttack(struct player players[], int attkPlyr)
{
	if(players[attkPlyr].strength <= 70)
	{
		players[attkPlyr].life_pts -= players[attkPlyr].strength*0.5;
	}
	else if(players[attkPlyr].strength > 70)
	{
		players[attkPlyr].life_pts -= players[attkPlyr].strength*0.3;
	}
}
void distantAttack(struct player players[], int pcounter, int attkPlyr)
{
	if(players[pcounter].dexterity > players[attkPlyr].dexterity)
	{
		players[pcounter].life_pts -= players[attkPlyr].strength*0.3;
	}
}
void magicAttack(struct player players[], int pcounter, int attkPlyr)
{
	players[attkPlyr].life_pts = players[attkPlyr].skill*0.5 + players[attkPlyr].smartness*0.2;
}
//adjacent test
int adjacentTest(struct player players[], int pcounter, int attkPlyr)
{
	if((players[attkPlyr].positionRow - players[pcounter].positionRow == 1 || players[attkPlyr].positionRow - players[pcounter].positionRow == 0 || players[attkPlyr].positionRow - players[pcounter].positionRow == -1) &&
		(players[attkPlyr].positionColumn - players[pcounter].positionColumn == 1 || players[attkPlyr].positionColumn - players[pcounter].positionColumn == 0 || players[attkPlyr].positionColumn - players[pcounter].positionColumn == -1))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
// test to see if the conditions for the distant attack are met
int distantTest(struct player players[], int pcounter, int attkPlyr)
{
	int test, distance;

	if(adjacentTest(players, pcounter, attkPlyr) == 1)
	{
		test = 0; // player [m] fails the distant test if he's adjacent to player[n]
	}

	distance = abs(players[attkPlyr].positionRow - players[pcounter].positionRow) + abs(players[attkPlyr].positionColumn - players[pcounter].positionColumn);

	if(distance >= 5)
	{
		test = 0;
	}
	else
	{
		test = 1;
	}
	return test;
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
