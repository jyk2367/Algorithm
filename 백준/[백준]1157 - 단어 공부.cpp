#include <stdio.h>

int main(void)
{
	int i, j;
	int max = 0;
	int s[26] = { 0 , };

	char word[1000001] = { 0, };
	scanf("%s", word);
	for (i = 0; word[i] != NULL; i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
			s[word[i] - 'A']++;
		else if (word[i] >= 'a' && word[i] <= 'z')
			s[word[i] - 'a']++;
	}
	for (i = 0; i < 26; i++)
	{
		if (s[i] > max) {
			max = s[i];
			j = i;
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (s[i] == max && j != i)
		{
			printf("?\n");
			return 0;
		}
	}
	printf("%c\n", j + 65);
	return 0;
}