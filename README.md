# smart-buffering
*C project for getting buffer's size from user input, parsing special characters to be accurate.*

## QUICK HOW TO USE

This programm understand octal characters in the \000 form, hexadecimals charaters in the \x00 form and specials non-printable in the form \n

There are five error codes you can encounter:
(if so while using normally i'm so sorry, don't hesistate to tell me how it happens)

## ERROR CODES MEANING

-**MFMI** ==> "Malloc Failed Making Input" means that the malloc used for creating the buffer storing your input failed... Responsible function is "char \*input_init(void)" in src/main.c.<br>
-**MFMO** ==> "Malloc Failed Making Output" means that the malloc used for creating the buffer storing the text containing the size you wanted to know failed... Responsible function is "char \*buffer_text(void)" in src/main.c.<br>
-**ESCP** ==> "Empty String Can't be Parse"... Well you entered in a dev's bar and asked for "" didn't you?Next time try typing before pressing enter!<br>
-**CPNU** ==> "Can't Parse Non-printables Uncoded" if you want to enter a non printable or extended ascii (especially whitespaces) please do it with '\' followed by corresponding ascii code formated.<br>
-**WHNI** ==> "Wrong Hex(adecimal) Number Input" ==> The programm detected an hexadecimal number input (starting by \x) but that doesn't correspond to hexadecimal writing (if you type a letter that come after f in the alphabet).

## AFTERWORDS

I made this for me and don't think anyone else will use it to be honest...<br>
So if you downloaded it, thank you, hope it serves you well, don't hesitate to send me feedbacks or if you find issues (but in civilised way FFS) and stay hazy~<br>
-Hazy_Az
