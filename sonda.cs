using System;
using System.Collections.Generic;
using System.IO;

public class Sonda
{

	// Check if a position is valid and empty in a grid
	public static bool valid(int i, int j, int n, int m, ref int[ , ] matrix) {
		if (i >= 0 && i <= n && j >= 0 && j <= m) {
			return (matrix[i, j] == 0);
		}
		return false;
	}

    public static void Main()
    {
     	int[] dx = {0, 1, 0, -1};
     	int[] dy = {1, 0, -1, 0};

     	int N, M;

     	string[] tokens = Console.ReadLine().Split();

     	N = int.Parse(tokens[0]);
     	M = int.Parse(tokens[1]);

     	int[ , ] Matrix = new int[N + 1, M + 1];

     	int x, y, d;
     	char c;
     	string str;
     	while ((str = Console.ReadLine()) != null) {
     		tokens = str.Split();

	     	x = int.Parse(tokens[0]);
	     	y = int.Parse(tokens[1]);
	     	c = char.Parse(tokens[2]);

			// Translate the character into a direction
	     	if (c == 'N') d = 0;
	     	else if (c == 'E') d = 1;
	     	else if (c == 'S') d = 2;
	     	else d = 3;

			// Execute the command list
	     	string commands = Console.ReadLine();
	     	foreach (char cur in commands.ToCharArray()) {
	     		if (cur == 'L') d = (d + 3) % 4;
	     		else if (cur == 'R') d = (d + 1) % 4;
	     		else {
					if (valid(x + dx[d], y + dy[d], N, M, ref Matrix)) {
						x += dx[d];
						y += dy[d];
					}   			
	     		}
	     	}

	     	Matrix[x, y] = 1;

			// Translate a charackter back into a direction
	     	if (d == 0) c = 'N';
	     	else if (d == 1) c = 'E';
	     	else if (d == 2) c = 'S';
	     	else c = 'W';

	     	Console.WriteLine(x + " " + y + " " + c);
		}
    }
}