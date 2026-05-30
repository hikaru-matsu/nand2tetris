#include <stdio.h>
#include <string.h>
#include "parser.h"

CommandType getCommandType(char *line) {
    if(line == NULL || strlen(line) == 0) {
        return UNKNOWN;
    } else if(line[0] == '@') {
        return A_COMMAND;
    } else if(line[0] == '(') {
        return L_COMMAND;
    } else {
        return C_COMMAND;
    }
}

char *symbol(char *line) {
    char *end_paren = strchr(line, ')');
    if(end_paren != NULL) {
        *end_paren = '\0';
    }
    return &line[1];
}

CParts parseCCommand(char *line) {
    CParts parts;
    parts.dest = NULL;
    parts.comp = NULL;
    parts.jump = NULL;

    char *eq_ptr = strchr(line, '=');
    char *semi_ptr = strchr(line, ';');

    if(semi_ptr != NULL) {
        *semi_ptr = '\0';
        parts.jump = semi_ptr + 1;
    } 
    if(eq_ptr != NULL) {
        *eq_ptr = '\0';
        parts.dest = line;
        parts.comp = eq_ptr + 1;
    } else {
        parts.comp = line;
    }
    return parts;
}