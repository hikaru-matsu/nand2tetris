#include <stdio.h>
#include <string.h>
#include "code.h"

const char* getDest(char *dest) {
    if(dest != NULL) {
        if(strcmp(dest, "M") == 0) {
            return "001";
        } else if(strcmp(dest, "D") == 0) {
            return "010";
        } else if(strcmp(dest, "MD") == 0) {
            return "011";
        } else if(strcmp(dest, "A") == 0) {
            return "100";
        } else if(strcmp(dest, "AM") == 0) {
            return "101";
        } else if(strcmp(dest, "AD") == 0) {
            return "110";
        } else {
            return "111";
        }
    }
    return "000";
}

const char* getComp(char *comp) {
    if(comp != NULL) {
        if(strcmp(comp, "0") == 0) {
            return "0101010";
        } else if(strcmp(comp, "1") == 0) {
            return "0111111";
        } else if(strcmp(comp, "-1") == 0) {
            return "0111010";
        } else if(strcmp(comp, "D") == 0) {
            return "0001100";
        } else if(strcmp(comp, "A") == 0) {
            return "0110000";
        } else if(strcmp(comp, "M") == 0) {
            return "1110000";
        } else if(strcmp(comp, "!D") == 0) {
            return "0001101";
        } else if(strcmp(comp, "!A") == 0) {
            return "1110001";
        } else if(strcmp(comp, "!M") == 0) {
            return "1110001";
        } else if(strcmp(comp, "-D") == 0) {
            return "0001111";
        } else if(strcmp(comp, "-A") == 0) {
            return "0110011";
        } else if(strcmp(comp, "-M") == 0) {
            return "1110011";
        } else if(strcmp(comp, "D+1") == 0) {
            return "0011111";
        } else if(strcmp(comp, "A+1") == 0) {
            return "0110111";
        } else if(strcmp(comp, "M+1") == 0) {
            return "1110111";
        } else if(strcmp(comp, "D-1") == 0) {
            return "0001110";
        } else if(strcmp(comp, "A-1") == 0) {
            return "0110010";
        } else if(strcmp(comp, "M-1") == 0) {
            return "1110010";
        } else if(strcmp(comp, "D+A") == 0) {
            return "0000010";
        } else if(strcmp(comp, "D+M") == 0) {
            return "1000010";
        } else if(strcmp(comp, "D-A") == 0) {
            return "0010011";
        } else if(strcmp(comp, "D-M") == 0) {
            return "1010011";
        } else if(strcmp(comp, "A-D") == 0) {
            return "0000111";
        } else if(strcmp(comp, "M-D") == 0) {
            return "1000111";
        } else if(strcmp(comp, "D&A") == 0) {
            return "0000000";
        } else if(strcmp(comp, "D&M") == 0) {
            return "1000000";
        }
    }
    return "0000000";
}

const char* getJump(char *jump) {
    if(jump != NULL) {
        if(strcmp(jump, "JGT") == 0) {
            return "001";
        } else if(strcmp(jump, "JEQ") == 0) {
            return "010";
        } else if(strcmp(jump, "JGE") == 0) {
            return "011";
        } else if(strcmp(jump, "JLT") == 0) {
            return "100";
        } else if(strcmp(jump, "JNE") == 0) {
            return "101";
        } else if(strcmp(jump, "JLE") == 0) {
            return "110";
        } else {
            return "111";
        }
    }
    return "000";
}