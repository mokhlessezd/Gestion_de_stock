#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP
#ifndef SIMULATOR
#include <ff.h>  // Inclure la bibliothèque FatFs
#endif
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include"main.h"
class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void ShowCounterValue();
    void updateTextInTextArea(const char* text); // Ajout de la fonction pour mettre à jour le textArea2

private:
    char lignes[30][100];
    Unicode::UnicodeChar textBuffer[100]; // Déclarez textBuffer ici
#ifndef SIMULATOR

    FATFS fs;    // Variable pour stocker la structure de la carte mémoire
    FIL fil;     // Variable pour stocker le fichier sur la carte mémoire
#endif

protected:

};

#endif // SCREEN2VIEW_HPP
