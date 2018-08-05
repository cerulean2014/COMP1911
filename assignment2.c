/*	Snapchar (assignment 2 of COMP1911 16S1).
	Written by Qingbei CHENG (z5042751@zmail.unsw.edu.au).
	Commenced date: 21/05/2016.
	Reference: https://www.cse.unsw.edu.au/~cs1911/16s1/assignments/snapchar/
*/

#include <stdio.h>
#include <math.h>

#define MAX_X       20
#define MAX_Y       20


//	I will make short explanations for every function below, much more details for these functions are shown after.
void printImage(int image[MAX_X][MAX_Y]);

int countBlackPixels(int image[MAX_X][MAX_Y]);
int countHeight(int image[MAX_X][MAX_Y]);
int countWidth(int image[MAX_X][MAX_Y]);

double calculateHB(int image[MAX_X][MAX_Y]);
double calculateVB(int image[MAX_X][MAX_Y]);
//	HB = Horizontal Balance; VB = Vertical Balance.

int countHoles(int image[MAX_X][MAX_Y]);
int countMaxZeroOfHoles(int image[MAX_X][MAX_Y]);
int countIslands(int image[MAX_X][MAX_Y]);

int countMax_h_Intersect(int image[MAX_X][MAX_Y]);
//	To count the maximum times that the letter can be intersected by a horizontal line.
int touch_boundary_x(int image[MAX_X][MAX_Y]);
//	To count the maximum times that the letter touches the x-axis boundary.
int count_middle_right_side_intersect(int image[MAX_X][MAX_Y]);
//	Find the middle of the letter, then set up a vertical line and count how many times that the line can intersect with the letter.
int higher_side(int image[MAX_X][MAX_Y]);
//	To determine which side of the tested letter is higher.
int middle_above_hole(int image[MAX_X][MAX_Y]);
//	Find the middle of the letter, find the first bottom line, then skip, then find how many holes will be there after.
int right_side_vertical_intersect(int image[MAX_X][MAX_Y]);
//	Set up a vertical line at the rightest part of the letter, then count the times that this line can intersect with the letter.
int top_horizontally_intersect(int image[MAX_X][MAX_Y]);
//	Find the top of the letter, then set up a horizontal line, count the times that the line can intersect with the letter.
int right_bottom_corner(int image[MAX_X][MAX_Y]);
//	Find the right bottom corner, then distinguish it (i.e. to see the number there is 0 or 1)


/*	Function prototypes are shown below.
	If you get confused somewhere, please do not be mad, I will show further explanation below the real functions. (otherwise it will be TOO MESSY)
*/

void processImage(int image[MAX_X][MAX_Y]) {
    int nBlackPixels, nHeight, nWidth, nHoles, nIslands, h_Intersection, touch_x, n_middle_intersect, determinant, nUpperHole, right_intersect, top_intersect, corner;
	double h, w, b, nDiagonal, nTallness, nBlackness, nHoleness;
	double h_b, v_b;
	char letter = '\0';

	// Definition part below.
    nBlackPixels = countBlackPixels(image);
	nHeight = countHeight(image);
	nWidth = countWidth(image);
	h = nHeight;
	w = nWidth;
	b = nBlackPixels;
	nDiagonal = sqrt(h * h + w * w);
	nTallness = h / w;
	nBlackness = b / (h * w);

	h_b = calculateHB(image) / b / w;
	v_b = calculateVB(image) / b / h;

	nHoles = countHoles(image);
	nHoleness = countMaxZeroOfHoles(image) / b;
	nIslands = countIslands(image);

	/*	Distinguishing letters part below.
		islands = 2 : i, j;
		all other letters' island = 1;
			holes = 2 : a, g;
			holes = 1 : a, b, d, e, g;
			holes = 0 : c, f, h, k ,l ,m;

	*/

	h_Intersection = countMax_h_Intersect(image);
	touch_x = touch_boundary_x(image);
	n_middle_intersect = count_middle_right_side_intersect(image);
	determinant = higher_side(image);
	nUpperHole = middle_above_hole(image);
	right_intersect = right_side_vertical_intersect(image);
	top_intersect = top_horizontally_intersect(image);
	corner = right_bottom_corner(image);

	if (nIslands == 2) {
		//ij
		if (h_b <= 0.5) {
			letter = 'i';
		} else {
			letter = 'j';
		}

	} else {
		//islands = 1 : abcdefghklm
		if (nHoles == 2) {
			//ag
			if (corner == 0) {
				letter = 'g';
			} else {
				letter = 'a';
			}
		} else if (nHoles == 1) {
			//abdeg
			if (determinant == -1) {
				letter = 'b';
			} else if (determinant == 1) {
				letter = 'd';
			} else {
				//aeg
				if (nUpperHole < 0) {
					letter = 'a';
				} else {
					if (h_b > 0.5) {
						letter = 'g';
					} else {
						letter = 'e';
					}
				}
			}

		} else {
			//cfhklm

			if (top_intersect == 2) {
				//sometimes m can only have 2 intersection with a horizontal line, such as m3 picture.
				letter = 'm';
			} else {

				if (h_Intersection >= 3) {
					letter = 'm';
				} else {
					//cfhkl
					if (touch_x == 1) {
						//cfl
						if (right_intersect == 1) {
							//fl
							if (v_b > 0.5) {
								letter = 'f';
							} else {
								letter = 'l';
							}
						} else {
							letter = 'c';
						}

					} else {
						//hk
						if (right_intersect == 2) {
							letter = 'k';
						} else {
							//hk
							if (n_middle_intersect == 1) {
								letter = 'h';
							} else {
								letter = 'k';
							}
						}
					}
				}
			}
		}
	}


	// Printing part below.

	printf("Pixel-count: %d\n", nBlackPixels);
	printf("Height: %d\n", nHeight);
	printf("Width: %d\n", nWidth);
	printf("Diagonal: %.6lf\n", nDiagonal);
	printf("Tallness: %.6lf\n", nTallness);
	printf("Blackness: %.6lf\n", nBlackness);

	printf("Horizontal-balance: %.6lf\n", h_b);
	printf("Vertical-balance: %.6lf\n", v_b);

	printf("Holes: %d\n", nHoles);
	printf("Holeness: %.6lf\n", nHoleness);
	printf("Islands: %d\n", nIslands);

	printf("Letter: %c\n", letter);
}


//	Now we are in the functions part, the mean reason that I wrote such a lot of functions is that I do not want to use numbers such as balances or holeness, which are not that accurate as I expect, so I wrote more functions focussing on the characteristics of letters.


/*	The function below counts the number of black pixels.
	It counts the pixels from the bottom to the top, from left to right, just as coordinate goes.
*/

int countBlackPixels(int image[MAX_X][MAX_Y]) {
    int x, y;
	int number_of_black_pixel = 0;
    x = 0;
    while (x < MAX_X) {
        y = 0;
        while (y < MAX_Y) {
            if (image[x][y] == 1) {
				number_of_black_pixel = number_of_black_pixel + 1;
            }
            y = y + 1;
        }
        x = x + 1;
    }
    return number_of_black_pixel;
}


/*	The function below counts the height.
	It finds the lowest and then the highest black pixels.
	And it is obviously that both lowest and highest black pixels' y-coordinates can not be MAX_Y.
*/

int countHeight(int image[MAX_X][MAX_Y]) {
    int x, y;
	int height_of_input;
	int highest = MAX_Y;
	int lowest = MAX_Y;

	// Lowest part first.
    y = 0;
    while (y < MAX_Y) {
        x = 0;
        while (x < MAX_X) {
            if (image[x][y] == 1) {
				lowest = y;
				break;
            }
            x = x + 1;
        }
		if (lowest != MAX_Y) {
			break;
		}
        y = y + 1;
    }

	// Then highest part.
	y = MAX_Y - 1;
    while (y >= 0) {
        x = 0;
        while (x < MAX_X) {
            if (image[x][y] == 1) {
				highest = y;
				break;
            }
            x = x + 1;
        }
		if (highest != MAX_Y) {
			break;
		}
        y = y - 1;
    }

	height_of_input = highest - lowest + 1;
    return height_of_input;
}


/*	The function below counts the height.
	It finds the leftest and then the rightest black pixels.
	And it is obviously that both leftest and rightest black pixels' x-coordinates can not be MAX_X.
*/

int countWidth(int image[MAX_X][MAX_Y]) {
    int x, y;
	int width_of_input;
	int leftest = MAX_X;
	int rightest = MAX_X;

	// Leftest part first.
    x = 0;
    while (x < MAX_X) {
        y = 0;
        while (y < MAX_Y) {
            if (image[x][y] == 1) {
				leftest = x;
				break;
            }
            y = y + 1;
        }
		if (leftest != MAX_X) {
			break;
		}
        x = x + 1;
    }

	// Then rightest part.
	x = MAX_X - 1;
    while (x >= 0) {
        y = 0;
        while (y < MAX_Y) {
            if (image[x][y] == 1) {
				rightest = x;
				break;
            }
            y = y + 1;
        }
		if (rightest != MAX_X) {
			break;
		}
        x = x - 1;
    }

	width_of_input = rightest - leftest + 1;
    return width_of_input;
}


/*	This function below calculates the horizontal-balance.
	Because all pixels are square, so just suppose the centre of mass of each pixel is at the geometric centre.
	For example, the first pixel's centre of mass is at (0.5,0.5), then (1.5,0.5) counts towards right, and (0.5,1.5) counts towards top.
	Then we get the sum of all black pixels' x-coordinates, then divide it by the numbers of black pixels, then divide it by the width.
*/

double calculateHB(int image[MAX_X][MAX_Y]) {
    int x, y;
	double sum_of_x = 0.0;
	double centre_of_mass_x = 0.0;
    x = 0;
    while (x < MAX_X) {
        y = 0;
        while (y < MAX_Y) {
            if (image[x][y] == 1) {
				centre_of_mass_x = x + 0.5;
				sum_of_x = sum_of_x + centre_of_mass_x;
            }
            y = y + 1;
        }
        x = x + 1;
    }
    return sum_of_x;
}


/*	This function below calculates the vertital-balance.
	Things are quite similar as the horizontal balance part above.
	Then we get the sum of all black pixels' y-coordinates, then divide it by the numbers of black pixels, then divide it by the height.
*/

double calculateVB(int image[MAX_X][MAX_Y]) {
    int x, y;
	double sum_of_y = 0.0;
	double centre_of_mass_y = 0.0;
    x = 0;
    while (x < MAX_X) {
        y = 0;
        while (y < MAX_Y) {
            if (image[x][y] == 1) {
				centre_of_mass_y = y + 0.5;
				sum_of_y = sum_of_y + centre_of_mass_y;
            }
            y = y + 1;
        }
        x = x + 1;
    }
    return sum_of_y;
}


/*	This function below counts holes.
	The lowest y-coordinate of the ideally possible holes are 1.
	The lowest x-coordinate of the ideally possible holes are 1.
	So x and y starts counting at 1.
*/

int countHoles(int image[MAX_X][MAX_Y]){
	int x, y;
	int number_of_holes = 0;
	int begin_bottom_of_hole;
	int end_bottom_of_hole;
	int begin_top_of_hole;
	int end_top_of_hole;
	int bottom_line_of_hole_exists = 1;
	int top_line_of_hole_exists = 1;
	int i = 0;

	y = 1;
	while (y < MAX_Y - 1) {
		x = 1;

		begin_bottom_of_hole = -1;
		while (x < MAX_X) {
			if (image[x][y] == 0 && image[x - 1][y] == 1) {
			// find the first 0.
				begin_bottom_of_hole = x;
				break;
			}
			x = x + 1;
		}
		if (x == MAX_X) {
			y = y + 1;

		} else {
			end_bottom_of_hole == -1;
			if (x < MAX_X) {
				while (x < MAX_X) {
					if (image[x][y] == 1 && image[x - 1][y] == 0) {
					//find the last 0.
						end_bottom_of_hole = x - 1;
						break;
					}
					x = x + 1;
				}
				if (x == MAX_X) {
					y = y + 1;
				} else {

					if (begin_bottom_of_hole >= 0 && end_bottom_of_hole >= 0) {
					//bottom line found.
						bottom_line_of_hole_exists = 1;
						i = 0;
						while (begin_bottom_of_hole + i <= end_bottom_of_hole) {
							if (image[begin_bottom_of_hole + i][y - 1] != 1) {
								bottom_line_of_hole_exists = 0;
							}
							i = i + 1;
						}
						if (bottom_line_of_hole_exists == 1) {
							//this line tends to be the base line of a hole.
							//then the top line of the hole should be found if possible.

							while (y < MAX_Y - 1) {
								x = 1;
								begin_top_of_hole = -1;

								while (x < MAX_X) {
									if (image[x][y] == 0 && image[x - 1][y] == 1) {
									// find the first 0.
										begin_top_of_hole = x;
										break;
									}
									x = x + 1;
								}

								if (x == MAX_X) {
									y = y + 1;
									break;
								} else {
									end_top_of_hole == -1;
									while (x < MAX_X) {
										if (image[x][y] == 1 && image[x - 1][y] == 0) {
										//find the last 0.
											end_top_of_hole = x - 1;
											break;
										}
										x = x + 1;
									}
									if (x == MAX_X) {
										y = y + 1;
										break;
									} else {

										if (begin_top_of_hole >= 0 && end_top_of_hole >= 0) {
										//top line found.
											top_line_of_hole_exists = 1;
											i = 0;
											while (begin_top_of_hole + i <= end_top_of_hole) {
												if (image[begin_top_of_hole + i][y + 1] != 1) {
													top_line_of_hole_exists = 0;
												}
												i = i + 1;
											}
											if (top_line_of_hole_exists == 0) {
												y = y + 1;
											} else {
												//this line tends to be the top line of the hole.
												number_of_holes = number_of_holes + 1;
												y = y + 1;
												break;
											}
										} else {
											// means that there is a line next above to the bottom line which is not enclosed.
											y = y + 1;
											bottom_line_of_hole_exists == 0;
											break;
										}
									}
								}
							}
						} else {
							y = y + 1;
						}
					}
				}
			}
		}
	}
	return number_of_holes;
}


/*	This function below records the maximum numbers of zeros in holes of the input letters.
	The method used here is similar as bubble sort.
*/


int countMaxZeroOfHoles(int image[MAX_X][MAX_Y]) {
	int x, y;
	int number_of_zeros_in_holes = 0;
	int max_number_of_zeros_in_holes = 0;
	int begin_bottom_of_hole;
	int end_bottom_of_hole;
	int begin_top_of_hole;
	int end_top_of_hole;
	int bottom_line_of_hole_exists = 1;
	int top_line_of_hole_exists = 1;
	int i = 0;

	y = 1;
	while (y < MAX_Y - 1) {
		x = 1;
		begin_bottom_of_hole = -1;
		while (x < MAX_X) {
			if (image[x][y] == 0 && image[x - 1][y] == 1) {
			// find the first 0.
				begin_bottom_of_hole = x;
				break;
			}
			x = x + 1;
		}
		if (x == MAX_X) {
			y = y + 1;
		} else {
			end_bottom_of_hole == -1;
			if (x < MAX_X) {
				while (x < MAX_X) {
					if (image[x][y] == 1 && image[x - 1][y] == 0) {
					//find the last 0.
						end_bottom_of_hole = x - 1;
						break;
					}
					x = x + 1;
				}
				if (x == MAX_X) {
					y = y + 1;
				} else {
					if (begin_bottom_of_hole >= 0 && end_bottom_of_hole >= 0) {
					//bottom line found.
						bottom_line_of_hole_exists = 1;
						i = 0;
						while (begin_bottom_of_hole + i <= end_bottom_of_hole) {
							if (image[begin_bottom_of_hole + i][y - 1] != 1) {
								bottom_line_of_hole_exists = 0;
							}
							i = i + 1;
						}
						if (bottom_line_of_hole_exists == 1) {
							//this line tends to be the base line of a hole.
							//then the top line of the hole should be found if possible.

							while (y < MAX_Y - 1) {
								x = 1;
								begin_top_of_hole = -1;

								while (x < MAX_X) {
									if (image[x][y] == 0 && image[x - 1][y] == 1) {
									// find the first 0, and starts counting.
										begin_top_of_hole = x;
										break;
									}
									x = x + 1;
								}
								if (x == MAX_X) {
									number_of_zeros_in_holes = 0;
									y = y + 1;
									break;
								} else {
									end_top_of_hole == -1;
									while (x < MAX_X) {
										if (image[x][y] == 1 && image[x - 1][y] == 0) {
										//find the last 0.
											end_top_of_hole = x - 1;
											break;
										}
										number_of_zeros_in_holes = number_of_zeros_in_holes + 1;
										x = x + 1;
									}
									if (x == MAX_X) {
										y = y + 1;
										number_of_zeros_in_holes = 0;
										break;
									} else {

										if (begin_top_of_hole >= 0 && end_top_of_hole >= 0) {
										//top line found.
											top_line_of_hole_exists = 1;
											i = 0;
											while (begin_top_of_hole + i <= end_top_of_hole) {
												if (image[begin_top_of_hole + i][y + 1] != 1) {
													top_line_of_hole_exists = 0;

												}
												i = i + 1;
											}
											if (top_line_of_hole_exists == 0) {
												y = y + 1;
											} else {
												//this line tends to be the top line of the hole.
												y = y + 1;
												if (max_number_of_zeros_in_holes < number_of_zeros_in_holes) {
													max_number_of_zeros_in_holes = number_of_zeros_in_holes;
												}
												number_of_zeros_in_holes = 0;
												break;
											}
										} else {
											// means that there is a line next above to the bottom line which is not enclosed.
											y = y + 1;
											bottom_line_of_hole_exists == 0;
											number_of_zeros_in_holes = 0;
											break;
										}
									}
								}
							}
						} else {
							y = y + 1;
							number_of_zeros_in_holes = 0;
						}
					}
				}
			}
		}
	}
	return max_number_of_zeros_in_holes;
}


/*	This function below counts islands.
	It is easy to see that in the region of the letter, if there is one empty line (without any "1"s), there should be 2 (= 1 + 1) islands.
	Also there is at least 1 island, and there is at least 1 black pixel at the bottom line.
	x = MAX_X means that the line above has no "1". So an island is finished counting.
*/

int countIslands(int image[MAX_X][MAX_Y]) {
	int x, y;
	int black_pixel_exist = 0;
	int number_of_islands = 1;
	y = MAX_Y - 1;
    while (y >= 0) {
        x = 0;
        while (x < MAX_X) {
            if (image[x][y] == 1) {
				black_pixel_exist = black_pixel_exist + 1;
				break;
            }
            x = x + 1;
        }
		if (x == MAX_X && black_pixel_exist > 0) {
			number_of_islands = number_of_islands + 1;
			black_pixel_exist = 0;
		}
        y = y - 1;
    }
	return number_of_islands;
}


/*	This function below aims to count the maximum times of intersection that a horizontal line can make with the letter.
	It is some kind of helpful to distinguish letters, especially for letter 'm'.
*/

int countMax_h_Intersect(int image[MAX_X][MAX_Y]) {
	int x, y;
	int max = 0;
	int intersect_time = 0;
	y = 0;
    while (y < MAX_Y) {
        x = 0;
		intersect_time = 0;
        while (x < MAX_X) {
			while (x < MAX_X) {
				while (image[x][y] == 0) {
					x = x + 1;
					if (x == MAX_X) {
						break;
					}
				}
				if (x == MAX_X) {
					break;
				}

				while (image[x][y] == 1) {
					x = x + 1;
					if (x == MAX_X) {
						break;
					}
				}
				if (x == MAX_X) {
					break;
				}
				intersect_time = intersect_time + 1;
			}
			x = x + 1;
		}
		if (max < intersect_time) {
			max = intersect_time;
		}
        y = y + 1;
    }
	return max;
}



//	This function below is to count how many times that the letter touch the x-axis boundary.
//	It will be useful for distinguishing the letter without holes (cfhkl), cfl touch the x-axis boundary once, hk touch twice.

int touch_boundary_x(int image[MAX_X][MAX_Y]) {
	int x, y;
	int i = 0;
	int times = 0;
	y = 0;
	x = 0;
	while (x < MAX_X) {
		while (x < MAX_X) {
			if (image[x][y] == 1) {
				times = times + 1;
				break;
			}
			x = x + 1;
		}
		while (x < MAX_X) {
			if (image[x][y] == 0) {
				break;
			}
			x = x + 1;
		}
	}
	return times;
}


//	This function is to count how many times that a vertical line (whose x-coordinate is at the 5 / 6 of the tested letter) can intersect with the tested letter.
//	I choose 5/6 because this reason has the highest possibility to find the difference between h and k (1 and 2 intersection), and this function is designed for distinguishing these 2 letters.

int count_middle_right_side_intersect(int image[MAX_X][MAX_Y]) {
	int x, y;
	int begin_x = 0;
	int end_x = 0;
	int middle_x;
	int counter = 0;

	x = 0;
	while (x < MAX_X) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			begin_x = x;
			break;
		} else {
			x = x + 1;
		}
	}

	x = MAX_X - 1;
	while (x >= 0) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			end_x = x;
			break;
		} else {
			x = x - 1;
		}
	}

	middle_x = 5 * (begin_x + end_x) / 6;

	y = 0;
	counter = 0;
	while (y < MAX_Y) {
		while (y < MAX_Y) {
			if (image[middle_x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			counter = counter + 1;
			while (y < MAX_Y) {
				if (image[middle_x][y] == 1) {
					y = y + 1;
				} else {
					break;
				}
			}
			if (y == MAX_Y) {
				break;
			} else {
				y = y + 1;
			}
		} else {
			break;
		}
	}

	return counter;
}


/*	This function is a continued function of the last one (count_middle_right_side_intersect).
	But it is a little bit different, it finds the middle of x-coordinates then set up a vertical line as a boundary
	If the right part of the boundary is higher, returns 1 (letter "d"), same returns 0 ("aeg"), left part higher returns -1 ("b").
*/

int higher_side(int image[MAX_X][MAX_Y]) {

	int x, y;
	int begin_x = 0;
	int end_x = 0;
	int middle_x;
	int left_highest = 0;
	int right_highest = 0;

	x = 0;
	while (x < MAX_X) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			begin_x = x;
			break;
		} else {
			x = x + 1;
		}
	}

	x = MAX_X - 1;
	while (x >= 0) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			end_x = x;
			break;
		} else {
			x = x - 1;
		}
	}

	middle_x = (begin_x + end_x + 1) / 2;

	y = MAX_Y - 1;
	while (y >= 0) {
		x = 0;
		while (x < middle_x) {
			if (image[x][y] == 0) {
				x = x + 1;
			} else {
				break;
			}
		}
		if (x == middle_x) {
			y = y - 1;
		} else {
			left_highest = y;
			break;
		}
	}

	y = MAX_Y - 1;
	while (y >= 0) {
		x = middle_x + 1;
		while (x < MAX_X) {
			if (image[x][y] == 0) {
				x = x + 1;
			} else {
				break;
			}
		}
		if (x == MAX_X) {
			y = y - 1;
		} else {
			right_highest = y;
			break;
		}
	}

	if (right_highest > left_highest) {
		return 1;
	} else if (right_highest == left_highest) {
		return 0;
	} else {
		return -1;
	}
}


/*	This function aims to find the middle x-coordinate, then find the bottom of a hole (if possible) without doing anything but skipping the bottom.
	Then it starts to find holes, this function is designed for distinguishing the letters with 1 hole : "a" (return -1) and "eg" (return 1).
*/

int middle_above_hole(int image[MAX_X][MAX_Y]) {

	int x, y;
	int begin_x = 0;
	int end_x = 0;
	int middle_x;
	int left_highest = 0;
	int right_highest = 0;
	int new_begin_y = 0;
	int number_of_holes = 0;
	int begin_bottom_of_hole;
	int end_bottom_of_hole;
	int begin_top_of_hole;
	int end_top_of_hole;
	int bottom_line_of_hole_exists = 1;
	int top_line_of_hole_exists = 1;
	int i = 0;

	x = 0;
	while (x < MAX_X) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			begin_x = x;
			break;
		} else {
			x = x + 1;
		}
	}

	x = MAX_X - 1;
	while (x >= 0) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y < MAX_Y) {
			end_x = x;
			break;
		} else {
			x = x - 1;
		}
	}

	middle_x = (begin_x + end_x + 1) / 2;

	y = 0;
	x = middle_x;
	while (y < MAX_Y) {
		if (image[x][y] == 0) {
			y = y + 1;
		} else {
			break;
		}
	}

	while (y < MAX_Y) {
		if (image[x][y] == 1) {
			y = y + 1;
		} else {
			break;
		}
	}

	if (y == MAX_Y) {
		return -1;
	} else {
		y = y + 1;
		while (y < MAX_Y - 1) {
			x = 1;

			begin_bottom_of_hole = -1;
			while (x < MAX_X) {
				if (image[x][y] == 0 && image[x - 1][y] == 1) {
				// find the first 0.
					begin_bottom_of_hole = x;
					break;
				}
				x = x + 1;
			}
			if (x == MAX_X) {
				y = y + 1;

			} else {
				end_bottom_of_hole == -1;
				if (x < MAX_X) {
					while (x < MAX_X) {
						if (image[x][y] == 1 && image[x - 1][y] == 0) {
						//find the last 0.
							end_bottom_of_hole = x - 1;
							break;
						}
						x = x + 1;
					}
					if (x == MAX_X) {
						y = y + 1;
					} else {

						if (begin_bottom_of_hole >= 0 && end_bottom_of_hole >= 0) {
						//bottom line found.
							bottom_line_of_hole_exists = 1;
							i = 0;
							while (begin_bottom_of_hole + i <= end_bottom_of_hole) {
								if (image[begin_bottom_of_hole + i][y - 1] != 1) {
									bottom_line_of_hole_exists = 0;
								}
								i = i + 1;
							}
							if (bottom_line_of_hole_exists == 1) {
								//this line tends to be the base line of a hole.
								//then the top line of the hole should be found if possible.

								while (y < MAX_Y - 1) {
									x = 1;
									begin_top_of_hole = -1;

									while (x < MAX_X) {
										if (image[x][y] == 0 && image[x - 1][y] == 1) {
										// find the first 0.
											begin_top_of_hole = x;
											break;
										}
										x = x + 1;
									}

									if (x == MAX_X) {
										y = y + 1;
										break;
									} else {
										end_top_of_hole == -1;
										while (x < MAX_X) {
											if (image[x][y] == 1 && image[x - 1][y] == 0) {
											//find the last 0.
												end_top_of_hole = x - 1;
												break;
											}
											x = x + 1;
										}
											if (x == MAX_X) {
											y = y + 1;
											break;
										} else {

											if (begin_top_of_hole >= 0 && end_top_of_hole >= 0) {
											//top line found.
												top_line_of_hole_exists = 1;
												i = 0;
												while (begin_top_of_hole + i <= end_top_of_hole) {
													if (image[begin_top_of_hole + i][y + 1] != 1) {
														top_line_of_hole_exists = 0;
													}
													i = i + 1;
												}
												if (top_line_of_hole_exists == 0) {
													y = y + 1;
												} else {
													//this line tends to be the top line of the hole.
													number_of_holes = number_of_holes + 1;
													y = y + 1;
													break;
												}
											} else {
												// means that there is a line next above to the bottom line which is not enclosed.
												y = y + 1;
												bottom_line_of_hole_exists == 0;
												break;
											}
										}
									}
								}
							} else {
								y = y + 1;
							}
						}
					}
				}
			}
		}
	}

	if (number_of_holes > 0) {
		return 1;
	} else {
		return -1;
	}
}


//	This function below is to find the times that the rightest vertical line intersects with the letter.
//	It can tell the main difference between letter "h" and "k".

int right_side_vertical_intersect(int image[MAX_X][MAX_Y]) {
	int x, y;
	int times = 0;
	x = MAX_X - 1;
	while (x >= 0) {
		y = 0;
		while (y < MAX_Y) {
			while (y < MAX_Y) {
				if (image[x][y] == 0) {
					y = y + 1;
				} else {
					break;
				}
			}
			if (y == MAX_Y) {
				break;
			} else {
				times = times + 1;
				while (y < MAX_Y) {
					if (image[x][y] == 1) {
						y = y + 1;
					} else {
						break;
					}
				}
				if (y == MAX_Y) {
					break;
				}
			}
		}
		if (times > 0) {
			return times;
		}
		x = x - 1;
	}
	return 0;
}


//	This function aims to count the times that the top horizontal line (where the "1" appears first time) with the tested letter.
//	It can find some of "m", but not all m. However it is still quite useful because this is the case that letters (such as m3 image) would meet.

int top_horizontally_intersect(int image[MAX_X][MAX_Y]) {
	int x, y;
	int times = 0;
	y = MAX_Y - 1;
	while (y >= 0) {
		x = 0;
		while (x < MAX_X) {
			if (image[x][y] == 0) {
				x = x + 1;
			} else {
				break;
			}
		}
		if (x == MAX_X) {
			y = y - 1;
		} else {
			break;
		}
	}

	x = 0;
	while (x < MAX_X) {
		while (x < MAX_X) {
			if (image[x][y] == 0) {
				x = x + 1;
			} else {
				times = times + 1;
				break;
			}
		}
		if (x == MAX_X) {
			break;
		} else {
			while (x < MAX_X) {
				if (image[x][y] == 1) {
					x = x + 1;
				} else {
					break;
				}
			}
			if (x == MAX_X) {
				break;
			}
		}
	}
	return times;
}


//	This function below is to find the number at the right bottom corner of the tested letter.
//	It was designed for distinguishing letters "a" and "g", as we can see from the reference images that the right bottom corner of letter "a" is 1, but for "g", it is 0.

int right_bottom_corner(int image[MAX_X][MAX_Y]) {

	int x, y;
	x = MAX_X - 1;
	while (x >= 0) {
		y = 0;
		while (y < MAX_Y) {
			if (image[x][y] == 0) {
				y = y + 1;
			} else {
				break;
			}
		}
		if (y == MAX_Y) {
			x = x - 1;
		} else {
			break;
		}
	}
	return image[x][0];
}







//	Till here are all I did for assignment 2.
//	Thanks for reading.

//	Functions below are given by Andrew, and I did not change anything.






//	This function prints the image which you may find useful for debugging
void printImage(int image[MAX_X][MAX_Y]) {
    int x, y;

    y = MAX_Y - 1;
    while (y >= 0) {
        x = 0;
        while (x < MAX_X) {
            if (image[x][y] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
            x = x + 1;
        }
        printf("\n");
        y = y - 1;
    }
    return;
}

//
// You do not need to understand the code below here.
//
// You do not need to change the code below here.
//
// If you wish to modify the code below, you have
// probably misunderstood the assignment specification
//


void readImage(FILE *stream, int image[MAX_X][MAX_Y]);

int main(int argc, char *argv[]) {
    int image[MAX_X][MAX_Y];
    FILE *f;
    int i;

    if (argc == 1) {
        readImage(stdin, image);
        processImage(image);
        return 0;
    }

    for (i = 1; i < argc; i = i + 1) {
        f = fopen(argv[i], "r");
        if (f == NULL) {
            fprintf(stderr, "image2letter: Can not open image file '%s'", argv[i]);
            return 1;
        }
        readImage(f, image);
        processImage(image);
    }
    return 0;
}


void readImage(FILE *stream, int image[MAX_X][MAX_Y]) {
    char line[4096];
    int y, x;

    for (y = MAX_Y - 1; y >= 0; y = y - 1) {
        if (fgets(line, sizeof line, stream) == NULL)
            break;
        if (line[0] == 'P' && y == MAX_Y - 1) {
            // PBM file (hopefully ascii) - skip dimensions
            fgets(line, sizeof line, stream);
            fgets(line, sizeof line, stream);
        }
        for (x = 0; x < MAX_X; x = x + 1) {
            if (line[x] == '\0' || line[x] == '\n') {
                break;
            } else if (line[x] == '0' || line[x] == ' ') {
                image[x][y] = 0;
            } else {
                image[x][y] = 1;
            }
        }
        // zero remainder of the row
        for (; x < MAX_X; x = x + 1)
            image[x][y] = 0;
    }
    // zero any remaining rows
    for (; y >= 0; y = y - 1)
        for (x = 0; x < MAX_X; x = x + 1)
            image[x][y] = 0;
}
