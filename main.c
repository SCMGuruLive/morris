/* main.c */
/* This file is part of the Morris project */

/* Copyright (C) 2020 Scott C. MacCallum */
/* scott@scm.guru */

/* This program is free software: you can redistribute it and/or  */
/* modify it under the terms of the GNU Affero License as published */
/* by the Free Software Foundation, either version 3 of the License, */
/* or (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see http://www.gnu.org/licenses/. */

#include <stdio.h>
#include <string.h>
#include <peekpoke.h>

void display(void)
{
	char Clear_Screen = 147;

	int Memory_Address_1 = 53280;
	int Memory_Address_2 = 53281;
	int Memory_Address_3 = 646;
	int Frame_Color = 0;
	int Screen_Color = 0;
	int Text_Color = 12;

	/* Clear the screen */

	printf("%c", Clear_Screen);

	/* Make all of the screen black and the text grey */

	POKE(Memory_Address_1, Frame_Color);
	POKE(Memory_Address_2, Screen_Color);
	POKE(Memory_Address_3, Text_Color);
}

void conversation(void)
{
	char Bot_Name[] = { 'M', 'o', 'r', 'r', 'i', 's', '\0' };
	char Answer[4];
	char Human_Name[10];

	int Count;

	printf("[ ");
	printf("%s", Bot_Name);
	printf(" ]");
	printf(" Hi, have we met?\n\n");

	printf("[ ");
	printf("Unknown");
	printf(" ] ");

	fgets(Answer, sizeof(Answer), stdin);

	if (strcmp(Answer, "yes") == 0) {
		printf("\n\n[ ");
		printf("%s", Bot_Name);
		printf(" ] ");
		printf("I don't remember you.\n");
	}

	printf("\n[ ");
	printf("%s", Bot_Name);
	printf(" ]");
	printf(" What is your name?\n\n");

	printf("[ ");
	printf("Unknown");
	printf(" ] ");

	fgets(Human_Name, sizeof(Human_Name), stdin);

	/* Replace the newline character in Human_Name with a null zero */

	for (Count = 0; Count < strlen(Human_Name); Count++) {
		if (Human_Name[Count] == '\n')
			Human_Name[Count] = '\0';
	}

	printf("\n[ ");
	printf("%s", Bot_Name);
	printf(" ]");
	printf(" How can I help, %s?\n\n", Human_Name);

	printf("[ ");
	printf("%s", Human_Name);
	printf(" ] ");

	fgets(Human_Name, sizeof(Human_Name), stdin);
}

int main(void)
{
	display();
	conversation();

	return (0);
}
