#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

struct route //структура пути
{
    char name_route;
    char top1;
    char top2;
};

int search(char nowTop, char* markTop);
void seeOnrouts(char nowTop, int collumnMax, struct route* routs, char* markTop, int topNumber);
int checkConnect(int collumnMax, struct route* routs, char* markTop);

int main(void*)
{
    FILE* file;
    FILE* write_file;

    int i = 1;
    int i_column = 0;
    char now_top;
    int sign;

    int collumnMax;
    char* markTop;

    route* routs, * tmp;
    routs = (struct route*)malloc(sizeof(route) * 8);

    file = fopen("C:\\Users\\Георгий\\Desktop\\table.txt", "r");

    fgetc(file);

    if (routs) {
        while ((sign = fgetc(file)) != '\n') {
            tmp = (struct route*)realloc(routs, sizeof(route) * 8 * i);
            routs = tmp;
            if (routs) {
                routs[i - 1].name_route = sign;
                routs[i - 1].top1 = '\0';
                routs[i - 1].top2 = '\0';
            }
            i++;
        }
        i--;
        collumnMax = i;
        while ((sign = fgetc(file)) != EOF) {
            if (sign != '\n') {
                //printf("%d",i_column);
                if (i_column == 0) {
                    now_top = sign;
                }
                else {
                    if (sign == '1' && routs) {
                        if (routs[i_column - 1].top1 == '\0')
                            routs[i_column - 1].top1 = now_top;
                        else
                            routs[i_column - 1].top2 = now_top;
                    }
                }
                i_column++;
            }
            else
                i_column = 0;
        }
    }
    fclose(file);

    write_file = fopen("C:\\Users\\Георгий\\Desktop\\tablewr.txt", "w");

    fprintf(write_file, "graph H{\n");
    for (;i > 0;i--) {
        if (routs)
            if (routs[i - 1].top2 != '\0')
                fprintf(write_file, "%c--%c\n", routs[i - 1].top1, routs[i - 1].top2);
            else
                fprintf(write_file, "%c--%c\n", routs[i - 1].top1, routs[i - 1].top1);
    }
    fprintf(write_file, "}\n");

    fclose(write_file);

    markTop = (char*)malloc(sizeof(char) * 8 * 2);
    if (markTop && routs) {
        markTop[0] = routs[0].top1;
        markTop[1] = '\0';
        seeOnrouts(routs[0].top1, collumnMax, routs, markTop, 2);
    }

    if (checkConnect(collumnMax, routs, markTop))// печатаем результат
        printf("graph is connect");
    else
        printf("graph does not connect");
}
int checkConnect(int collumnMax, struct route* routs, char* markTop) { // проверяем есть ли маршрут от первой точи ко всем остальным
    int i = 0;
    for (;i < (collumnMax);i++) {
        if (!search(routs[i].top1, markTop))
            return 0;
        else if (!search(routs[i].top2, markTop))
            return 0;
    }
    return 1;
}
int search(char nowTop, char* markTop) { //смотрим есть ли в массиве вершина
    int i = 0;
    while (markTop[i] != '\0') {
        if (markTop[i] == nowTop)
            return 1;
        i++;
    }
    if (nowTop == '\0')
        return 1;
    return 0;
}
void seeOnrouts(char nowTop, int collumnMax, struct route* routs, char* markTop, int topNumber) {//смотрим на соседние верршины и записываем их в массив если их там нет
    int i = 0;
    char* tmp;
    while (i < collumnMax) {
        if (routs[i].top1 == nowTop) {
            if (!search(routs[i].top2, markTop) && routs[i].top2 != '\0') {
                topNumber++;
                tmp = (char*)realloc(markTop, sizeof(char) * 8 * topNumber);
                markTop = tmp;
                if (markTop) {
                    markTop[topNumber - 2] = routs[i].top2;
                    markTop[topNumber - 1] = '\0';
                }
                seeOnrouts(routs[i].top2, collumnMax, routs, markTop, topNumber);
            }
        }
        if (routs[i].top2 == nowTop) {
            if (!search(routs[i].top1, markTop) && routs[i].top1 != '\0') {
                topNumber++;
                tmp = (char*)realloc(markTop, sizeof(char) * 8 * topNumber);
                markTop = tmp;
                if (markTop) {
                    markTop[topNumber - 2] = routs[i].top1;
                    markTop[topNumber - 1] = '\0';
                }
                seeOnrouts(routs[i].top1, collumnMax, routs, markTop, topNumber);
            }
        }
        i++;
    }
}
