#include <stdio.h>
#include <string.h>
#include "symbolTable.h"

Symbol table[1000];
int symbol_count = 0;

void addEntry(char *symbol, int address) {
    strcpy(table[symbol_count].name, symbol);
    table[symbol_count].address = address;
    symbol_count++;
}

int contains(char *symbol) {
    for(int i = 0; i < symbol_count; i++) {
        if(strcmp(table[i].name, symbol) == 0) {
            return 1;
        }
    }
    return 0;
}

int getAddress(char *symbol) {
    for(int i = 0; i < symbol_count; i++) {
        if(strcmp(table[i].name, symbol) == 0) {
            return table[i].address;
        }
    }
    return -1;
}

void initSymbolTable() {
    addEntry("SP", 0);
    addEntry("LCL", 1);
    addEntry("ARG", 2);
    addEntry("THIS", 3);
    addEntry("THAT", 4);

    // R0 から R15 までの汎用レジスタ（0〜15番地）
    addEntry("R0", 0);
    addEntry("R1", 1);
    addEntry("R2", 2);
    addEntry("R3", 3);
    addEntry("R4", 4);
    addEntry("R5", 5);
    addEntry("R6", 6);
    addEntry("R7", 7);
    addEntry("R8", 8);
    addEntry("R9", 9);
    addEntry("R10", 10);
    addEntry("R11", 11);
    addEntry("R12", 12);
    addEntry("R13", 13);
    addEntry("R14", 14);
    addEntry("R15", 15);

    // I/Oポインタ
    addEntry("SCREEN", 16384);
    addEntry("KBD", 24576);
}