#include <bits/stdc++.h>
#include "fetch_unit.h"
using namespace std;

int main(){

    Fetch_Unit* fu = new Fetch_Unit();
    fu->init();

    fu->Instruction_Memory[0] = "A";
    fu->Instruction_Memory[1] = "B";
    fu->Instruction_Memory[2] = "C";

    while (fu->Instruction_Fetch(fu->PC) != ""){
        
        cout<<fu->Instruction_Fetch(fu->PC)<<"\n"; // Rather than cout return the fetched instruction to the next unit
        fu->update_PC();

    }
    return 0;

}