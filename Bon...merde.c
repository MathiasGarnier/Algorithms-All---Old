#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define SIZE 4

void mat_print(int mat[SIZE][SIZE]) {

    for (unsigned int i = 0; i < SIZE; i++) {

        for (unsigned int j = 0; j < SIZE; j++) printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

int calc_coeff(int mat_1[SIZE][SIZE], int mat_2[SIZE][SIZE], unsigned int i, unsigned int j) {

    unsigned int res = 0;
    for (unsigned int k = 0; k < SIZE; k++) res += mat_1[i][k] * mat_2[k][j];

    return res;
}

int** mat_mul(int mat_1[SIZE][SIZE], int mat_2[SIZE][SIZE], int mat_12[SIZE][SIZE]) {

    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) mat_12[i][j] = calc_coeff(mat_1, mat_2, i, j);
    }

    return mat_12;
}

int** mat_mul_r(int mat_1[SIZE][SIZE], int mat_2[SIZE][SIZE]) {

    int mat_12[SIZE][SIZE];

    for (unsigned int i = 0; i < SIZE; i++) {

        for (unsigned int j = 0; j < SIZE; j++) mat_12[i][j] = calc_coeff(mat_1, mat_2, i, j);
    }

    mat_print(mat_12);
    return mat_12;
}

//int** mat_pow(int mat[SIZE][SIZE], unsigned int n, int mat_res[SIZE][SIZE]) {
//
//    mat_res = mat;
//
//    for (unsigned int i = 0; i < n; i++) {
//
//        mat_res = mat_mul_r(mat_res, mat);
//
//        //mat_print(mat_res);
//        printf("\n");
//    }
//    return mat_res;
//}

int main() {

    int mat_1[SIZE][SIZE] = {   {1, 0, 1, 0},
                                {0, 1, 0, 1},
                                {0, 0, 1, 1},
                                {0, 0, 0, 1}    };
    int mat_2[SIZE][SIZE] = {   {-1, 0, -1,  0},
                                {0 ,-1,  0, -1},
                                {0 , 0, -1, -1},
                                {0 , 0,  0, -1}  };
    int mat_12[SIZE][SIZE];

    // Multiplication of mat_1 and
    //mat_mul(mat_1, mat_2, mat_12);

    // Matrix exponentiation
    mat_mul(mat_1, mat_2, mat_12);

    // Show matrix
    mat_print(mat_12);
    return 0;
}


//    FILE *file;
//    file = fopen("C:\\Users\\Yapix\\Desktop\\temp.txt","wb");
//
//    unsigned int top_size;
//
//    for (int K = 0; K <= 10; K++) {
//
//        top_size = pow(2, K);
//        int set[K];
//        int top[top_size - 1];
//
//        for (unsigned int i = 0; i <= K; i++) set[i] = i;
//
//
//        fprintf(file, "___________===___________ K = %d\n", K);
//
//
//        for (unsigned int i = 0; i < K; i++) {
//
//            for (unsigned int j = 0; j < K; j++) {
//
//                if (i * j <= K) top[i] = pow(-set[i], i * j) * set[i * j] * set[j] - i * set[j] + j * set[i];
//                else top[i] = i * set[j] - i * j * j + set[i] * set[i];
//                //printf("%d ", top[i]);
//            }
//        }
//        for (unsigned int i = 0; i < top_size; i++) fprintf(file, "%d ", top[i]);
//        fprintf(file, "\n\n");
//    }
//
//    fclose(file);


//    #define SIZE 5
//    #define nSET_SIZE (int) pow(2, SIZE)
//
//    int set[SIZE] = {0, 1, 2, 3, 4};
//    int top[nSET_SIZE][SIZE];
//
//
//
//     GENERATE USUAL MULTIPLICATION TABLE
//    for (int i = 0; i <= nSET_SIZE; i++) {
//        for (int j = 0; j <= SIZE; j++) {
//            top[i][j] = i * set[j];
//        }
//    }
//
//     GENERATE POWER TABLE
//    for (int i = 0; i <= nSET_SIZE; i++) {
//        for (int j = 0; j <= SIZE; j++) {
//            top[i][j] = i * set[j];
//        }
//    }
//
//     etc...
//
//     PRINT RESULT
//
//    int sum = 0;
//    for (int i = 0; i <= nSET_SIZE; i++) {
//
//        for (int j = 0; j <= SIZE; j++) {
//
//            printf("%d\t", top[i][j]);
//            sum += top[i][j];
//        }
//        printf("\t%d", sum / SIZE);
//        printf("\n");
//    }
