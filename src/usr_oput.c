/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   usr_oput.c                                            -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <hazyazttv@gmail.com>                    *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/04 16:31:57 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/05 00:33:05 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "usr_oput.h"

//short animation just for fun and delaying
void	waiter(int time)
{
	int	index;

	index = 0;
	while (index < time)
	{
		sleep(1);
		write(1, ".", 1);
		index++;
	}
	write(1, "\033[0m", 4);
	return ;
}

//display error code, free the user input, abort prog
void	error_manager(char *error_code, char *to_free)
{
	free(to_free);
	system("clear");
	write(2, "\e[0;31;47mOops! something went poorly...\n", 41);
	write(2, "\e[0;31;47mFor more information please see\n", 42);
	write(2, " the dedicated section in doc/readme.md\n", 40);
	write(2, " with the given error code...\n", 30);
	write(2, "Error code : ", 14);
	write(2, error_code, 4);
	write(2, "\e[0;m\n\nNow aborting program ", 28);
	write(2, "before anything more happens...\n\n", 33);
	abort();
}
