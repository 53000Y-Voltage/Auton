# Robot-config.cpp
Overall, our program is simple at a glance but it is a consistently high scoring.

Below is our Robot-config.cpp explained at great length:

  To start off our code, we use the competition template so our robot can work when connected to a field. 

  Our second step is to begin configuring the robot. This is one of the most essential and core pieces of robotics as it allows the  motors and pneumatics to work properly as well as the autonomous function.


We begin by defining a chasis as it is the most basic part of the robot. We do this by writing lines like this:

    motor leftMotorA = motor(PORT8, ratio18_1, true);

  By starting with "motor", we are telling the code we are about to define a motor. This individual motor is called leftMotorA. 
We the write " = motor(PORT8," so the code knows that the motor is whatever is plugged into port 8 on the brain. 
We then need to tell the brain what insert the motor is so that the brain knows how much to spin it.
If we did not have this, it would make the motor spin less or more than we tell it to.

  For example, if it was hypothetically defined as a 18:1 insert (the green 200 RPM insert), but it was a 6:1 insert (the blue 600 RPM insert). It would only spin for 1/3 of the amount needed. (i.e. if it was told to spin for 90 degrees it would only spin 30 degrees)

  This line ends with ", true);" true tells the brain the motor is placed upside down so all values should be made negative. The semicolon tells the brain that the line is over.

  This general logic follows all devices used, motors or not. The next type of device we use is a motor_group. It is written as below:

    motor intakeMotorA = motor(PORT11, ratio18_1, false);
    motor intakeMotorB = motor(PORT18, ratio18_1, false);
    motor_group intake = motor_group(intakeMotorA, intakeMotorB);
    
  The code uses a motor_group to group two motors together, named intakeMotorA and intakeMotorB, that may be used together. For example, the motor in specific used in this example is for the two intake motors. The two motors are defined seperately to later be used in the motor_group line. It is defined as a motor_group and is named intake. Then inside the parantheses, there is just the two motors instead of the ports and motor placement. This is because that part has already been defined 
