#ifndef AFD_TEST_H_INCLUDED
#define AFD_TEST_H_INCLUDED

void AFD_Run(string sentence,list<AFD_Edge> AFD_Edges){
    string current_state;
    bool v;
    for (list<AFD_Edge>::iterator it2 = AFD_Edges.begin(); it2 != AFD_Edges.end(); ++it2){
            if(it2->state_type == 1 || it2->state_type == 3){
                current_state = it2->id;
                break;
            }
    }
    for (char c:sentence){
        string a;
        a.push_back(c);
        v=false;
         for (list<AFD_Edge>::iterator it3 = AFD_Edges.begin(); it3 != AFD_Edges.end(); ++it3){
            if(strcmp(it3->id,current_state.c_str()) == 0){
                for (list<AFD_Transition>::iterator it4 = it3->transitions.begin(); it4 != it3->transitions.end(); ++it4){
                        if(strcmp(a.c_str(),it4->read) == 0){
                            v=true;
                            current_state = it4->to.back();
                            break;
                        }
                }
            }
        }
        if(v == false){
            printf("Sentenca Ivalida!\n");
            return;
        }
        a.pop_back();
    }
    for (list<AFD_Edge>::iterator it5 = AFD_Edges.begin(); it5 != AFD_Edges.end(); ++it5){
            if(strcmp(it5->id,current_state.c_str()) == 0){
                if(it5->state_type == 2 || it5->state_type == 3){
                    printf("Sentenca aceita!\n");
                    return;
                }
            }
    }
    printf("Sentenca nao aceita!\n");
}

#endif // AFD_TEST_H_INCLUDED
