/*
 * crossfireOperations.h
 *
 *  Created on: 31 Mar 2017
 *      Author: vikin
 */

#ifndef CROSSFIREOPERATIONS_H_
#define CROSSFIREOPERATIONS_H_

typedef int bool;
enum{false, true};

int numplayers;

struct player
{
	char name[15];
	char player_type[10];
	int life_pts;
	int smartness;
	int strength;
	int skill;
	int luck;
	int dexterity;
	int positionRow;
	int positionColumn;
};

struct slot{
	char type[20];
	int row;
	int column;

	struct slot *left;
	struct slot *right;
	struct slot *up;
	struct slot *down;
}slot;

void getDesiredElement(int maxsize, int * row, int * col);
void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight);
void reachDesiredElement(int row, int column, struct slot * initialSlot);
void pointsHuman(struct player players[]);
void pointsOgre(struct player players[]);
void pointsElf(struct player players[]);
void pointsWizard(struct player players[]);
#endif

