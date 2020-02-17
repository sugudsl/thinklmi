#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdlib.h>
 
#include "thinklmi.h"
 
void get_settings_all(int fd)
{
    query_arg_t q;
    int i, count;

    q.count =0;

    if (ioctl(fd, THINKLMI_GET_SETTINGS, &q) == -1)
    {
        perror("query_apps ioctl get");
    }
    else
    {
	for(count=0;count<q.settings_count;count+=MAXCOUNT)
	{
                q.count = count; 
                if (ioctl(fd, THINKLMI_GET_SETTINGS_STRINGS, &q) == -1)
                {
                   perror("query_apps ioctl get");
                }
		else
		{
			for(i=0;i<MAXCOUNT;i++)
			{
				printf("%s\n", q.settings[i]);
			}
		}

	}


    }
   
}


void thinklmi_get(int fd, char * argv2)
{
	char get_string[MAXLEN + MAXCOUNT];
        strcpy(get_string, argv2);
	if(ioctl(fd, THINKLMI_SHOW_SETTING, &get_string) == -1)
	{
	   perror(" ioctl set_ setting failed");
	}

	else
	{
           printf("%s\n", get_string);

	}
}

void thinklmi_set(int fd, char * argv2, char* argv3)
{
	char setting_string[MAXLEN + MAXCOUNT];
        strcpy(setting_string, argv2);
	strcat(setting_string, ",");
	strncat(setting_string, argv3, strlen(argv3));

	strcat(setting_string, ";");

	if(ioctl(fd, THINKLMI_SET_SETTING, &setting_string) == -1)
	{
	   perror(" ioctl set_ setting failed");
	}


}
void thinklmi_authenticate(int fd, char *argv2, char *argv3, char *argv4 )
{
	char setting_string[MAXLEN + MAXCOUNT];
	strcpy(setting_string, argv2);
	strcat(setting_string,"\n");
	strcat(setting_string,argv3);
	strcat(setting_string,"\n");
	strcat(setting_string,argv4);
	strcat(setting_string,"\n");

        if(ioctl(fd, THINKLMI_AUTHENTICATE, &setting_string) == -1)
	{
		printf("ioctl authenticate failed\n");
	}

}
 
int main(int argc, char *argv[])
{
    char *file_name = "/dev/thinklmi";
    int fd;
    enum
    {
	get_settings,
	get,
	set,
	authenticate
    } option;

    if (argc == 1)
    {
        printf(" thinklmi --help\n");
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "getsettings") == 0)
        {
            option = get_settings;
        }
        else
        {
            fprintf(stderr, "Usage: %s [-g | -s]\n", argv[0]);
            return 1;
        }

        

    }
    else if (argc == 3)
    {

        if (strcmp(argv[1], "-g") == 0)
	{
	   option = get;
        }
	else
	{
	   fprintf(stderr, "Usage: not correct\n");	
	}
        	
    }
    else if (argc == 4)
    {
	if (strcmp(argv[1], "-s") == 0)    
        {
	    option = set;
	    printf("%s %s \n", argv[2], argv[3]);
        }
        else
	{
	   fprintf(stderr, "Usage: not correct\n");	
	}


    }
    else if (argc == 5)
    {
	if (strcmp(argv[1], "-p") == 0)
	{
	    option = authenticate;

	}
	else
	{
	   fprintf(stderr, "Usage: not correct\n");
	}
    }
    else
    {
        fprintf(stderr, "Usage: %s [-g | -s]\n", argv[0]);
        return 1;
    }
    fd = open(file_name, O_RDWR);
    if (fd == -1)
    {
        perror("query_apps open");
        return 2;
    }
 
    switch (option)
    {
        case get_settings:
            get_settings_all(fd);
            break;
	case get:
	    thinklmi_get(fd, argv[2]);
	    break;
        case set:
            thinklmi_set(fd, argv[2], argv[3]);
            break;
	case authenticate:
	    thinklmi_authenticate(fd, argv[2], argv[3],argv[4]);
	    break;
        default:
            break;
    }
 
    close (fd);
 
    return 0;
} 
