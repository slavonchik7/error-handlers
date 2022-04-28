
#include "errhand.h"



static char *usr_message;
static char *err_message;



static void
form_error_mssg();




int
error_handler_mssg_write(int fd, int errnum, const char *usrmssg) {

    const char *errno_mess = strerror(errnum);
    size_t em_buff_size = strlen(usrmssg) + strlen(errno_mess) + 100;
    char em_buff[em_buff_size + 1];
    bzero(em_buff, em_buff_size + 1);

    snprintf(em_buff, em_buff_size,
            "<Error>: \n\tErrnum:%d\n\tMessage: %s\n\tAdd-on message: %s\n",
            errno, errno_mess, usrmssg);
            printf("%d\n", (int)strlen(em_buff));

    if (writen(fd, em_buff, em_buff_size) < 0)
        return -1;

    return 0;
}

