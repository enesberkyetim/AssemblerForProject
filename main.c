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

        int instruction_bin[20];
        char instruction_hex[5];

        int i = 0;

        while (line[i] != ' ') {
            opcode_str[i] = line[i];
            i++;
        }

        opcode_str[i] = '\0';
        i++;

        if (strcmp(opcode_str, "ADD") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 0;
            instruction_bin[3] = 0;

            char src1[2] = {'\0', '\0'};
            char src2[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            int src1_reg = 0;
            int src2_reg = 0;
            int dest_reg = 0;

            i++;

            int j = 0;

            while (line[i] != ',') {
                src1[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (src1[1] == '\0') {
                src1_reg = src1[0] - 48;
            }
            else {
                src1_reg = 10 * (src1[0] - 48) + src1[1] - 48;
            }


            i = i + 2;

            while (line[i] != ',') {
                src2[j] = line[i];
                j++;
                i++;
            }

            j = 0;


            if (src2[1] == '\0') {
                src2_reg = src2[0] - 48;
            }
            else {
                src2_reg = 10 * (src2[0] - 48) + src2[1] - 48;
            }

            i = i + 2;

            while ((line[i] != '\0') && (line[i] != '\n')) {
                dest[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (dest[1] == '\0') {
                dest_reg = dest[0] - 48;
            }
            else {
                dest_reg = 10 * (dest[0] - 48) + dest[1] - 48;
            }


            instruction_bin[12] = 0;

            instruction_bin[13] = 0;
            instruction_bin[14] = 0;
            instruction_bin[15] = 0;

            i = 0;
            j = 0;

            for (i = 7; i > 3; i--) {
                int result = src1_reg % 2;
                src1_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 11; i > 7; i--) {
                int result = src2_reg % 2;
                src2_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 19; i > 15; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 0; i < 20; i++) {
                printf("%d", instruction_bin[i]);
            }

            printf("\n");
        }
        else if (strcmp(opcode_str, "ADDI") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 0;
            instruction_bin[3] = 0;

            instruction_bin[12] = 1;


            printf("ADDI\n");
        }
        else if (strcmp(opcode_str, "NAND") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 0;
            instruction_bin[3] = 1;

            char src1[2] = {'\0', '\0'};
            char src2[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            int src1_reg = 0;
            int src2_reg = 0;
            int dest_reg = 0;

            i++;

            int j = 0;

            while (line[i] != ',') {
                src1[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (src1[1] == '\0') {
                src1_reg = src1[0] - 48;
            }
            else {
                src1_reg = 10 * (src1[0] - 48) + src1[1] - 48;
            }


            i = i + 2;

            while (line[i] != ',') {
                src2[j] = line[i];
                j++;
                i++;
            }

            j = 0;


            if (src2[1] == '\0') {
                src2_reg = src2[0] - 48;
            }
            else {
                src2_reg = 10 * (src2[0] - 48) + src2[1] - 48;
            }

            i = i + 2;

            while ((line[i] != '\0') && (line[i] != '\n')) {
                dest[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (dest[1] == '\0') {
                dest_reg = dest[0] - 48;
            }
            else {
                dest_reg = 10 * (dest[0] - 48) + dest[1] - 48;
            }


            instruction_bin[12] = 0;

            instruction_bin[13] = 0;
            instruction_bin[14] = 0;
            instruction_bin[15] = 0;

            i = 0;
            j = 0;

            for (i = 7; i > 3; i--) {
                int result = src1_reg % 2;
                src1_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 11; i > 7; i--) {
                int result = src2_reg % 2;
                src2_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 19; i > 15; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 0; i < 20; i++) {
                printf("%d", instruction_bin[i]);
            }

            printf("\n");
        }
        else if (strcmp(opcode_str, "NANDI") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 0;
            instruction_bin[3] = 1;

            instruction_bin[12] = 1;
            printf("NANDI\n");
        }
        else if (strcmp(opcode_str, "OR") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 1;
            instruction_bin[3] = 0;

            char src1[2] = {'\0', '\0'};
            char src2[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            int src1_reg = 0;
            int src2_reg = 0;
            int dest_reg = 0;

            i++;

            int j = 0;

            while (line[i] != ',') {
                src1[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (src1[1] == '\0') {
                src1_reg = src1[0] - 48;
            }
            else {
                src1_reg = 10 * (src1[0] - 48) + src1[1] - 48;
            }


            i = i + 2;

            while (line[i] != ',') {
                src2[j] = line[i];
                j++;
                i++;
            }

            j = 0;


            if (src2[1] == '\0') {
                src2_reg = src2[0] - 48;
            }
            else {
                src2_reg = 10 * (src2[0] - 48) + src2[1] - 48;
            }

            i = i + 2;

            while ((line[i] != '\0') && (line[i] != '\n')) {
                dest[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (dest[1] == '\0') {
                dest_reg = dest[0] - 48;
            }
            else {
                dest_reg = 10 * (dest[0] - 48) + dest[1] - 48;
            }


            instruction_bin[12] = 0;

            instruction_bin[13] = 0;
            instruction_bin[14] = 0;
            instruction_bin[15] = 0;

            i = 0;
            j = 0;

            for (i = 7; i > 3; i--) {
                int result = src1_reg % 2;
                src1_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 11; i > 7; i--) {
                int result = src2_reg % 2;
                src2_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 19; i > 15; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 0; i < 20; i++) {
                printf("%d", instruction_bin[i]);
            }

            printf("\n");;
        }
        else if (strcmp(opcode_str, "ORI") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 1;
            instruction_bin[3] = 0;

            instruction_bin[12] = 1;
            printf("ORI\n");
        }
        else if (strcmp(opcode_str, "SUB") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 1;
            instruction_bin[3] = 1;

            char src1[2] = {'\0', '\0'};
            char src2[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            int src1_reg = 0;
            int src2_reg = 0;
            int dest_reg = 0;

            i++;

            int j = 0;

            while (line[i] != ',') {
                src1[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (src1[1] == '\0') {
                src1_reg = src1[0] - 48;
            }
            else {
                src1_reg = 10 * (src1[0] - 48) + src1[1] - 48;
            }


            i = i + 2;

            while (line[i] != ',') {
                src2[j] = line[i];
                j++;
                i++;
            }

            j = 0;


            if (src2[1] == '\0') {
                src2_reg = src2[0] - 48;
            }
            else {
                src2_reg = 10 * (src2[0] - 48) + src2[1] - 48;
            }

            i = i + 2;

            while ((line[i] != '\0') && (line[i] != '\n')) {
                dest[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (dest[1] == '\0') {
                dest_reg = dest[0] - 48;
            }
            else {
                dest_reg = 10 * (dest[0] - 48) + dest[1] - 48;
            }


            instruction_bin[12] = 0;

            instruction_bin[13] = 0;
            instruction_bin[14] = 0;
            instruction_bin[15] = 0;

            i = 0;
            j = 0;

            for (i = 7; i > 3; i--) {
                int result = src1_reg % 2;
                src1_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 11; i > 7; i--) {
                int result = src2_reg % 2;
                src2_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 19; i > 15; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 0; i < 20; i++) {
                printf("%d", instruction_bin[i]);
            }

            printf("\n");
        }
        else if (strcmp(opcode_str, "SUBI") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 0;
            instruction_bin[2] = 1;
            instruction_bin[3] = 1;

            instruction_bin[12] = 1;
            printf("SUBI\n");
        }
        else if (strcmp(opcode_str, "SLL") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 1;
            instruction_bin[2] = 0;
            instruction_bin[3] = 0;

            char src1[2] = {'\0', '\0'};
            char src2[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            int src1_reg = 0;
            int src2_reg = 0;
            int dest_reg = 0;

            i++;

            int j = 0;

            while (line[i] != ',') {
                src1[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (src1[1] == '\0') {
                src1_reg = src1[0] - 48;
            }
            else {
                src1_reg = 10 * (src1[0] - 48) + src1[1] - 48;
            }


            i = i + 2;

            while (line[i] != ',') {
                src2[j] = line[i];
                j++;
                i++;
            }

            j = 0;


            if (src2[1] == '\0') {
                src2_reg = src2[0] - 48;
            }
            else {
                src2_reg = 10 * (src2[0] - 48) + src2[1] - 48;
            }

            i = i + 2;

            while ((line[i] != '\0') && (line[i] != '\n')) {
                dest[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (dest[1] == '\0') {
                dest_reg = dest[0] - 48;
            }
            else {
                dest_reg = 10 * (dest[0] - 48) + dest[1] - 48;
            }


            instruction_bin[12] = 0;

            instruction_bin[13] = 0;
            instruction_bin[14] = 0;
            instruction_bin[15] = 0;

            i = 0;
            j = 0;

            for (i = 7; i > 3; i--) {
                int result = src1_reg % 2;
                src1_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 11; i > 7; i--) {
                int result = src2_reg % 2;
                src2_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 19; i > 15; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 0; i < 20; i++) {
                printf("%d", instruction_bin[i]);
            }

            printf("\n");
        }
        else if (strcmp(opcode_str, "SLLI") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 1;
            instruction_bin[2] = 0;
            instruction_bin[3] = 0;

            instruction_bin[12] = 1;
            printf("SLLI\n");
        }
        else if (strcmp(opcode_str, "LD") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 1;
            instruction_bin[2] = 0;
            instruction_bin[3] = 1;

            printf("LD\n");
        }
        else if (strcmp(opcode_str, "ST") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 1;
            instruction_bin[2] = 1;
            instruction_bin[3] = 0;

            printf("ST\n");
        }
        else if (strcmp(opcode_str, "JUMP") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 1;
            instruction_bin[2] = 1;
            instruction_bin[3] = 1;

            printf("JUMP\n");
        }
        else if (strcmp(opcode_str, "BEQ") == 0) {
            instruction_bin[0] = 1;
            instruction_bin[1] = 0;
            instruction_bin[2] = 0;
            instruction_bin[3] = 0;

            printf("BEQ\n");
        }
        else if (strcmp(opcode_str, "BLT") == 0) {
            instruction_bin[0] = 1;
            instruction_bin[1] = 0;
            instruction_bin[2] = 0;
            instruction_bin[3] = 1;


            printf("BLT\n");
        }
        else if (strcmp(opcode_str, "BGT") == 0) {
            instruction_bin[0] = 1;
            instruction_bin[1] = 0;
            instruction_bin[2] = 1;
            instruction_bin[3] = 0;

            printf("BGT\n");
        }
        else if (strcmp(opcode_str, "BLE") == 0) {
            instruction_bin[0] = 1;
            instruction_bin[1] = 1;
            instruction_bin[2] = 0;
            instruction_bin[3] = 0;

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
