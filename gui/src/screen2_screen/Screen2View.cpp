#include <gui/screen2_screen/Screen2View.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <string.h>
#include <stm32f4xx_hal.h>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{

}


void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}



void Screen2View::updateTextInTextArea(const char* texte)
{
    Unicode::strncpy(textArea3Buffer, texte, sizeof(textArea3Buffer));
    textArea3.setWildcard(textArea3Buffer);
    textArea3.invalidate();
}
