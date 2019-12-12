#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdlib.h>
 
#include "thinklmi.h"
 
void get_vars(int fd)
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
void clr_vars(int fd)
{
        perror("query_apps ioctl clr");
}
void set_vars(int fd)
{
    query_arg_t q;
 
 
        perror("query_apps ioctl set");
}
 
int main(int argc, char *argv[])
{
    char *file_name = "/dev/thinklmi";
    int fd;
    enum
    {
        e_get,
        e_set
    } option;

    if (argc == 1)
    {
        option = e_get;
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "getsettings") == 0)
        {
            option = e_get;
        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            option = e_set;
        }
        else
        {
            fprintf(stderr, "Usage: %s [-g | -s]\n", argv[0]);
            return 1;
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
        case e_get:
            get_vars(fd);
            break;
        case e_set:
            set_vars(fd);
            break;
        default:
            break;
    }
 
    close (fd);
 
    return 0;
} 
