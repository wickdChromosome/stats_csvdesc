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
void split(Container& cont, const string& str, const string& delim = ",") {

	boost:split(cont, str, boost::is_any_of(delim));

}

template <class Container>
double mean(Container& cont) {

	/*Gets the mean of a collection*/
	double sum = 0;
	for (string& var : cont) sum += stod(var);	
	return sum/cont.size();

}



vector<vector<string>> read_csv(string& filename, string& delim, vector<int>& cols) {

	vector<vector<string>> full_file;
	ifstream infile (filename);
	int numcols = cols.size();
	cout << "reading number of columns from file: " << numcols << endl;

	//Allocate a vector in the main vector for each column
	for (int i = 0; i < numcols; i++) {

		vector<string> col;
		full_file.push_back(col);

	}			

	string line;
	vector<string> temp;
	int linec = 0;
	//fill the vector with the chosen columns
	while(getline(infile, line)) {

		if (linec != 0) {
			split(temp, line);
			
			//check if there are more cols than the
			//number of headers
			if (temp.size() < numcols && temp.size() > numcols) {

				cout << "The CSV file is fucked" << endl;

			} else {

				int full_file_vectnum = 0;
				//add the string to the right column	
				for (auto& colnum : cols) {

					full_file[full_file_vectnum].push_back(temp[colnum]);
					full_file_vectnum += 1;
				}

				temp.clear(); //erase everything in vector

			}

		}	
		linec += 1;
	}

	return full_file;

}


int main (int argc, char *argv[]) 
{

        /*Read in the csv */
	string filename = argv[1];
	string delim = ",";
	vector<int> cols2read = {1,2};

	auto data = read_csv(filename, delim, cols2read); 

	//lets iterate over each read in column and get the mean
	for (int i=0; i < data.size(); i++) {

		cout << mean(data[i]) << endl;	

	}
	

	return 0;
}

