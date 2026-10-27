#include "addToBuffer.cpp"
//=>out

void Nation::addToAllTracesBuffers(Trace *t)
{
    mutex mt;
    mt.lock();
    this->allTracesBuffers.getItemLnk(t->bufferIndex).push(t);
    mt.unlock();
}

Trace *Nation::getTraceFromBuffer(int index)
{
    mutex mt;
    mt.lock();
    Array<Trace *> &buffer = this->allTracesBuffers.getItemLnk(index);
    Trace *trace = buffer.find([](Trace *t)
                               { return t->readyToOut; });
    if (trace)
    {
        trace->readyToOut = false;
    }
    mt.unlock();
    return trace;
}