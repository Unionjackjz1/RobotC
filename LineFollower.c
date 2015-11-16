#pragma config(Sensor, S2,     light,                  sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 true && true = true
 false && false = false
 false && true = false
 true && false = false
*/

int Threshold = 45;
int Loop = 0;

void display()
{
	displayMotorValues(line1, motorB);
	displayMotorValues(line2, motorC);
    displaySensorValues(line4, light);
}

task main()
{
    playSound(soundFastUpwardTones);
    wait1Msec(0500);
	
	while(true)
	{
		while(SensorValue[light] < Threshold - 5)
		{
			motor[motorB] = 0;
			motor[motorC] = 75;
            display();
		}

		while(SensorValue[light] > Threshold + 5)
		{
			motor[motorB] = 75;
			motor[motorC] = 0;
            display();
        }
        while(SensorValue[light] = Threshold ||
              SensorValue[light] = Threshold - 1 ||
              SensorValue[light] = Threshold - 2 ||
              SensorValue[light] = Threshold - 3 ||
              SensorValue[light] = Threshold - 4 ||
              SensorValue[light] = Threshold + 1 ||
              SensorValue[light] = Threshold + 2 ||
              SensorValue[light] = Threshold + 3 ||
              SensorValue[light] = Threshold + 4 ||)
        {
            motor[motorB] = 50;
            motor[motorC] = 50;
        }
	}
}
