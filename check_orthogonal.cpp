#include <iostream>
using namespace std;
#define N 3
class matrix
{
private:
  int mat[N][N];
public:
  void create ();
  void matmul (matrix & m1, matrix & m2);
  void transpose (matrix & m);
  void display ();
  int check_ortho ();
};
void
matrix::create ()
{
  cout << "Enter elements of matrix: \n";
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> mat[i][j];
}

void
matrix::matmul (matrix & m1, matrix & m2)
{
  int i, j, k;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      {
	mat[i][j] = 0;
	for (k = 0; k < N; k++)
	  mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
      }
}

void
matrix::transpose (matrix & m)
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      mat[i][j] = m.mat[j][i];
}

void
matrix::display ()
{
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	cout << mat[i][j] << " ";
      cout << endl;
    }
}

int
matrix::check_ortho ()
{
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	{
	  if (i == j && mat[i][j] != 1)
	    {
	      cout << "Not a orthogonal matrix";
	      return 1;
	    }
	  if (i != j && mat[i][j] != 0)
	    {
	      cout << "Not a orthogonal matrix";
	      return 2;
	    }
	}
    }
  cout << "Orthogonal matrix";
  return 0;
}

int
main ()
{
  matrix A, T, I;
  A.create ();
  cout << "You entered:-\n";
  A.display ();
  T.transpose (A);
  cout << "Transpose of A:\n";
  T.display ();
  I.matmul (A, T);
  cout << "After multiplication:\n";
  I.display ();
  I.check_ortho ();
  return 0;
}
