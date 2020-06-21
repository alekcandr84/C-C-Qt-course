  #include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <string.h>                      
		void create_file (FILE* name_fp, int N); 
	int random_number (int min, int max); кс
	int find_ch (FILE* name_fp, char ch); 
		int main()
	{
		FILE *fp;
		fp = fopen ("File.txt", "w+");
		if ((fp = fopen ("File.txt", "w+")) == NULL)
			{
				printf("Файл не создан\n");
			}
		int n = 0;
		char ch_use;	
		printf ("Введите общее количество символов в создаваемом файле и cимвол для поиска:");
		scanf ("%d %c", &n, &ch_use); 
		create_file (fp, n);
		fseek (fp,0,SEEK_SET);//   установка каретки в начало
		printf ("Частота использования '%c' = %d\n", ch_use, find_ch (fp, ch_use));
	    fclose (fp);
	    return 0;
	}
		void create_file (FILE* name_fp, int N)
	{
		int i = 1;
		while (i <= N)
			{
				srand (time(NULL)+i);
				fprintf (name_fp, "%c", (char) random_number(65,127));
				++i;
			}
		printf ("Файл заполнен\n");
	}
		int random_number (int min, int max)
	{
		int rand_num;	
		rand_num = min + rand()%(max - min + 1);
		return rand_num;
	}
		int find_ch (FILE* name_fp, char ch)
	{
		//int i = 0;
		char ch_f = '0';
		int N_ch = 0; 
			    do 
		    {
		    	//printf ("karetka: %d",ftell (name_fp));
		    	//i++;
		    	ch_f = fgetc (name_fp);
		    	if (ch_f == ch) 
		    	{ 
		    	    N_ch++;
		  	    }	
		  	    //printf ("i:%d\nN:%d\n""char:%c\n", i, N_ch, ch_f);
		    }
		    while (ch_f != EOF ); 
				return N_ch;
		}
