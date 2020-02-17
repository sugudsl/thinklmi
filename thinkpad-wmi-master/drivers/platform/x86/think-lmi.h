/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef _THINK_LMI_H_
#define _THINK_LMI_H_

#include <linux/ioctl.h>

#define TLMI_SETTINGS_MAXCNT 15
#define TLMI_SETTINGS_MAXLEN 35

#define GETSET_STRING_SIZE 0xFF

typedef struct
{
	char settings[TLMI_SETTINGS_MAXCNT][TLMI_SETTINGS_MAXLEN];
	int  settings_count;
	int  count;
} tlmi_query_arg_t;

#define THINKLMI_GET_SETTINGS _IOR('q', 1, tlmi_query_arg_t *)
#define THINKLMI_GET_SETTINGS_STRINGS _IOWR('s', 2, tlmi_query_arg_t *)
#define THINKLMI_SET_SETTING _IOW('t', 1, char *)
#define THINKLMI_SHOW_SETTING _IOWR('u',1, char *)
#define THINKLMI_AUTHENTICATE _IOW('v',1, char *)

#endif /* !_THINK_LMI_H_ */

