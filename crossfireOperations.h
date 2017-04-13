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
};

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot **board);
void pointsHuman(struct player players[]);
void pointsOgre(struct player players[]);
void pointsElf(struct player players[]);
void pointsWizard(struct player players[]);
void nearAttack(struct player players[], int attacked);
void distantAttack(struct player players[], int pcounter, int attacked);
void magicAttack(struct player players[], int pcounter, int attacked);
int adjacentTest(struct player players[], int pcounter, int attacked);
int distantTest(struct player players[], int pcounter, int attacked);
void type_of_slot(struct slot **board, struct player players[], int pcounter);


#endif

