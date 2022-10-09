// Alejandro Valencia
// CFD BU Online Course Step 1: 1D conduction
// Update: 20 November, 2021

/************************************************************************
* This program uses a finite difference method to solve the 1D 			*
* 	diffusion equation as Step 3 of 12 of the online BU CFD course 		*
* 	taught by Lorena Barba 												*
************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


#define PI 4*atan(1.0)


// Function Prototypes
int linspace(double A[],double x0, double xf, int nx);
void plot2D(char name[], double x[], double y[],int nx);

/************************************************************************
* Main Program 															*
************************************************************************/

int main(){


    clock_t begin = clock();

    //[A]:Declarations
    // The parameters given in the "inputs" file are listed first
	int 	
    nt = 0,     // Number of time steps
    nx = 0;     

	double
    dt  = 0.0,  // Time step
    k   = 0.0,  // Diffusion coefficient
    x0  = 0.0,  // Inlet boundary location 
    xf  = 0.0,  // Outlet boundary location 
    x00 = 0.0,  // Square wave left location
    xff = 0.0,  // Square wave right location
    bcl = 0.0,  // Inlet boundary condition
    bcr = 0.0;  // Outlet boundary condition

    int    n, i;
    double dx, CFL;
	char   name[30];


    //[B]:Read Input File And Assign Values
    FILE *fp;                       //File pointer
    fp = fopen("inputs","r"); //Open file

    if ( fp != NULL ){
        char line[256];             //Line buffer or other suitable maximum line size
        char input_line[256];       //buffer for input name from control_file
        double value;

        //Read Line by line
        while (fgets(line, sizeof line, fp) != NULL){

            // trimLine();

            sscanf(line,"%s = %lf", input_line, &value); //

    		if (strcmp(input_line, "nt") == 0 && nt == 0)
            {
    			nt = (int) value;
    		} 
            else if(strcmp(input_line, "dt") == 0 && dt == 0)
            {
    			dt = value;
            }
            else if(strcmp(input_line, "k") == 0 && k == 0.0)
            {
                k = value;
            }
            else if(strcmp(input_line, "nx") == 0 && nx == 0)
            {
    			nx = (int) value;
            }
            else if(strcmp(input_line, "x0") == 0 && x0 == 0.0)
            {
        		x0 = value;
            } 
            else if(strcmp(input_line, "xf") == 0 && xf == 0.0)
            {
                xf = value;
            }
            else if(strcmp(input_line, "x00") == 0 && x00 == 0.0)
            {
        		x00 = value;
            } 
            else if(strcmp(input_line, "xff") == 0 && xff == 0.0)
            {
                xff = value;
            }
            else if(strcmp(input_line, "bcl") == 0 && bcl == 0.0)
            {
                bcl = value;
            }
            else if(strcmp(input_line, "bcr") == 0 && bcr == 0.0)
            {
                bcr = value;
    		}//end if

        }//end while

        fclose(fp);
        printf("\nFile read successfully\n");

    } else {
        printf("file doesn't exist. Aborting program\n");
        abort();
    }//end if


    //[D]:Derive Remaining Values
    dx  = (xf-x0) / (nx-1);	    // Space increment
    CFL = k * dt / pow(dx, 2);  // CFL number(determies stability <=1)
    printf("CFL = %0.3f\n", CFL); // CFL number(determies stability <=1)

    //[E]:Check Stability
    if (CFL > 1){
        printf("\nWARNING INSTABILITY CFL number is greater than 1\n");
        printf("Aborting Program\n");
        printf("dx = %f\n",dx);
        abort();
    } else {


    //[F]:Create Space Arrays
    // Once nx(number of nodes) has been read declare necessary arrays
    double 	xvector[nx], u0[nx], u[nx], un[nx];
    linspace(xvector,x0,xf,nx);  //Space vector


    //[G]:Initial State
    // For this exercise the initial state was stated to be a square wave
    for (i = 0; i < nx; i++){
        if (xvector[i] >= x00 && xvector[i] <= xff){
            u0[i] = 2;
        } else {
            u0[i] = 1;
        }//end if
    }//end for i

    sprintf(name,"./Output/data%04d.dat", 0);
    plot2D(name, xvector, u0, nx);

	// [H]:Time March
	memcpy(u, u0, sizeof u); // Initialize Solution
	for (n = 1; n < nt+1; n++){
		memcpy(un, u, sizeof u);

		// Boundary Conditions
		u[0] = bcl;
		u[nx-1] = bcr;

        // Solution //
		for (i = 1; i < nx-1; i++){
			u[i] = un[i] + CFL*(un[i+1] - 2*un[i] + un[i-1]);
		}//end for i

		sprintf(name,"./Output/data%04d.dat", n);
		plot2D(name,xvector,u,nx);

	}//end for n

    printf("Program done...\n");

    }//end if

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n  Executed Time = %.3f  \n\n",time_spent);




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

