#include <bits/stdc++.h>
using namespace std;

class Fetch_Unit{
    
    public:
        
        int PC;

        std::string Instruction_Memory[1000];

        void init(){
            this->PC = 0;
            for (int i = 0; i < 1000; i++){
                this->Instruction_Memory[i] = "";
            }
        }
        
        int update_PC(){
            this->PC += 4;
            return this->PC;
        }

        std::string Instruction_Fetch(int cur_pc){
            if (cur_pc > 3996) return "";
            return this->Instruction_Memory[cur_pc/4];
        }
};