// Author: Christian Ehrhardt

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char txt[1000];
int LEN;
char listc[210][210];

#define UK -1
#define YES 1
#define NO 0

void init ()
{
	int i, j;
	for (i=0; i<=LEN; ++i) {
		for (j=0; j<=LEN; ++j) {
			listc[i][j] = UK;
		}
		listc[i][i] = YES;
	}
}
int islist (int i, int j);
int isatom (int i, int j);

int isset (int i, int j)
{
	if (txt[i] != '{')
		return 0;
	if (txt[j] != '}')
		return 0;
	if (i+1 == j)
		return 1;
	return islist (i+1, j-1);
}

int islist (int i, int j)
{
	int k;
	if (listc[i][j] == YES)
		return 1;
	if (listc[i][j] == NO)
		return 0;
	if (i==j)
		return listc[i][j] = 1;
	if (isatom (i, j))
		return listc[i][j] = 1;
	for (k=i+1; k<j; ++k) {
		if (txt[k] != ',')
			continue;
		if (isatom (i, k-1) && islist (k+1, j)) {
			return listc[i][j] = 1;
		}
	}
	return listc[i][j] = 0;
}

int isatom (int i, int j){
	if (i==j)
		return 1;
	return isset (i, j);
}

int main (){
	int kase, nkase = 1;
	scanf ("%d", &kase);
	while (nkase <= kase) {
		scanf("%s", txt);
		LEN = strlen (txt)-1;
		init ();
		printf ("Word #%d:%s Set\n", nkase, isset (0, LEN)?"":" No");
		nkase++;
	}
	return 0;
}
