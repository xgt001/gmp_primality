//DEVELOPMENT MILESTONE FILES TO BE APPENDED HERE
//NOT TO BE MESSED AROUND
//		ganesh@techsplurge.com

#include <stdio.h>
#include <iostream>
#include <gmp.h> 	//GMP
#include <math.h>
#include <gmpxx.h> // C++ headers of GMP
#include "primality.h" //USING THIRD PARTY POLYNOMIAL MULTIPLICAITON HEADER 
//NEED OUR OWN LIBRARY IMPLEMENTATION SOON
mpz_class k;
mpz_class res;
mpz_t n,r;
mpz_class logn,limit ;
void logfunc(mpz_t n);
int power_check(mpz_t n);
void order_of_modulo(mpz_t n); //we are implementing step 2,3,4 here; 
void totient_function(mpz_t n); //final polynomial multiplication for AKS
int main()
{
	mpz_init(r);
	mpz_set_ui(r,2);
	mpz_inp_str (n,stdin,10);

	if(power_check(n)!=0)
	{
		printf("Composite and Perfect Square \n");
	}
	//printf("PASS1 CLEAR \n");
	logfunc(n);
	order_of_modulo(n);
	totient_function(n);
	return 0;
}

void logfunc(mpz_t n)
{
	logn = mpz_sizeinbase(n,2);
	limit = logn * logn ;
}

//fix it to other return type, later to do
int power_check(mpz_t n)
{
	mpz_t op;
	mpz_init(op);
	mpz_set(op,n);

	return(mpz_perfect_power_p (op));
	mpz_clear(op);

}

void order_of_modulo(mpz_t n)
{

mpz_class res,k;
 
bool flag = false;
	while(mpz_cmp(r,n) == -1)
	{
		if(mpz_divisible_p(n,r)!=0)  //essentially step 3 of the ALGO
		{
			//printf("Divisible by %ld \n",mpz_get_ui(r)); 
			printf("Divisible\n");
			exit(EXIT_SUCCESS);
		}
		k = 1;
		for(;mpz_get_ui(n)<=limit;k++)
		{	res = 0;
			mpz_powm(res.get_mpz_t(),n,k.get_mpz_t(),r);
			if(res == 1)
				goto STOP;
		}
	mpz_add_ui(r,r,1);

	}
STOP : printf("");
//mpz_out_str(stdout,10,r);
//printf("\n");

if(mpz_cmp(r,n)==0)
{
	printf(" N is prime, detected in Phase 2 \n");
	exit(EXIT_SUCCESS);
}

}

void totient_function(mpz_t n)
{
 	mpz_t sqroot,poly_limit;
 	mpz_init(sqroot);
 	mpz_init(poly_limit);

 	mpz_sqrt(sqroot,r);
	mpz_add_ui(poly_limit,sqroot,1);
	mpz_mul(poly_limit,poly_limit,logn.get_mpz_t());
	unsigned int intr = mpz_get_ui(r);
	unsigned int a;

	printf("Inside polynomial multiplication \n");
	for ( a = 1; a<=mpz_get_ui(poly_limit) ; a++)
	{
		
		mpz_t f;
		mpz_init(f);
		mpz_mod(f,n,r);
		mpz_pX compare(mpz_get_ui(f));
		compare.setCoef(1,mpz_get_ui(f));
		compare.setCoef(a,0);
		mpz_pX res(intr);
		mpz_pX base(1);
		base.setCoef(a,0);
		base.setCoef(1,1);
		mpz_class kk(n);
		mpz_pX_mod_power(res,base,kk,kk,intr);
		if(!res.isEqual(compare)){
				printf("Found Composite \n");
				exit(EXIT_SUCCESS);
		}

	}

printf("Found Prime \n");
}
