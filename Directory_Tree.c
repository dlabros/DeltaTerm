#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
/*This function receives as arguments the name, ID and parent ID of a
directory and adds it to the directory tree.*/
int  Write_to__Tree(int argc,char* argv[])
{
	int i;
	char *control_name,*control_did[10],*control_pdid[10],*name[50];
	FILE *fd;

	//Open the file for appending and reading.
	if (fd=fopen("Tree.txt","a+")==-1)
	{
		perror("fopen");
		return 1;
	}

	if (!argc==3)
	{//Checking the nuber of arguments.
		printf("Wrong number of arguments. The required arguments are:\n");
		printf("Name of the directory,ID number of the directory and file ID number of the parent directory, in this particular order.\n");
		return 1;
	}

	sscanf(argv[0]," %c",&control_name);

	if (!isalpha(control_name)&&(control_name!='_'))
	{//Enforcing the restrictions for naming directories.
		printf("The name of the directory must begin with a letter or _ .\n");
		return 2;
	}

	if ((argv[1]>=10)||(argv[1]<0))
	{//Checking the validity of the directory ID.
		printf("The directory ID you have given exceeds the limits of CentOS.\n");
		printf("Valid  file descriptors  range from 0 to 1024.\n");
		return 3;
	}

	if ((argv[2]>=10)||(argv[2]<0))
    {//Checking the validity of the parent directory ID.
        printf("The directory ID you have given exceeds the limits of CentOS.\n");$
        printf("Valid  file descriptors  range from 0 to 1024.\n");
        return 3;
    }

	for (i=0;i<10;i++)
	{//Reading from file. The variable name remains unused here.
		fscanf(fd," %s %d %d",&name,&control_did,&control_pdid);

		if ((argv[1]==atoi(control_did))||(argv[i]==atoi(control_pdid)))
		{//Checking if the  given ID or parent ID already exists.
			printf("The ID you have given is already in use. Please choose another one.\n");
			return 4;
		}

		if ((argv[2]==atoi(control_did))||(argv[2]==atoi(control_pdid)))
		{
			printf("The parent ID you have given is already in use. Please choose another one.\n");
			return 4;
		}
	}
	//Writing the given directory parameters to the specidied file.
	fprintf(fd,"%s\t%s\t%s\n",argv[0],argv[1],argv[2]);
	fclose(fd);
	return 0;
}

