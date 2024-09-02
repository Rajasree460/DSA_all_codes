 
/*The file newton.c itself is as follows*/
 #include <stdio.h>
 #include <math.h>

 #define absval(x) ((x) >= 0.0 ? (x) : (-(x)))

 double funct(double);
 double dfunct(double);

 double newton(double (*fnct)(double), double (*deriv)(double),
 double startingval, double xtol, int maxits, double *fx,
 int *itcount, int *outcome);

 main()
 {
 /* This program implements the Newton’s method
 for solving an equation funct(x)=0. The function
 funct() and its derivative dfunct() is defined
 separately. */
 
 const double tol=5e-10;
 double x, fx, root;
 int its, success;
 root = newton(&funct, &dfunct,
 3.0, tol, 50, &fx,
 &its, &success);
 if ( success == 2 ) {
 printf("The root is %.12f. The value of "
 " the function\nat the root is %.12f.\n", root, fx);
 printf("%u iterations were used to find "
 " the root\n", its);
 }
 else if (success == 1) {
 printf("The derivative is too flat at %.12f\n", x);
 }
 else if (success == 0) {
 printf("The maximum number of iterations has been reached\n");
 }
 }

 double newton(double (*fnct)(double), double (*deriv)(double),
 double startingval, double xtol, int maxits, double *fx,
 int *itcount, int *outcome)
 {
 double x, dx, dfx, assumedzero=1e-20;
 *outcome = 0;
 x = startingval;
 for (*itcount = 0; *itcount < maxits; (*itcount)++) {
 dfx = deriv(x);
 if ( absval(deriv(x))<=assumedzero ) {
 *outcome = 1; /* too flat */
 break;
 }
 *fx = fnct(x);
 /* The next two lines are included so as to monitor
 the progress of the calculation. These lines
 should be deleted from a program of
 practical utility. */
 printf("Iteration number %2u: ", *itcount);
 printf("x=% .12f and f(x)=% .12f\n", x, *fx);
 dx = -*fx/dfx; x = x+dx;
 if ( absval(dx)/(absval(x)+assumedzero) <= xtol ) {
 *outcome = 2; /* within tolerance */
 *fx = fnct(x);
 break;
 }
 }
 return x; /* returning the value of the root */
 }

