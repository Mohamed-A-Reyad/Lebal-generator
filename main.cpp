#include <iostream>
#include<fstream>

using namespace std ;

class LabelGenerator{
protected:
    string str;
    int i ;
public:
    LabelGenerator(string str , int i){
        this -> str = str;
        this -> i = i ;
    }

    string nextLabel(){
        return str + to_string(i++);
    }
};

class  FileLabelGenerator : public LabelGenerator {
    string fname;
public:

    ifstream file;
    FileLabelGenerator(string str , int i , string fname ):LabelGenerator(str,i){
        this ->fname = fname;
        file.open(fname);
    }


    string nextLabel(){
        string line;
        getline(file,line);
        return str + to_string(i++) + " " +line;

    }
};

int main() {
    LabelGenerator figureNumbers("Figure ", 1);  // the idea here is : each object has its own attributes
                                                // so the i of figure will be different of the i of point //
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }

    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }

    cout << endl;

    // here I added a file (labels) to raed a line frm it to add it in my line in my output //

    FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
}