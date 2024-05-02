#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Структура для хранения информации о книгах Пушкина
typedef struct {
    char reader[50]; // Имя читателя
    char title[100]; // Название книги
} PushkinBook;

// Прототип функции для печати списка книг Пушкина
void print_out(PushkinBook v[], int n);

int main() {
    PushkinBook books[MAX_ENTRIES]; // Массив структур для хранения информации о книгах Пушкина
    int num_books = 0; // Количество книг Пушкина

    // Открытие файла для чтения
    FILE *file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    // Чтение данных из файла
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char date[20], reader[50], title[100], author[50];
        sscanf(line, "%[^;];%[^;];%[^;];%s", date, reader, title, author);

        // Проверка, является ли автор Пушкиным
        if (strcmp(author, "Пушкин") == 0) {
            strcpy(books[num_books].reader, reader); // Сохранение имени читателя
            strcpy(books[num_books].title, title); // Сохранение названия книги
            num_books++; // Увеличение счетчика книг Пушкина
        }
    }

    // Закрытие файла
    fclose(file);

    // Вывод списка книг Пушкина в консоль и запись в файл
    printf("Читатель\tКнига\n");
    print_out(books, num_books);

    return 0;
}

// Функция для печати списка книг Пушкина в файл
void print_out(PushkinBook v[], int n) {
    // Открытие файла для записи
    FILE *out = fopen("out.txt", "w");
    if (out == NULL) {
        printf("Ошибка при создании файла.\n");
        exit(1);
    }
    // Запись заголовка в файл
    fprintf(out, "Читатель\tКнига\n");
    // Печать информации о книгах Пушкина в файл и в консоль
    for (int i = 0; i < n; i++) {
        fprintf(out, "%s\t%s\n", v[i].reader, v[i].title); // Запись в файл
        printf("%s\t%s\n", v[i].reader, v[i].title); // Вывод в консоль
    }
    // Закрытие файла
    fclose(out);
}