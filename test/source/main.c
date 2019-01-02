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
	const char *face[] = { "一","二","三","四","五","六","七","八","九","十","J","Q","K" };
	const char *suit[] = { "紅心","方塊","梅花","黑桃" };
	srand(time(NULL));
	fillDeck(deck, face, suit);
	printf("是否要開始新賽局(y/n)\n");
	scanf_s("%s", choose, sizeof(choose));
	while(!strcmp(choose ,"y"))
	{
		shuffle(deck);

		start(deck, &z);
		printf("是否要開始新賽局(y/n)\n");
		scanf_s("%s", choose, sizeof(choose));
	}

	system("pause");
	return 0;
}


void start(const card* const wDeck, int *z)
{
	int i;
	printf("\n您手上的牌:");
	show(0, 1, wDeck);
	int con = init_Bet();
	if (con == -1)
	{
		return;
	}
	printf("\n\n\n\n");
	//==================================================================第一回合結束
	printf("\n\n您手上的牌:");
	show(0, 1, wDeck);
	printf("\n場上的牌:");
	show(2, 4, wDeck);
	printf("\n\n\n\n");
	con = init_Bet();
	if (con == -1)
	{
		return;
	}
	//==================================================================第二回合結束
	printf("\n\n您手上的牌:");
	show(0, 1, wDeck);
	printf("\n場上的牌:");
	show(2, 5, wDeck);
	printf("\n\n\n\n");
	con = init_Bet();
	if (con == -1) 
	{
		return;
	}
	//==================================================================第三回合結束
	printf("\n\n\n\n\n\n\n\n");
	if (con == -1)
	{
		return;
	}
	printf("\n場上的牌:");
	show(2, 6, wDeck);
	printf("\n\n您手上的牌:");
	show(0, 1, wDeck); 
	printf("\n\n\n\n");
	//==================================================================第四回合結束
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
	//printf("對面玩家下賭注%d", Basic);
	printf("\n是否棄牌?(y/n)\n");
	scanf_s("%s", select, sizeof(char) * 4);
	if(!strcmp(select, "n"))
	{
		printf("電腦現在有:%d元\n", opmoney);
		printf("現在我有:%d元\n", gold);
		printf("請下賭注\n");
		scanf_s("%d", &Basic);
		while (Basic  > gold)
		{
			printf("你沒有錢窮鬼\n請重新下注:");
			scanf_s("%d", &Basic);
		}
			if (react == 0)
			{
				printf("對手不想跟你玩\n");
				printf("return the game");
				return -1;
			}
			else
			{
				printf("對手跟注\n");
				tablemoney = tablemoney + Basic * 2;
				gold = gold - Basic;
				opmoney = opmoney - Basic;
				if (gold == 0)
				{
					printf("全下!!!!!!!!");
					printf("檯面上的金額: 4000\n");
					return 0;
				}
				if (gold < 0)
				{
					printf("破產了!!!!!!!!!");
					return -1;
				}
				printf("電腦現在有:%d元\n", opmoney);
				printf("您剩餘的籌碼:%d\n", gold);
				printf("檯面上的金額;%d\n", tablemoney);
				printf("\n是否加注?(y/n)\n");
				scanf_s("%s", select, sizeof(char) * 4);
				if (!strcmp(select, "y"))
				{
					printf("加注多少\n?");
					scanf_s("%d", &amount);
					while (amount > gold)
					{
						printf("你沒有錢窮鬼\n請重新下注:");
						scanf_s("%d", &amount);
					}
					{
						if (react == 0)
						{
							printf("對手棄牌\n");
							gold = gold + amount + Basic * 2;
							printf("電腦現在有:%d元\n", opmoney);
							printf("您剩餘的籌碼:%d", gold);
							printf("return the game");
							return -1;
						}
						else
						{
							printf("對手跟注\n");
							tablemoney = tablemoney + amount * 2;
							gold = gold - amount;
							opmoney = opmoney - amount;
							printf("剩餘的籌碼:%d\n", gold);
							printf("電腦現在有:%d元\n", opmoney);
							printf("檯面上的金額;%d\n", tablemoney);

							if (gold == 0)
							{
								printf("全下!!!!!!!!");
								printf("檯面上的金額: 4000\n");
								return 0;
							}
							if (gold < 0)
							{
								printf("破產了!!!!!!!!!");
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
