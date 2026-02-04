/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   utilities.c                                           -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <hazyazttv@gmail.com>                    *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/04 16:32:23 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/04 16:32:26 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//recoded strlen cause i didnt want to use string.h
int	str_len(char *string)
{
	int	index;

	index = 0;
	while (string[index])
		++index;
	return (index);
}

//simplified itoa for uInt until 999 cause i dont need more
void	itoa(int number, char *dest)
{
	int		index;
	int		div;
	int		time;

	time = 0;
	index = 3;
	div = 100;
	while (time < 3)
	{
		if ((number / div) != 0 || index != 3 || time == 2)
		{
			dest[3 - index] = '0' + (number / div);
			--index;
		}
		number = number % div;
		div = div / 10;
		++time;
	}
	while (index >= 0)
	{
		dest[3 - index] = '\0';
		index--;
	}
	return ;
}
