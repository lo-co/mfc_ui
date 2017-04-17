#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/find.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::stringstream ss("");

    std::ifstream file( "/home/mrichardson/test_alicat_model_info.txt" );

    if ( file )
    {

        ss << file.rdbuf();

        file.close();

        // operations on the buffer...
    }

    string line; // Inidividual lines of test in the model_data string


    while(std::getline(ss, line)){
        if (boost::find_first(line, "Model") || boost::find_first(line, "Mdl")){

            std::vector<string> tokens;
            boost::split(tokens, line, boost::is_any_of(" "));
            std::vector<string> subtokens;

            for (auto const& token: tokens){
                boost::split(subtokens, token, boost::is_any_of("-"));
                if (subtokens.size() > 1){
                    for (auto const&stoken: subtokens){
                        cout << stoken <<endl;
                    }
                    break;
                }



            }
        }
    }

    return a.exec();
}

