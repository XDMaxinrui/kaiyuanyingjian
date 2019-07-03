 #include "Arduino.h"#include "Morse.h"

      Morse: :Morse(int pin)

      pi nMode(pin, OUTPUT) ;_pin = pin;

      void Morse: :dot () .

      digitalWrite(_ pin, HIGH) ;delay(250) ;

      digitalWrite(_ pin, LOW) ;delay(250) ;

      void Morse: :dash()

      digitalWrite(_ pin, HIGH) ;delay(I000) ;

      digitalWrite(_ pin, LOW) ;delay(250) ;
