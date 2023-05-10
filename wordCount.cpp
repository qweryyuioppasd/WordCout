#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_LINE_LEN 1024

int word_count(char *filename);
int char_count(char *filename);

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LEN];
    int count;
    if (argc > 1) {
        strcpy(filename, argv[2]);
    } else {
        strcpy(filename, "input.txt");
    }
    if (strcmp(argv[1], "-w") == 0) {
        count = word_count(filename);
        printf("单词数：%d\n", count);
    } else if (strcmp(argv[1], "-c") == 0) {
        count = char_count(filename);
        printf("字符数：%d\n", count);
    } else {
        printf("无效的参数\n");
    }
    return 0;
}

int word_count(char *filename) {
    FILE *fp = fopen("C:\\Users\\csr\\Desktop\\wordCount\\input.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败\n");
        exit(1);
    }
    int count = 0;
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        char *word = strtok(line, " ,\n\t");
        while (word != NULL) {
            count++;
            word = strtok(NULL, " ,\n\t");
        }
    }
    fclose(fp);
    return count;
}

int char_count(char *filename) {
    FILE *fp = fopen("C:\\Users\\csr\\Desktop\\wordCount\\input.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败\n");
        exit(1);
    }
    int count = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}


