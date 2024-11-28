#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
    FILE *input_file = fopen("input.txt", "r+");

    while (feof(input_file) == 0) {
        char line[100];
        fgets(line, 100, input_file);
        char opcode_str[6];

        int i = 0;

        while (line[i] != ' ') {
            opcode_str[i] = line[i];
            i++;
        }

        opcode_str[i] = '\0';
        i++;

        if (strcmp(opcode_str, "ADD") == 0) {
            printf("ADD\n");
        }
        else if (strcmp(opcode_str, "ADDI") == 0) {
            printf("ADDI\n");
        }
        else if (strcmp(opcode_str, "NAND") == 0) {
            printf("NAND\n");
        }
        else if (strcmp(opcode_str, "NANDI") == 0) {
            printf("NANDI\n");
        }
        else if (strcmp(opcode_str, "OR") == 0) {
            printf("OR\n");
        }
        else if (strcmp(opcode_str, "ORI") == 0) {
            printf("ORI\n");
        }
        else if (strcmp(opcode_str, "SUB") == 0) {
            printf("SUB\n");
        }
        else if (strcmp(opcode_str, "SUBI") == 0) {
            printf("SUBI\n");
        }
        else if (strcmp(opcode_str, "SLL") == 0) {
            printf("SLL\n");
        }
        else if (strcmp(opcode_str, "SLLI") == 0) {
            printf("SLLI\n");
        }
        else if (strcmp(opcode_str, "LD") == 0) {
            printf("LD\n");
        }
        else if (strcmp(opcode_str, "ST") == 0) {
            printf("ST\n");
        }
        else if (strcmp(opcode_str, "JUMP") == 0) {
            printf("JUMP\n");
        }
        else if (strcmp(opcode_str, "BEQ") == 0) {
            printf("BEQ\n");
        }
        else if (strcmp(opcode_str, "BLT") == 0) {
            printf("BLT\n");
        }
        else if (strcmp(opcode_str, "BGT") == 0) {
            printf("BGT\n");
        }
        else if (strcmp(opcode_str, "BLE") == 0) {
            printf("BLE\n");
        }
        else if (strcmp(opcode_str, "BNE") == 0) {
            printf("BNE\n");
        }

        for (int j = 0; j < 5; j++) {
            opcode_str[j] = '\0';
        }
    }
    return 0;
}
