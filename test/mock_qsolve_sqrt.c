// mock_qsolve_sqrt.c
// mock_qsolve_sqrt is a mock object for qsolve_sqrt() 
// This allows:
//   testing of the qsolve_roots() with a mock object, 
// 
// First called is:
// mock_setup_qsolve_sqrt(): currently allows only one x value at a time.
//
// Them call :
// qsolve_sqrt(): the mock qsolve_sqrt() in this module (which does 
//     not call sqrt() ). It has the same signiture as the usual 
//     qsolve_sqrt() (which does call sqrt() )
// 
// Then call
// mock_check_qsolve_sqrt():  to check for corectness of
//     the call to the mock qsiolve_sqrt()
//  
// The mock qsolve_sqart() does keep track of the number of times
//    it is calledm, which should only be 1.

#include <math.h>
#include "mock_qsolve_sqrt.h"
#include "qsolve_sqrt.h"

static double x     = -1.0;  // actual arguement passed to qsolve_sqrt()
static double ex    = -1.0;  // expected argument x to qsolve_sqrt()
static double eps   = -1.0;  // absolute error allowed in x
static double sqrtx = -1.0;  // result to return fomr qsolve_sqrt(), sqrt(x)
static int    count = 0;     // actual count of calls to qsolve_sqrt() made
static int    flag  = -1;

// initialize to expect 1 call to the mock qsolve_sqrt() 
// expecting arguement lx within leps absolute error
// return    result    lsqrtx
void mock_setup_qsolve_sqrt(double lx, double lsqrtx, double leps) {
ex = x;
eps = leps;
sqrtx = lsqrtx;
count = 0;
flag=0;
}

double qsolve_sqrt(double lx) { 
if(fabs(ex- lx) > eps) {
  flag=1;
}
x = lx;
count++;
return sqrtx; 
}

// Returns 0 if the corr4eft argument was passed and only one call was made.
// else there was a problem and retun 1
int mock_check_qsolve_sqrt(int *lcount,  double *lx) {
int	ret;
*lcount = count;
*lx = x;
if((flag == 0) && (count==1)) {
  ret = 0;
} else {
  ret = 1;
}
return ret; 
}

void mock_teardown_qsolve_sqrt() {
x = -1.0;
ex = -1.0;
eps = -1.0;
sqrtx = -1.0;
count = 0;
flag  = -1;
return ;
}
