<img src='http://i294.photobucket.com/albums/mm96/JavenLoh/MCU-PilotMedium.jpg' alt='Photobucket' border='0'>
<hr />
<h1><b><i>Introduction</i></b></h1>
This project will be based on a STM32F4 MCU as the brain of the Stabilization Unit.<br>
The current goal of the MCU-Pilot project is to create a Stabilization Unit for Unmanned Aerial Vehicles to operate in outdoor environments.<br>
<br>
Typical application scenarios are unmanned air to ground surveillance.<br>
In air to ground surveillance applications, high level of stability and loitering shall be prioritized.<br>
<br>
Due to the application of this vehicle, wind resistance is very crucial. Therefore, a 600 sized single-rotor collective pitch helicopter will be used as the development platform for this project.<br>
<br>
<img src='http://i294.photobucket.com/albums/mm96/JavenLoh/KX016008TA_01.jpg' alt='Photobucket' border='0'>
<hr />
<h1><i><b>Project description</b></i></h1>
The goal of this project is to create a new flight electronic as well as software for the MCU-Pilot platform. The flight electronic mainly consists of 11-Degree Of Freedom(DOF) sensor arrangement and one Real-Time MCU. The flight electronic system will be tightly integrated to physically reduce the system's package weight and dimension.<br>
<hr />
<h1><i><b>Design task</b></i></h1>
The hardware platform includes these design tasks:<br>
<ul><li>30% Electronic design<br>
</li><li>40% Software design<br>
</li><li>15% CAD Mechanical design of Electronic Package(Multiple sensor and modules arrangement in 3D)<br>
</li><li>15% CAD Mechanical design to Improve the existing helicopter platform in 3D<br>
<hr /></li></ul>

<h1><i><b>Electronic Package Requirements</b></i></h1>
<h2><i><b>Safety Requirement:</b></i></h2>
The electronic package shall has as minimum part count as possible to reduce the chance of failure as redundancy is not an option due to weight and dimension limitation. The electronic package should be maximally safe.<br>
<br>
<br>
<h2><i><b>Flight requirements:</b></i></h2>
The Printed Circuit Board's(PCB) dimension should be as minimal as possible to fit into the helicopter. Double Layer PCB shall also be used to reduce the overall dimension of the PCB. To reduce vibration on the PCB,a thicker PCB shall also be used.<br>
<br>
<br>
<h2><i><b>Strategic requirements:</b></i></h2>
Instead of designing the electronic package to work only in 600-sized helicopters, the electronic should also be cross-platform compatible with other platform such as:<br>
<ul><li>Multi-Rotors<br>
</li><li>Fixed-Wing</li></ul>


<h2><i><b>Sensors requirements:</b></i></h2>
<ul><li>3-Axis Gyroscope<br>
</li><li>3-Axis Accelerometer<br>
</li><li>3-Axis Digital Compass<br>
</li><li>Ultra high-resolution barometer<br>
</li><li>10Hz GPS</li></ul>

<hr />
<h1><i><b>Work Flow</b></i></h1>
<ol><li><i><b>Time Constrain:</b></i> The time constrain for this project is 48weeks.(Started on 20th of March 2012)<br>
</li><li><i><b>Familiarization:</b></i> with current autopilot systems such as Arducopter, Multiwii and many more.<br>
</li><li><i><b>Literature Research:</b></i> about the sensors mentioned earlier. Choices of sensors shall be made through this research.<br>
</li><li><i><b>Software development:</b></i> Learning how to program a STM32F4 chip as well as designing a flight control system.<br>
</li><li><i><b>Flight Electronics development:</b></i> To design and manufacture the PCB for selected sensors and MCU.<br>
</li><li><i><b>Literature Research:</b></i> about the helicopter platform as mentioned earlier. Choice of  helicopter platform shall be made through this research.<br>
</li><li><i><b>Helicopter Platform Development:</b></i> To modify the current helicopter platform to suit UAV application better.<br>
</li><li><i><b>Tests and Validation:</b></i> Functional tests have to be conducted throughout the whole development of the hardware and software. In a final measurement the technical data of the newly developed hardware and the improvement over the current hardware have to be assessed.<br>
<hr />