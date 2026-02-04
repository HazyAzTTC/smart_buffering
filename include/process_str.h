/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   process_str.h                                         -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <hazyazttv@gmail.com>                    *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/04 16:33:03 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/04 16:33:06 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_STR_H
# define PROCESS_STR_H

char	oct_to_char(char *oct, int pos);
char	hex_to_char(char *hex, int pos);
char	spe_to_char(char *spe, int pos);
char	special_char(char *string, int *pos);
int		processing(char *input);

#endif
