#include "log_timestamp.h"

short __log_ptr = 1;

char *get_time_stamp()
{
    char stamp[12];
    struct timeval tv;
    static char _gtime[20];
    gettimeofday(&tv, NULL);
    strftime(stamp, 20, "%p %I.%M.%S", localtime(&tv.tv_sec));
    sprintf(_gtime, "%s.%06ld", stamp, tv.tv_usec);
    return _gtime;
}
