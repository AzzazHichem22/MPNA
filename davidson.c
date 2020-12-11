#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <lapacke.h>
#include <sys/time.h>
#include <time.h>

#define N 1000		//size of default matrix


//_______lecture d'une matrice a partir d'un fichier .txt_______
double**
read_matrix (int n, FILE * data_in)
{
  double **A = malloc (sizeof (double *) * n);
  for (int i = 0; i < n; i++)
    {
      A[i] = malloc (sizeof (double) * n);
    }
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  fscanf (data_in, "%le \n", &A[i][j]);
	}
    }
  return A;

}


 //____exempple d'une matrice n*n creuse  symetrique inversible________
double** 
generate_matrix (double** A)
{
  for (int i = 0; i < N; i++)
  	for (int j = 0; j < N; j++)
  	{
  		if (i == j)
  		{
  			A[i][j] = 4.;
  			if (i<N-1)
  			A[i][j+1]=A[i+1][j]=2. ;
  		}
  	}
  return A;
}

//_________display a matrix___________ 

void
display_matrix(double **matrice, int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
		printf ("%le \t", matrice[i][j]);
      printf ("\n");
    }
}


//_______generate an initial unit vector_________
double
norm_vect(double *v, int n)
{
	double tmp;
	for (int i = 0; i < n; ++i)
		tmp += v[i]*v[i] ;
  return sqrt (tmp); //racine carre d'un produit salire de mm vect
}

void display_vector(double * v,int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%le \t",v[i]);
	}
	printf("\n");
}

double *
generate_vector (int n,double *v)
{

  srand(1);
  for (int i = 0; i < n; i++)
    v[i] = rand();
display_vector(v,n);
  double norm = norm_vect (v, n);
  printf("%le\n",norm );
  for (int i = 0; i < n; i++)
    v[i] /= norm;
  return v;
}


//_______main function_______
int
main (int argc, char *argv[])
{

double** A ;
A= (double **)malloc(N*sizeof(double*));
for(int i=0;i<N;i++)
	A[i] = (double *) malloc(N*sizeof(double));

generate_matrix(A);

display_matrix(A,N);


double *v = malloc (N * sizeof (double));
v = generate_vector (N,v) ;
display_vector(v,N);




  free (A);
  free (v);
  return 0;
}
