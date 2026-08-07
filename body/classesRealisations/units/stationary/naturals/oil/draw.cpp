#include "create.cpp"
//=>out.h

void Oil::draw()
{
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;
    this->linePusherY += 2;

    int hold = 20;
    int s = 100 / this->linesCount;
    int index = this->linePusherY / s;
    this->linePusherY = this->linePusherY >= 100 + hold * s ? -hold * s : this->linePusherY;

   this->lines.forEach([](AnimLines* line){
    line->deltaX -= 0.03;
   });

    for (int i = index - hold; i < index + hold; i++)
    {
        if (i >= 0 && i < this->lines.length)
        {
            AnimLines *line = this->lines.getItem(i);
            float delta = abs(this->linePusherY - line->y);
            line->deltaX = delta / 20;
            line->alpha = 255 - delta / 2;
        }
    }

    this->lines.forEach([this](AnimLines *line)
                        { line->draw(this); });

};