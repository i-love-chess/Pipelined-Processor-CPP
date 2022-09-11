#include <bits/stdc++.h>
using namespace std;

class Fetch_Unit{
    
    public:
        
        static int PC;

        static string Instruction_Memory[1000];

        void init(){
            PC = 0;
            for (int i = 0; i < 1000; i++){
                Instruction_Memory[i] = "";
            }
        }
        
        int update_PC(){
            PC += 4;
            return PC;
        }

        std::string Instruction_Fetch(int cur_pc){
            if (cur_pc > 3996) return "";
            return Instruction_Memory[cur_pc/4];
        }
};