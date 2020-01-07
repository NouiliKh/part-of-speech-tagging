//
// Created by NouiliKh on 07.01.20.
//

#include "helpers.h"
#include <set>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;



set <string> read_tags(string fileName) {
    set <string> tags;
    ifstream infile(fileName);
    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;
        tags.insert(s);
    }
    return tags;
}

class Dataset{
public:

    Dataset(string tagFile, string dataFile) {
        set <string> tagSet = read_tags(tagFile);
    }
};
