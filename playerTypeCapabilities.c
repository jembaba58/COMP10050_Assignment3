/*
 * playerTypeCapabilities.c
 *
 *  Created on: 31 Mar 2017
 *      Author: vikin
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "crossfireOperations.h"

void pointsHuman(struct player players[])
{
	int i;
	int sum, check;

	for(i=0; i<numplayers; i++)
	{
		//set capabilities according to human criteria
		if(strcmp(players[i].player_type, "human") == 0)
		{
			players[i].smartness = 1 +(rand()%100);
			players[i].strength = 1 +(rand()%100);
			players[i].skill = 1 +(rand()%100);
			players[i].luck = 1 +(rand()%100);
			players[i].dexterity = 1 +(rand()%100);
			sum = players[i].smartness + players[i].strength + players[i].skill + players[i].luck + players[i].dexterity;

			//if all capabilities add to give more than 300, re-set them all
			check = 0;
			while(check == 0)
			{
				if(sum >=300)
				{
					players[i].smartness = rand()%100 + 1;
					players[i].strength = rand()%100 + 1;
					players[i].skill = rand()%100 + 1;
					players[i].dexterity = rand()%100 + 1;
					players[i].luck = rand()%100 + 1;
				}
				else{
					check = 1;
				}
			}
		}
	}

}

void pointsOgre(struct player players[])
{
	int i, sum;

	for(i=0; i<numplayers; i++)
	{
		//set capabilities according to ogre criteria
		if(strcmp(players[i].player_type, "ogre") == 0)
		{
			players[i].strength = (rand()%80);
			players[i].dexterity = (rand()%80);
			players[i].luck = (rand()%50);
			players[i].smartness = (rand()%20);
			players[i].skill = 0;
			sum = players[i].luck + players[i].smartness;

			//if sum of luck and smartness is greater than 50, re-set both
			int check = 1;
			while(check == 1)
			{
				if(sum > 50)
				{
					players[i].luck = rand()%50;
					players[i].smartness = rand()%20;
				}
				else{
					check = 0;
				}
			}
		}
	}

}

void pointsElf(struct player players[])
{
	int i;

	for(i=0; i<numplayers; i++)
	{
		//set capabilities according to elf criteria
		if(strcmp(players[i].player_type, "elf") == 0)
		{
			players[i].luck = 60 +(rand()%40);
			players[i].smartness  = 70 +(rand()%30);
			players[i].strength = 1 +(rand()%50);
			players[i].skill = 50 +(rand()%30);
		}
	}

}

void pointsWizard(struct player players[])
{
	int i;

	for(i=0; i<numplayers; i++)
	{
		//set capabilities according to wizard criteria
		if(strcmp(players[i].player_type, "wizard") == 0)
		{
			players[i].luck = 50 +(rand()%50);
			players[i].smartness = 90 +(rand()%10);
			players[i].strength = 1 +(rand()%20);
			players[i].skill = 80 +(rand()%20);
		}
	}

}
