/*
Hybrid Simulated Annealing Algorithm for the Multiple Choice Multidimensional Knapsack Problem
----------------------------------------------------------------------------------------------

Implementation of simulated annealing algorithm for the multiple choice multidimensional knapsack
problem. The algorithm uses greedy principles along with simulated annealing to find high quality
solutions to the problem instances. The algorithm follows the following steps:

	1) Find the greedy estimate and populate the global vectors
   2) Run simulated annealing algorithm on the greedy estimate
   3) Report the final solution

Change the global ANNEALING_ITERATIONS to change the number of iterations that the algorithm runs for.

* Requirements *
	The algorithm requires a "data.dat" file in the current directory in the format specified by
   following URL:
   ftp://cermsem.univ-paris1.fr/pub/CERMSEM/hifi/MMKP/MMKP.html

Author: Shalin Shah
Email: shah.shalin@gmail.com

*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <ctime>
using namespace std;

/* Generate a random number in [min, max] */
int generateRandomNumber(int min, int max)
{
	int r;
	double randd = ((double)rand() / ((double)(RAND_MAX)+(double)(1)));
	r = (int) (randd * (double)(max-min+1)) + min;
	return r;
}

/* Generate a random number in [0, 1) */
double generateDoubleRandomNumber()
{
	return ((double)rand() / ((double)(RAND_MAX)+(double)(1)));
}

/* Return a random crossover type */
int randomCrossover()
{
	int cc = (int)((double)generateDoubleRandomNumber() * (double)2);
	return cc;
}

/* Class used for creating a global vector of greedy objects */
class GreedyObject
{
	public:
		double ratio;
   	int group;
      int index;

   	GreedyObject()
	   {
   	}

      GreedyObject(int g, double r, int i)
      {
      	ratio = r;
         group = g;
         index = i;
      }

      GreedyObject(const GreedyObject & copy)
      {
       	this->ratio = copy.ratio;
         this->group = copy.group;
         this->index = copy.index;
      }

      bool operator < (const GreedyObject & right) const
      {
      	return this->ratio > right.ratio;
      }

      bool operator > (const GreedyObject & right) const
      {
      	return this->ratio < right.ratio;
      }
};

/* Class used to create a global vector of groups */
class Group
{
	public:
   	int group;
      vector<GreedyObject> objects;

      Group()
      {
      }

      Group(int g)
      {
      	group = g;
      }

      int getGroup()
      {
      	return group;
      }

      vector<GreedyObject> getObjects()
      {
      	return objects;
      }

      void sortObjects()
      {
      	sort(objects.begin(), objects.end());
      }

      GreedyObject getObjectAtIndex(int in)
      {
      	return objects.at(in);
      }

      void addObject(GreedyObject obj)
      {
      	objects.push_back(obj);
      }

      GreedyObject getObject(int index)
      {
      	return objects.at(index);
      }
};

/* Globals */
int NUMBER_GROUPS = 0; // populated in processData()
int NUMBER_OBJECTS_IN_GROUP = 0; // populated in processData()
int NUMBER_CONSTRAINTS = 0; // populated in processData()
int ***CONSTRAINTS; // populated in processData()
int *CAPACITIES; // populated in processData()
int **VALUES; // populated in processData()
int VALID_SOLUTION_ITERATIONS; // populated in main()

/* Simulated Annealing variables */
int ANNEALING_ITERATIONS = 100000;
int RANDOM_CHANGES; // populated in main()
const double ANNEALING_FACTOR = 10;

/* Global vectors for various uses across the algorithm */
vector<GreedyObject> GREEDY_OBJECTS;
vector<Group> GROUPS;
GreedyObject ** RATIO_OBJECTS;



/* Process the data and populate the global variables.
 	The data is in the format specified by the following URL:
   ftp://cermsem.univ-paris1.fr/pub/CERMSEM/hifi/MMKP/MMKP.html
*/
void processData(char * filename)
{
 	FILE * file;
	file = fopen(filename, "r");
   if(file == NULL)
   {
   		printf("File Not Found in Current Directory.");
      exit(1);
   }

	char * line = new char [1000];
	fgets(line, 1000, file);
	while(strlen(line) <= 1)
	{
			fgets(line, 1000, file);
	}
	char * tok = strtok(line, " ");
   NUMBER_GROUPS = atoi(tok);
	tok = strtok(NULL, " ");
	NUMBER_OBJECTS_IN_GROUP = atoi(tok);
	tok = strtok(NULL, " ");
	NUMBER_CONSTRAINTS = atoi(tok);

	int i = 0;
   fgets(line, 1000, file);

   /* Capacities */
   CAPACITIES = new int[NUMBER_CONSTRAINTS];
   tok = strtok(line, " ");
	for(i=0; i<NUMBER_CONSTRAINTS; i++)
   {
   	CAPACITIES[i] = atoi(tok);
		tok = strtok(NULL, " ");
   }

   /* Values and Constraints */
	VALUES = new int*[NUMBER_GROUPS];
   CONSTRAINTS = new int**[NUMBER_GROUPS];
   fgets(line, 1000, file);
	for(i=0; i<NUMBER_GROUPS; i++)
	{
   	CONSTRAINTS[i] = new int*[NUMBER_OBJECTS_IN_GROUP];
      VALUES[i] = new int[NUMBER_OBJECTS_IN_GROUP];
      fgets(line, 1000, file);
      tok = strtok(line, " ");
      for(int g=0; g<NUMBER_OBJECTS_IN_GROUP; g++)
      {
      	CONSTRAINTS[i][g] = new int[NUMBER_CONSTRAINTS];
		  	int value = atoi(tok);
   	   VALUES[i][g] = value;

	      for(int c=0; c<NUMBER_CONSTRAINTS; c++)
   	   {
      		tok = strtok(NULL, " ");
	         CONSTRAINTS[i][g][c] = atoi(tok);
   	   }
         fgets(line, 1000, file);
      	tok = strtok(line, " ");
      }
	}

	delete [] line;
}

/* A solution in the simulated annealing algorithm */
class MNode
{
	public:
		int * objects;
      int * weights;
      int value;

   /* Constructor */
   MNode()
   {
   	objects = NULL;
   }

   /* Deep copying constructor */
   MNode(int * o)
   {
   	objects = new int[NUMBER_GROUPS];
      for(int i=0; i<NUMBER_GROUPS; i++)
      {
      	objects[i] = o[i];
      }
      calculateValue();
      calculateWeights();
   }

   /* Destructor */
   ~MNode()
   {
   	if(objects != NULL)
      	delete [] objects;

      if(weights != NULL)
      	delete [] weights;
   }

   /* Copy Constructor */
   MNode(const MNode & copy)
   {
   	int * o = copy.objects;
      objects = new int[NUMBER_GROUPS];
      for(int i=0; i<NUMBER_GROUPS; i++)
      {
      	objects[i] = o[i];
      }
      calculateValue();
      calculateWeights();
   }

   /* Assignment operator */
   MNode & operator = (const MNode & copy)
   {
   	if(objects != NULL)
      	delete [] objects;

      if(weights != NULL)
      	delete [] weights;

   	int * o = copy.objects;
      objects = new int[NUMBER_GROUPS];
      for(int i=0; i<NUMBER_GROUPS; i++)
      {
      	objects[i] = o[i];
      }
      calculateValue();
      calculateWeights();
      return *this;
   }

   /* '<' operator used by std::sort() */
   bool operator < (const MNode & right)
   {
   	return this->value > right.value;
   }

   /* '>' operator */
   bool operator > (const MNode & right)
   {
   	return this->value < right.value;
   }

   /* Calculate the objective function value */
   void calculateValue()
   {
   	value = 0;
      for(int i=0; i<NUMBER_GROUPS; i++)
      {
      	value+=VALUES[i][objects[i]];
      }
   }

   /* Calculate the weights array */
   void calculateWeights()
   {
      weights = new int[NUMBER_CONSTRAINTS];
      for(int i=0; i<NUMBER_CONSTRAINTS; i++)
      {
      	weights[i] = 0;
      	for(int j=0; j<NUMBER_GROUPS; j++)
         {
      		int aas = objects[j];
            weights[i]+=CONSTRAINTS[j][aas][i];
         }
      }
   }

   /* Does this solution violate any constraints? */
   bool violatesConstraints() const
   {
       for(int i=0; i<NUMBER_CONSTRAINTS; i++)
       {
       	if(weights[i] > CAPACITIES[i])
         {
         	return true;
         }
       }
       return false;
   }

   /* How much is the constraint violation? */
   int constraintViolation() const
   {
   	int violation = 0;
   	for(int i=0; i<NUMBER_CONSTRAINTS; i++)
      {
      	if(weights[i] > CAPACITIES[i])
         {
         	violation+=(weights[i]-CAPACITIES[i]);
         }
      }
      return violation;
   }

   /* Change the selection of the passed in group to the passed in assignment */
   void changeSelection(int group, int assignment)
   {
   	if(objects[group] == assignment)
      	return;

   	int previous = objects[group];
      for(int i=0; i<NUMBER_CONSTRAINTS; i++)
      {
      	weights[i]-=CONSTRAINTS[group][previous][i];
      }

      value-=VALUES[group][previous];

      for(int i=0; i<NUMBER_CONSTRAINTS; i++)
      {
       	weights[i]+=CONSTRAINTS[group][assignment][i];
      }

		value+=VALUES[group][assignment];

      objects[group] = assignment;
   }

   /* Return the fitness of this solution.
    	This is the value if none of the constraints are violated.
      If a constraint is violated, the fitness is -100
      */
   int fitness()
   {
   	if(violatesConstraints())
      {
      	return -100;
      }
      else
      {
      	return value;
      }
   }

   /* Get the selection of passed in group */
   int getValueOfIndex(int index)
   {
   	return objects[index];
   }

   /* Deep clone this solution */
   MNode clone()
   {
   	int * obj = new int[NUMBER_GROUPS];

      for(int i=0; i<NUMBER_GROUPS; i++)
      {
			obj[i] = objects[i];
      }

      MNode clone(obj);
      delete [] obj;
      return clone;
   }
};

/* Improve upon the passed in MNode object locally through Simulated Annealing */
inline void simulatedAnnealing(MNode &n)
{
	MNode node = n.clone();
   MNode best = n.clone();
	for(int i=0; i < ANNEALING_ITERATIONS; i++)
	{
   	/* Make random changes to the solution */
   	for(int j=0; j<RANDOM_CHANGES; j++)
      {
      	int rand1 = generateRandomNumber(0, NUMBER_GROUPS-1);
			int rand2 = generateRandomNumber(0, NUMBER_OBJECTS_IN_GROUP-1);
         while(node.getValueOfIndex(rand1) == rand2)
         {
          	rand1 = generateRandomNumber(0, NUMBER_GROUPS-1);
				rand2 = generateRandomNumber(0, NUMBER_OBJECTS_IN_GROUP-1);
         }
         node.changeSelection(rand1, rand2);
      }

      /* If the node violates any of the constraints, correct the solution.
       	Correction will take place in order of non-decreasing order of the
         utility ratio (greedy) of the chosen objects in the solution */
      if(node.violatesConstraints())
      {
	      vector<GreedyObject> vec;
   	   for(int k=0; k<NUMBER_GROUPS; k++)
      	{
	      	int sel = node.getValueOfIndex(k);
   	      double ratio = RATIO_OBJECTS[k][sel].ratio;
      	   GreedyObject obj(k, ratio, sel);
				vec.push_back(obj);
	      }

      	sort(vec.begin(), vec.end());

      	int count = vec.size()-1;
         while(node.violatesConstraints())
         {
         	int val = -1;
            if(count < 0)
            {
            	val = generateRandomNumber(0, NUMBER_GROUPS-1);
            }
            else
            {
					GreedyObject obj = vec.at(count);
	            count--;
               val = obj.group;
            }

            Group group = GROUPS.at(val);
            for(int i=0; i<NUMBER_OBJECTS_IN_GROUP; i++)
		      {
      			GreedyObject obj = group.objects.at(i);
		         int index = obj.index;
   		      int group = obj.group;
					int previous = node.getValueOfIndex(group);
         		int pv = node.constraintViolation();
	         	node.changeSelection(group, index);
	   	      int nv = node.constraintViolation();
   	   	   if(pv < nv)
      	   	{
	      	   	node.changeSelection(group, previous);
   	      	}
            }
      	}
      }

		int numObjects = NUMBER_GROUPS * NUMBER_OBJECTS_IN_GROUP;

      /* Try to improve upon the solution by upgrading the most promising objects */
   	for(int ii=0; ii<numObjects; ii++)
	   {
   		GreedyObject obj = GREEDY_OBJECTS.at(ii);
   	  	int index = obj.index;
	      int group = obj.group;
      	int previous = node.getValueOfIndex(group);
	      int preValue = node.fitness();
   	   node.changeSelection(group, index);
      	if(node.violatesConstraints() || preValue > node.fitness())
	      {
   	   	node.changeSelection(group, previous);
      	}
	   }

      printf("\nIteration:%d Fitness:%d",i, best.fitness());

      if(best.fitness() < node.fitness())
      {
         best = node;
      }
      else
      {
      	/* Linear Annealing Schedule */
      	double probability = (double)i / (double)ANNEALING_ITERATIONS;
         probability*=ANNEALING_FACTOR;
         double rand = generateDoubleRandomNumber();
         if(rand < probability)
         	node = best;
   	}
   }

   n = best;
}

/* The greedy algorithm for the multiple choice multidimensional knapsack problem */
MNode greedyAlgorithm()
{
	/* Create the global vector of GREEDY_OBJECTS */
   RATIO_OBJECTS = new GreedyObject*[NUMBER_GROUPS];
	for(int i=0; i<NUMBER_GROUPS; i++)
   {
      RATIO_OBJECTS[i] = new GreedyObject[NUMBER_OBJECTS_IN_GROUP];
   	Group group(i);
   	for(int j=0; j<NUMBER_OBJECTS_IN_GROUP; j++)
      {
      	double weight = 0;
      	for(int k=0; k<NUMBER_CONSTRAINTS; k++)
         {
         	weight+=CONSTRAINTS[i][j][k];
         }

         double value = VALUES[i][j];
         double ratio = value/weight;
      	GreedyObject obj(i, ratio, j);
         GREEDY_OBJECTS.push_back(obj);
         GreedyObject o(i, ratio, j);
         group.addObject(o);
         RATIO_OBJECTS[i][j] = o;

      }
      group.sortObjects();
      GROUPS.push_back(group);
   }

   sort(GREEDY_OBJECTS.begin(), GREEDY_OBJECTS.end());

   int * flags = new int[NUMBER_GROUPS];
   for(int i=0; i<NUMBER_GROUPS; i++)
   {
   	flags[i] = 0;
   }

   /* Construct a solution from the GREEDY_OBJECTS */
   int numObjects = NUMBER_GROUPS * NUMBER_OBJECTS_IN_GROUP;
   int * objects = new int [NUMBER_GROUPS];
   int * chain = new int[NUMBER_GROUPS];
   int count = 0;
   for(int i=0; i<numObjects; i++)
   {
       GreedyObject obj = GREEDY_OBJECTS.at(i);
       int group = obj.group;
       int index = obj.index;
       if(flags[group] == 0)
       {
       	chain[count] = group;
         count++;
       	objects[group] = index;
         flags[group] = 1;
       }
   }
   MNode node(objects);

   /* Try to correct conflicts from the solution node */
   count = NUMBER_GROUPS -1;
   int nn = 0;
	while(node.violatesConstraints())
   {
   	int val = -1;
      if(count < 0)
   		val = generateRandomNumber(0, NUMBER_GROUPS-1);
      else
      	val = chain[count];

      count--;
   	Group group = GROUPS.at(val);
      for(int i=0; i<NUMBER_OBJECTS_IN_GROUP; i++)
      {
      	GreedyObject obj = group.objects.at(i);
         int index = obj.index;
         int group = obj.group;
			int previous = node.getValueOfIndex(group);
         int pv = node.constraintViolation();
         node.changeSelection(group, index);
         int nv = node.constraintViolation();
         if(pv < nv)
         {
         	node.changeSelection(group, previous);
         }
      }

      nn++;
      if(nn > VALID_SOLUTION_ITERATIONS)
      {
      	printf("A valid solution might NOT exist for the instance! Quitting.");
         exit(0);
      }
   }

   /* Try to improve upon the solution by upgrading objects
    in the order given by GREEDY_OBJECTS */
   for(int i=0; i<numObjects; i++)
   {
   	GreedyObject obj = GREEDY_OBJECTS.at(i);
      int index = obj.index;
      int group = obj.group;
      int previous = node.getValueOfIndex(group);
      int preValue = node.fitness();
      node.changeSelection(group, index);
      if(node.violatesConstraints() || preValue > node.fitness())
      {
      	node.changeSelection(group, previous);
      }
   }

   printf("\nGreedy Solution: %d", node.fitness());

   delete [] chain;
   delete [] objects;
	delete [] flags;
   return node;
}

int main(int argc, char *argv[])
{
   /* Initialize the random number generator */
	srand(time(NULL));

	if(argc < 3)
	{
			printf("\nUsage: ./a.out filename number_iterations\n\n");
			exit(0);
	}

	printf("Filename: %s\n", argv[1]);
	printf("Iterations: %s\n", argv[2]);

   /* Process the data from the format specified by the data file
    	See comments on the processData() function */
	processData(argv[1]);
	ANNEALING_ITERATIONS = atoi(argv[2]);

   /* How much time to spend in finding a valid solution before quitting? */
   VALID_SOLUTION_ITERATIONS = NUMBER_GROUPS * NUMBER_OBJECTS_IN_GROUP;

   /* The number of random changes that simulated annealing
    	performs on the solution. The values are found experimentally */
   if(NUMBER_GROUPS < 50)
   	RANDOM_CHANGES = 3;
   else
   	RANDOM_CHANGES = 5;

   /* Run the greedy algorthm. This function populates the global vectors:
   	GREEDY_OBJECTS, RATIO_OBJECTS, and GROUPS */
   MNode node = greedyAlgorithm();

   /* Run the simulated annealing algorithm on the solution produced by the greedy algorithm */
   simulatedAnnealing(node);

   /* Print the final solution */
   printf("\nFinal Solution: %d\n", node.fitness());

   for(int i=0; i<NUMBER_GROUPS;i++)
   {
   	printf("%d ", node.getValueOfIndex(i));
   }

   /* Free Memory */
   delete [] CAPACITIES;
   for(int i=0; i<NUMBER_GROUPS; i++)
   {
   	delete [] VALUES[i];
   }
   delete [] VALUES;
   for(int i=0; i<NUMBER_GROUPS;i++)
   {
   	for(int j=0; j<NUMBER_OBJECTS_IN_GROUP; j++)
      {
      	delete [] CONSTRAINTS[i][j];
      }

      delete [] CONSTRAINTS[i];
   }
   delete [] CONSTRAINTS;
	for(int i=0; i<NUMBER_GROUPS; i++)
   {
   	delete RATIO_OBJECTS[i];
   }

   delete [] RATIO_OBJECTS;

   return 0;
}
