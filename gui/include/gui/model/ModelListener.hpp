#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void updateTime(uint8_t hour, uint8_t minute, uint8_t second) {}
    virtual void updateDate(uint8_t date, uint8_t month, uint8_t year) {}
    virtual void count (bool state){};
    virtual void updateTextFromBuffer(const char* texte) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
