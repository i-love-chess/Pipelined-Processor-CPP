#include<bits/stdc++.h>
#include "fetch_unit.h"
using namespace std;

class Decode_Unit{
    public :
        int reg[32];
        string instruction;
        string OpCode;
        string rs;
        string rt;
        string rd="";
        string shamt="";
        string funct="";
        string address="";
        bool RegDst=0,ALUSrc=0,MemtoReg=0,RegWrite=0,MemRead=0,MemWrite=0,Branch=0,ALUOp0=0,ALUOp1=0;



        void decode_main(){
            // call Instruction_Fetch() from fetch_unit class and store it in instruction var. 
            OpCode=instruction.substr(0,6);
            rs=instruction.substr(6,5);
            rt=instruction.substr(11,5);
            if(OpCode.compare("000000")==0){
                rd=instruction.substr(16,5);
                shamt=instruction.substr(21,5);
                funct=instruction.substr(26,6);
            }
            else{
                address=instruction.substr(16,16);
            }

        }

        int read_register(int r_no){
            return reg[r_no];
        }

        int write_register_mux(bool RegDst,int rt,int rd){
            if(RegDst){
                return rd;
            }
            else{
                return rt;
            }
        }

        void write_register(int r_no,int data){
            reg[r_no]=data;                                     //RegWrite
        }

        string sign_extension(string address){
            char c=address[0];
            string sign_extended=address;
            for(int i=0;i<16;i++){
                sign_extended=c+sign_extended;
            }
            return sign_extended;
        }

        void control_unit(int opcode){
            if(opcode==0){    //R type 
                RegDst=1;ALUSrc=0;MemtoReg=0;RegWrite=1;MemRead=0;MemWrite=0;Branch=0;ALUOp0=0;ALUOp1=1;
            }
            else if(opcode==35){        //LW
                RegDst=0;ALUSrc=1;MemtoReg=1;RegWrite=1;MemRead=1;MemWrite=0;Branch=0;ALUOp0=0;ALUOp1=0;
            }
            else if(opcode==43){    //SW
                RegDst=0;ALUSrc=1;MemtoReg=0;RegWrite=0;MemRead=0;MemWrite=1;Branch=0;ALUOp0=0;ALUOp1=0;
            }
            else if(opcode==4){       // BEQ
                RegDst=0;ALUSrc=0;MemtoReg=0;RegWrite=0;MemRead=0;MemWrite=0;Branch=1;ALUOp0=1;ALUOp1=0;
            }
            else{
                return;
            }
        }

};

int main(){
    Decode_Unit* du=new Decode_Unit();
    du->decode_main();
}
