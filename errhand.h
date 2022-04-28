


#ifndef ERRHAND_H
#define ERRHAND_H 1

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "sunp.h"

int
error_handler_mssg_write(int fd, int errnum, const char *usrmssg);

int
error_handler_out(int errnum);
#endif /* ERRHAND_H */
