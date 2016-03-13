/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include<stdio.h>

struct student {
	char *name;
	int score;
};
void quicksort(struct student *, int, int);

struct student ** topKStudents(struct student *students, int len, int K) {
	if (len <= 0 || K <= 0 || students == NULL)
		return NULL;
	else{
		int i, j;
		struct student **result = (struct student **)malloc(sizeof(struct student)*K);
		quicksort(students, 0, len - 1);
		for (i = 0; i<K; i++)
		{
			result[i] = &students[i];
		}

		return result;
	}

}
void quicksort(struct student *students, int first, int last){
	int pivot, j, i;
	struct student temp;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (students[i].score >= students[pivot].score&&i<last)
				i++;
			while (students[j].score<students[pivot].score)
				j--;
			if (i<j){
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}

		temp = students[pivot];
		students[pivot].score = students[j].score;
		students[j] = temp;
		quicksort(students, first, j - 1);
		quicksort(students, j + 1, last);

	}
}