#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
/*This functions reads the table containng the directory tree and prints it 
on the console.*/
int Read_from_Tree()
{
	struct Tree_Table
	{
		int did;//Directory ID.
		int pdid;//Parent directory ID.
		char *name[50]
	}

	FILE* fd;
	int i;
	//Opening the file containing the directory tree for reading.
	if(fd=fopen(Tree.txt,"r")==-1)
	{
		perror("fopen");
		return 1;
	}
	for (i=0;i<10;i++)
	{
		fscanf(fd," %s %d %d",&name,&did,&pdid);
		printf("%s\t%d\t%d\n",name,did,pdid);
	}
	return 0;
}
