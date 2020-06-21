#include <stdio.h>
		#include <stdlib.h>
		#include <time.h> 
		#include <string.h>
		#define MAX_Size_data 5 
		#define MAX_Size_name 15 
		typedef struct Data_task 
		{
			char name [MAX_Size_data] [MAX_Size_name];
			int time [MAX_Size_data];
			int size;
		} Data;
		void print_main_menu (); 
		void print_menu (); 
		int get_number (int total); 
		void peek (Data *data, int type); 
		void push (Data *data, int time_task, char* name_task, int type); 
		void run (Data *data, int type); 
		void pop (Data *data, int type); 
		int main ()
		{
			Data data; 
			data.size = 0;	
			char str [MAX_Size_name];
			int number_item_menu = 0;
			int type_data = 0; 
			print_main_menu(); 	    
			type_data = get_number(3);
			if (type_data == 3)
			{
			exit (1);
			}
			do
			{
				print_menu ();	
				number_item_menu = get_number(5);		
				switch (number_item_menu)
				{
					case 1:
								printf ("Введите имя задачи: "); 
						scanf("%s", str); 
						push (&data, rand() % 10, str, type_data); 
						break; 
					case 2:
						pop (&data, type_data);				
						break;
					case 3:
						peek (&data, type_data);
						sleep(2);
						break;
					case 4:
						run (&data, type_data);
						sleep(2);
						break;
					case 5:
						exit(1);
				} 
			} while (number_item_menu != 5);
			return 0;
		}
				void run (Data *data, int type) 
		{
			int i = data -> size;
			if (i == 0) 
				if (type == 1)
				{
					printf ("стек пуст!\n");
				} else 
					{
					printf ("очередь пуста!\n");
					}
			} else if (type == 1) // стек
				{
					do 
					{
						printf ("Выполнение задачи ""%s"" ,Time = %d\n", data-> name [i - 1], data->time [i - 1] );
						printf ("  Осталось:\n");
						for (int j = data-> time [i - 1]; j >= 0; j--)
						{
							printf("  %d сек. \n", j);
							sleep(1);
						}
							i--;
					} while (i > 0);
				} else if (type == 2) 
						{
							for (int k = 0; k < data -> size; k++)  
							{
								printf ("Выполнение задачи ""%s"" ,Time = %d\n", data-> name [k], data->time [k] );
								printf ("  Осталось:\n");
								for (int j = data-> time [k]; j >= 0; j--)
								{
									printf("  %d сек. \n", j);
									sleep(1);
								}
								i--;
							} 
						}
			}
				void peek (Data *data, int type) 
		{
			if (data -> size == 0 )
			{
				if (type == 1)	
				{	
					printf ("cтек пуст\n");
				} else if (type == 2)	
					{
						printf ("oчередь пуста\n");
					}
			} else if (type == 1)
				{
					printf("Name =%s ,Time = %d\n", data-> name [data -> size - 1], data->time [data -> size - 1] );
				} else if (type == 2)
					{
						printf("Name =%s ,Time = %d\n", data-> name [0], data->time [0] );
					}
		}
			void push (Data *data, int time_task,  char name_task [MAX_Size_name], int type) 
		{
			if (data->size >= MAX_Size_data) 
			{
				if (type == 1)	
				{	
					printf ("cтек переполнен\n");
				} else 
					{
						printf ("oчередь переполнена\n");
					}
			} else
				{
					data -> time [data -> size] = time_task;
					strcpy (data-> name [data -> size],name_task); 
					data -> size++;
				}
			printf ("текущий размер  = %d,  свободно %d\n", data -> size, MAX_Size_data - data -> size);
			sleep (1);
		}
			void pop (Data *data, int type) 
		{
			if (data -> size == 0) 
			{
				if (type == 1)	
				{	
					printf ("стек пуст\n");
				} else if (type == 2)	
					{
						printf ("очередь пуста\n");
					}
			} else if (type == 1)
				{
				data -> size--;
				} else if (type == 2)
					{
					int i = 0;
					for ( ; i <= data -> size ; i++)
						{
						data -> time [i] = data -> time [i+1];
						strcpy (data-> name [i], data -> name [i+1]);		
						}
					data -> size--;
					}
			printf ("размер данных = %d,  свободно %d\n", data -> size, MAX_Size_data - data -> size);
			sleep (1);
		}
				void print_main_menu ()
		{
			system ("clear"); 
			printf ("тип данных\n");
			printf ("1 - стек\n    2 - очередь\n    3 - выход\n\nВыберите пункт меню: ");
		}
			void print_menu ()
		{
			system ("clear"); 
			printf ("    Менеджер задач\n");
			printf ("    1 - Добавить задачу\n    2 - Удалить задачу\n    3 - Посмотреть головной элемент\n    4 - Выполнить задачи\n    5 - Выход\n\nВыберите пункт меню: ");
		}
			int get_number (int total)
		{ 
			int number;
		    char str[100];
		    scanf("%s", str); 
		    while (sscanf(str, "%d", &number) != 1 || number < 1 || number > total) 
			{
		        printf("Некорректный ввод! Попробуйте еще: "); 
		        scanf("%s", str); 
			}
			return number;
		}
