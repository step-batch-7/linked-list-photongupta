#include "../list.h"
#include <stdio.h>

void print_status(Status status)
{
  if (status)
    printf("✅");
  else
    printf("❌");
  NEW_LINE;
}

void run_add_to_start(List_ptr list)
{
  printf("should add the number at the start of the list : ");
  Status status = add_to_start(list, 5);
  print_status(status);
}

void run_add_to_end(List_ptr list)
{
  printf("should add the number at the end of the list : ");
  Status status = add_to_end(list, 5);
  print_status(status);
}

int main(void)
{
  List_ptr list = create_list();
  printf("Testing start");
  NEW_LINE;
  printf(".............");
  NEW_LINE;
  run_add_to_end(list);
  run_add_to_start(list);
  printf(".............");
  NEW_LINE;
  printf("Testing end");

  return 0;
}
