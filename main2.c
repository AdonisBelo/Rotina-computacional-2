#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define f(x) 2*x*x*x - 3*x*x + 1
int main(){
	printf("\tMetodo da Bisseccao\n\n");
	printf("A funcao analisada eh: 2x^3 - 3x^2 + 1\n");
	
	float a,b,c,erroEstimado, fa, fb, fc, a0, b0;
	int i=0;
	printf("Digite o intervalo:\n");
	scanf("%f %f",&a,&b);
	printf("Digite o erro estimado:\n");
	scanf("%f",&erroEstimado);
	a0=a;
	b0=b;
	
	clock_t Ticks[6];
    Ticks[0] = clock();
    
	if((f(a)*f(b))>0){
	    printf("Intervalo invalido!");      
	    exit(1);                                                 
	}
	else if(f(a)==0 || f(b)==0){
	    printf("A raiz eh um dos intervalos. A raiz eh %f\n",f(a)==0?a:b);
	    exit(0);
	}
	printf("Com 3 algarismos na mantissa\n");
	do{	  
		fa = f(a);  
		fb = f(b);
		c = (a+b)/2;
		fc = f(c);
	    if(fa*fc<0){
	    	b=c;
	    	fb=fc;
		} else{
			a=c;
			fa=fc;
		}
		i++;
		printf("Iteracao: %d\t", i);
		printf("Raiz c: %.3f\t", c);
		printf("f(c): %.3f\n", fc);
	    
	}while(fabs(fc)>erroEstimado);
		printf("A raiz aproximada eh %.3f\n",c);
		
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n", Tempo);
	 
	
	Ticks[2] = clock();
	printf("Com 4 algarismos na mantissa\n");
	a=a0;
	b=b0;
	i=0;
	do{	  
		fa = f(a);  
		fb = f(b);
		c = (a+b)/2;
		fc = f(c);
	    if(fa*fc<0){
	    	b=c;
	    	fb=fc;
		} else{
			a=c;
			fa=fc;
		}
		i++;
		printf("Iteracao: %d\t", i);
		printf("Raiz c: %.4f\t", c);
		printf("f(c): %.4f\n", fc);
	    
	}while(fabs(fc)>erroEstimado);
		printf("A raiz aproximada eh %.4f\n",c);
		
	Ticks[3] = clock();
    Tempo = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n", Tempo);
	
	
	Ticks[4] = clock();
    
	
	printf("Com 5 algarismos na mantissa\n");
	a=a0;
	b=b0;
	i=0;
	do{	  
		fa = f(a);  
		fb = f(b);
		c = (a+b)/2;
		fc = f(c);
	    if(fa*fc<0){
	    	b=c;
	    	fb=fc;
		} else{
			a=c;
			fa=fc;
		}
		i++;
		printf("Iteracao: %d\t", i);
		printf("Raiz c: %.5f\t", c);
		printf("f(c): %.5f\n", fc);
	    
	}while(fabs(fc)>erroEstimado);
	printf("A raiz aproximada eh %.5f\n",c);
		
	Ticks[5] = clock();
    Tempo = (Ticks[5] - Ticks[4]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n", Tempo);
		return 0;
	}
