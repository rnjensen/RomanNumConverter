# RomanNumConverter
Converts Roman numerals to modern numbers and vice versa

Time spent on project: ~3h 15m

Run with the .exe file or compile .cpp file and run executable

Notes:
The rules for converting Roman numerals were found on the site http://sierra.nmsu.edu/morandi/coursematerials/RomanNumerals.html save for one modification that M can be repeated more than 3 times in order to increase the max number able to be displayed.
Also due to lack of character options the following rule was excluded:
"To represent larger numbers, a bar over a numeral means to multiply the number by 1000. For example, D represents 1000 x 500 = 500,000 and M represents 1000 x 1000 = 1,000,000, one million."

The following improvements could be implemented but have not been due to time constraints (school and work tend to keep me rather busy) as well as the current functionality fulfilling the prompt to sufficient requirements.
To Improve:
Rules:
Improve rules to remove ambiguity for example both IXX and XIX can represent 19, adding rules to remove that ambiguity would be ideal
Add lower case characters to represent the 'barred' characters from the excluded rule (see Notes)
UI:
clean up user input (i.e. when input is separated by spaces I II, both answers are output to console separated by new line 1, 2)
Create a user friendly input device such as a calculater GUI (possibly even adding basic mathmatic functions like adding or subtracting roman numerals)
Allow for file reading (for cases when whole files full of roman numerals need to be converted)
