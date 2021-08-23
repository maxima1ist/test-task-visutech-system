#include <iostream>
#include <regex>
#include <functional>

#include "Logger.h"
#include "ConstantStrings.h"
#include "Exception.h"

using std::ifstream;
using std::regex;

static Logger* logger = nullptr;

void removePatternWords(ifstream& fin, const string& pattern, const std::function<void(const string&)>& callbackF) {
    const string outFileName("Output.txt");
    ofstream fout(outFileName);
    if (!fout) {
        logger->log(Tags::ERROR, "file \'" + outFileName + "\' creating failed");
        throw Exception();
    }
    else {
        logger->log(Tags::INFO, "file \'" + outFileName + "\' was created");
    }
    
    regex regexPattern = regex(pattern);
    string word;
    logger->log(Tags::INFO, "processing started");
    while (fin >> word) {
        if (std::regex_match(word, regexPattern)) {
            callbackF(word);
            logger->log(Tags::INFO, "word \'" + word + "\' was removed");
        }
        else {
            fout << word << ' ';
        }
    }
    logger->log(Tags::INFO, "processing ended");
    
    fout.close();
    logger->log(Tags::INFO, "file \'" + outFileName + "\' was closed");
}

int main(int argc, char** argv) {
    logger = new Logger("maxima1ist");
    
    try {
        if (argc < 2) {
            logger->log(Tags::ERROR, "there is no name of input text file");
            throw Exception();
        }
        
        const string inFileName(argv[1]);
        ifstream fin(inFileName);
        if (!fin) {
            logger->log(Tags::ERROR, "file \'" + inFileName + "\' opening failed");
            throw Exception();
        }
        else {
            logger->log(Tags::INFO, "file \'" + inFileName + "\' was opened");
        }
        
        // if file is empty nothing is to do
        if (fin.peek() == ifstream::traits_type::eof()) {
            logger->log(Tags::INFO, "file \'" + inFileName + "\' is empty");
        }
        else {
            string outFileName = "RemovedWords.txt";
            ofstream fout(outFileName);
            if (!fout) {
                logger->log(Tags::ERROR, "file \'" + outFileName + "\' creating failed");
                throw Exception();
            }
            else {
                logger->log(Tags::INFO, "file \'" + outFileName + "\' was created");
            }
            
            removePatternWords(fin,
                               argc > 2 && argv[2] != 0 ? Regexs::UPPER_ALPHABET : Regexs::DIGITS,
                               [&fout](const string& str) { fout << str << '\n'; });
            
            fout.close();
            logger->log(Tags::INFO, "file \'" + outFileName + "\' was closed");
        }
        
        fin.close();
        logger->log(Tags::INFO, "file \'" + inFileName + "\' was closed");
        
        std::cout << "Program worked successful." << '\n';
    }
    catch (const Exception& error) {
        std::cout << error.what() << '\n';
    }
    
    delete logger;
    
    return 0;
}
