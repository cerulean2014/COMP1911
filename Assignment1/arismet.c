#include <stdio.h>

int main(void){
	int max;
	max = 13;

	// because the range of number that can be tested is from 5 to 13 inclusive.

	int numbers, numbersread, input[max];
	int i, j;

	// i and j are basic counters.

// Firstly make up an array to collect numbers.

	numbers = 0;
	scanf ("%d", &numbersread);
	max = numbersread;
	while (numbers < numbersread) {
		scanf ("%d", &input[numbers]);
		numbers = numbers + 1;
	}

// Then for even triple.

	int even[max], evenscore;
	// the even array collects all the even numbers appearing in the input.
	i = numbersread - 1;
	// to maximize the evenscore, just begin counting from the highest number, where is the back.
	j = 0;
	// j is the counter for the number of even number in the input.
	while (i >= 0 && j < 3) {
		if (input[i] % 2 == 0) {
			even[j] = input[i];
			j = j + 1;
		}
		i = i - 1;
	}
	//this loop above should stop as soon as j reaches 3.
	if (j == 3) {
		evenscore = even[0] + even[1] + even[2] + 2;
	} else {
	// so 'else' here means that j is less than 3, which means that there are not enough numbers to make up an even triple.
		evenscore = 0;
	}

// Then for odd triple, things are completely same as the part of even triple, excpet the name of array and score.

	int odd[max], oddscore;

	i = numbersread - 1;
	j = 0;
	while (i >= 0 && j < 3) {
		if (input[i] % 2 == 1) {
			odd[j] = input[i];
			j = j + 1;
		}
		i = i - 1;
	}
	if (j == 3) {
		oddscore = odd[0] + odd[1] + odd[2] + 1;
	} else {
		oddscore = 0;
	}

// Then for run.

	int same, runscore, runs, runsnumber, display;

	i = 0;
	same = 1;

	// the variable same means the times that a number appears in the input.

	runscore = 0;
	runs = 0;

	// runscore is the RESULTED score that the 'run' has. 
	// and the runs is all the scores that all the possibilities can get.

	runsnumber = 0;
	while (i < (numbersread - 1)) {
		while ((i < (numbersread - 1)) && input[i] == input[i + 1]) {
			same = same + 1;
			i = i + 1;
		}
		if (same > 1) {

		// Same > 1 means that 'run' part exists in the sequence.
		// Then do the comparing part for run.

			runs = (same * same * input[i]) - 13;
			if (runs > runscore) {

			//the reason I used > but not >= here is that the first term should be as small as possible when there are several cases that can get same scores.

				runscore = runs;
				runsnumber = same;
			}
		}
		same = 1;
		i = i + 1;
	}
	if (runsnumber > 1) {
		display = (runscore + 13) / runsnumber / runsnumber;
	} else {
		runscore = 0;
	}



// Sequence part.

	int k, d, n, t, next, ap, e;
	// i, j, k, n, e are elements for loops to make the array (input[max]) run.
	// next is the next theoretical value for the sequence. (i.e. If there is a number == next, the number of terms will be added 1)
	// d stands for difference between two selected terms.
	// e is also a counter, because an independent counter is needed to make the loops run.
	// t is the number of terms that each sequence has.

	int begin[1000] = {};
	int diff[1000] = {};
	int times[1000] = {};
	int maxi[1000] = {};

// Theoretically, there would be a large amount of possible sequences inside the input, so in order to make life easier, just suppose a relatively larger number, (i.e. 1000) for the arrays.
// ap is the counter for those 4 arrays. (i.e. when a possible sequence appears, ap increase by 1)
// begin[] is the first number in the sequence.
// diff[] is the difference between adjacent terms in the sequence.
// times[] is the number of terms in the sequence.
// maxi[] is the maximum number is the sequence.

	// then I initialized those variables, and the reasons will be explained step by step.

	d = 1;
	j = 0;
	k = 0;
	next = 0;
	t = 2;
	n = 0;
	ap = 0;
	e = 0;

	// difference should be at least 1, otherwise it is a run.
	// t should be at least 2, because I choose two numbers as the base of sequence.

/*
	I found two ways to run the loop, in the positive direction and the negative direction. in order to make the comparing part, which is after this part, more easier, I use NEGATIVE direction.
	(i.e. suppose the first term in the sequences as input[i], then count it NEGATIVELY, let j be (i - 1), then work out the difference = input[j] - input[i] + 31. (the reason I add 31 is that j < i, so input[j] < input[i], which cannot satisfy the condition of the loop)

	then j needs to be deducted by 1 to make an estimating circulation.

	as we can see from the results, there is no need for the difference to be more than 15, because when difference = 16, it is the same as when difference = 15, and so must after. hence difference must be in a range of 1 and 15 inclusive.

	after finding out input[i] as the first term, input[j] as the second term, then we can work out the third term theoritically. and if the third term exists, there is a arithmetic progression. we use the variable k to do this judging part.

	ap is also a counter for the result arrays (begin[], diff[], times[] and maxi[]), when collection for the very sequence was finished, ap would be added 1 to start another collection.
*/

	i = 0;

	// we count i from the beginning, but j from the elements just before i.

	while (i < numbersread) {
		j = i - 1;
		if (j == -1) {

		// when i = 0, j = -1, however -1 is not acceptable for the loop, and -1 stands for the last term of the input, because this is a circulation.

			j = numbersread - 1;
		}
		while (e < (numbersread - 1)) {
			if (j == -1) {
				j = numbersread - 1;
			}

			// same reason as above.

			d = input[j] - input[i];
			if (d < 0) {

			// d < 0 means input[j] < input[i], that is not acceptable, and so d should be added 31.

				d = d + 31;
			}
			while (d > 15) {

			/*
			wherever there is a d > 15, there must be another d < 15, but does the samething as the bigger d.
			e.g. if d = 16, it is the same as d = 15; if d = 17, it is the same as d = 14, etc.
			so we do not need to consider the cases that d > 15. so we continue to substract d.
			*/

				j = j - 1;
				if (j == -1) {
					j = numbersread - 1;
				}
				d = input[j] - input[i];
				if (d < 0) {
					d = d + 31;
				}
			}
			if (d == 0) {

				// d = 0 means that two selected number is the same.
				// if so, we should roll to the next case (so break). because we cannot have an arithmetic sequences which has same numbers, otherwise, it is the run part.

				break;
			}
			next = input[j] + d;

			// so till here we ensured two selected item. now simply calculated the next theorictical term that the sequence should have if it is an arithmetic sequence.

			while (k < numbersread) {

				// also, the next theoritical number should be in a range of 1 and 31 inclusive. so we make some changes towards it.

				if (next > 31) {
					next = next % 31;
					k = 0;
				}
				if (next != input[k]) {
					k = k + 1;
				} else {
					t = t + 1;
					next = next + d;

					// now we make sure that an arithmetic progression exists (because t >= 3), and this is also the reason why t is initialised to be 2.
					
					while (n < numbersread) {
						if (next > 31) {
							next = next % 31;
							n = 0;
						}
						if (next == input[n]) {
							t = t + 1;
							next = next + d;
							n = 0;
						} else {
							n = n + 1;	
						}
					}
					// now write down those numbers as the conditions for this sequence.

					begin[ap] = input[i];
					diff[ap] = d;
					times[ap] = t;
					ap = ap + 1;
				}	
			}
			t = 2;
			k = 0;
			j = j - 1;
			e = e + 1;

			// I increment e to make the e loops run in control.

		}
		e = 0;
		j = 0;
		i = i + 1;
	}


// so now, maximum numbers in arithmetic progressions were found.

	int test, maximum;
	i = 0;
	t = 0;
	test = 0;
	maximum = 0;
	while (i < ap) {
		while (begin[i] > 0 && t < times[i]) {
			test = (t * diff[i]) + begin [i];
			if (test >= 31) {
				if (test % 31 != 0) {
					test = test % 31;
				} else {
					test = 31;
				}
			}
			if (test > maximum) {
				maximum = test;
			}
			t = t + 1;
		}
		t = 0;
		maxi[i] = maximum;
		maximum = 0;
		i = i + 1;
	}

	//  use maximum numbers to calculate the final scores.

	int sequencescore, c, f, g, realt;

	/*
	f and g is the judging variable which are needed during comparison.
	c is the counter for calculating the output, we can use ap again, but in order to make it more readable and easier, I use c.
	realt is the number of the output array, for the theorical results.
	*/

	c = ap;

	// ap is the possibile sequences that have been recorded.

	sequencescore = 0;
	f = 0;
	g = 0;
	realt = 0;

	/*
	after running random test for thousands of times, I get the rule to judge the winner:
	suppose two sequences, one is the 'better sequence', which is defined as maxi[]; and the other is the comparing sequence, which is the other output sequences.
	the one with higher mark will win.
	if they have same marks, the one whose first term is smaller will win.
	if terms are same, the longer one will win.
	if they are the same, the one whose second term is smaller, will win.
	*/

	while (c >= 0) {
		if ((maxi[c] * times[c] - 42) > sequencescore) {
			sequencescore = maxi[c] * times[c] - 42;
			realt = c;
		} else if ( maxi[c] * times[c] - 42 == sequencescore) {
			if (begin[c] < begin[realt]) {
				realt = c;
			} else if (begin[c] == begin[realt]) {
				if (times[realt] < times[c]) {
					realt = c;
				} else if (times[realt] == times[c]) {
					f = begin[c] + diff[c];
					g = begin[realt] + diff[realt];

					// this part aims to ensure the second term of the resulted sequence, and because it cannot be more than 31, so we should make some changes when these numbers > 31.

					if (f > 31) {
						f = f % 31;
					}
					if (g > 31) {
						g = g % 31;
					}
					if (f < g) {
						realt = c;
					}
				}
			}
		}
		c = c - 1;
	}

	// comparing part below.
	// firstly it should be compared alphabetically. this is the reasons for where should I put >= or <= .
	
	if ((evenscore >= oddscore) && (evenscore >= runscore) && (evenscore >= sequencescore)) {
		printf ("Even-triple {%d,%d,%d} scoring %d.\n", even[2], even[1], even[0], evenscore);
	}

	if ((oddscore > evenscore) && (oddscore >= runscore) && (oddscore >= sequencescore)) {
		printf ("Odd-triple {%d,%d,%d} scoring %d.\n", odd[2], odd[1], odd[0], oddscore);
	}

	int a;

	//	a is a counter of how many same numbers appear in the run part.

	a = 1;
	if ((runscore > evenscore) && (runscore > oddscore) && (runscore >= sequencescore)) {
		printf ("Run {");
		while (a < runsnumber) {
			printf ("%d,", display);
			a = a + 1;
		}
		if (a == runsnumber) {
			printf ("%d}", display);
		}
		printf (" scoring %d.\n", runscore);

	}

	int beginner;
	beginner = begin[realt];

// beginner is the first theoritical term for the resulted sequence, because I made an array called 'begin'.

	if ((sequencescore > evenscore) && (sequencescore > oddscore) && (sequencescore > runscore)) {
		printf ("Sequence {");
		i = 0;
		while (i < times[realt] - 1) {
			printf ("%d,", beginner);
			beginner = beginner + diff[realt];
			if (beginner > 31) {
				beginner = beginner - 31;
			}
			i = i + 1;
		}
		if (i == times[realt] - 1) {
			if (beginner > 31) {
				beginner = beginner - 31;
			}
			printf("%d}", beginner);
		}
		printf (" scoring %d.\n", sequencescore);
	}

	return 0;
}

//	Thanks for reading, have a good day :)
