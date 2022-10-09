// Author: Alejandro Valencia
// CFD BU Online Course Step 1: 1D convection
// Update: 20 November, 2021

/************************************************************************
* This program uses a finite difference method to solve the 1D 			*
* 	convection equation as Step 1 of 12 of the online BU CFD course 	*
* 	taught by Lorena Barba 												*
************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



// Function Prototypes
int linspace(double A[],double x0, double xf, int nx);
int disparray(double A[], int nx);
void plot2D(char name[], double x[], double y[],int nx);



/************************************************************************
* Main Program 															*
************************************************************************/
																			
int main(){
	
	//[A]:Declarations
	int 	n,i, nt = 51,nx = 101;
	double 	dx,x0,xf,t0,tf,dt,CFL,c;
	double 	xvector[nx],u0[nx],u[nx],un[nx],time[nt];
	char 	name[30];


	//[B]:Parameters
	c   = 1.0;				//Propagation speed
	x0  = 0.0;				//Initial boundary
	xf  = 2.0;				//Boundary limit
	dx  = (xf-x0)/(nx-1);	//Space increment 
	t0  = 0.0;				//Starting time
	tf  = 0.5;				//Final time
	CFL = 1.0;				//CFL number(determies stability <=1)
	dt  = CFL*dx/c;			//Time step

	FILE *fp;
	fp = fopen("inputs.dat","w");
	fprintf(fp,"%d %f",nt,dt );


	//[C]:Create Space and Time Arrays
	linspace(xvector,x0,xf,nx); //Space vector
	linspace(time,t0,tf,nt);    //Time array


	//[D]:Initial State
	// For this exercise the initial state was stated to be a square wave
	for (i = 0; i < nx; i++){
		if (xvector[i] >= 0.5 && xvector[i] <= 1.0){
			u0[i] = 2;
		} else {
			u0[i] = 1;
		}//end if
	}//end for i


	//[E]:Time March
	memcpy(u,u0,sizeof u); //Initialize Solution
	for (n = 0; n < nt+1; n++){
		memcpy(un,u,sizeof u);

		/* Boudary Conditions */
		u[0] = 1;
		u[nx-1] = 1;
		
		/* Solution */
		for (i = 1; i < nx; i++){
			u[i] = un[i] - CFL*(un[i] - un[i-1]);
		}//end for i


	sprintf(name,"./Output/data%04d.dat", n);
	plot2D(name,xvector,u,nx);

	}//end for n





}//end program



/************************************************************************
* Linspace Function 													*
************************************************************************/

int linspace(double A[],double x0, double xf, int nx){

	/* Declarations */
	double dx;
	int i;
	
	/* Loop and create array */
	dx = (xf - x0)/(nx - 1);
	for (i = 0; i < nx; i++){
		A[i] = x0 + i*dx;
	}//end for i

	return 0;

}// end function linspace



/************************************************************************
* Data File To Plot Function 											*
************************************************************************/

void plot2D(char name[], double x[], double y[],int nx){
	
	int i;	
	FILE * fp;
	fp = fopen(name,"w");

	for (i = 0; i < nx; i++){
		fprintf(fp,"%f %f\n",x[i],y[i]);
	}//end for i

	fclose(fp);

}//end function plot2D



