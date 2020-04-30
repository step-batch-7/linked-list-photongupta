#include<stdio.h>
#include "list.h"

void display_menu(void)
{
  NEW_LINE;
  printf("Main Menu");
  NEW_LINE;
  printf("---------");
  NEW_LINE;
  printf("(a) add a number to the end of the list");
  NEW_LINE;
  printf("(b) add a number to the start of the list");
  NEW_LINE;
  printf("(c) insert a number at a given position in the list");
  NEW_LINE;
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)");
  NEW_LINE;
  printf("(e) remove a number from the beginning of the list");
  NEW_LINE;
  printf("(f) remove a number from the end of the list");
  NEW_LINE;
  printf("(g) remove a number from a given position in the list");
  NEW_LINE;
  printf("(h) remove first occurrence of a number");
  NEW_LINE;
  printf("(i) remove all occurrences of a number");
  NEW_LINE;
  printf("(j) clear the whole list");
  NEW_LINE;
  printf("(k) check if a number exists in the list");
  NEW_LINE;
  printf("(l) display the list of numbers");
  NEW_LINE;
  printf("(m) exit");
  NEW_LINE;
  printf("Please enter the alphabet of the operation you would like to perform : ");
}


