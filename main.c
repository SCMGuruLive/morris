/* main.c
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
#include <peekpoke.h>

void display(void)
{
  char ClearScreen = 147;

  int MemoryAddress1 = 53280;
  int MemoryAddress2 = 53281;
  int MemoryAddress3 = 646;
  int FrameColor = 0;
  int ScreenColor = 0;
  int TextColor = 12;

  printf("%c",ClearScreen);

  POKE(MemoryAddress1,FrameColor);
  POKE(MemoryAddress2,ScreenColor);
  POKE(MemoryAddress3,TextColor);
}

void conversation(void)
{
  char BotName[] = {'M','o','r','r','i','s','\0'};

  printf("[");
  printf("%s",BotName);
  printf("]");
  printf(" Hi, have we met?\n");
  printf("[");
  printf("Unknown");
  printf("]");
}

int main(void)
{
  display();

  conversation();

  return(0);
}
