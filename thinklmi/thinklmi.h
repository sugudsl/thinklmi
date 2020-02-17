#include <linux/ioctl.h>

#define MAXCOUNT 15
#define MAXLEN 35

#define GETSET_STRING_SIZE 0xFF
 
typedef struct
{
    char  settings[MAXCOUNT][MAXLEN];
    int settings_count;
    int count;
} query_arg_t;
 
#define THINKLMI_GET_SETTINGS _IOR('q', 1, query_arg_t *)
#define THINKLMI_GET_SETTINGS_STRINGS _IOWR('s', 2, query_arg_t *)
#define THINKLMI_SET_SETTING _IOW('t', 1, char *)
#define THINKLMI_SHOW_SETTING _IOWR('u',1, char *)
#define THINKLMI_AUTHENTICATE _IOW('v',1, char *)


