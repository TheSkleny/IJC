// Name: tail.c
// IJC_DU2 solution - task A
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



// struct for something like circular array
// not used head, because in this use of circular array we don't need to delete elements from array
struct circ_array{
    char **values;
    int tail, size;
};

// function for initialization of circular array
// ARGS: c_array - pointer to circular array
//       size - size of array (number of last lines we want to print)
bool circ_array_create(struct circ_array *c_array, int size){
    c_array->values = malloc(sizeof(char *) * size);
    if (c_array->values == NULL){
        fprintf(stderr, "ERROR: Nepovedlo se naaolokovat pamet\n");
        return false;
    }
    for (int i =0; i < size; i++){
        c_array->values[i] = NULL;
    }
    c_array->size = size;
    c_array->tail = 0;
    return true;
}

// function to free all allocated memory in circular array
// ARGS: c_array - pointer to circular array
void circ_array_destroy(struct circ_array *c_array){
    for (int i = 0; i < c_array->size; i++){
        free(c_array->values[i]);
    }
    free(c_array->values);
    c_array->size = 0;
    c_array->tail = 0;
}

// adds string to circular array
// ARGS: c_array - pointer to circular array
//       string - string what we want to add to array
void circ_array_add(struct circ_array *c_array, char *string){
    c_array->values[c_array->tail] = realloc (c_array->values[c_array->tail], strlen(string) + 1);
    strcpy(c_array->values[c_array->tail], string);
    c_array->tail = (c_array->tail + 1) % c_array->size;
}

// main function of tail.c
int main(int argc, char const *argv[]){

    struct circ_array arr;
    FILE *f;
    char buffer[4098] = {'\0',}; //buffer for storing lines from file or stdin, takes max length of line 4095 without '\n'
    char *str_ptr; //temporary variable for use with strtoul()
    long n_value; //temorary variable for use with strtoul()
    bool is_longer = false;
    int line_count = 0; //temporary variable to store count of lines, only used to print number of first too long line
    int c; //temporary variable to help skip rest of too long line
    bool set = false; //almost useless variable, only for really, really edge case of line length
    
    switch (argc){
        //input from stdin, no parameter
        case 1:
            f = stdin;
            if(circ_array_create(&arr, 10) == false) return 1;
            //reading of all lines from file and store them into circular array
            while(fgets(buffer, 4098, f) != NULL){ //4098
                line_count++;
                //check if line isn't too long
                if (buffer[4096] != '\0'){     //4096
                    if (is_longer == false){
                        fprintf(stderr, "ERROR: Radek %d je prilis dlouhy (max. 4095 znaku), dale pokracuji se zkracenymi radky\n", line_count);
                        is_longer = true;
                    }
                    if(buffer[4096] == '\n'){
                        set = true;
                    }
                    buffer[4096] = '\0';   //4096
                    buffer[4095] = '\n';   //4095
                    //skip of the rest of too long line
                    if(set == false){
                        while((c = getchar()) != '\n' && c != EOF);
                    }
                    set = false;
                }
                circ_array_add(&arr, buffer);
            }
            break;

        //input from file, -n cannot be entered
        case 2:
            //check if -n was entered
            if (!strcmp(argv[1], "-n")){
                fprintf(stderr, "ERROR: -n must have value\n");
                return 1;
            }
            else{
                f = fopen(argv[1], "r");
                if (f == NULL){
                    fprintf(stderr, "ERROR: Soubor se nepovedlo otevrit.\n");
                    return 1;
                }
                if(circ_array_create(&arr, 10) == false) return 1;
                //reading of all lines from file and store them into circular array
                while(fgets(buffer, 4098, f) != NULL){ //4098
                    line_count++;
                    //check if line isn't too long
                    if (buffer[4096] != '\0'){     //4096
                        if (is_longer == false){
                            fprintf(stderr, "ERROR: Radek %d je prilis dlouhy (max. 4095 znaku), dale pokracuji se zkracenymi radky\n", line_count);
                            is_longer = true;
                        }
                        if(buffer[4096] == '\n'){
                            set = true;
                        }
                        buffer[4096] = '\0';   //4096
                        buffer[4095] = '\n';   //4095
                        //skip of the rest of too long line
                        if(set == false){
                            while((c = getchar()) != '\n' && c != EOF);
                        }
                        set = false;
                    }
                    circ_array_add(&arr, buffer);
                }
            }
            break;

        // input only from stdin, -n has value
        case 3:
            //check if -n was entered
            if (!strcmp(argv[1], "-n")){
                n_value = strtoul(argv[2], &str_ptr, 10);
                n_value = abs(n_value);
                if (strcmp(str_ptr, "")){
                    fprintf(stderr, "ERROR: -n musi byt kladne cele cislo\n");
                    return 1;
                }
            }
            else{
                fprintf(stderr, "ERROR: spatne zadane argumenty\n");
                return 1;
            }
            f = stdin;
            if(circ_array_create(&arr, n_value) == false) return 1;
            //reading of all lines from file and store them into circular array
            while(fgets(buffer, 4098, f) != NULL){ //4098
                line_count++;
                //check if line isn't too long
                if (buffer[4096] != '\0'){     //4096
                    if (is_longer == false){
                        fprintf(stderr, "ERROR: Radek %d je prilis dlouhy (max. 4095 znaku), dale pokracuji se zkracenymi radky\n", line_count);
                        is_longer = true;
                    }
                    if(buffer[4096] == '\n'){
                        set = true;
                    }
                    buffer[4096] = '\0';   //4096
                    buffer[4095] = '\n';   //4095
                    //skip of the rest of too long line
                    if(set == false){
                        while((c = getchar()) != '\n' && c != EOF);
                    }
                    set = false;
                }
                circ_array_add(&arr, buffer);
            }
            break;

        //input from file, -n has value
        case 4:
            //check if -n was entered first, file second
            if (!strcmp(argv[1], "-n")){
                n_value = strtoul(argv[2], &str_ptr, 10);
                n_value = abs(n_value);
                if (strcmp(str_ptr, "")){
                    fprintf(stderr, "ERROR: -n musi byt kladne cele cislo\n");
                    return 1;
                }
                f = fopen(argv[3], "r");
                if (f == NULL){
                    fprintf(stderr, "ERROR: Soubor se nepovedlo otevrit.\n");
                    return 1;
                }
                if(circ_array_create(&arr, n_value) == false) return 1;
                //reading of all lines from file and store them into circular array
                while(fgets(buffer, 4098, f) != NULL){ //4098
                    line_count++;
                    //check if line isn't too long
                    if (buffer[4096] != '\0'){     //4096
                        if (is_longer == false){
                            fprintf(stderr, "ERROR: Radek %d je prilis dlouhy (max. 4095 znaku), dale pokracuji se zkracenymi radky\n", line_count);
                            is_longer = true;
                        }
                        if(buffer[4096] == '\n'){
                            set = true;
                        }
                        buffer[4096] = '\0';   //4096
                        buffer[4095] = '\n';   //4095
                        //skip of the rest of too long line
                        if(set == false){
                            while((c = getchar()) != '\n' && c != EOF);
                        }
                        set = false;
                    }
                    circ_array_add(&arr, buffer);
                }

            }
            //-n was entered second, file first
            else{
                f = fopen(argv[1], "r");
                if (f == NULL){
                    fprintf(stderr, "ERROR: Soubor se nepovedlo otevrit.\n");
                    return 1;
                }
                if (!strcmp(argv[2], "-n")){
                    n_value = strtoul(argv[3], &str_ptr, 10);
                    n_value = abs(n_value);
                    if (strcmp(str_ptr, "")){
                        fprintf(stderr, "ERROR: -n musi byt kladne cele cislo\n");
                        return 1;
                    }
                }
                else{
                    fprintf(stderr, "ERROR: Neznamy argument\n");
                    return 1;
                }
                if(circ_array_create(&arr, n_value) == false) return 1;
                //reading of all lines from file and store them into circular array
                while(fgets(buffer, 4098, f) != NULL){ //4098
                    line_count++;
                    //check if line isn't too long
                    if (buffer[4096] != '\0'){     //4096
                        if (is_longer == false){
                            fprintf(stderr, "ERROR: Radek %d je prilis dlouhy (max. 4095 znaku), dale pokracuji se zkracenymi radky\n", line_count);
                            is_longer = true;
                        }
                        if(buffer[4096] == '\n'){
                            set = true;
                        }
                        buffer[4096] = '\0';   //4096
                        buffer[4095] = '\n';   //4095
                        //skip of the rest of too long line
                        if(set == false){
                            while((c = getchar()) != '\n' && c != EOF);
                        }
                        set = false;
                    }
                    circ_array_add(&arr, buffer);
                }
            }
            break;

        //too many arguments
        default:
            fprintf(stderr, "ERROR: Prilis velky pocet argumentu.\n");
            return 1;
            break;
    }
    fclose(f);

    // print of last n lines from file
    int pos = arr.tail;
    for(int i = 0; i < arr.size; i++){
        if (arr.values[pos] != NULL){
            printf("%s", arr.values[pos]);
        }
        pos = (pos + 1) % arr.size;
    }
    circ_array_destroy(&arr);

    return 0;
}
