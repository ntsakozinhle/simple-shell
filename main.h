#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **argv);

/**
 * getline: a function that accepts user input as command
 * @lineptr: stores the addres of the buffer holding whatever is typed
 * @n: stores allocated size in bytes
 * @stream: source from which we want the function to get data from
 * Return: stdin
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
 * strtok: a function that breaks a string into a sequence of non-empty tokens
 * @str: the string to be tokenized
 * @delim: characters used to break the string into smaller chunks
 * Return: str tokens
 */
char *strtok(char *str, const char *delim);


#endif
