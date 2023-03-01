// CIS 4634 Assignment 02 (DES).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Matrices {
public:
    const int IP[64] = { 58, 50, 42, 34, 26, 18, 10, 2,  60, 52, 44,
    36, 28, 20, 12, 4,  62, 54, 46, 38, 30, 22,
    14, 6,  64, 56, 48, 40, 32, 24, 16, 8,  57,
    49, 41, 33, 25, 17, 9,  1,  59, 51, 43, 35,
    27, 19, 11, 3,  61, 53, 45, 37, 29, 21, 13,
    5,  63, 55, 47, 39, 31, 23, 15, 7 };

    const int IP_1[64] = { 40, 8,  48, 16, 56, 24, 64, 32, 39, 7,  47,
    15, 55, 23, 63, 31, 38, 6,  46, 14, 54, 22,
    62, 30, 37, 5,  45, 13, 53, 21, 61, 29, 36,
    4,  44, 12, 52, 20, 60, 28, 35, 3,  43, 11,
    51, 19, 59, 27, 34, 2,  42, 10, 50, 18, 58,
    26, 33, 1,  41, 9,  49, 17, 57, 25 };

    const int PC_1[56] = { 57, 49, 41, 33, 25, 17, 9,  1,  58, 50,
    42, 34, 26, 18, 10, 2,  59, 51, 43, 35,
    27, 19, 11, 3,  60, 52, 44, 36, 63, 55,
    47, 39, 31, 23, 15, 7,  62, 54, 46, 38,
    30, 22, 14, 6,  61, 53, 45, 37, 29, 21,
    13, 5,  28, 20, 12, 4 };

    const int PC_2[48] = { 14, 17, 11, 24, 1,  5,  3,  28, 15, 6,
    21, 10, 23, 19, 12, 4,  26, 8,  16, 7,
    27, 20, 13, 2,  41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32 };

    const int EXP[48] = { 32, 1,  2,  3,  4,  5,  4,  5,  6,  7,
    8,  9,  8,  9,  10, 11, 12, 13, 12, 13,
    14, 15, 16, 17, 16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32, 1 };

    const int PERM[32] = { 16, 7, 20, 21, 29, 12, 28, 17, 1,  15, 23,
    26, 5, 18, 31, 10, 2,  8,  24, 14, 32, 27,
    3,  9, 19, 13, 30, 6,  22, 11, 4,  25 };

    const int S_BOX[8][64] = { 
                { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6,
                    12, 5, 9, 0, 7,
                  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12,
                    11, 9, 5, 3, 8,
                  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,
                    3, 10, 5, 0,
                  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14,
                    10, 0, 6, 13 },

                { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13,
                    12, 0, 5, 10,
                  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10,
                    6, 9, 11, 5,
                  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6,
                    9, 3, 2, 15,
                  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12,
                    0, 5, 14, 9 },

                { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7,
                    11, 4, 2, 8,
                  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14,
                    12, 11, 15, 1,
                  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,
                    5, 10, 14, 7,
                  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3,
                    11, 5, 2, 12 },

                { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5,
                    11, 12, 4, 15,
                  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12,
                    1, 10, 14, 9,
                  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3,
                    14, 5, 2, 8, 4,
                  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11,
                    12, 7, 2, 14 },

                { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15,
                    13, 0, 14, 9,
                  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15,
                    10, 3, 9, 8, 6,
                  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5,
                    6, 3, 0, 14,
                  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9,
                    10, 4, 5, 3 },

                { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4,
                    14, 7, 5, 11,
                  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14,
                    0, 11, 3, 8,
                  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10,
                    1, 13, 11, 6,
                  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7,
                    6, 0, 8, 13 },

                { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7,
                    5, 10, 6, 1,
                  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12,
                    2, 15, 8, 6,
                  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6,
                    8, 0, 5, 9, 2,
                  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15,
                    14, 2, 3, 12 },

                { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14,
                    5, 0, 12, 7,
                  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11,
                    0, 14, 9, 2,
                  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13,
                    15, 3, 5, 8,
                  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0,
                    3, 5, 6, 11 } 
                };

    Matrices() = default;
    ~Matrices() = default;
    
};

void init_perm(const int IP[], int IP_vals[], int binary[]) {
    for (int i = 0; i < 64; i++) {
        int cell_val = IP[i];
        int bin_val = binary[cell_val - 1];
        IP_vals[i] = bin_val;
    }
}

void init_lr_split(int ip_vals[], int l[], int r[]) {
    for (int i = 0; i < 32; i++) {
        l[i] = ip_vals[i];
        r[i] = ip_vals[32 + i];
    }
}

void pc_1_transform(const int pc_1[], int bin_k_64[], int bin_k_56[]) {
    for (int i = 0; i < 56; i++) {
        bin_k_56[i] = bin_k_64[pc_1[i] - 1];
    }
}

void init_cd_split(int bin_k_56[], int c[], int d[]) {
    for (int i = 0; i < 28; i++) {
        c[i] = bin_k_56[i];
        d[i] = bin_k_56[28 + i];
    }
}

void rotate_1(int c[], int d[]) {
    int drop_c = c[0];
    int drop_d = d[0];

    for (int i = 0; i < 27; i++) {
        c[i] = c[i + 1];
        d[i] = d[i + 1];
    }

    c[27] = drop_c;
    d[27] = drop_d;
}

void rotate_2(int c[], int d[]) {
    rotate_1(c, d);
    rotate_1(c, d);
}

void cd_combine(int c[], int d[], int bin_k_56[]) {
    for (int i = 0; i < 28; i++) {
        bin_k_56[i] = c[i];
        bin_k_56[28 + i] = d[i];
    }
}

void pc_2_transform(const int pc_2[], int bin_k_56[], int subk[][48], int idx) {
    for (int i = 0; i < 48; i++) {
        subk[idx][i] = bin_k_56[pc_2[i] - 1];
    }
}

void f_func_expansion(const int exp[], int r[], int r_exp[]) {
    int num = 0;
    int idx = 0;

    for (int i = 0; i < 32; i++) {
        num = i + 1;

        for (int j = 0; j < 48; j++) {
            if (exp[j] == num) {
                idx = j;
                r_exp[idx] = r[i];
            }
        }
    }
}

// arr2 overwritten with result
void bit_xor(int arr1[], int arr2[], int len) {
    for (int i = 0; i < len; i++) {
        if (arr1[i] == arr2[i]) {
            arr2[i] = 0;
        }
        else {
            arr2[i] = 1;
        }
    }
}

void init_s_split(int r[], int s_bits[][6]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            s_bits[i][j] = r[(i * 6) + j];
        }
    }
}

int binary_to_dec(int binary[], int bin_len) {
    int dec = 0;

    for (int i = 0; i < bin_len; i++) {
        dec += binary[i] * int(pow(2, (bin_len - 1 - i)));
    }

    return dec;
}

void dec_to_binary(int dec, int binary[]) {
    int r;
    int q;
    //int init_dec = dec;
    int binary_rev[4] = { 0 };

    for (int i = 0; i < 4; i++) {
        //if (init_dec < 8) {
        //    init_dec = 100;
        //    binary_rev[0] = 0;
        //    continue;
        //}
        r = dec % 2;
        q = dec / 2;    // int division

        binary_rev[i] = r;
        dec = q;
    }

    int end = 3;
    for (int i = 0; i < 4; i++) {
        binary[i] = binary_rev[end];
        end--;
    }
}

void s_box_transform(const int s_box[][64], int s_bits_6[][6], int s_bits_4[][4]) {
    for (int i = 0; i < 8; i++) {
        int row_arr[2] = { s_bits_6[i][0], s_bits_6[i][5] };
        int col_arr[4] = { s_bits_6[i][1], s_bits_6[i][2], s_bits_6[i][3], s_bits_6[i][4] };

        int row = binary_to_dec(row_arr, 2);
        int col = binary_to_dec(col_arr, 4);

        int cell_num = (row * 16) + col;
        int cell_content = s_box[i][cell_num];

        dec_to_binary(cell_content, s_bits_4[i]);
    }
}

void f_func_perm(const int perm[], int s_bit_4[][4], int s_perm[]) {
    int s_4_combined[32] = { 0 };
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            s_4_combined[(i * 4) + j] = s_bit_4[i][j];
        }
    }

    for (int i = 0; i < 32; i++) {
        int cell_val = perm[i];
        int bin_val = s_4_combined[cell_val - 1];
        s_perm[i] = bin_val;
    }
}

void f_func(const int exp[], const int perm[], const int s_box[][64], int r[], int subk[], int s_perm[]) {
    int r_exp[48] = { 0 };
    f_func_expansion(exp, r, r_exp);
    cout << "r_exp: ";
    for (int i = 0; i < 48; i++) {
        cout << r_exp[i];
    }
    cout << endl;

    bit_xor(subk, r_exp, 48);
    cout << "r_xor: ";
    for (int i = 0; i < 48; i++) {
        cout << r_exp[i];
    }
    cout << endl << endl;

    int init_s_bits[8][6] = { 0 };
    init_s_split(r_exp, init_s_bits);
    cout << "s_bits: " << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            cout << init_s_bits[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    int s_bits_4[8][4] = { 0 };
    s_box_transform(s_box, init_s_bits, s_bits_4);
    cout << "s_bits transform: " << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            cout << s_bits_4[i][j];
        }
        cout << endl;
    }
    cout << endl;

    f_func_perm(perm, s_bits_4, s_perm);
    cout << "s_perm: ";
    for (int i = 0; i < 32; i++) {
        cout << s_perm[i];
    }
    cout << endl;
}

void lr_combine(int l[], int r[], int comb[]) {
    for (int i = 0; i < 32; i++) {
        comb[i] = r[i];
        comb[32 + i] = l[i];
    }
}

void inv_perm(const int IP_1[], int ip_vals[], int binary[]) {
    for (int i = 0; i < 64; i++) {
        int cell_val = IP_1[i];
        int bin_val = binary[cell_val - 1];
        ip_vals[i] = bin_val;
    }
}

// Converts hexadecimal to binary
void hex_to_binary(string hex, int binary[]) {
    string num;
    //int len = hex.length();
    int binary_rev[64];
    int num_split;
    int r;
    int q;

    for (int i = 0; i < 16; i++) {
        //cout << hex[i];
        num = hex[i];
        //cout << num;

        // convert letters to ints via ascii
        if (num == "A" || num ==  "B" || num ==  "C" || num ==  "D" || num ==  "E" || num ==  "F" ) {
            num_split = int(hex[i] - 65 + 10);
            cout << "entered split";
        }
        else {
            num_split = hex[i] - '0';
        }

        cout << "num split " << num_split << endl;

        for (int j = 0; j < 4; j++) {
            r = num_split % 2;
            q = num_split / 2;

            binary_rev[(4 * i) + j] = r;
            num_split = q;
        }

        int end = (4 * i) + 3;
        for (int k = (4 * i); k < (4 * i) + 4; k++) {
            binary[k] = binary_rev[end];
            end--;
        }

    }
}

string binary_to_hex(int binary[]) {
    string hex = "";
    int bin_group[16][4] = { 0 };

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            bin_group[i][j] = binary[(i * 4) + j];
        }
    }

    for (int i = 0; i < 16; i++) {
        int num = binary_to_dec(bin_group[i], 4);

        if (num > 9) {
            num = num - 10 + 65;
            char num_hex = char(num);
            hex += num_hex;
        }
        else {
            hex += to_string(num);
        }
    }
    cout << "cipher " << hex;
    return hex;
}

void key_reverse(int keys[][48], int rev_keys[][48]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 48; j++) {
            rev_keys[15 - i][j] = keys[i][j];
        }
    }
}

int main()
{
    Matrices mtx;
    string input = "123456ABCD132536";
    string key = "AABB09182736CCDD";

    // conv key, input to binary
    int binary_key[64] = { 0 };
    hex_to_binary(key, binary_key);

    int binary_input[64] = { 0 };
    hex_to_binary(input, binary_input);

    cout << "bin key 64: ";
    for (int i = 0; i < 64; i++) {
        cout << binary_key[i];
    }
    cout << endl << endl;

    // initial permutation
    int ip_vals[64] = { 0 };
    init_perm(mtx.IP, ip_vals, binary_input);
    cout << "ip vals: ";
    for (int i = 0; i < 64; i++) {
        cout << ip_vals[i];
    }
    cout << endl;

    // initial L/R split
    int l_split[32] = { 0 };
    int r_split[32] = { 0 };
    init_lr_split(ip_vals, l_split, r_split);
    cout << "l split: ";
    for (int i = 0; i < 32; i++) {
        cout << l_split[i];
    }
    cout << endl;
    cout << "r split: ";
    for (int i = 0; i < 32; i++) {
        cout << r_split[i];
    }
    cout << endl << endl;

    // initial PC-1
    int binary_key_56[56] = { 0 };
    pc_1_transform(mtx.PC_1, binary_key, binary_key_56);
    cout << "bin key 56: ";
    for (int i = 0; i < 56; i++) {
        cout << binary_key_56[i];
    }
    cout << endl;

    // initial C/D split
    int c_split[28] = { 0 };
    int d_split[28] = { 0 };
    init_cd_split(binary_key_56, c_split, d_split);
    cout << "c split: ";
    for (int i = 0; i < 28; i++) {
        cout << c_split[i];
    }
    cout << endl;
    cout << "d split: ";
    for (int i = 0; i < 28; i++) {
        cout << d_split[i];
    }
    cout << endl << endl;;

    // rest of C/D splits => subkey generation
    int subkeys[16][48] = { 0 };
    for (int i = 0; i < 16; i++) {
        // 1-bit rotation
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            rotate_1(c_split, d_split);
        }
        // 2-bit rotation
        else {
            rotate_2(c_split, d_split);
        }

        // combine for new binary_key_56
        cd_combine(c_split, d_split, binary_key_56);

        // generate subkeys
        pc_2_transform(mtx.PC_2, binary_key_56, subkeys, i);
    }
    cout << "subkeys" << endl;
    for (int i = 0; i < 16; i++) {
        cout << i << ": ";
        for (int j = 0; j < 48; j++) {
            cout << subkeys[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // middle L/R splits => f function
    int s_perm[32] = { 0 };
    //int l_xor[32] = { 0 };
    // fills L1, R1 to L16, R16
    // L0, R0 filled in init_lr_split
    for (int i = 0; i < 16; i++) {   // FIXME change < 1 to < 16
        f_func(mtx.EXP, mtx.PERM, mtx.S_BOX, r_split, subkeys[i], s_perm);
        bit_xor(l_split, s_perm, 32);
        for (int j = 0; j < 32; j++) {
            l_split[j] = r_split[j];
            r_split[j] = s_perm[j];
        }
    }

    //IP^-1
    int final_perm[64] = { 0 };
    lr_combine(l_split, r_split, final_perm);

    int ciphertext_bin[64] = { 0 };
    inv_perm(mtx.IP_1, ciphertext_bin, final_perm);
    cout << "ciphertext bin " << endl;
    for (int i = 0; i < 64; i++) {
        cout << ciphertext_bin[i];
    }
    cout << endl;

    string ciphertext = binary_to_hex(ciphertext_bin);

    /********************** decrypt **********************/
    int rev_keys[16][48] = { 0 };
    key_reverse(subkeys, rev_keys);
    
    // initial permutation
    //ip_vals[64] = { 0 };
    init_perm(mtx.IP, ip_vals, ciphertext_bin);
    cout << "ip vals: ";
    for (int i = 0; i < 64; i++) {
        cout << ip_vals[i];
    }
    cout << endl;

    // initial L/R split
    //l_split[32] = { 0 };
    //r_split[32] = { 0 };
    init_lr_split(ip_vals, l_split, r_split);
    cout << "l split: ";
    for (int i = 0; i < 32; i++) {
        cout << l_split[i];
    }
    cout << endl;
    cout << "r split: ";
    for (int i = 0; i < 32; i++) {
        cout << r_split[i];
    }
    cout << endl << endl;

    // initial PC-1
    //binary_key_56[56] = { 0 };
    //pc_1_transform(mtx.PC_1, binary_key, binary_key_56);
    //cout << "bin key 56: ";
    //for (int i = 0; i < 56; i++) {
    //    cout << binary_key_56[i];
    //}
    //cout << endl;

    //// initial C/D split
    ////c_split[28] = { 0 };
    ////d_split[28] = { 0 };
    //init_cd_split(binary_key_56, c_split, d_split);
    //cout << "c split: ";
    //for (int i = 0; i < 28; i++) {
    //    cout << c_split[i];
    //}
    //cout << endl;
    //cout << "d split: ";
    //for (int i = 0; i < 28; i++) {
    //    cout << d_split[i];
    //}
    //cout << endl << endl;;

    //// rest of C/D splits
    ////int subkeys[16][48] = { 0 };
    //for (int i = 0; i < 16; i++) {
    //    // 1-bit rotation
    //    if (i == 0 || i == 1 || i == 8 || i == 15) {
    //        rotate_1(c_split, d_split);
    //    }
    //    // 2-bit rotation
    //    else {
    //        rotate_2(c_split, d_split);
    //    }

    //    // combine for new binary_key_56
    //    cd_combine(c_split, d_split, binary_key_56);

    //    // generate subkeys
    //    //pc_2_transform(mtx.PC_2, binary_key_56, subkeys, i);
    //}

    // middle L/R splits => f function
    //s_perm[32] = { 0 };
    //int l_xor[32] = { 0 };
    // fills L1, R1 to L16, R16
    // L0, R0 filled in init_lr_split
    for (int i = 0; i < 16; i++) {   // FIXME change < 1 to < 16
        f_func(mtx.EXP, mtx.PERM, mtx.S_BOX, r_split, rev_keys[i], s_perm);
        bit_xor(l_split, s_perm, 32);
        for (int j = 0; j < 32; j++) {
            l_split[j] = r_split[j];
            r_split[j] = s_perm[j];
        }
    }

    //IP^-1
    //final_perm[64] = { 0 };
    lr_combine(l_split, r_split, final_perm);

    int decoded_bin[64] = { 0 };
    inv_perm(mtx.IP_1, decoded_bin, final_perm);
    cout << "decoded bin " << endl;
    for (int i = 0; i < 64; i++) {
        cout << decoded_bin[i];
    }
    cout << endl;

    string decoded = binary_to_hex(decoded_bin);
}
