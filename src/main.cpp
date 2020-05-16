#include <iostream>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
using namespace std;

int main(int argc, char** argv){
#ifdef __EMSCRIPTEN__
    cout<<"__EMSCRIPTEN__ = true"<<endl;
#endif
    cout<<"loren ipsun"<<endl;
    return 0;
}