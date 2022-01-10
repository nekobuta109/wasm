#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>



unsigned char raw[128];
void* _heap=(void*)0;   //

EMSCRIPTEN_KEEPALIVE
unsigned char* get_heap(void)
{
    _heap = malloc(1024);
    *(unsigned char*)_heap = 0xef;  //
    printf("address= 0x%x\n", (unsigned int)_heap);
    return (unsigned char*)_heap;
}
EMSCRIPTEN_KEEPALIVE
void free_heap(void)
{
    free(_heap);
}
EMSCRIPTEN_KEEPALIVE
unsigned char* getAddress(){
    return &raw[0];
}
EMSCRIPTEN_KEEPALIVE
int test() {
    //write heap memory
    *((char*)_heap) = 1;

    //write external memory
    raw[0] = 3;
    raw[1] = 4;
    raw[2] = 5;
    return raw[7];
}

//これでエクスポートされるらしい。
EMSCRIPTEN_KEEPALIVE
float add(float x, float y){

    return x + y ;
}