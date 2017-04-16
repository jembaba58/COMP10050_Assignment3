/*
 * attack.c
 *
 *  Created on: 13 Apr 2017
 *      Author: vikin
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "crossfireOperations.h"
#include <math.h>

void nearAttack(struct player players[], int attacked)
{
	if(players[attacked].strength <= 70)
	{
		players[attacked].life_pts -= players[attacked].strength*0.5;
	}
	else if(players[attacked].strength > 70)
	{
		players[attacked].life_pts -= players[attacked].strength*0.3;
	}
}
void distantAttack(struct player players[], int pcounter, int attacked)
{
	if(players[pcounter].dexterity > players[attacked].dexterity)
	{
		players[pcounter].life_pts -= players[attacked].strength*0.3;
	}
}
void magicAttack(struct player players[], int pcounter, int attacked)
{
	players[attacked].life_pts = players[attacked].skill*0.5 + players[attacked].smartness*0.2;
}
//adjacent test
int adjacentTest(struct player players[], int pcounter, int attacked)
{
	if((players[attacked].positionRow - players[pcounter].positionRow == 1 || players[attacked].positionRow - players[pcounter].positionRow == 0 || players[attacked].positionRow - players[pcounter].positionRow == -1) &&
		(players[attacked].positionColumn - players[pcounter].positionColumn == 1 || players[attacked].positionColumn - players[pcounter].positionColumn == 0 || players[attacked].positionColumn - players[pcounter].positionColumn == -1))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
// test to see if the conditions for the distant attack are met
int distantTest(struct player players[], int pcounter, int attacked)
{
	int test, distance;

	if(adjacentTest(players, pcounter, attacked) == 1)
	{
		test = 0; // player [m] fails the distant test if he's adjacent to player[n]
	}

	distance = abs(players[attacked].positionRow - players[pcounter].positionRow) + abs(players[attacked].positionColumn - players[pcounter].positionColumn);

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
