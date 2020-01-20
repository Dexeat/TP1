#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

struct Monstre
{
	int pv;
	int att;
	int attsort;
};

typedef struct Monstre monstre;





int genRandoms(int lower, int upper,int count){ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        return num; 
    } 
} 

monstre geneCombat(monstre table[5],int lower, int upper,int count){return table[genRandoms(lower,upper,count)];}


void clrscr()
{
    system("@cls||clear");
}



int tourPlayer(int pvM,int pvJ,int pmJ){
	int choix;
	
	printf("Vous avez %d PV et %d PM, \nLe monstre a %d PV\n",pvJ,pmJ,pvM );
	printf("Que voulez vous faire ? \nAttaque:1 Defence:2 Competence:3 Antidote:4\n");
	scanf("%d",&choix);
	if (choix == 1)
	{
		return choix;
	}
	if (choix == 2)
	{
		return choix;
	}
	if (choix == 3)
	{
		if (pmJ>=7)
		{
			return choix;	

		}
		else{
			printf("vous n'avez pas assez de PM !\n");
			tourPlayer(pvM,pvJ,pmJ);
		}
	}
	if (choix == 4)
	{
		return choix;
	}

}


int tourMonstre(int pvM,int pvJ,int lower, int upper,int count){
	int choix;
	printf("Tour du montre!\n");
	choix = genRandoms(lower, upper, count);
	return choix;

}

int poison(){

}

int main(void)
{
	int lower = 1, upper = 3, count = 1;
	int game = 1;
	int defOn = 0;
	int tour;
	int tourM;
	int pvMonstre = 50, pvJoueur = 50;
	int pmJoueur = 10;
	int defOnM = 0;
	int bleedL = 0;
	srand(time(0));

	//creation des monstre
	monstre demon_inferieur={50,4,6};
	monstre demon_superieur={100,10,16};
	monstre roi_des_slime={500,2,8000};
	monstre goblin={15,5,5};
	monstre dragon={5000,50,90};

	monstre tableMonstre[5]= {demon_inferieur,demon_superieur,roi_des_slime,goblin,dragon};

	monstre combat[3];

	for (int i = 0; i < 3; i++)
	{
		combat[i] = geneCombat(tableMonstre,0,4,1);
		printf("PV:%d ATT:%d ATTS:%d\n", combat[i].pv,combat[i].att,combat[i].attsort);
	}
	//operateur ternaire

	/*
	while(game){
		defOn = 0;
		pmJoueur++;
		tour = tourPlayer(pvMonstre, pvJoueur, pmJoueur);
		printf("%d\n",bleedL);


		if (bleedL > 0)
		{
			pvJoueur = pvJoueur - bleedL;
			printf("Vous etes empoisonnez, vous perdez %dPV\n Il vous reste %d PV\n",bleedL, pvJoueur );
		}

		if (tour == 1)
		{
			if (defOnM == 1)
			{
				clrscr();
				pvMonstre --;
				printf("Vous attaquez le monstre il perd 1PV, il lui reste %dPV\n",pvMonstre );
				
			}
			else{
				clrscr();
				pvMonstre -= 4;
				printf("Vous attaquez le monstre il perd 4PV, il lui reste %dPV\n",pvMonstre );	
				
			}
			
		}
		if (tour == 2)
		{
			clrscr();
			defOn = 1;
			printf("vous vous defendez ! vous reduisez vos degats de 75% !\n");
			
		}
		if (tour == 3)
		{
			clrscr();
			pmJoueur -=7;
			pvMonstre -= 10;
			printf("Vous lancez une boule de feu ! \n Vous perdez 7PM ! il vous reste %dPM\n Elle inflige 10 points de degats au Montre !\n il lui reste %dPV\n",pmJoueur,pvMonstre);
			
		}
		if (tour == 4)
		{
			clrscr();
			bleedL = 0;
			printf("vous n'etes plus empoisonne!\n" );
		}


		printf("\n");
		defOnM = 0;
		tourM = tourMonstre(pvMonstre, pvJoueur,lower, upper, count);
		if (tourM == 1){
			if (defOn == 1)
			{
				pvJoueur--;
				printf("Le montre vous attaque !, grace a votre defence vous perdez 1PV\nIl vous reste %dPV\n",pvJoueur);
			}
			else{
				pvJoueur-=4;
				printf("Le montre vous attaque !\nVous perdez 4PV !\nIl vous reste %dPV\n",pvJoueur);
			}
			
		}
		if (tourM == 2)
		{
			defOnM = 1;
			printf("Le monstre se defend ! il reduit ses degats de 75% !\n");
		}
		if (tourM == 3)
		{
			bleedL++;
			printf("Le montre vous empoisonne !, Vous devez vous gerir ou vous perderez %d par tour !\n",bleedL );
		}
		printf("\n");

	}
	*/
	
	return 0;
}