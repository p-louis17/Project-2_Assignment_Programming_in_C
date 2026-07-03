#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[100];
    int count;
}Word;

void count_words(Word *text, int used){
    printf("\n");
    printf("There are %d words\n", used);
    printf("\n");
    
}

void longest_word(Word *text, int used){
    int highest = strlen(text[0].name);
    int highest_index = 0;
    for(int i = 0; i<used; i++){
        if(strlen(text[i].name)>highest){
            highest = strlen(text[i].name);
            highest_index = i;
        }
    }
    printf("\n");
    printf("The word \"%s\" is the longets word\n",text[highest_index].name);
    printf("\n");

}

void most_frequent(Word *text, int used){
    int highest = text[0].count;
    int highest_index = 0;
    for(int i = 0; i<used; i++){
        if(text[i].count > highest){
            highest = text[i].count;
            highest_index = i;
        }
    }
    printf("\n");
    printf("The word \"%s\" is the most frquent word apearing %d times\n",text[highest_index].name, text[highest_index].count);
    printf("\n");
    
}

void average_word_length(Word *text, int used){
    int sum = 0;
    for(int i = 0; i<used; i++){
        sum += strlen(text[i].name);
    }
    printf("\n");
    printf("The average length is %d\n", sum/used);
    printf("\n");
    
}

void free_memory(Word *text){
    free(text);
}

void (*analysis[])(Word*, int) = {
    count_words,
    longest_word,
    most_frequent,
    average_word_length
};


int main(){
    int array_nums = 100;
    int used = 1;
    int user_choice;
    Word *text = malloc(array_nums*sizeof(Word));
    printf("Word array stored at memory address: %p\n", (void*)text);
    char str[] = "JavaScript and Python devs aren’t used to a separate compilation step at all–though behind the scenes it’s happening! Python compiles your source code into something called bytecode that the Python virtual machine can execute. Java devs are used to compilation, but that produces bytecode for the Java Virtual Machine. When compiling C, machine code is generated. This is the 1s and 0s that can be executed directly and speedily by the CPU.";

    char* token = strtok(str, " .,!?");
    strcpy(text[0].name, token);
    text[0].count = 1;

    printf("\n");
    printf("=======Text Manipulator========\n");
    printf("\n");
    printf("%s: %d times\n", text[0].name, text[0].count);

    while(token != NULL){
        token = strtok(NULL, " .,!?");
        if(token == NULL || token[0] == '\0') continue;
        int found = 0;
        for(int i = 0; i<used; i++){
            if(strcmp(text[i].name, token) == 0){
                text[i].count++;
                found = 1;
                printf("%s : %d times\n", text[i].name, text[i].count);
                break;
            }  
        }
        if(found == 0){
            strcpy(text[used].name, token);
            text[used].count = 1;
            printf("%s : %d times\n", text[used].name, text[used].count);
            used++;
        }
    }

    while(1){
            printf("Type:\n 1 for word count\n 2 for the longest word \n 3 for the most frequent word\n 4 for the average word length\n 5 to exit\n");
            if (scanf("%d", &user_choice) != 1){
                printf("Invalid choice. Enter a valid chioce");
                while(getchar()!= '\n');

                continue;
            }
            if(user_choice >= 1 && user_choice <= 4){
                analysis[user_choice-1](text, used);
            }else if (user_choice == 5){
                break;
            }else{
                printf("Invalid choice\n");
            }
        }

    free_memory(text);
    return 0;

}
