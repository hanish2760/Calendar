
#include <iostream>
#include <string>
#include <windows.h> // we need this header for the 'gotoxy' function.
#include <conio.h> // we need this header for the 'getch' function.
using namespace std;

void ChangeCursorStatus(bool);

void gotoxy(int, int); // by this function you can goto any position on the cmd line screen.

void header();



int UiForMonth(){

	system("cls");
	header();
	ChangeCursorStatus(false);
	char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Septemer", "October", "November", "December" };
	int choice = 0;
	char key; //for entering the key (up arrow,down arrow,etc...);

	while (1){
		for (int i = 0; i < 12; i++){
			gotoxy(35, 8 + i);//8 beacause the header coes till 6.
			if (i == choice){
				printf("<-- ");
			}
			else{
				printf("    ");
			}
			printf("%s", months[i]);
			if (i == choice){
				printf("--> \n");
			}
			else{
				printf("    \n");
			}

		}
		key = _getch(); //get the key.
		switch (key) //check the entered key.
		{
		case '\r': // if the entered key is 'Enter'.
			system("cls");
			ChangeCursorStatus(true);
			fflush(stdin);
			return choice + 1;
			break;

		case 'P': // if the entered key is the 'Down arrow' notice that its equal to 'P' (capital)
			choice++; //then we will increment the cursor by one.
			if (choice > 11) // if the cursor value is more than the items count.
				choice = 0;         //    then it will return back to the first item.
			break;

		case 'H': // same but with 'up arrow' and decrement the cursor.
			choice--;
			if (choice < 0)
				choice = 11;
			break;
		default:
			break;

		}

	}
}
void ChangeCursorStatus(bool Visible)
{
		CONSOLE_CURSOR_INFO *c = new CONSOLE_CURSOR_INFO;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		if (Visible)
		{
			c->bVisible = TRUE;
			c->dwSize = 0;//(0) is invild so the default value is set
		}
		else
		{
			c->bVisible = FALSE;
			c->dwSize = 1;//it must be assigned to a valid value
		}

		SetConsoleCursorInfo(h, c);
	}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos)  // just take this function as it is.
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void  header(){
	gotoxy(25, 2);
	for (int i = 0; i < 50; i++)
		printf("~");
	gotoxy(40, 4);
	printf("CALENDAR");
	gotoxy(25, 6);
	for (int i = 0; i < 50; i++)
		printf("~");
	
}
int toYr(int* yr){
	return yr[0] * 1000 + yr[1] * 100 + yr[2] * 10 + yr[3];
}
int UiYear(){

	header();
	gotoxy(30, 8);
	printf("Select year using arrow keys");
	gotoxy(38, 10);

	
	int x = 38, y = 13;
	int yr[4] = { 0, 0, 0, 0 };
	int ch = 0;


	char key; //for entering the key (up arrow,down arrow,etc...);

	ChangeCursorStatus(false);
	while (1){

		for (int i = 0;  i < 4; i=i+1){
			gotoxy(x+(i*2), y);
			printf("%d ", yr[i]);
			if (i == ch){
				gotoxy(x + (i * 2), y - 3);
				printf("^");
				gotoxy(x + (i * 2), y - 2);
				printf("|");
				gotoxy(x + (i * 2), y - 1);
				printf("|");
				gotoxy(x + (i * 2), y + 3);
				printf("^");
				gotoxy(x + (i * 2), y + 2);
				printf("|");
				gotoxy(x + (i * 2), y + 1);
				printf("|");

			}
			else{
				gotoxy(x + (i * 2), y - 3);
				printf(" ");
				gotoxy(x + (i * 2), y - 2);
				printf(" ");
				gotoxy(x + (i * 2), y - 1);
				printf(" ");

				gotoxy(x + (i * 2), y + 3);
				printf(" ");
				gotoxy(x + (i * 2), y + 2);
				printf(" ");
				gotoxy(x + (i * 2), y + 1);
				printf(" ");

			}


		}
		key = _getch();
		//printf("arrow key %c  %d", key, key);
		//K for lefft, M for right
		
		//get the key.
		switch (key) //check the entered key.
		{
		case '\r': // if the entered key is 'Enter'.
			ChangeCursorStatus(true);
			fflush(stdin);
			return toYr(yr);
			break;

		case 'P':	// if the entered key is the 'Down arrow' notice that its equal to 'P' (capital)
			yr[ch]=(yr[ch] - 1);	//then we will increment the cursor by one.
			if (yr[ch] < 0){
				yr[ch] = 9;
			}
			
			//yr[ch] = yr[ch] % 10;
				// if the cursor value is more than the items count.
					//then it will return back to the first item.
			break;

		case 'H': // same but with 'up arrow' and decrement the cursor.
			
			yr[ch] = (yr[ch] + 1) % 10;	//then we will increment the cursor by one.

			break;
		case 'K' : //left arrow key
			
			ch--;
			if (ch < 0){
				ch = 3;
			}
			break;
		case 'M': //right arrow key
			ch++;
			if (ch > 3){
				ch = 0;
			}
			
			break;

		default:

			break;

		}





	}
	return 2018;
}


