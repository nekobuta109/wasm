#include <stdio.h>
#include <emscripten.h>

//これでエクスポートされるらしい。
EMSCRIPTEN_KEEPALIVE
float add(float x, float y){

    return x + y ;
}