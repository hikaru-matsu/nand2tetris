#ifndef PARSER_H
#define PARSER_H

typedef enum {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND,
    UNKNOWN
} CommandType;

typedef struct {
    char *dest;
    char *comp;
    char *jump;
}CParts;

CommandType getCommandType(char *line);

char* symbol(char *line);

CParts parseCCommand(char *line);

#endif