#include <bits/stdc++.h>
using namespace std;

class Execution_Unit{
    public:
        int a;
        int b;
        int pc;
        int imm;
        string Instruction;

        bool Branch;
        bool ALUSrc;
        string ALUOp;

        int alu_output;
        int zero;

        void init(){
            a = 0;
            b = 0;
            pc = 0;
            imm = 0;
            Branch = 0;
            ALUSrc = 0;
            ALUOp = "";
            Instruction = "";
            alu_output = 0;
            zero = 0;
        }

        // int mux1(){
        //     if(this->Branch){
        //         return this->pc;
        //     }
        //     else{
        //         return this->a;
        //     }
        // }

               

        int mux2(){
            if(this->ALUSrc){
                return this->imm;
            }
            else{
                return this->b;
            }
        }

        string ALUControl(){
            //look aluop on internet and verify!!!!!
            if((this->ALUOp == "00")||(this->ALUOp == "11")){   //here 00 is load and 11 is store
                return "add";
            }
            else if(this->ALUOp == "01"){   //for beq and bne
                return "subtract";
            }
            else{
                if(this->Instruction == "100000"){
                    return "add";
                }
                else if(this->Instruction == "100010"){
                    return "subtract";
                }
                else if(this->Instruction == "100100"){
                    return "AND";
                }
                else if(this->Instruction == "100101"){
                    return "OR";
                }
                else if(this->Instruction == "101010"){
                    return "set on less than";
                }
                else if(this->Instruction == "111111"){ //look on internet
                    return "multiply";
                }
                else if(this->Instruction == "101111"){
                    return "divide";
                }
            }
        }

        int alu_main(){
            string alu_control = this->ALUControl();
            int a1 = this->a;
            int a2 = this->mux2();
            if(alu_control == "add"){
                return a1+a2;
            }
            else if(alu_control == "subtract"){
                return a1-a2;   //!!!!
            }
            else if(alu_control == "AND"){
                return (a1&a2);
            }
            else if(alu_control == "OR"){
                return (a1|a2);
            }
            else if(alu_control == "set on less than"){
                return (a1<a2)?1:0;
            }
            else if(alu_control == "multiply"){
                return (a1*a2);
            }
            else if(alu_control == "divide"){
                return (int)(a1/a2);
            }
        }

        void update_alu_output(){
            this->alu_output = this->alu_main();
            if(this->Branch){
                this->zero = this->alu_output;
            }
        }

};