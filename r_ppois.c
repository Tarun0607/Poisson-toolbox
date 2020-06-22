#include<stdlib.h>
#include<stdio.h>
#include<Rembedded.h>
#include<Rinternals.h>
#include<Rinterface.h>
#include<R.h>
#include<R_ext/Parse.h>
#include "r_ppois.h"
#include <string.h>

double* r_ppois(double q,double lambda)
{
  int argc = 2;
  char *argv[] = {"r_ppois","--quiet"};

  Rf_initEmbeddedR(argc,argv);
  SEXP q1;
  SEXP q2;
  PROTECT(q1=Rf_allocVector(INTSXP,1));
  memset(INTEGER(q1),q,sizeof(double));
  PROTECT(q2=Rf_allocVector(INTSXP,1));
  memset(INTEGER(q2),lambda,sizeof(double));
  SEXP symbol1 = Rf_install("Q.var");
  SEXP symbol2 = Rf_install("Lambda.var");
  Rf_defineVar(symbol1,q1,R_GlobalEnv);
  Rf_defineVar(symbol2,q2,R_GlobalEnv);
  
  //UNPROTECT(1);
  const char* str = "print(ppois(Q.var/16843009,lambda=Lambda.var/16843009))";
  int error;
  SEXP code, expr = R_NilValue;
  ParseStatus status;
  
  
  
  PROTECT(code = Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(code, 0, Rf_mkChar(str));
 
  expr = PROTECT(R_ParseVector(code, -1, &status, R_NilValue));
  //printf("%s\n",STRSXP(code));
  //printf("%s\n",Rf_mkChar(str));
  switch (status) {
  case PARSE_OK:
    break;
  case PARSE_INCOMPLETE:
    fprintf(stderr, "Expression incomplete! Missing brackets?\n");
    UNPROTECT(2);
    return -1;
  case PARSE_ERROR:
    fprintf(stderr, "Syntax error!\n");
    UNPROTECT(2);
    return -1;
  default:
    UNPROTECT(2);
    return -1;
  }
   
  int i,j;
  double *result;
  //printf("%d\n",LENGTH(expr));
    for(i=0;i<LENGTH(expr);i++){
    SEXP answer,answer0,answer4,answer1,answer2,answer3;
    answer = R_tryEval(VECTOR_ELT(expr, i), R_GlobalEnv, &error);
    result = REAL(answer);
    printf("%lf",result[0]);
    //double *temp1 = temp;
    //char *s0 = CHAR(asChar(answer0));
    //
    //*result = *temp;
    //result[0]=temp1[0];
    //printf("%lf\n",*result);
   } 
  //s[LENGTH(expr)] = '\0';
 
  UNPROTECT(2);
  
  Rf_endEmbeddedR(0); 
  
  return result;
}


