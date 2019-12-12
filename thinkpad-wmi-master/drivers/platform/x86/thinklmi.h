#include <linux/ioctl.h>

#define MAXCOUNT 15
#define MAXLEN 35
 
typedef struct
{
    char  settings[MAXCOUNT][MAXLEN];
    int settings_count;
    int count;
} query_arg_t;
 
#define THINKLMI_GET_SETTINGS _IOR('q', 1, query_arg_t *)
#define THINKLMI_GET_SETTINGS_STRINGS _IOWR('s', 2, query_arg_t *)



