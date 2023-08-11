#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings up to n bytes.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes from s2 to concatenate.
 *
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *result;
    unsigned int len1 = 0, len2 = 0, i, j;

    // Handle NULL strings
    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    // Calculate the lengths of s1 and s2
    while (s1[len1])
        len1++;
    while (s2[len2])
        len2++;

    // Allocate memory for the concatenated string
    result = malloc(len1 + n + 1);
    if (result == NULL)
        return NULL;

    // Copy s1 into result
    for (i = 0; i < len1; i++)
        result[i] = s1[i];

    // Concatenate up to n bytes of s2 into result
    for (j = 0; j < n && s2[j]; j++)
        result[i++] = s2[j];

    // Null-terminate the result
    result[i] = '\0';

    return result;
}

int main()
{
    char *s1 = "Hello, ";
    char *s2 = "World!";
    unsigned int n = 5;

    char *concatenated = string_nconcat(s1, s2, n);
    if (concatenated != NULL) {
        printf("Concatenated string: %s\n", concatenated);
        free(concatenated);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}}
