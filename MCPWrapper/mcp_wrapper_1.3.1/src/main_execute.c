/* web: cmrr.umn.edu/~strupp/serial.html */

#include <stdio.h>  /* Standard input/output definition */
#include <string.h> /* String function definition */
#include <unistd.h> /* UNIX standard function definition */
#include <fcntl.h>  /* File control definitions */
#include <errno.h>  /* Error number definition */
#include <termios.h> /* POSIX terminal control definitions */

#include "mcp_wrapper.h"
#include "mcp/protocol.h"

mcp_wrapper_t *mcpw;

/*
 * open_port() -- Open Serial Port 1
 *
 * Returns the file descriptor on success or -1 on error
 * 
 */

int open_port(void)
{
    int fd; /*File descriptor for the port*/

    fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1)
    {
        /* could not open the port */
        perror("open_port: Unable to open serial port");
    }
    else
        fcntl(fd, F_SETFL, 0);

    return(fd);
}

int main()
{
    printf("Start opening port...\n");
    /*open_port();*/
    open_port();

    /*int ping = mcpw_ping(mcpw);
    printf("Ping:%i", ping);*/

    return 0;
}