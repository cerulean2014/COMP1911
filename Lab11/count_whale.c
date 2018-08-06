//quoted from Andrew.

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_LINE_LENGTH 256
#define MAX_WHALE_NAME_LENGTH 128
#define MAX_WHALE_SPECIES 128


int readCountName(int *countp, char name[MAX_WHALE_NAME_LENGTH]) {
    char line[MAX_LINE_LENGTH];
    int i,j;
    if (scanf("%d", countp) != 1) {
        return 0;
    }

    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        return 0;
    }

    i = 0;
    while (isspace(line[i]) && line[i] != '\0') {
        i = i + 1;
    }

    j = 0;
    while (line[i] != '\0' && line[i] != '\n') {
        name[j] = line[i];
        j = j + 1;
        i = i + 1;
    }
    name[j] = '\0';

    if (line[i] == '\n') {
        return 1;
    } else {
        return 0;
    }
}

int
main(int argc, char *argv[]) {
    int count, lastCount;
	int sum = 0;
	int pods = 0;
    char name[MAX_WHALE_NAME_LENGTH + 1];
    char lastName[MAX_WHALE_NAME_LENGTH + 1];

    if (readCountName(&lastCount, lastName) != 1) {
        return 0;
    }
    while (readCountName(&count, name) == 1) {
        if (strcmp(name, argv[argc-1]) == 0) {
			sum = sum + count;
			pods++;
        } 
    }
    printf("%s count: %d pods containing %d whales\n", argv[argc-1], pods, sum);
    return 0;
}

