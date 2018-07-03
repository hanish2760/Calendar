
/*i.e here 0 is Mon,1 is tue

sdm is the starting day of the month;;som is the size of the month*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"Ui.h"

// pm is for printing month and year above the callander
void pm(int m, int y)
{
	if (m == 1)

		printf("\t\t\t\tJANUARY , %d\n", y);

	else if (m == 2)

		printf("\t\t\t\tFEBRUARY , %d\n", y);

	else if (m == 3)

		printf("\t\t\t\tMARCH , %d\n", y);

	else if (m == 4)

		printf("\t\t\t\tAPRIL , %d\n", y);

	else if (m == 5)

		printf("\t\t\t\tMAY , %d\n", y);

	else if (m == 6)

		printf("\t\t\t\tJUNE , %d\n", y);

	else if (m == 7)

		printf("\t\t\t\tJULY  , %d\n", y);

	else if (m == 8)

		printf("\t\t\t\tAUGUST , %d\n", y);

	else if (m == 9)

		printf("\t\t\t\tSEPTEMBER ,  %d\n", y);

	else if (m == 10)

		printf("\t\t\t\tOCTOBER , %d\n", y);

	else if (m == 11)

		printf("\t\t\t\t NOVEMBER , %d\n", y);

	else

		printf("\t\t\t\t DECEMBER , %d\n", y);
}

int month(int sdm, int som, int m, int y)

{

	int l, i;
	char a[5];
	pm(m, y);
	printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\tMON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN\n\t\t");
	for (l = 0; l<sdm; l++)
		printf("---\t");
	for (i = 1; i <= som; i++)
	{
		if (m == 1 && (i == 1 || i == 14 || i == 26) && y >= 1950)
			printf("%3d^\t", i);
		else if (m == 1 && (i == 1 || i == 14))
			printf("%3d^\t", i);
		else if (m == 2 && i == 14)
			printf("%3d^\t", i);
		else if (m == 5 && i == 1)
			printf("%3d^\t", i);
		else if (m == 6 && i == 19)
			printf("%3d^\t", i);
		else if (m == 8 && i == 15 && y >= 1947)
			printf("%3d^\t", i);
		else if (m == 9 && i == 5)
			printf("%3d^\t", i);
		else if (m == 10 && i == 2)
			printf("%3d^\t", i);
		else if (m == 11 && i == 14)
			printf("%3d^\t", i);
		else if (m == 12 && (i == 24 || i == 25 || i == 31))
			printf("%3d^\t", i);
		else
			printf("%3d\t", i);
		if ((i + l) % 7 == 0)
			printf("\n\t\t");
	}
	if (m == 1)
	{
		printf("\n\n\t1 - New Year");
		printf("\n\t14 - Makar Sankranti");
		if (y >= 1950)
			printf("\n\t26 - Republic Day");
	}
	if (m == 2)
	{
		printf("\n\n\t14 - Valentine's Day");
	}
	if (m == 5)
	{
		printf("\n\n\t1 - May Day");
	}
	if (m == 6)
	{
		printf("\n\n\t19 - Father's Day");
	}
	if (m == 8 && y >= 1947)
	{
		printf("\n\n\t15 - Independence Day");
	}
	if (m == 9)
	{
		printf("\n\n\t5 - Teacher's Day");
	}
	if (m == 10)
	{
		printf("\n\n\t2 - Gandhi Jayanti");
	}
	if (m == 11)
	{
		printf("\n\n\t14 - Children's Day");
	}
	if (m == 12)
	{
		printf("\n\n\t24 - Christmas eve");
		printf("\n\t25 - Christmas");
		printf("\n\t31 - New Year's Eve");
	}
	printf("\n\t=====================================================================\n");
	printf("\tPress \n\t->'n' for next month\n\t->'p' for previous month\n\t->'nn' for next year\n\t->'pp' for previous year and \n\t->Any other key to exit\n");
	scanf("%s", a);
	if (a[0] == 'n'&&a[1] == '\0')
	{
		system("cls");
		return 10;
	}
	else if (a[0] == 'p'&&a[1] == '\0')

	{
		system("cls");
		return 9;
		
	}
	else if (a[0] == 'n'&&a[1] == 'n')
	{
		system("cls");
		return 11;
		
	}
	else if (a[0] == 'p'&&a[1] == 'p')

	{

		system("cls");
		return 8;
		
	}
	else
	{
		printf("\n\tThanks you! :)");
		_getch();
		return 1;
	}
}
// function o forr the size ofrr the month intresringooo ;;;;; szom is the size of the month
int szom(int a, int y)
{
	int z;
	switch (a)
	{
	case 1:
		z = 31;
		break;
	case 2:
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			z = 29;
		else
			z = 28;
		break;
	case 3:
		z = 31;
		break;
	case 4:
		z = 30;
		break;
	case 5:
		z = 31;
		break;
	case 6:
		z = 30;
		break;
	case 7:
		z = 31;
		break;
	case 8:
		z = 31;
		break;
	case 9:
		z = 30;
		break;
	case 10:
		z = 31;
		break;
	case 11:
		z = 31;
		break;
	case 12:
		z = 31;
		break;
	}
	return z;
}
// a function to calculate starting day of month:D..HERE SDM is starting day of month;;y is the year n sdy is starting day of the year
int sdm(int y, int m, int sdy)//for not  a leap year
{
	int a;
	switch (m)
	{
	case 1:
		a = sdy;
		break;
	case 2:
		a = (sdy + 3) % 7;
		break;
	case 3:
		a = (sdy + 3) % 7;
		break;
	case 4:
		a = (sdy + 6) % 7;
		break;
	case 5:
		a = (sdy + 1) % 7;
		break;
	case 6:
		a = (sdy + 4) % 7;
		break;
	case 7:
		a = (sdy + 6) % 7;
		break;
	case 8:
		a = (sdy + 2) % 7;
		break;
	case 9:
		a = (sdy + 5) % 7;
		break;
	case 10:
		a = (sdy + 0) % 7;
		break;
	case 11:
		a = (sdy + 3) % 7;
		break;
	case 12:
		a = (sdy + 5) % 7;
		break;
	}
	return a;
}


// function to calculate starting day in a month idf it is  aleap year

int sdml(int y, int m, int sdy)

{
	int a;
	switch (m)

	{
	case 1:
		a = sdy;
		break;
	case 2:
		a = (sdy + 3) % 7;
		break;
	case 3:

		a = (sdy + 4) % 7;

		break;

	case 4:

		a = (sdy + 7) % 7;

		break;

	case 5:

		a = (sdy + 3) % 7;

		break;

	case 6:

		a = (sdy + 5) % 7;

		break;

	case 7:

		a = (sdy + 7) % 7;

		break;

	case 8:

		a = (sdy + 3) % 7;

		break;

	case 9:

		a = (sdy + 6) % 7;

		break;

	case 10:

		a = (sdy + 1) % 7;

		break;

	case 11:

		a = (sdy + 4) % 7;

		break;

	case 12:

		a = (sdy + 6) % 7;

		break;

	}

	return a;

}

int stdyr(int y)

{

	//a is number of leap years between 1900 and the given year

	int a, i = 0, b;

	for (a = 1901; a<y; a++)

	{

		if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))

			i++;

	}

	b = ((y - 1900) + i) % 7;

	return b;

}
int mn(char s[21])
{
	int m = 0;

	if (strcmp(s, "11") == 0 || strcmp(s, "november") == 0 || strcmp(s, "nov") == 0)
		m = 11;
	if (strcmp(s, "9") == 0 || strcmp(s, "september") == 0 || strcmp(s, "sep") == 0 || strcmp(s, "sept") == 0)
		m = 9;
	if (strcmp(s, "1") == 0 || strcmp(s, "january") == 0 || strcmp(s, "jan") == 0)
		m = 1;
	if (strcmp(s, "2") == 0 || strcmp(s, "february") == 0 || strcmp(s, "feb") == 0)
		m = 2;
	if (strcmp(s, "3") == 0 || strcmp(s, "march") == 0 || strcmp(s, "mar") == 0)
		m = 3;
	if (strcmp(s, "4") == 0 || strcmp(s, "april") == 0 || strcmp(s, "apr") == 0)
		m = 4;
	if (strcmp(s, "5") == 0 || strcmp(s, "may") == 0 || strcmp(s, "may") == 0)
		m = 5;
	if (strcmp(s, "6") == 0 || strcmp(s, "june") == 0 || strcmp(s, "jun") == 0)
		m = 6;
	if (strcmp(s, "7") == 0 || strcmp(s, "july") == 0 || strcmp(s, "jul") == 0)
		m = 7;
	if (strcmp(s, "8") == 0 || strcmp(s, "august") == 0 || strcmp(s, "aug") == 0)
		m = 8;
	if (strcmp(s, "10") == 0 || strcmp(s, "october") == 0 || strcmp(s, "oct") == 0)
		m = 10;
	if (strcmp(s, "12") == 0 || strcmp(s, "december") == 0 || strcmp(s, "dec") == 0)
		m = 12;


	return m;

}


int  main()

{// y is the year

	// m is the month

	// som is the size of the month

	//ssdm is the starting day in  a month

	//sdy is the stsrting day in a year
	//s stores the month number or the month name
	//ans tores the reply from user ::::::
	int z, y, m, som, ssdm, sdy, i = 1;

	char s[21], r, ans[5];

	//clrscr();
	system("cls");
	
	//printf("\nEnter the Year :\n");
	//scanf("%d", &y);
	
	y = UiYear();

start:
	//printf("\nEnter the Month  :\n");
	//scanf("%s", s);
	//m = mn(s);
	m=UiForMonth();
	if (m == 0 && i <= 4)
	{
		if (i == 1)
			printf("\nenter a valid month !! \n\n");
		if (i == 2)
		{
			printf("not again!\n");
			printf("try again!\n");

		}
		if (i == 3)
		{
			printf(" \ncheck spelling of the month or at least enter number of the month correctly!\n NOTE : there can only be 12 months in a YEAR!!");

		}

		if (i == 4)
		{

			if (s[0] == 'f' || s[0] == 'F')
			{
				printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
				printf("\nis it FEBRUARY ?\n");
				m = 2;
			}

			else
				if (s[0] == 'd' || s[0] == 'D')
				{
					printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
					printf("is it DECEMBER ?\n");
					m = 12;
				}

				else
					if (s[0] == 'N' || s[0] == 'n')

					{
						printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
						printf("is it NOVEMBER ?\n");
						m = 11;
					}
					else
						if (s[0] == 's' || s[0] == 'S')
						{
							printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
							printf("is it SEPTEMBER ? \n");
							m = 9;
						}


						else
							if (s[0] == 'o' || s[0] == 'O')
							{
								printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
								printf("is it OCTOBER ? \n");
								m = 10;
							}

							else
								if (s[0] == 'j' || s[0] == 'J')
								{

									if (s[1] == 'a' || s[1] == 'A')
									{

										printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
										printf("is it JANUARY ?\n");
										m = 1;
									}

									else
										if (s[2] == 'n' || s[2] == 'N')
										{

											printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
											printf("is it  JUNE ?\n");
											m = 6;
										}

										else
										{
											printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
											printf("is it JULY ?\n");
											m = 7;
										}


								}
								else

									if (s[0] == 'm' || s[0] == 'M')
									{
										if (s[2] == 'r' || s[2] == 'R')
										{
											printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
											printf("is it MARCH ?\n");
											m = 3;
										}

										else
										{
											printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
											printf("is it  MAY ?\n");
											m = 5;
										}


									}
									else

										if (s[0] == 'a' || s[0] == 'A')
										{
											if (s[1] == 'p' || s[1] == 'P')
											{
												printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
												printf("is it APRIL? \n");
												m = 4;
											}


											else

											{

												printf("\ni don't think u r going to get it right!\nthis is your last chance !\natleast tell me :\n");
												printf("is it AUGUST ?\n");
												m = 8;
											}

										}
										else
										{
											printf("i couldn't get u; even the first letter u entered is in't matching with any of the month's\n");
											return 100;

										}
			printf("\n:::::\n");
			scanf("%s", ans);

			if (ans[0] == 'n' || ans[0] == 'N')
			{
				printf("try later \n");
				return 100;
			}

		}
		if (i == 5)
			return 100;
		i++;
		if (i <= 4)
			goto start;

	}
again:
	sdy = stdyr(y);
	// to find size of the month
	som = szom(m, y);
	// to find starting day in  a month...but first find starting day in a year

	if ((y % 4 == 0 && y != 1900 && y % 100 != 0) || (y % 400 == 0))
		ssdm = sdml(y, m, sdy);
	else
		ssdm = sdm(y, m, sdy);
	z = month(ssdm, som, m, y);
	if (z == 10)
	{
		if (m <= 11)
		{
			m++;
			goto again;
		}
		if (m == 12)
		{
			m = 1;
			y++;
			goto again;
		}
	}
	if (z == 9)
	{
		if (m >= 2)
		{
			m--;
			goto again;
		}
		if (m == 1)
		{
			m = 12;
			y--;
			goto again;
		}
	}
	if (z == 11)
	{
		y++;
		goto again;
	}
	if (z == 8)
	{
		y--;
		goto again;
	}
}

