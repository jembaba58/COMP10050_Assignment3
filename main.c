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
	int invalid=0, invalid1=0, invalid5=0, invalid6; //checking variable to make sure user inputs are valid

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

	int k, n, q, g, o;
	for(i=0; i<numplayers; i++)
	{
		k = rand()%(boardSize);
		n = rand()%(boardSize);

		players[i].positionRow = k;
		players[i].positionColumn = n;
	}

	int pcounter, cplayer;
	int invalid3 = 0, checker, rowChoice, columnChoice, attkType, attacked;
	char attkPlyr[15];

	while(numplayers>1)
	{
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
					while(invalid5 == 0)
					{
						printf("Please specify the name of the player you intend to attack: ");
						scanf("%s", &attkPlyr[15]);

						for(cplayer=0; cplayer<numplayers; cplayer++)
						{
							if(strcmp(players[cplayer].name, attkPlyr[15]) == 0)
							{
								attacked = cplayer;
								invalid6=0;
							}
							else
							{
								printf("Player is not in game.\n");
								invalid6=1;
							}
						}


						while(invalid6 == 0)
						{
							printf("Please specify the type of attack: 1 for near, 2 for distant, 3 for magic");
							scanf("%d", &attkType);

							//the test for the near attack
							if(attkType == 1)
							{
								if(adjacentTest(players, pcounter, attacked) == 0)//Call the test first to see if they are adjacent
								{
									printf("Attack not allowed: player not in range.\n");//If they're not adjacent
								}
								else
								{
									nearAttack(players, attacked);//Call the attack if they're adjacent
									invalid5=1;
								}
							}

							//The test for the distant attack
							else if(attkType == 2)
							{
								if(distantTest(players, pcounter, attacked) == 0) //Call the test for the distant attack
								{
									printf("Attack not allowed: player not in range");
								}
								else
								{
									distantAttack(players, pcounter, attacked); //Call the attack if the distance is 2,3 or 4
									invalid5=1;
								}

							}
								//Test for the magic attack
							else if(attkType == 3)
							{
								if(players[i].smartness + players[i].skill <= 150)
								{
									printf("Attack not allowed: points not sufficient.\n");
								}
								else
								{
									magicAttack(players, pcounter, attacked); // Call the attack if the attacker has more than 150.
									invalid5=1;
								}
							}
							else
							{
								printf("Invalid choice.\n");
							}
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

			// Print player names, types and life points after each round and check if any player out of game
			printf("\n\n");
			for(q=0; q < numplayers; q++)
			{
				printf("%s (%s, %d)\n", players[q].name, players[q].player_type, players[q].life_pts);
			}
			printf("\n");

		}

		//When a player’s life points become <= 0 that player has to leave the game.
		//Do this after each round to see if someone is down to 0 lift points
		for(g=0; g < numplayers; g++)
		{
			if(players[g].life_pts <= 0)
			{
				printf("Game over for player %s", players[g].name);
				for(o = g; o < numplayers; o++)
				{

					strcpy(players[o].name, players[o+1].name);
					strcpy(players[o].player_type, players[o+1].player_type);
					players[o].life_pts = players[o+1].life_pts;
					players[o].smartness = players[o+1].smartness;
					players[o].strength = players[o+1].strength;
					players[o].skill = players[o+1].skill;
					players[o].luck = players[o+1].luck;
					players[o].dexterity = players[o+1].dexterity;
					players[o].positionRow = players[o+1].positionRow;
					players[o].positionColumn = players[o+1].positionColumn;
				}
				numplayers--;
			}
		}

	}

	if(numplayers==1)
	{
		printf("Game over.\n %s is the winner.", players[0].name);
	}
	else if(numplayers==0)
	{
		printf("Game over.\n");
	}



	return 0;
}


