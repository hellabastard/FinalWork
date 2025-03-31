#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Books{
	char bookname[100];
	char author[100];
	char availibility;
	int price;
};


struct HeaderB
{
	char f4[50];
	char f5[50];
};

struct Header 
{
	char f1[50];
	char f2[50];
	char f3[50];
	struct HeaderB otherF;
};

void changeRows(struct Books* source, int i2);

int main() {
	setlocale(LC_ALL, "");

	const int SIZE = 5;

	struct Books books_st[SIZE] = {
		{"Двенадцать", "Блок А.", 'Y', 320},
		{ "Одиссея", "Гомер", 'Y', 300},
		{"Илиада", "Гомер", 'N', 400},
		{"Мертвые души", "Гоголь", 'Y', 310},
		{"Россиада", "Херасков", 'N', 500} };
	struct Books* b = books_st;
	struct Header header = { "Поэма", "Наличие", "Цена", { "Название", "Автор" } };

	printf("Изначальная таблица:\n");
	printf("---------------------------------------------------------\n");
	printf("%16s %13s %10s %15s\n", header.f1, "|", "|", "|");
	printf("-----------------------------| %10s %15s\n", "|", "|");
	printf("%s %9s %6s %4s %5s %2s %8s %6s\n", header.otherF.f4, "|", header.otherF.f5, "|", header.f2, "|", header.f3, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", b->bookname, "|", b->author, "|", b->availibility, "|", b->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 1)->bookname, "|", (b + 1)->author, "|", (b + 1)->availibility, "|", (b + 1)->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 2)->bookname, "|", (b + 2)->author, "|", (b + 2)->availibility, "|", (b + 2)->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 3)->bookname, "|", (b + 3)->author, "|", (b + 3)->availibility, "|", (b + 3)->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 4)->bookname, "|", (b + 4)->author, "|", (b + 4)->availibility, "|", (b + 4)->price, "|");
	printf("---------------------------------------------------------\n");

	changeRows(b, SIZE);

	printf("Измененная таблица:\n");
	printf("---------------------------------------------------------\n");
	printf("%16s %13s %10s %15s\n", header.f1, "|", "|", "|");
	printf("-----------------------------| %10s %15s\n", "|", "|");
	printf("%s %9s %6s %4s %5s %2s %8s %6s\n", header.otherF.f4, "|", header.otherF.f5, "|", header.f2, "|", header.f3, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", b->bookname, "|", b->author, "|", b->availibility, "|", b->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 1)->bookname, "|", (b + 1)->author, "|", (b + 1)->availibility, "|", (b + 1)->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 2)->bookname, "|", (b + 2)->author, "|", (b + 2)->availibility, "|", (b + 2)->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 3)->bookname, "|", (b + 3)->author, "|", (b + 3)->availibility, "|", (b + 3)->price, "|");
	printf("-----------------------------|----------|---------------|\n");
	printf("%-17s%s%-11s%s    %-6c%s      %-9d%s\n", (b + 4)->bookname, "|", (b + 4)->author, "|", (b + 4)->availibility, "|", (b + 4)->price, "|");
	printf("---------------------------------------------------------\n");
}

void changeRows(struct Books *source, int sourceSize) {
	int i1, i2;
	struct Books temp;
	char input[100];
	char* endptr;

	printf("Выберете номер первой строки для проведения операции замены (от 1 до 5): ");
	while (1) {
		if (fgets(input, sizeof(input), stdin) != NULL) {
			input[strcspn(input, "\n")] = 0;
			i1 = (int)strtol(input, &endptr, 10);
			if (*endptr == '\0' && i1 <= sourceSize && i1 > 0) {
				break;
			}
		}
		printf("\nОшибка! Пожалуйста, введите целое число от 1 до 5: ");
	}

	printf("Выберете номер второй строки для проведения операции замены (от 1 до 5): ");
	while (1) {
		if (fgets(input, sizeof(input), stdin) != NULL) {
			input[strcspn(input, "\n")] = 0;
			i2 = (int)strtol(input, &endptr, 10);
			if (*endptr == '\0' && i2 <= sourceSize && i2 > 0 && i1 != i2) {
				break;
			}
		}
		printf("\nОшибка! Пожалуйста, введите целое число от 1 до 5: ");
	}

	temp = *(source + (i1 - 1));
	*(source + (i1 - 1)) = *(source + (i2 - 1));
	*(source + (i2 - 1)) = temp;
}