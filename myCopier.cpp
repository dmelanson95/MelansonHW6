/* Program takes two arguments, file 1 to be read from, file 2 to write that file to.
 *e.g. myCopier readFile.txt writeFile.txt
 */

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

#define FILE_PATH "/home/debian"

int main(int argc, char* argv[]){
	//error checking
	if(argc != 3){
		cout << endl;
		cout << "Usage is myCopier and name of file to be read from, name of file to be written to." << endl;
		cout << "e.g. myCopier readFile.txt writeFile.txt" << endl << endl;
		return 2;
	}
	//take file names from command line arguments
	string cmdr(argv[1]);
	string cmdw(argv[2]);

	//print to command line
	cout << "The current file path is " << FILE_PATH << endl;
	cout << "Reading from file " << cmdr << endl;
	cout << "Writing to file " << cmdw << endl;
	
	//instantiate objects
	fstream fsr, fsw;
	string line;
	
	//create file name to be cat-ed to file path
	string readName = "/"+cmdr;
	string writeName = "/"+cmdw;
	
	//concatenate
	string readPath = FILE_PATH + readName;
	string writePath = FILE_PATH + writeName;
	
	//open files
	fsr.open((readPath).c_str(), fstream::in);
	fsw.open((writePath).c_str(), fstream::out);
	
	//loop through read file, write to write file per line
	while(getline(fsr,line)){
		fsw << line << endl;
	}

	//close and exit
	fsw.close();
	fsr.close();
	return 0;
}


