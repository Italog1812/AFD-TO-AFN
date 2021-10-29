#ifndef XML_WRITE_H_INCLUDED
#define XML_WRITE_H_INCLUDED
#include <fstream>
#include <sstream>
#include <string>
#include "XML_READ.h"
#include "rapidxml_print.hpp"


void Write_AFD(list<AFD_Edge> AFD_Edges){

    int position = 90;
    string s ;
    char const *value;
    xml_document<> doc;
    xml_node<>* root = doc.allocate_node(node_element, "structure");
    doc.append_node(root);
    xml_node<>* type = doc.allocate_node(node_element, "type","fa");
    root->append_node(type);
    xml_node<>* aut = doc.allocate_node(node_element, "automaton");
    root->append_node(aut);
    xml_node<>* state;
    xml_node<>* x;
    xml_node<>* y;
    xml_node<>* initial;
    xml_node<>* Final;
    xml_node<>* transitions;
    xml_node<>* transitions_childs;

    for (list<AFD_Edge>::iterator it = AFD_Edges.begin(); it != AFD_Edges.end(); ++it){
        s = to_string(position);
        value = s.c_str();
        state = doc.allocate_node(node_element, "state");
        state->append_attribute(doc.allocate_attribute("id",it->id));
        state->append_attribute(doc.allocate_attribute("name",it->id));
        aut->append_node(state);
        x = doc.allocate_node(node_element,"x",value);
        state->append_node(x);
        y = doc.allocate_node(node_element,"y",value);
        state->append_node(y);
        if(it->state_type == 1){
            initial = doc.allocate_node(node_element,"initial");
            state->append_node(initial);
        }
        if(it->state_type == 2){
            Final = doc.allocate_node(node_element,"final");
            state->append_node(Final);
        }
    }

     for (list<AFD_Edge>::iterator it = AFD_Edges.begin(); it != AFD_Edges.end(); ++it){

            for(list<AFD_Transition>::iterator it2 = it->transitions.begin(); it2 != it->transitions.end(); ++it2){
                transitions = doc.allocate_node(node_element, "transition");
                aut->append_node(transitions);
                transitions_childs = doc.allocate_node(node_element, "from", it->id);
                transitions->append_node(transitions_childs);
                transitions_childs = doc.allocate_node(node_element, "to", it2->to.back());
                transitions->append_node(transitions_childs);
                transitions_childs = doc.allocate_node(node_element, "read", it2->read);
                transitions->append_node(transitions_childs);

            }

     }

    ofstream file_stored("Teste2.jff");
    file_stored << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
    file_stored << doc;
    file_stored.close();
    doc.clear();
    printf("AFD escrita no Teste2.jff\n");
}

#endif // XML_WRITE_H_INCLUDED
