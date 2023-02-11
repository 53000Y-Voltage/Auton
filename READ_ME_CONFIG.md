# Robot-config.cpp
Overall, our program is simple at a glance but it is a consistent high scoring monster.

I'm going to explain our Main.cpp code first.

To start off our code we use the competition template so our robot can work when connected to a field. 

Our second step is to begin configuring the robot. This is one of the most essential and core pieces of robotics as it allows the build to work, motors and pneumatics to function and even the code being written.


We begin by defining a chasis as it is the most basic part of the robot. We do this by writing lines like this:

motor leftMotorA = motor(PORT8, ratio18_1, true);

By starting with "motor", we are telling the code we are about to define a motor. This individual motor is called leftMotorA. 
We the write " = motor(PORT8" so the code knows that the motor is whatever is plugged into port 8 on the brain. 
We then need to tell the brain what insert the motor is so that the brain knows how much to spin it.
If we did not have this, it would make the motor spin less or more than we tell it to.

For example, if it was hypothetically defined as a 18:1 insert (the green 200 RPM insert), but it was a 6:1 insert (the blue 600 RPM insert). It would only spin for 1/3 of the amount needed. (i.e. if it was told to spin for 90 degrees it would only spin 30 degrees)

This line ends with ", true);" true tells the brain the the motor is placed upside down so all values should be made negative. The semicolon tells the brain that the line is over.
