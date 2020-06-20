/*
This is supposed to be a template file that has everything set up 
to print out a description of a csv file 
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <boost/algorithm/string.hpp>


using namespace std;

template <class Container>
void split(Container& cont, string& str, string& delim = ",") {

	boost:split(cont, str, boost::is_any_of(delim));

}


auto read_csv(string& filename, string& delim, int& cols[]) {

	vector<string> full_file;
	ifstream infile (filename);
	int numcols = sizeof(cols)/sizeof(int);

	string line;
	vector<string> temp;
	//fill the vector with the chosen columns
	while(getline(infile, line)) {

		split(temp, line);
		
		//check if there are more cols than the
		//number of headers
		if (temp.size() < numcols && temp.size() > numcols) {

			cout << "The CSV file is fucked" << endl;

		} else {

			full_file.push_back(temp);
			temp.clear(); //erase everything in vector

		}
	}

	return full_file;
}


int main (int argc, char *argv[]) 
{

        /*Read in the csv */
	string const filename = argc[1];
	int cols2read = {0,1};

	auto data = read_csv(filename, ",");
	
	//Lets iterate over the vector we read in and get some 
	
	

	return 0;
}

