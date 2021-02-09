#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* ch = malloc(sizeof(char) * 1000001);
	int count = 0, i = 0;

	fgets(ch, 1000001, stdin);

	while (ch[i] != '\0') {
		if (ch[i] == ' ')
			count++;

		i++;
	}
	if (ch[i-2] == ' ')
		count--;

	if (ch[0] == ' ')
		count--;

	printf("%d", count+1);

	return 0;
}