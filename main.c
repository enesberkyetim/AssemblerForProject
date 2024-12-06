#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
    FILE *input_file = fopen("input.txt", "r+");
    FILE *output_file = fopen("output.txt", "w+");

    fprintf(output_file,"v2.0 raw\n");

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

        if ((strcmp(opcode_str, "ADD") && strcmp(opcode_str, "NAND") && strcmp(opcode_str, "OR") && strcmp(opcode_str, "SUB") && strcmp(opcode_str, "SLL")) == 0) {
            if (strcmp(opcode_str, "ADD") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 0;
                instruction_bin[3] = 0;
            }
            else if (strcmp(opcode_str, "NAND") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 0;
                instruction_bin[3] = 1;
            }
            else if (strcmp(opcode_str, "OR") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 1;
                instruction_bin[3] = 0;
            }
            else if (strcmp(opcode_str, "SUB") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 1;
                instruction_bin[3] = 1;
            }
            else if (strcmp(opcode_str, "SLL") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 1;
                instruction_bin[2] = 0;
                instruction_bin[3] = 0;
            }


            char src1[2] = {'\0', '\0'};
            char src2[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            int src1_reg = 0;
            int src2_reg = 0;
            int dest_reg = 0;

            i++;

            int j = 0;

            while (line[i] != ',') {
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


            i = i + 2;

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

            while (line[i] != '\n' && line[i] != EOF && line[i] != '\0') {
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

            //for (i = 0; i < 20; i++) {
            //printf("%d", instruction_bin[i]);
            //}


        }
        else if ((strcmp(opcode_str, "ADDI") && strcmp(opcode_str, "NANDI") && strcmp(opcode_str, "ORI") && strcmp(opcode_str, "SUBI") && strcmp(opcode_str, "SLLI")) == 0) { // Data Selçuk bu kısmı dolduracak

             if (strcmp(opcode_str, "ADDI") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 0;
                instruction_bin[3] = 0;
            }
            else if (strcmp(opcode_str, "NANDI") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 0;
                instruction_bin[3] = 1;
            }
            else if (strcmp(opcode_str, "ORI") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 1;
                instruction_bin[3] = 0;
            }
            else if (strcmp(opcode_str, "SUBI") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 0;
                instruction_bin[2] = 1;
                instruction_bin[3] = 1;
            }
            else if (strcmp(opcode_str, "SLLI") == 0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 1;
                instruction_bin[2] = 0;
                instruction_bin[3] = 0;
            }

            instruction_bin[12] = 1;
            char src[2] = {'\0', '\0'};
            char dest[2] = {'\0', '\0'};
            char imm[4] = {'\0', '\0','\0', '\0'};
            int dest_reg = 0;
            int src_reg = 0;
            i++;
            int j = 0;

            while (line[i] != ',') {
                dest[j] = line[i];
                i++;
                j++;
            }

            j = 0;

            if (dest[1] == '\0') {
                dest_reg = dest[0] - 48;
            }
            else {
                dest_reg = 10 * (dest[0] - 48) + dest[1] - 48;
            }

            i+=2;

            while (line[i] != ',') {
                src[j] = line[i];
                i++;
                j++;
            }

            j = 0;

            if (src[1] == '\0') {
                src_reg = src[0] - 48;
            }
            else {
                src_reg = 10 * (src[0] - 48) + src[1] - 48;
            }

            i++;
            j= 0;

            while (line[i] != '\n' && line[i] != EOF && line[i] != '\0') {
                imm[j] = line[i];
                i++;
                j++;
            }

            if (imm[0] != '-') {
                j--;
            } else {
                j -= 2;
            }


            int count = 0;
            int k = 0;
            int integer_imm_p = 0;
            int integer_imm_n = 0;
            int integer_imm = 0;

            while (imm[k] != '\0') {
                if (imm[0] != '-') {
                    integer_imm_p += (imm[k] - 48) * pow(10, j);
                    k++;
                    j--;
                    integer_imm = integer_imm_p;
                } else {
                    integer_imm_n += ((imm[k + 1] - 48) * (int) (pow(10, j)));
                    k++;
                    j--;
                    integer_imm = integer_imm_n;
                }

            }

            if (integer_imm == integer_imm_p) {
                for (i = 19; i > 12; i--) {
                    int result = integer_imm % 2;
                    integer_imm /= 2;
                    instruction_bin[i] = result;
                }
            } else if (integer_imm == integer_imm_n) {
                int positive_binary[7];
                int p = 6;
                int j = 19;
                for (p = 6; p >= 0; p--) {
                    int pbit = integer_imm_n % 2;
                    integer_imm_n /= 2;
                    positive_binary[p] = pbit;
                }
                for (p = 6; p >= 0; p--) {
                    if (positive_binary[p] == 0) {
                        positive_binary[p] = 1;
                        continue;
                    }

                    if (positive_binary[p] == 1) {
                        positive_binary[p] = 0;
                        continue;
                    }

                }

                p = 6;
                while (positive_binary[p] != 0) {
                    positive_binary[p] = 0;
                    p--;
                }
                positive_binary[p] = 1;

                p = 6;
                for (j = 19; j > 12; j--) {
                    instruction_bin[j] = positive_binary[p];
                    p--;
                }
            }

            for (i = 7; i > 3; i--) {
                int result = src_reg % 2;
                src_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 11; i > 7; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            //for (i = 0; i < 20; i++) {
            //printf("%d", instruction_bin[i]);
            //}


        }
        else if (strcmp(opcode_str, "LD") == 0 || strcmp(opcode_str, "ST") == 0) {

            if (strcmp(opcode_str, "LD")==0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 1;
                instruction_bin[2] = 0;
                instruction_bin[3] = 1;
            } else if (strcmp(opcode_str, "ST")==0) {
                instruction_bin[0] = 0;
                instruction_bin[1] = 1;
                instruction_bin[2] = 1;
                instruction_bin[3] = 0;
            }


            char dest[2] = {'\0', '\0'};
            char address[4] = {'\0', '\0', '\0', '\0'};
            int dest_reg = 0;
            int integer_address = 0;

            i++;
            int j = 0;

            while (line[i] != ',') {
                dest[j] = line[i];
                i++;
                j++;
            }

            if (dest[1] == '\0') {
                dest_reg = dest[0];
            } else if (dest[1] != '\0') {
                dest_reg = dest[0] + 10 * dest[1];
            }

            j = 0;

            i++;

            while (line[i] != '\n' && line[i] != EOF && line[i] != '\0') {
                address[j] = line[i];
                i++;
                j++;
            }

            j--;
            int k = 0;
            while (address[k] != '\0') {
                integer_address += (address[k] - 48) * pow(10, j);
                k++;
                j--;
            }

            for (i = 7; i > 3; i--) {
                int result = dest_reg % 2;
                dest_reg /= 2;
                instruction_bin[i] = result;
            }

            for (i = 19; i > 7; i--) {
                int result = integer_address % 2;
                integer_address /= 2;
                instruction_bin[i] = result;
            }

            //for (i = 0; i < 20; i++) {
                //printf("%d", instruction_bin[i]);
            //}



        } else if (strcmp(opcode_str, "JUMP") == 0) {
            instruction_bin[0] = 0;
            instruction_bin[1] = 1;
            instruction_bin[2] = 1;
            instruction_bin[3] = 1;

            char address[6] = {'\0','\0','\0','\0','\0','\0'};
            int integer_address = 0;
            int integer_address_p = 0;
            int integer_address_n = 0;


            int j = 0;

            while (line[i] != '\n' && line[i] != EOF && line[i] != '\0') {
                address[j] = line[i];
                i++;
                j++;
            }

            if (address[0] != '-') {
                j--;
            } else {
                j -= 2;
            }
            int k = 0;
            while (address[k] != '\0') {
                if (address[0] != '-') {
                    integer_address_p += (address[k] - 48) * pow(10, j);
                    k++;
                    j--;
                    integer_address = integer_address_p;
                } else {
                    integer_address_n += ((address[k + 1] - 48) * (int) (pow(10, j)));
                    k++;
                    j--;
                    integer_address = integer_address_n;
                }

            }

            if (integer_address == integer_address_p) {
                for (i = 19; i > 3; i--) {
                    int result = integer_address_p % 2;
                    integer_address_p /= 2;
                    instruction_bin[i] = result;
                }
            } else if (integer_address == integer_address_n) {
                int positive_binary[16];
                int p = 15;
                int j = 19;
                for (p = 15; p >= 0; p--) {
                    int pbit = integer_address_n % 2;
                    integer_address_n /= 2;
                    positive_binary[p] = pbit;
                }
                for (p = 15; p >= 0; p--) {
                    if (positive_binary[p] == 0) {
                        positive_binary[p] = 1;
                        continue;
                    }

                    if (positive_binary[p] == 1) {
                        positive_binary[p] = 0;
                        continue;
                    }

                }

                p = 15;
                while (positive_binary[p] != 0) {
                    positive_binary[p] = 0;
                    p--;
                }
                positive_binary[p] = 1;

                p = 15;
                for (j = 19; j > 3; j--) {
                    instruction_bin[j] = positive_binary[p];
                    p--;
                }

            }

            //for (i = 0; i < 20; i++) {
            //printf("%d", instruction_bin[i]);
            //}


        }
        else if ((strcmp(opcode_str, "BEQ") == 0) || (strcmp(opcode_str, "BLT") == 0) || (strcmp(opcode_str, "BGT") == 0) || (strcmp(opcode_str, "BLE") == 0) || (strcmp(opcode_str, "BGE") == 0)) {
            if (strcmp(opcode_str, "BEQ") == 0) {
                instruction_bin[0] = 1;
                instruction_bin[1] = 0;
                instruction_bin[2] = 0;
                instruction_bin[3] = 0;
            } else if (strcmp(opcode_str, "BLT") == 0) {
                instruction_bin[0] = 1;
                instruction_bin[1] = 0;
                instruction_bin[2] = 0;
                instruction_bin[3] = 1;
            } else if (strcmp(opcode_str, "BGT") == 0) {
                instruction_bin[0] = 1;
                instruction_bin[1] = 0;
                instruction_bin[2] = 1;
                instruction_bin[3] = 0;
            } else if (strcmp(opcode_str, "BLE") == 0) {
                instruction_bin[0] = 1;
                instruction_bin[1] = 0;
                instruction_bin[2] = 1;
                instruction_bin[3] = 1;
            } else if (strcmp(opcode_str, "BGE") == 0) {
                instruction_bin[0] = 1;
                instruction_bin[1] = 1;
                instruction_bin[2] = 0;
                instruction_bin[3] = 0;
            }
            char op1[] = {'\0', '\0'};
            char op2[] = {'\0', '\0'};
            int op1_reg = 0;
            int op2_reg = 0;

            char address[5] = {'\0','\0','\0','\0','\0'};
            int integer_address = 0;
            int integer_address_p = 0;
            int integer_address_n = 0;

            i++;
            int j = 0;

            while (line[i] != ',') {
                op1[j] = line[i];
                j++;
                i++;
            }

            j = 0;

            if (op1[1] == '\0') {
                op1_reg = op1[0] - 48;
            } else {
                op1_reg = 10 * (op1[0] - 48) + op1[1] - 48;
            }

            i+= 2;
            j = 0;

            while (line[i] != ',') {
                op2[j] = line[i];
                j++;
                i++;
            }

            if (op2[1] == '\0') {
                op2_reg = op2[0] - 48;
            } else {
                op2_reg = 10 * (op2[0] - 48) + (op2[1] - 48);
            }

            i++;
            j = 0;

            while (line[i] != '\n' && line[i] != EOF && line[i] != '\0') {
                address[j] = line[i];
                i++;
                j++;
            }

            if (address[0] != '-') {
                j--;
            } else {
                j -= 2;
            }
            int k = 0;
            while (address[k] != '\0') {
                if (address[0] != '-') {
                    integer_address_p += (address[k] - 48) * pow(10, j);
                    k++;
                    j--;
                    integer_address = integer_address_p;
                }
                else {
                    integer_address_n += ((address[k + 1] - 48) * (int) (pow(10, j)));
                    k++;
                    j--;
                    integer_address = integer_address_n;
                }
            }

            if (integer_address == integer_address_p) {
                for (i = 19; i > 11; i--) {
                    int result = integer_address_p % 2;
                    integer_address_p /= 2;
                    instruction_bin[i] = result;
                }

            } else if (integer_address == integer_address_n) {
                int positive_binary[8];
                int p = 7;
                int j = 19;
                for (p = 7; p >= 0; p--) {
                    int pbit = integer_address_n % 2;
                    integer_address_n /= 2;
                    positive_binary[p] = pbit;
                }
                for (p = 7; p >= 0; p--) {
                    if (positive_binary[p] == 0) {
                        positive_binary[p] = 1;
                        continue;
                    }

                    if (positive_binary[p] == 1) {
                        positive_binary[p] = 0;
                        continue;
                    }

                }

                p = 7;
                while (positive_binary[p] != 0) {
                    positive_binary[p] = 0;
                    p--;
                }
                positive_binary[p] = 1;

                p = 7;
                for (j = 19; j > 11; j--) {
                    instruction_bin[j] = positive_binary[p];
                    p--;
                }

            }


            for (i = 7; i > 3; i--) {
                int result = op1_reg % 2;
                op1_reg /= 2;
                instruction_bin[i] = result;
            }
            for (i = 11; i > 7; i--) {
                int result = op2_reg % 2;
                op2_reg /= 2;
                instruction_bin[i] = result;
            }


            //for (i = 0; i < 20; i++) {
            //printf("%d", instruction_bin[i]);
            //}


        }

        int cur_hex[4] = {0, 0, 0, 0};

        for (i = 0; i < 20; i++) {

            if (i % 4 == 3) {
                cur_hex[i % 4] = instruction_bin[i];
                int hex_num = 0;
                for (int j = 3; j >= 0; j--) {
                    hex_num += (cur_hex[j]) * pow(2, (3 - j));
                }

                if (hex_num < 10) {
                    fprintf(output_file, "%d", hex_num);
                }
                else {
                    switch (hex_num) {
                        case 10:
                            fprintf(output_file,"a");
                        break;
                        case 11:
                            fprintf(output_file,"b");
                        break;
                        case 12:
                            fprintf(output_file,"c");
                        break;
                        case 13:
                            fprintf(output_file,"d");
                        break;
                        case 14:
                            fprintf(output_file,"e");
                        break;
                        case 15:
                            fprintf(output_file,"f");
                        break;
                    }
                }

                cur_hex[0] = 0;
                cur_hex[1] = 0;
                cur_hex[2] = 0;
                cur_hex[3] = 0;
                hex_num = 0;
            }
            else {
                cur_hex[i % 4] = instruction_bin[i];
            }
        }

        fprintf(output_file, " ");

        for (int j = 0; j < 5; j++) {
            opcode_str[j] = '\0';
        }

    }
    return 0;
}
