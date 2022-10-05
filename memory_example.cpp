#include "MemoryUnit.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    MemoryUnit *mu = new MemoryUnit("00",23,24,"10");
    mu->MemoryAccess();

cout<<mu->RegoutReadData;


}