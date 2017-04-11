void nearAttack(struct player players[int num])
{
	if(players[num].strength <= 70)
	{
		players[num].life_pts -= players[num].strength*0.5;
	}

	else if(players[num].strength > 70)
	{
		players[num].life_pts -= players[num].strength*0.3;
	}
}

void distantAttack(struct player players[int attacker], struct player players[int attacked])

{
	if(players[attacker].dexterity > players[attacked].dexterity)
	{
		players[attacker].life_pts -= players[attacked].strength*0.3;
	}
}

void magicAttack(struct player players[int attacker], struct player players[int attacked])
{
	if(players[attacker].smartness + players[attacker].skill > 150)
	{
		It determines a decrease in the life points of the attacked player equal to 
		((0.5 * Magic Skills of attacker player) + (0.2 * Smartness of attacker player))
		
		players[attacked].life_pts = players[attacker].skill*0.5 + players[attacked].smartness*0.2

	}

}
//adjacent test
bool adjacentTest(struct player players[int attacker], struct player players[int attacked])
{
	if((players[attacked].positionRow - players[attacker].positionRow = 1 || players[attacked].positionRow - players[attacker].positionRow = 0 players[attacked].positionRow - players[attacker].positionRow = -1) &&
	(players[attacked].positionColumn - players[attacker].positionColumn == 1 ||players[attacked].positionColumn - players[attacker].positionColumn == 0 || players[attacked].positionColumn - players[attacker].positionColumn == -1))
	
	{
		return 1;
	}

	else
	{
		return 0;
	}		
			
}

// test to see if the conditions for the distant attack are met
bool distantTest(struct player players[int m], struct player players[int n]){
int test, distance;
if(adjacentTest(players[m], players[n]) = 1){
test = 0;
}
distance = max(abs(players[m].positionRow - players[n].positionRow), abs(players[m].positionCol - players[n].positionCol));
//include math library
//create max function

if(distance >= 5){
test = 0;
}
else{
test = 1;
}
bool = test;
}

int attkType;

// Print player names, types and life points after each round and check if any player out of game
printf("\n");
for(i=0; i < numplayers; i++)
{
printf("%s (%s, %d)\n", players[i].name, players[i].player_type, players[i].life_pts);
}
for(i=0; i < numplayers; i++)
{
if(players[i].life_pts <= 0){
printf("Game over for player %d", i)
}
}



printf("Please specify the number of the player you intend to attack");
scanf(%d, &players[num]);
printf("Please specify the type of attack: 1 for near, 2 for distant, 3 for magic");
scanf(%d, &attkType);

//the test for the near attack
if(attkType = 1){
	if(testAdjacent(players[attacker], players[num]) = 0){
	printf("Attack not allowed: player not in range");
	}
	else{
	nearAttack(players[num]);
	}
}

//The test for the distant attack
else if(attkType = 2){
	if(distantTest(players[attacker], players[num]) = 0){
	printf("Attack not allowed: player not in range");
	}
	else{
	distantAttack(players[attacker], players[num]);
	}	
	
	//Test for the magic attack
else if(attkType = 3){
	if(players[attacker].smartness + players[attacker].magicskills <= 150){
	printf("Attack not allowed: points not sufficient");
	}
	else{
	magicAttack(players[attacker], players[num]);
	}	
}


	
	