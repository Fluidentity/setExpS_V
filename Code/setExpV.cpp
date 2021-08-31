#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<ctype.h>
#include"exprtk.hpp"

using namespace std;

int main() {

    
    ifstream n;
    string l0;
    string expression_string;
    n.open("expressionV");
    while(getline(n, l0)) {
        if(!(l0[0]=='|' || l0[0]=='/'))
            expression_string=l0;
    }
    n.close();
    double x, y, z;

    
    typedef double T;
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>   expression_t;
    typedef exprtk::parser<T>       parser_t;

    T x1;
    T x2;
    T x3;
    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_variable("y", y);
    symbol_table.add_variable("z", z);
    symbol_table.add_variable("x1", x1);
    symbol_table.add_variable("x2", x2);
    symbol_table.add_variable("x3", x3);

    expression_t expression;
    expression.register_symbol_table(symbol_table);
    parser_t parser;

    string a, b;
    cout << endl << endl;
    cout << "Which Vector do you want to Modify" << endl;
    cin >> a;
    b=a+".org";
    string l1;
    string l;

    ifstream m;
    m.open(a);
    if(!m)
    {
        cout << "Error opening files!" << endl;
        return 1;
    }
    ofstream m1;
    m1.open(b);

    
    while(getline(m, l)) {
        m1 << l << "\n";
    }
    m1.close();
    m.close();

    ifstream m2;
    m2.open(b);
    ifstream m3("C");
    ofstream m4;
    m4.open(a);

    string search = "internalField" ;
    string replace = "internalField   nonuniform List<vector>\n" ;
    if(!m2 || !m3 || !m4)
    {
        cout << "Error opening files!" << endl;
        return 1;
    }
    int p, p0;
    int nl=0, nl0;
    while(getline(m2, l1)) {
        p=l1.find(search, 0);
        if(p!=-1) {
            m4 << replace << "\n";
            break;
        }
        else
            m4 << l1 << "\n";
    }
    while(getline(m3, l)) {
        p=l.find(search, 0);
        if(p!=-1)   
            break;
    }
    
    getline(m3, l1);
    m4 << l1 << "\n";
    int num=stof(l1);
    float A[num+3][3];
    int i=0, j=0, k=0;
    getline(m3, l1);
    m4 << l1 << "\n";
    if (!parser.compile(expression_string,expression))
    {
        cout << "Compilation error...\n";
        return 0;
    }
    
    while(getline(m3, l1) && l1[0]=='(') {
        istringstream iss(l1);
        string word;
        while(iss >> word) {
            if(word[0]=='(')
                word=word.substr(1);
            A[i][j]=stof(word);
            j++;
        }
        x=A[i][0];
        y=A[i][1];
        z=A[i][2];
        
        x1, x2, x3 = expression.value();
        m4 << "(" << x1 << " " << x2 << " " << x3 << ")" << "\n";
        j=0;
        i++;
    }
    m4 << l1 << "\n";
    getline(m3, l1);
    m4 << l1 << "\n";
    
    while(getline(m2, l)) {
        if(!(l[0]=='(' || l[0]==')' || l[0]==';' || l[0]=='-' || isdigit(l[0])))
            m4 << l << "\n";
    }

    m2.close();
    m3.close();
    m4.close();

    return 0;
}