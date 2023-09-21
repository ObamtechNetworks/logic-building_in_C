#include <stdio.h>
/**
 * strcat_space - a function that concatenates two string with space in-between
 * @s1: the first string
 * @s2: the second string
 * Return: the concatenated string
 */
char *strcat_space(char *s1, char *s2)
{
	int i = 0, j = 0;
	char *ptr_s1, *ptr_s2; /*pointers to s1 and s2*/
	/*edge cases*/
	if (s1 == NULL)
		return (s2);
	else if (s2 == NULL)
		return (s1);
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (*s1 == '\0' && *s2 != '\0')
		return (s2);
	else if (*s1 != '\0' && *s2 == '\0')
		return (s1);

	ptr_s1 = s1;
	ptr_s2 = s2;
	/*get length of s1*/
	for (; ptr_s1[i] != '\0'; i++)
		;
	printf("%d\n", i);
	/*at position of length of s1 add space*/
	ptr_s1[i] = ' ';/*add space character*/
	i++;/*increment length for next character*/
	j = 0;
	/*loop to add s2 to s1*/
	while (ptr_s2[i] != '\0')
	{
		ptr_s1[i] = ptr_s2[j];
		i++;/*increment the length of i for s1*/
		j++;
	}
	return (ptr_s1);
}

int main(void)
{
	char s1[] = "HELLO";
	char s2[] = "WORLD";

	char add[] = "THERE IS NOTHING GOD CANNOT";
	char me[] = "DO! That's impossible!";
	char *concatenated = strcat_space(s1, s2);
	char *str_concat = strcat_space(add, me);

	printf("%s\n", concatenated);
	printf("%s\n", str_concat);

	return (0);
}
