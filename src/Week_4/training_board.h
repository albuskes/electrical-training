#include <math.h>

#define D1_PIN 11
#define D2_PIN 10
#define D3_PIN 9
#define D4_PIN 6
#define D5_PIN 5

#define ANG_RANGE_1 -1.5
#define ANG_RANGE_2 -0.75
#define ANG_RANGE_3 0.75
#define ANG_RANGE_4 1.5
 
int pinArray = [D1_PIN,D2_PIN,D3_PIN,D4_PIN,D5_PIN];

namespace tb
{
    struct Vector3D
    {
        float x_g;
        float y_g;
        float z_g;
    };

    void SetBubbleIndicator(Vector3D vector)
    {
        float angle = atan2f(vector.x_g, vector.z_g);
        int pinPos;

        // Checks if angle of vector is in valid range
        if(angle <= ANG_RANGE_1)
        {
            pinPos = 0;
        }
        else if(angle > ANG_RANGE_1 && angle <= ANG_RANGE_2)
        {
            pinPos = 1;
        }
        else if(angle > ANG_RANGE_2 && angle <= ANG_RANGE_3)
        {
            pinPos = 2;
        }
        else if(angle > ANG_RANGE_3 && angle <= ANG_RANGE_4)
        {
            pinPos = 3;
        }
        else
        {
            pinPos = 4;            
        }

        // Loop through pin array
        for(int i = 0; i < 4; i++)
        {
            if(i == pinPos)
            {
                digitalWrite(pinArray[i], HIGH);
            }
            else
            {
                digitalWrite(pinArray[i], LOW);
            }
            
        }
        
    }

    
}