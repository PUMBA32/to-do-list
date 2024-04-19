#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#define LENGTH 500

void addNote();
void removeNote();
void showNotes();

int main(void)
{
    printf("Welcome back, my creator!\n\n");
    while(true)
    {
        char choice;
        printf("[1] - Add note\n");
        printf("[2] - Remove note\n");
        printf("[3] - Show notes\n");
        printf("[4] - Exit\n\n");

        scanf("%c", &choice);
        while(getchar() != '\n');

        if(choice == '1')  // adding notes
            addNote();
        else if(choice == '2')  { // removing notes
            removeNote();
            while(getchar() != '\n');
        }
        else if(choice == '3')  // showing notes
            showNotes();
        else 
            break;
    }
    return 0;
}

void addNote()
{
    system("cls");
    char c;
    char text[LENGTH];
    int i = 0;

    printf("\nEnter Note: \n");
    while((c = getchar()) != '\n') 
        text[i++] = c;
    text[i++] = '\n';
    text[i] = '\0';

    FILE *file = fopen("D:\\Coding\\C\\projects\\To-do-list\\data.txt", "a");
    fprintf(file, text);
    fclose(file);
    system("cls");
    printf("Note was written!\n\n");
}

void removeNote()
{
    int n;
    printf("Number of line to be deleted: ");
    scanf("%d", &n);

    FILE *file = fopen("D:\\Coding\\C\\projects\\To-do-list\\data.txt", "r");  // открытие файла для чтения
    char *lines[LENGTH];
    char current_line[LENGTH];
    int count = 0;

    // Запись строк в массив
    while (fgets(current_line, LENGTH, file) != NULL) {
        lines[count] = strdup(current_line);
        if (lines[count] == NULL) {
            printf("Error allocating memory!\n");
            return;
        }
        count++;
    }
    fclose(file);

    // Открытие файла для перезаписи
    file = fopen("D:\\Coding\\C\\projects\\To-do-list\\data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    // Запись строк в файл
    for (int i = 0; i < count; i++) {
        if (i != n - 1) {
            fprintf(file, "%s", lines[i]);
        }
        free(lines[i]);  // освобождение памяти после записи строки в файл
    }
    fclose(file); 
    system("cls");
    printf("Note was deleted!\n\n");
}

void showNotes()
{
    system("cls");
    printf("\n");
    FILE *file = fopen("D:\\Coding\\C\\projects\\To-do-list\\data.txt", "r");
    char line[LENGTH];
    int count = 1;

    while (fgets(line, LENGTH, file) != NULL) 
        printf("%d - %s", count++, line);
    
    printf("\n");
    fclose(file);
}