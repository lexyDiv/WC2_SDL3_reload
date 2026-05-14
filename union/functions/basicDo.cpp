#include "../FS/FS.cpp"

void basicDo(function<void()> fn) {
    listenner(quit);
    fn();
    console.proc(mouse.x, mouse.y, mouse.leftKey);
}