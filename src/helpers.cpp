//
// Created by NouiliKh on 07.01.20.
//

#include "helpers.h"
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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

vector <string> read_data(string fileName) {
    ifstream infile(fileName);
    int i = 0;
    vector <string> sentenceIds ;
    vector <vector <string>> sentenceWords ;
    vector <vector <string>> sentenceTags ;
    vector <string> middleSentenceWords ;
    vector <string> middleSentenceTags ;


    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;
        if (s == "")
        {
            sentenceWords.insert(sentenceWords.end(), middleSentenceWords);
            sentenceTags.insert(sentenceTags.end(), middleSentenceTags);

            middleSentenceWords.clear();
            middleSentenceTags.clear();
            i = 0;
            continue;
        }

        if (i == 0) {
            sentenceIds.insert(sentenceIds.end(), s);
            i +=1;
        }
        else {
            istringstream iss(s);
            string isst;
            getline( iss, isst, '\t' );
            middleSentenceWords.insert(middleSentenceWords.end(), isst);
            getline( iss, isst, '\t' );
            middleSentenceTags.insert(middleSentenceTags.end(), isst);
        }
    }
    return sentenceIds;
}

class Dataset{
public:

    Dataset(string tagFile, string dataFile) {
        set <string> tagSet = read_tags(tagFile);
        vector <string> data = read_data(dataFile);

    }
};
