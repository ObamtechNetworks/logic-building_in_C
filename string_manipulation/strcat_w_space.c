#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * get_length - gets length of a string;
 * @str: the string to get its legnth;
 * Return: the total length of the string
 */
size_t get_length(char *str)
{
	int length = 0;

	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}
/**
 * strcat_space - a function that concatenates two string with space in-between
 * @s1: the first string
 * @s2: the second string
 * Return: the concatenated string
 */
char *strcat_space(char *s1, char *s2)
{
	int i = 0, j = 0, len1 = 0, len2 = 0;
	char *joined_str = NULL;
	/*edge cases*/
	if (s1 == NULL || s2 == NULL)
	{
		fprintf(stderr,"Error: NULL String");
		errno = EINVAL;
	}
	/*get length of s1 and that of s2*/
	len1 = get_length(s1);
	len2 = get_length(s2);
	/*edge case*/
	if (len1 == 0 || len2 == 0)
	{
		fprintf(stderr, "Error: empty string s1: %s s2: %s\n", s1, s2);
		errno = EINVAL;
	}
	/*alloc space for resultant concat str based on len of s1/s2 with 2bytes extra*/
	joined_str = malloc(sizeof(char) * (len1 + len2 + 2));
	/*MALLOC RETURN */
	if (joined_str == NULL)
	{
		fprintf(stderr, "Error Memory allocation failed\n");
		errno = ENOMEM;
		exit(EXIT_FAILURE);
	}
	/*copy contents of s1 to joined str*/
	for (; i < len1; i++)
		joined_str[i] = s1[i];
	/*add the space char to joined_str*/
	joined_str[i] = ' ';
	i++;/*move one step forward to add string 2*/
	/*add characters of s2 to output variable*/
	for (; j < len2; j++, i++)
		joined_str[i] = s2[j];
	joined_str[i] = '\0';/*add the NULL BYTE*/
	return (joined_str);/*remember to free joined string in the main function*/
}

int main(void)
{
	char s1[] = "HELLO";
	char s2[] = "WORLD";
	char add[] = "THERE IS NOTHING GOD CANNOT";
	char me[] = "DO! ULTIMATE TRUTH AND FACT!";
	char *concatenated = strcat_space(s1, s2);
	char *str_concat = strcat_space(add, me);
	char *not_empty = "NON EMPTY";
	char *empty_str = "";/*empty string*/
	char *empty = "";
	char *empty2 = "";
	char *one_empty_str = strcat_space(not_empty, empty_str);
	char *double_empty = strcat_space(empty, empty2);

	printf("%s\n", concatenated);
	printf("%s\n", str_concat);
	printf("%s\n", one_empty_str);
	printf("%s\n", double_empty);

	free(concatenated);
	free(str_concat);
	free(one_empty_str);
	free(double_empty);
	return (0);
}
