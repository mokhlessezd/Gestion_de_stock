#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void saveButton(int counterValue);
    int getCounterValue() const;
    const char* getTextFromBuffer();
    void sendData (const char *data);


protected:
    ModelListener* modelListener;
    bool button_State;
    int counterValue;

};

#endif // MODEL_HPP
