#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdlib.h> // Just for clearing the screen and malloc 
#include <stdbool.h> // need for boolean calculations

const int sentenceSize = 100;
const int _time_ = 60;
#define MAX_WORDS_IN_SENTENCE 100
double elapsed_time;

typedef struct{
    int wordCount;
    char **words;
} WordBreakDown;


void intro();
void delay(float secs);
WordBreakDown wordBreakdownFunction(char* sentence);
int compare(WordBreakDown value, WordBreakDown usrValue);
void outro(int result, time_t start_time, time_t current_time);

int main()
{
    time_t start_time = time(NULL);
    int wordsTypedCorrectly = 0;
    time_t current_time;

    FILE *file = fopen("sentences.txt", "r");
    if (file == NULL)
    {
        printf("File opening Error");
        return 1;
    }
    intro();

    // Main Program Logic:
    char sentence[sentenceSize];

    while(fgets(sentence, sentenceSize, file))
    {
        printf("%s", sentence);
        for (int i = 0; i <= strlen(sentence); i++)
        {
            printf("-");
        }
        printf("\n");

        char userSentence[sentenceSize];
        strcpy(userSentence, sentence);

        current_time = time(NULL); // TIMER SYSTEM: Basically gets current calender Time from certain conventional time according to C idk anymore.
        elapsed_time = difftime(current_time, start_time); // Checking 1 minute has passed!

        if (elapsed_time > _time_)
        {
            // closing program logic
            outro(wordsTypedCorrectly, start_time, current_time);
            break;
        }

        // Better method for getting user input than scanf
        if (fgets(userSentence, sentenceSize, stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }
        WordBreakDown result_sentence = wordBreakdownFunction(sentence);
        WordBreakDown result_usrSentence = wordBreakdownFunction(userSentence);
        wordsTypedCorrectly += compare(result_sentence, result_usrSentence);

        // Repeated codes but didn't wanna make new function
        // Freeing memory that was allocated
        for (int i = 0; i < result_sentence.wordCount; i++)
            free(result_sentence.words[i]);
        for (int i = 0; i < result_usrSentence.wordCount; i++)
            free(result_usrSentence.words[i]);
        free(result_sentence.words);
        free(result_usrSentence.words);

        printf("Type:\n");
    }
    fclose(file);
    printf("\n");
    return 0;
}

WordBreakDown wordBreakdownFunction(char sentence[]) {
    const char delimiters[] = " .;!?";
    WordBreakDown result;

    result.words = malloc(MAX_WORDS_IN_SENTENCE * sizeof(char *));
    if (result.words == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1); // Exit if memory allocation fails
    }

    int word_count = 0;
    char *token = strtok(sentence, delimiters);

    while (token != NULL) {
        // Allocate memory and copy each word
        result.words[word_count] = malloc(strlen(token) + 1);
        if (result.words[word_count] == NULL) {
            printf("Memory Allocation Failed\n");
            // Free previously allocated memory
            for (int i = 0; i < word_count; i++) {
                free(result.words[i]);
            }
            free(result.words);
            exit(1);
        }
        strcpy(result.words[word_count], token);
        word_count++;
        token = strtok(NULL, delimiters); // next word else token equals NULL
    }

    result.wordCount = word_count;
    return result;
}

int compare(WordBreakDown value, WordBreakDown usrValue)
{
    int tempValue = 0;
    for(int i = 0; i < usrValue.wordCount; i++)
    {
        if (strcmp(value.words[i], usrValue.words[i]) == 0)
        {
            tempValue++;
        }
    }
    return tempValue;
}

void intro()
{
    system("clear");
    printf("%d sec typing test:\n", _time_);
    delay(0.5f);
    printf("Press \"Enter\" Button to Start");
    scanf("%*c"); // waiting for new line: nice implementation right!    
    printf("Starting in: ...\n");
    printf("Starting in: 3\n");
    delay(1.0f);
    printf("Starting in: 2\n");
    delay(1.0f);
    printf("Starting in: 1\n");
    delay(1.0f);
    printf("GO!!!\n");
    delay(0.1f);
    system("clear");
    printf("Type:\n");
}

void delay(float secs)
{
    // Convert seconds to the equivalent number of clock ticks
    clock_t start_time = clock(); // Miracle by timer.h header XD.
    clock_t delay_time = (clock_t)(secs * CLOCKS_PER_SEC);

    // Wait until the required time has passed
    while (clock() < start_time + delay_time);
}

void outro(int result, time_t start_time, time_t current_time)
{
    /* 
        Basically this is my calculation for this part LOL
        42 = x sec
        1 sec = 42/x
        60 sec = 42/x *60
    */
    elapsed_time = difftime(current_time, start_time);
    int accurateResult = (int)(((float)(result) / elapsed_time) * 60);
    printf("You typed at the speed of %d word per minute\n", accurateResult);
    printf("Press \"R\" to retry OR Press any other key to Exit.\n");
    char choice = getchar();
    if (choice == 'R' || choice == 'r') {
        main(); // Retry by calling main() again
    }
    // quits program else: Programming magic :)
}