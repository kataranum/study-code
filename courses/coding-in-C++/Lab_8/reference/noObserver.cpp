#include <iostream>

class Display
{
public:
    void show_temperature(float value)
    {
        std::cout << "Display: " << value << " C\n";
    }
};

class Logger
{
public:
    void log_temperature(float value)
    {
        std::cout << "Logger: " << value << " C\n";
    }
};

class Alarm {
public:
    void check_temperature(float value)
    {
        if (value < 30.0) {
            return;
        }

        std::cout << "Alarm: High temperature " << value << std::endl;
    }
};

class TemperatureSensor
{
private:
    float temperature = 0.0f;

    Display display;
    Logger logger;
    Alarm alarm;

public:
    void set_temperature(float value)
    {
        temperature = value;

        // directly coupled to other classes
        display.show_temperature(temperature);
        logger.log_temperature(temperature);
        alarm.check_temperature(temperature);
    }
};

int main()
{
    TemperatureSensor sensor;

    sensor.set_temperature(23.5f);

    return 0;
}