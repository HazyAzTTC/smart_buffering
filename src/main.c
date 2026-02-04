/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   main.c                                                -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <hazyazttv@gmail.com>                    *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/04 16:28:37 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/05 00:35:34 by hazy_az             .:-#=-+*==**+-..     */
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

//verify that the string end doesn't contain unwanted char
char	*verify_string(char *string, int index)
{
	while (string[index] < 32 || string[index] > 126)
	{
		string[index] = '\0';
		index--;
	}
	return (string);
}

//initialising input to 300 charand assuring it goes well
char	*input_init(void)
{
	char	*string;

	string = malloc(8 * 300);
	if (string == NULL)
		error_manager("MFMI", string);
	return (string);
}

//initialising the text of the size of buffer to 3 char
char	*buffer_text(void)
{
	char	*string;

	string = malloc(8 * 4);
	if (string == NULL)
		error_manager("MFMO", string);
	return (string);
}

//getting user input, send it to process, displaying result
int	main(void)
{
	char	*user_input;
	char	*buffer_size;
	int		size;

	write(1, "\033[1;36mPlease enter ", 21);
	write(1, "what you want in your buffer:\033[0m\n\n", 35);
	user_input = input_init();
	read(0, user_input, 299);
	if (user_input[0] == '\n')
		error_manager("ESCP", user_input);
	user_input = verify_string(user_input, str_len(user_input));
	if (user_input[0] == '\0')
		error_manager("CPNU", user_input);
	size = processing(user_input);
	buffer_size = buffer_text();
	itoa(size, buffer_size);
	write(1, "\n\033[1;34mProcessing this entry", 30);
	waiter(3);
	write(1, "\033[0m\033[2K\r", 9);
	write(1, "\033[0;95m==> Your buffer's size is \033[1;32m", 40);
	write(1, buffer_size, 3);
	free(buffer_size);
	write(1, "\033[0;95m !\033[0m\n", 14);
	return (0);
}
