/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double* gen_array(int size) {
    
    double *array = malloc(size);
    
    for(int i = 0; i < size; i++) {
        array[i] = i;
    }
    
    return array;
}

bool check(int size) {
    

    int arr_size = sizeof(gen_array(size)) / sizeof(gen_array(size)[0]);
    bool exists_M;
    
    for (int i = 0; i < arr_size; i++) {
        if (!(__builtin_types_compatible_p(typeof(gen_array(size)[i] + 1), double))) {
            printf("FALSE");
            exists_M = false;
            return exists_M;
        }
        else {
            printf("NO PB");
        }
    }
    
    return exists_M;

}

int main()
{
    printf("Hello World\n");

    double* arr = gen_array(5);
    for (int i = 0; i < 5; i++) {
        printf("%f\n", arr[i]);
    }
    
    printf("%b", check(5));
    
    free(arr);
    return 0;
}
