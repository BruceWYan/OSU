#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>


// Basic time step will be 1 month. Necessary consts:
const float RYEGRASS_GROWS_PER_MONTH =		20.0; //inches
const float ONE_RABBITS_EATS_PER_MONTH =	 1.0;
// PRECIP is in inches.
const float AVG_PRECIP_PER_MONTH =	        12.0;	// average
const float AMP_PRECIP_PER_MONTH =		    4.0;	// plus or minus
const float RANDOM_PRECIP =			        2.0;	// plus or minus noise
const float MIDPRECIP =				        14.0;

// TEMP is in degrees Fahrenheit (°F).
const float AVG_TEMP =				60.0;	// average
const float AMP_TEMP =				20.0;	// plus or minus
const float RANDOM_TEMP =			10.0;	// plus or minus noise
const float MIDTEMP =				60.0;

// State Global Variables 
int	    NowYear;		// 2023 - 2028
int	    NowMonth;		// 0 - 11
int     NowPrintMonth;
float	NowPrecip;		// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight;		// Rye height in inches
int	    NowNumRabbits;		// number of rabbits in the current population

float   NowRabbitsWumpusMod; 		// Represents perecent of population killed
float   NowRyeWumpusMod;		// Represents percent of height in grains killed

unsigned int seed = 0;

omp_lock_t	Lock;
volatile int	NumInThreadTeam;
volatile int	NumAtBarrier;
volatile int	NumGone;

//------------helper function-----------//

float Sqr(float x) {
	return x*x;
}

float Ranf( unsigned int *seedp,  float low, float high ){
	float r = (float) rand_r( seedp );              // 0 - RAND_MAX
	return(low  +  r * ( high - low ) / (float)RAND_MAX   );
}

void setNextEnvironment() {
	float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

	float temp = AVG_TEMP - AMP_TEMP * cos( ang );
	NowTemp = temp + Ranf( &seed, -RANDOM_TEMP, RANDOM_TEMP );

	float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
	NowPrecip = precip + Ranf( &seed,  -RANDOM_PRECIP, RANDOM_PRECIP );
	if( NowPrecip < 0. )
		NowPrecip = 0.;
}



//-----------section fucntions-----------//

void Rabbits(){
	while(NowYear < 2029){
		int nextNumRabbits = NowNumRabbits;
		int carryingCapacity = (int)(NowHeight);
		//	Carrying Capacity function that will determine how many rabbits will exist in the next given month
		// 	If the numbe of rabits is less than the carrying capacity (more rye), increment
		if (nextNumRabbits < carryingCapacity) 
			nextNumRabbits+=2;
		// 	If number of rabbits exceed the carrying capacity (more rabbits than rye), decrement
		else if (nextNumRabbits > carryingCapacity)
			nextNumRabbits--;
		// 	Clamp next num of rabbtis
		if (nextNumRabbits < 0)
			nextNumRabbits = 0;

		//	myAgent if wumpus is present, subtract the percent of rabits killed
		if (NowRabbitsWumpusMod > .0)
			nextNumRabbits = nextNumRabbits - int(nextNumRabbits * NowRabbitsWumpusMod);
	
		// 	DoneComputing barrier
		#pragma omp barrier

		NowNumRabbits = nextNumRabbits;
		
		//	DoneAssigning barrier
        #pragma omp barrier

		//	DonePriting barrier
        #pragma omp barrier
	}
}

void RyeGrass(){
	while(NowYear < 2029){
		float nextHeight;

		//	Variables taht determine the growth of Rye grass 
		float tempFactor = exp(-Sqr((NowTemp - MIDTEMP) / 10));
		float precipFactor = exp(-Sqr((NowPrecip - MIDPRECIP) / 10));

		nextHeight = NowHeight;
		nextHeight += tempFactor * precipFactor * RYEGRASS_GROWS_PER_MONTH; //	Get the number of ryegrass per month
		nextHeight -= (float)NowNumRabbits * ONE_RABBITS_EATS_PER_MONTH;	//	Decrease number of rye by numrabbits * how much each eats 

		if (nextHeight < 0) 
			nextHeight = 0;

		if (NowRyeWumpusMod > .0)
			nextHeight = nextHeight - (nextHeight * NowRyeWumpusMod);

		//	DoneComputer barrier
		#pragma omp barrier

		NowHeight = nextHeight;

		//	DoneAssigning barrier
		#pragma omp barrier

		//  DonePrinting barrier
        #pragma omp barrier
	}
}

//myAgent
void Wumpus(){
	while(NowYear < 2029){
		
		int randd = Ranf(&seed, 1.0, 10.0);
		float NextRabbitWummpusMod = 0.0;
		float NextRyeWumpusMod = 0.0;

		//	20% chance of wumpus eating the rabbits
		//	Wumpus will eat 20% of rabbits 
		if (randd % 5 == 0)
			NextRabbitWummpusMod = 0.3;

		// 10% chance that the wumpus would eat the rye
		// Wumpus will eat 30% of the rye
		else if (randd % 7 == 0)
			NextRyeWumpusMod = 0.3;

		//	DoneComputing barrier
		#pragma omp barrier

		NowRabbitsWumpusMod = NextRabbitWummpusMod;
		NowRyeWumpusMod = NextRyeWumpusMod;

		//	DoneAssigning barrier
        #pragma omp barrier

		//	DonePrinting barrier
        #pragma omp barrier

	}
}

void Watcher(){
	while(NowYear< 2029){
		// DoneComputing barrier:
        #pragma omp barrier

        // DoneAssigning barrier:
        #pragma omp barrier

		//	Increment Time
		if (NowMonth >= 11){
			NowMonth = 0;
			NowYear++;
		}
		else{
			NowMonth++;
		}
		NowPrintMonth++;
		setNextEnvironment();
		printf("%d, %d,%d,%lf,%lf,%lf,%lf\n", NowPrintMonth, NowNumRabbits, int(NowRabbitsWumpusMod * NowNumRabbits), (NowHeight * 2.54),(NowRyeWumpusMod * NowHeight * 2.54),(5./9.)*(NowTemp-32), (NowPrecip * 2.54));

		//	DonePrinting barier:
		#pragma omp barrier
	}
}



int main () { 
	// starting date and time:
	NowMonth =    0;
	NowYear  = 2023;

	// starting state (feel free to change this if you want):
	NowNumRabbits = 1;
	NowHeight =  5.;

	NowNumRabbits = 1;
	NowHeight = 1;
	NowRabbitsWumpusMod = 0.;
	NowRyeWumpusMod = 0.;

	setNextEnvironment();

	printf("Months,Rabbits,Rabbits Eaten By Wumpus,Rye Grass cm, Rye Grass Eaten By Wumpus cm,Temperature C,Precipitation cm\n");
	

	omp_set_num_threads(4);	// same as # of sections
	#pragma omp parallel sections 
	{

		#pragma omp section 
		{
			Rabbits();
		}

		#pragma omp section 
		{
			RyeGrass();
		}

		#pragma omp section 
		{
			Watcher();
		}

		#pragma omp section 
		{
			Wumpus();	// your own
		}
	}       // implied barrier -- all functions must return in order to allow any of them to get past here
}

