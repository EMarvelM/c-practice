#include "main.h"

int _strlen(char *next_tok)
{
    int tok_len = 0;
    while(next_tok[tok_len] != '\0')
    {
        tok_len++;
    }

    /* Testing */
    /* printf("Token of %s = %d", next_tok, tok_len); */

    return (tok_len);
}