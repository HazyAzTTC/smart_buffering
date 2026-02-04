/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   process_str.c                                         -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <hazyazttv@gmail.com>                    *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/04 16:31:03 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/04 16:31:10 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "process_str.h"
#include "usr_oput.h"
#include "utilities.h"

//convert the str of an oct to corresponding char
char	oct_to_char(char *oct, int pos)
{
	char	result;
	int		decimal;

	decimal = 0;
	result = '\0';
	decimal += (oct[pos] - '0') * 64;
	decimal += (oct[pos + 1] - '0') * 8;
	decimal += oct[pos + 2] - '0';
	result += decimal;
	return (result);
}

//convert the str of an hex to corresponding char
char	hex_to_char(char *hex, int pos)
{
	char	result;
	int		decimal;
	int		index;

	decimal = 0;
	index = 0;
	result = '\0';
	while (index < 2)
	{
		if (hex[pos + index] > 47 && hex[pos + index] < 58)
			decimal += (hex[pos + index] - '0') * (16 - (15 * index));
		else if (hex[pos + index] > 64 && hex[pos + index] < 71)
			decimal += (hex[pos + index] - 'A' + 10) * (16 - (15 * index));
		else if (hex[index] > 96 && hex[pos + index] < 103)
			decimal += (hex[pos + index] - 'a' + 10) * (16 - (15 * index));
		else
			error_manager("WHNI", hex);
		++index;
	}
	result += decimal;
	return (result);
}

//convert the str of a special char to the special char
char	spe_to_char(char *spe, int pos)
{
	char	result;

	if (spe[pos] > 96 && spe[pos] < 122)
		result = '\n';
	else if (spe[pos] == '0')
		result = ' ';
	else
		result = spe[pos];
	return (result);
}

//parse what format use a special char in input
char	special_char(char *string, int *pos)
{
	char	result;

	result = '\0';
	if (string[1 + *pos] > 47 && string[1 + *pos] < 58)
	{
		result = oct_to_char(string, 1 + *pos);
		*pos += 4;
	}
	else if (string[1 + *pos] == 'x' || string[1 + *pos] == 'X')
	{
		result = hex_to_char(string, 2 + *pos);
		*pos += 4;
	}
	else
	{
		result = spe_to_char(string, 1 + *pos);
		*pos += 2;
	}
	return (result);
}

//detect and convert spe char to compact input
int	processing(char *input)
{
	char	adapted_input[255];
	int		index;
	int		target;

	index = 0;
	target = 0;
	while (input[index])
	{
		if (input[index] == '\\')
		{
			adapted_input[target] = special_char(input, &index);
			++target;
		}
		else
		{
			adapted_input[target] = input[index];
			++index;
			++target;
		}
	}
	free(input);
	adapted_input[target] = '\0';
	target = str_len(adapted_input);
	return (target);
}
