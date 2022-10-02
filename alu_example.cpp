#include <bits/stdc++.h>
#include "execution_unit.h"
using namespace std;

int main(){

    Execution_Unit* eu = new Execution_Unit();
    eu->init();

    //filling values in execution unit registers. In actual thing, these will be taken from prev unit.
    eu->a = 3;
    eu->b = 3;
    eu->pc = 1234;
    eu->imm = 5;
    eu->Branch = 0;
    eu->ALUSrc = 0;
    eu->ALUOp = "11";
    eu->Instruction = "101010";

    eu->update_alu_output();

    cout << eu->alu_output << " " << eu->zero << endl;

    return 0;

}