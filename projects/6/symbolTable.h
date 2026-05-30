#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct {
    char name[100];
    int address;
} Symbol;

void addEntry(char *symbol, int address);

int contains(char *symbol);

int getAddress(char *symbol);

void initSymbolTable();

#endif