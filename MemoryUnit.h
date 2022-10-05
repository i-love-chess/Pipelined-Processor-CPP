#include <bits/stdc++.h>
using namespace std;

class MemoryUnit
{
    public:
    string ReginZero;
    int ReginALUResult;
    int ReginReadData2;
    string ReginAddresult;
    int RegoutReadData;
    
    int memory[1000]={};
    MemoryUnit(string a,int b,int c,string d)
    {
        ReginZero=a;
        ReginALUResult=b;
        ReginReadData2=c;
        ReginAddresult =d;
        
    }
    MemoryUnit()
    {
         ReginZero="";
        ReginALUResult=0;
        ReginReadData2=0;
        ReginAddresult ="";
    }
    
    int RegoutALUResult = ReginALUResult;
    void MemoryAccess()
    {
        RegoutReadData = memory[ReginALUResult];

        memory[ReginALUResult]=ReginReadData2;
    }




};