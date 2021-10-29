#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "rapidxml.hpp"
#include "XML_READ.h"
#include "AFN_TO_AFD.h"
#include "XML_WRITE.h"
#include "AFD_Test.h"

int main(void)
{
    list<Edge> Edges;
    list<AFD_Edge> AFD_Edges;
    Read_file("Teste.jff",&Edges);
    AFN_to_AFD(&Edges, &AFD_Edges);
    Write_AFD(AFD_Edges);
    string str;
    while (true){
        cout<<"\nInserindo Sentenca!\n";
        cout<<"Digite a sentenca: ";
        getline(cin, str);
        AFD_Run(str,AFD_Edges);
    }

}


