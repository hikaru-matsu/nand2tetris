#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "code.h"
#include "parser.h"
#include "symbolTable.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char *data = NULL;
    int count = 0, c;
    int i = 0, j = 0;
    if(argc < 2) {
        printf("Usage: ./assembler <filename.asm>\n");
        exit(1);
    }

    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error!\n");
        exit(1);
    }

    while((c = fgetc(file)) != EOF) {
        data = (char*)realloc(data, sizeof(char) * (count + 1));
        data[count] = c;
        count++;
    }
    data = (char*)realloc(data, sizeof(char) * (count + 1));
    data[count] = '\0';
    fclose(file);
    
    int in_comment = 0;

    while(data[i] !='\0') {
        if(data[i] == '/' && data[i + 1] == '/') {
            in_comment = 1;
        } else if(data[i] == '\n') {
            in_comment = 0;
            data[j] = data[i];
            j++;
        }else if(in_comment == 0 && data[i] != ' ' && data[i] != '\r' ) {
            data[j] = data[i];
            j++;
        }
        i++;
    }
    data[j] = '\0';
    
    int rom_address = 0;

    char *pass1_data = strdup(data);
    char *pass1_line = strtok(pass1_data, "\n");

    while(pass1_line != NULL) {
        int type = getCommandType(pass1_line);
        if(type == 0 || type == 1) {
            rom_address++;
        } else if(type == 2) {
            char *label_name=symbol(pass1_line);
            addEntry(label_name, rom_address);
        }
        pass1_line = strtok(NULL, "\n");
    }
    free(pass1_data);

    int ram_address = 16;
    char *line = strtok(data, "\n");

    while(line != NULL) {
        CommandType type = getCommandType(line);

        if(type == A_COMMAND) {
            char *val_str = symbol(line);
            int value;

            if(isdigit(val_str[0])) {
                value = atoi(val_str);
            } else {
                if(contains(val_str)) {
                    value = getAddress(val_str);
                } else {
                    addEntry(val_str, ram_address);
                    value = ram_address;
                    ram_address++;
                } 
            }

            char binary[17];

            for(int k = 0; k <= 15; k++) {
                int shift = 15 - k;
                if((value >> shift) & 1) {
                    binary[k] = '1';
                } else {
                    binary[k] = '0';
                }
            }
            binary[16] = '\0';
            printf("%s\n", binary);
        } else if(type == C_COMMAND) {
            CParts parts = parseCCommand(line);
            printf("111%s%s%s\n", 
                   getComp(parts.comp), 
                   getDest(parts.dest), 
                   getJump(parts.jump));
        } else if(type == L_COMMAND) {

        }
        line = strtok(NULL, "\n");
    }

    free(data);
    return 0;
}