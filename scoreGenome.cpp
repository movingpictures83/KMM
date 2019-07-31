#include "CScore.h"
#include <sys/time.h>

/*
 * Execute as follows: ./scoreGenome order pathToModel inputFile outputFile
 * 						order = The order of the Markov Model
 * 						pathToModel = Path to where the model for that genome is
 * 						inputFile = The name of the input file
 * 						outputFile = The name of the output file
 */


int main(int argc, char* argv[]) {
	CScore* s = new CScore();
	struct timeval tv1, tv2;

	gettimeofday(&tv1, NULL);

	if(argc>4) {
		int order = atoi(argv[1]);
		string pathToModels(argv[2]);
		string inputName(argv[3]);
		string outputName(argv[4]);

		s->scoreModels(pathToModels, inputName, outputName, order);

	} else {
		 cout << "Execute as follows: ./scoreGenome order pathToModel inputFile outputFile\n";
		 cout << "\t\t\t" << "order = The order of the Markov Model\n";
		 cout << "\t\t\t" << "pathToModel = Path to where the model for that genome is\n";
		 cout << "\t\t\t" << "inputFile = The name of the input file\n";
		 cout << "\t\t\t" << "outputFile = The name of the output file\n";
	}

	gettimeofday(&tv2, NULL);
	double tm = (double) (tv2.tv_usec - tv1.tv_usec)/1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	cout << "Time taken in execution = " << tm << " seconds\n";

	return 0;
}
