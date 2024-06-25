#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_OPERATION_SIZE 100
#define INITIAL_WORD_SIZE 10

char buffer[MAX_OPERATION_SIZE];
char **words;
size_t word_count = 0;

int is_number(const char *str)
{
    for (size_t i = 0; i < strlen(str); ++i)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

void print_words(char **words, size_t word_count)
{
    for (size_t i = 0; i < word_count; ++i)
    {
        printf("Word %zu is '%s'.\n", i, words[i]);
    }
}

int sum(const char *word1, const char *word2)
{
    return atoi(word1) + atoi(word2);
}

int subtract(const char *word1, const char *word2)
{
    return atoi(word1) - atoi(word2);
}

int multiply(const char *word1, const char *word2)
{
    return atoi(word1) * atoi(word2);
}

int divide(const char *word1, const char *word2)
{
    int denominator = atoi(word2);
    if (denominator == 0)
    {
        printf("Error: division by zero\n");
        return -1;
    }
    else
    {
        return atoi(word1) / denominator;
    }
}

int format_checker(char *buffer)
{
    const char delimiters[] = " \t\r\n\v\f";
    char *token = strtok(buffer, delimiters);
    int state = 0;

    while (token != NULL)
    {
        if (state == 0 || state == 2)
        {
            if (!is_number(token))
            {
                return 0;
            }
            state++;
        }
        else if (state == 1)
        {
            if (!(strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0))
            {
                return 0;
            }
            state++;
        }
        token = strtok(NULL, delimiters);
    }

    return (state == 3);
}

void perform_operation(char **words, size_t word_count)
{
    for (size_t i = 0; i < word_count; ++i)
    {
        if (strcmp(words[i], "+") == 0)
        {
            printf("Operation is addition, the result is %d\n", sum(words[i - 1], words[i + 1]));
        }
        else if (strcmp(words[i], "-") == 0)
        {
            printf("Operation is subtraction, the result is %d\n", subtract(words[i - 1], words[i + 1]));
        }
        else if (strcmp(words[i], "*") == 0)
        {
            printf("Operation is multiplication, the result is %d\n", multiply(words[i - 1], words[i + 1]));
        }
        else if (strcmp(words[i], "/") == 0)
        {
            printf("Operation is division, the result is %d\n", divide(words[i - 1], words[i + 1]));
        }
    }
}

void divide_string_into_words(char *buffer)
{
    const char delimiters[] = " \t\r\n\v\f";
    size_t word_capacity = INITIAL_WORD_SIZE;

    words = malloc(word_capacity * sizeof(char *));
    if (words == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    char *token = strtok(buffer, delimiters);
    while (token != NULL)
    {
        if (word_count >= word_capacity)
        {
            word_capacity *= 2;
            words = realloc(words, word_capacity * sizeof(char *));
            if (words == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
        }

        words[word_count] = malloc((strlen(token) + 1) * sizeof(char));
        if (words[word_count] == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, delimiters);
    }

    perform_operation(words, word_count);
}

void handle_input()
{
    while (1)
    {
        printf("Input an operation using the following format "
               "NUMBER 'OP' NUMBER"
               ": \n");
        if (fgets(buffer, MAX_OPERATION_SIZE, stdin) == NULL)
        {
            fprintf(stderr, "Error reading input\n");
            exit(1);
        }

        char buffer_copy[MAX_OPERATION_SIZE];
        strncpy(buffer_copy, buffer, MAX_OPERATION_SIZE);

        if (!format_checker(buffer_copy))
        {
            fprintf(stderr, "Error: Invalid format. Please use the format \"NUMBER 'OP' NUMBER\".\n");
        } else{
            break;
        }
    }

    divide_string_into_words(buffer);
}

void free_words(char **words, size_t word_count)
{
    for (size_t i = 0; i < word_count; i++)
    {
        free(words[i]);
    }
    free(words);
}

int main()
{
    handle_input();
    free_words(words, word_count);
    return 0;
}
