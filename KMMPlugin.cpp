#include "CScore.h"
#include "KMMPlugin.h"
#include <sys/time.h>

/*
 * Execute as follows: ./scoreGenome order pathToModel inputFile outputFile
 * 						order = The order of the Markov Model
 * 						pathToModel = Path to where the model for that genome is
 * 						inputFile = The name of the input file
 * 						outputFile = The name of the output file
 */

void KMMPlugin::input(std::string file) {
   std::ifstream infile(file.c_str(), ios::in);
   
   infile >> order;
   infile >> pathToModels;
   infile >> inputName;
}

void KMMPlugin::run() {
   // Only because these classes were already built, we have to do the execution in output
   // so we have the output file in time
}


void KMMPlugin::output(std::string file) {
	CScore* s = new CScore();
        s->scoreModels(pathToModels, inputName, file, order);
        delete s;
	//struct timeval tv1, tv2;

	//gettimeofday(&tv1, NULL);

	/*if(argc>4) {
		int order = atoi(argv[1]);
		string pathToModels(argv[2]);
		string inputName(argv[3]);
		string outputName(argv[4]);
*/

	/*} else {
		 cout << "Execute as follows: ./scoreGenome order pathToModel inputFile outputFile\n";
		 cout << "\t\t\t" << "order = The order of the Markov Model\n";
		 cout << "\t\t\t" << "pathToModel = Path to where the model for that genome is\n";
		 cout << "\t\t\t" << "inputFile = The name of the input file\n";
		 cout << "\t\t\t" << "outputFile = The name of the output file\n";
	}

	gettimeofday(&tv2, NULL);
	double tm = (double) (tv2.tv_usec - tv1.tv_usec)/1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	cout << "Time taken in execution = " << tm << " seconds\n";

	return 0;*/
}

PluginProxy<KMMPlugin> KMMPluginProxy = PluginProxy<KMMPlugin>("KMM", PluginManager::getInstance());

