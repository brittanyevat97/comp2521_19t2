// Develop an algorithm to determine if a character array of
// length n encodes a palindrome — that is, it reads the same
// forward and backward. For example, racecar is a palindrome.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Write the algorithm in pseudocode

//  isPalindrome(A, len):
//      i = 0
//      j = len - 1
//      while i < j do
//          if A[i] != A[j] then
//              return false
//          end if
//          i = i + 1
//          j = j - 1
//      end while
//      return true

// Implement the algorithm in C

static bool isPalindrome (char A[], int len);

int main (int argc, char *argv[]) {
	if (argc == 2) {
		if (isPalindrome(argv[1], strlen(argv[1])))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

static bool isPalindrome (char A[], int len) {
    int i = 0;
    int j = len - 1;
    while (i < j) {
        if (A[i] != A[j])
            return false;
        i++;
        j--;
    }
    return true;
}
