#include <stdio.h>
#include <emscripten.h>

//����ŃG�N�X�|�[�g�����炵���B
EMSCRIPTEN_KEEPALIVE
float add(float x, float y){

    return x + y ;
}