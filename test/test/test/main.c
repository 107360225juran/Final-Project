#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct card
{
	char* face;
	char* suit;
}card;
int  init_Bet();
void show(int i, int f, card* const wDeck);
void start(const card* const wDeck, int *z);
void shuffle(card* const wDeck);
void fillDeck(card  *wDeck, const char* wFace[], const char* wSuit[]);
void compare(card  wDeck, const char wFace[], const char* wSuit[]);
int gold = 2000;
int opmoney = 2000;
int tablemoney = 0;
int main()
{
	int z = 0;
	card  deck[52];
	char choose[10];
	const char *face[] = { "�@","�G","�T","�|","��","��","�C","�K","�E","�Q","J","Q","K" };
	const char *suit[] = { "����","���","����","�®�" };
	srand(time(NULL));
	fillDeck(deck, face, suit);
	printf("�O�_�n�}�l�s�ɧ�(y/n)\n");
	scanf_s("%s", choose, sizeof(choose));
	while(!strcmp(choose ,"y"))
	{
		shuffle(deck);

		start(deck, &z);
		printf("�O�_�n�}�l�s�ɧ�(y/n)\n");
		scanf_s("%s", choose, sizeof(choose));
	}

	system("pause");
	return 0;
}


void start(const card* const wDeck, int *z)
{
	int i;
	printf("\n�z��W���P:");
	show(0, 1, wDeck);
	int con = init_Bet();
	if (con == -1)
	{
		return;
	}
	printf("\n\n\n\n");
	//==================================================================�Ĥ@�^�X����
	printf("\n\n�z��W���P:");
	show(0, 1, wDeck);
	printf("\n���W���P:");
	show(2, 4, wDeck);
	printf("\n\n\n\n");
	con = init_Bet();
	if (con == -1)
	{
		return;
	}
	//==================================================================�ĤG�^�X����
	printf("\n\n�z��W���P:");
	show(0, 1, wDeck);
	printf("\n���W���P:");
	show(2, 5, wDeck);
	printf("\n\n\n\n");
	con = init_Bet();
	if (con == -1) 
	{
		return;
	}
	//==================================================================�ĤT�^�X����
	printf("\n\n\n\n\n\n\n\n");
	if (con == -1)
	{
		return;
	}
	printf("\n���W���P:");
	show(2, 6, wDeck);
	printf("\n\n�z��W���P:");
	show(0, 1, wDeck); 
	printf("\n\n\n\n");
	//==================================================================�ĥ|�^�X����
}
void show(int i, int f, card* const wDeck)
{
	for (int j = i; j <= f; j++)
	{
		printf("%s%-5s", wDeck[j].suit, wDeck[j].face);
	}
	printf("\n");
}
int init_Bet()
{
	int i =0 ;
	char select[10] = "";
	int amount = 0, Basic, react;
	srand(time(NULL));
	Basic = 1 + rand() % 50;
	react = rand() % 10;
	//printf("�ﭱ���a�U��`%d", Basic);
	printf("\n�O�_��P?(y/n)\n");
	scanf_s("%s", select, sizeof(char) * 4);
	if(!strcmp(select, "n"))
	{
		printf("�q���{�b��:%d��\n", opmoney);
		printf("�{�b�ڦ�:%d��\n", gold);
		printf("�ФU��`\n");
		scanf_s("%d", &Basic);
		while (Basic  > gold)
		{
			printf("�A�S�����a��\n�Э��s�U�`:");
			scanf_s("%d", &Basic);
		}
			if (react == 0)
			{
				printf("��⤣�Q��A��\n");
				printf("return the game");
				return -1;
			}
			else
			{
				printf("����`\n");
				tablemoney = tablemoney + Basic * 2;
				gold = gold - Basic;
				opmoney = opmoney - Basic;
				if (gold == 0)
				{
					printf("���U!!!!!!!!");
					printf("�i���W�����B: 4000\n");
					return 0;
				}
				if (gold < 0)
				{
					printf("�}���F!!!!!!!!!");
					return -1;
				}
				printf("�q���{�b��:%d��\n", opmoney);
				printf("�z�Ѿl���w�X:%d\n", gold);
				printf("�i���W�����B;%d\n", tablemoney);
				printf("\n�O�_�[�`?(y/n)\n");
				scanf_s("%s", select, sizeof(char) * 4);
				if (!strcmp(select, "y"))
				{
					printf("�[�`�h��\n?");
					scanf_s("%d", &amount);
					while (amount > gold)
					{
						printf("�A�S�����a��\n�Э��s�U�`:");
						scanf_s("%d", &amount);
					}
					{
						if (react == 0)
						{
							printf("����P\n");
							gold = gold + amount + Basic * 2;
							printf("�q���{�b��:%d��\n", opmoney);
							printf("�z�Ѿl���w�X:%d", gold);
							printf("return the game");
							return -1;
						}
						else
						{
							printf("����`\n");
							tablemoney = tablemoney + amount * 2;
							gold = gold - amount;
							opmoney = opmoney - amount;
							printf("�Ѿl���w�X:%d\n", gold);
							printf("�q���{�b��:%d��\n", opmoney);
							printf("�i���W�����B;%d\n", tablemoney);

							if (gold == 0)
							{
								printf("���U!!!!!!!!");
								printf("�i���W�����B: 4000\n");
								return 0;
							}
							if (gold < 0)
							{
								printf("�}���F!!!!!!!!!");
								return -1;
							}
						}
					}
				}
				else
				{
					return 0;
				}
			}
		}
	else
	{
		return -1;
	}
}
		  
	 
    


void compare(card  *wDeck, const char* wFace[], const char* wSuit[])
{

}



void shuffle(card* const wDeck)
{
	int j;
	card temp;
	for (int i = 0; i < 52; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}



void fillDeck(card  *wDeck, const char* wFace[], const char* wSuit[])
{
	int i;
	for (i = 0; i < 52; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}
