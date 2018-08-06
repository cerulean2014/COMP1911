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


int main(int argc, char *argv[]) {
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
	if (argc == 1) {
		while (printvariable <= counter) {
			if (sum[printvariable] > 0) {
				printf("%d %s\n", sum[printvariable], name[printvariable]);
			}
			printvariable++;
		}
	} else {


		// sort alpha
		
		char temp [MAX_WHALE_NAME_LENGTH + 1];
		int i, j, n, tem;
 		n = counter;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n - 1; j++) {
				if (strcmp(name[j], name[j + 1]) > 0) {
					strcpy(temp, name[j]);
					tem = sum[j];

					strcpy(name[j], name[j + 1]);
					sum[j] = sum[j+1];

					strcpy(name[j + 1], temp);
					sum[j+1] = tem;
				}
			}
		}


		int result[MAX_WHALE_SPECIES + 1] = {};
		int a = 0;
		int max = 0;
		int b = 0;
		while (a < counter) {
			// find the maximum value first, then print it out, then let it be 0 to avoid double counting.
			while (b < counter) {
				if (sum[b] > max) {
					result[a] = b;
					max = sum[b];
				}
				b++;
			}
			if (sum[result[a]] > 0) {
				printf("%d %s\n", sum[result[a]], name[result[a]]);
			}
			sum[result[a]] = 0;
			a++;
			b = 0;
			max = 0;
		}
	}
	return 0;
}


