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

int main(void) {
    int count[MAX_WHALE_SPECIES + 1];
	int sum[MAX_WHALE_SPECIES + 1] = {};
    char name[MAX_WHALE_SPECIES + 1][MAX_WHALE_NAME_LENGTH + 1];
	int counter = 0;
	int compare = 0;


    while (readCountName(& count[counter], name[counter]) == 1) {
		compare = 0;
		while (compare < counter) {
			if (strcmp(name[compare], name[counter]) == 0) {
				sum[compare] = sum[compare] + count[counter];
				break;
			} else {
				compare++;
			}
        } 
		if (compare == counter) {
			// means this string is a new string.
			sum[counter] = count[counter];
		}
		counter++;
	}

	int printvariable = 0;
	while (printvariable <= counter) {
		if (sum[printvariable] != 0) {
			printf("%d %s\n", sum[printvariable], name[printvariable]);
		}
		printvariable++;
	}
	return 0;
}
