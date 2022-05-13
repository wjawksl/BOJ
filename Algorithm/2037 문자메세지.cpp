#include<iostream>
#include<string>

using namespace std;
int main()
{
	char btn, s[1010];
	int p, w, time = 0;
	scanf("%d %d", &p, &w);
	getchar();
	scanf("%[^\n]s", s);

	string str = s;
	for (int i = 0; i < str.length(); i++)
	{
		btn = str[i];
		switch (btn)
		{
		case 'A':
			if (i != 0)
			{
				if (str[i - 1] == 'A' || str[i - 1] == 'B' || str[i - 1] == 'C')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'B':
			if (i != 0)
			{
				if (str[i - 1] == 'A' || str[i - 1] == 'B' || str[i - 1] == 'C')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'C':
			if (i != 0)
			{
				if (str[i - 1] == 'A' || str[i - 1] == 'B' || str[i - 1] == 'C')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'D':
			if (i != 0)
			{
				if (str[i - 1] == 'D' || str[i - 1] == 'E' || str[i - 1] == 'F')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'E':
			if (i != 0)
			{
				if (str[i - 1] == 'D' || str[i - 1] == 'E' || str[i - 1] == 'F')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'F':
			if (i != 0)
			{
				if (str[i - 1] == 'D' || str[i - 1] == 'E' || str[i - 1] == 'F')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'G':
			if (i != 0)
			{
				if (str[i - 1] == 'G' || str[i - 1] == 'H' || str[i - 1] == 'I')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'H':
			if (i != 0)
			{
				if (str[i - 1] == 'G' || str[i - 1] == 'H' || str[i - 1] == 'I')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'I':
			if (i != 0)
			{
				if (str[i - 1] == 'G' || str[i - 1] == 'H' || str[i - 1] == 'I')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'J':
			if (i != 0)
			{
				if (str[i - 1] == 'J' || str[i - 1] == 'K' || str[i - 1] == 'L')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'K':
			if (i != 0)
			{
				if (str[i - 1] == 'J' || str[i - 1] == 'K' || str[i - 1] == 'L')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'L':
			if (i != 0)
			{
				if (str[i - 1] == 'J' || str[i - 1] == 'K' || str[i - 1] == 'L')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'M':
			if (i != 0)
			{
				if (str[i - 1] == 'M' || str[i - 1] == 'N' || str[i - 1] == 'O')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'N':
			if (i != 0)
			{
				if (str[i - 1] == 'M' || str[i - 1] == 'N' || str[i - 1] == 'O')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'O':
			if (i != 0)
			{
				if (str[i - 1] == 'M' || str[i - 1] == 'N' || str[i - 1] == 'O')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'P':
			if (i != 0)
			{
				if (str[i - 1] == 'P' || str[i - 1] == 'Q' || str[i - 1] == 'R' || str[i - 1] == 'S')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'Q':
			if (i != 0)
			{
				if (str[i - 1] == 'P' || str[i - 1] == 'Q' || str[i - 1] == 'R' || str[i - 1] == 'S')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'R':
			if (i != 0)
			{
				if (str[i - 1] == 'P' || str[i - 1] == 'Q' || str[i - 1] == 'R' || str[i - 1] == 'S')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'S':
			if (i != 0)
			{
				if (str[i - 1] == 'P' || str[i - 1] == 'Q' || str[i - 1] == 'R' || str[i - 1] == 'S')
				{
					time += w + p * 4;
				}
				else time += p * 4;
			}
			else time += p * 4;
			break;
		case 'T':
			if (i != 0)
			{
				if (str[i - 1] == 'T' || str[i - 1] == 'U' || str[i - 1] == 'V')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'U':
			if (i != 0)
			{
				if (str[i - 1] == 'T' || str[i - 1] == 'U' || str[i - 1] == 'V')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'V':
			if (i != 0)
			{
				if (str[i - 1] == 'T' || str[i - 1] == 'U' || str[i - 1] == 'V')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'W':
			if (i != 0)
			{
				if (str[i - 1] == 'W' || str[i - 1] == 'X' || str[i - 1] == 'Y' || str[i - 1] == 'Z')
				{
					time += w + p;
				}
				else time += p;
			}
			else time += p;
			break;
		case 'X':
			if (i != 0)
			{
				if (str[i - 1] == 'W' || str[i - 1] == 'X' || str[i - 1] == 'Y' || str[i - 1] == 'Z')
				{
					time += w + p * 2;
				}
				else time += p * 2;
			}
			else time += p * 2;
			break;
		case 'Y':
			if (i != 0)
			{
				if (str[i - 1] == 'W' || str[i - 1] == 'X' || str[i - 1] == 'Y' || str[i - 1] == 'Z')
				{
					time += w + p * 3;
				}
				else time += p * 3;
			}
			else time += p * 3;
			break;
		case 'Z':
			if (i != 0)
			{
				if (str[i - 1] == 'W' || str[i - 1] == 'X' || str[i - 1] == 'Y' || str[i - 1] == 'Z')
				{
					time += w + p * 4;
				}
				else time += p * 4;
			}
			else time += p * 4;
			break;
		default:
			time += p;
			break;
		}
	}
	printf("%d", time);
	return 0;
}