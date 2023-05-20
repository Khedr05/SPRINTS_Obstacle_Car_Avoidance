# Obstacle_Avoidance_Robot
![WhatsApp Image 2023-05-20 at 14 05 24](https://github.com/sherifkhadr/SPRINTS_Obstacle_Car_Avoidance/assets/60091384/95f43bdf-e554-47d3-b05d-6b227aefff78)


## Static Design Project
### Brief
> Embedded C application controlling a robot to avoid obstacles and take a suitable actions.

#### Author: Team_5 

|     Members    |        🔗 [GitHub] Links               |
|----------------| --------------------------------------- |
|     Sherif     | (https://github.com/sherifkhadr)        |
|     Sharpel    | (https://github.com/sharpelmalak)       |
|     Moamen     | (https://github.com/MomenHassan12)      |
|     Mowafey    | (https://github.com/Mahmoud-Mowafy)     |

## Documentation
> - `Project Documentation`
        [Documentation](https://docs.google.com/document/d/1IRe-8jyH7wxBTIzXYDLSMfOx0oQpCD-H/edit)
> - `Team Backlog` 
        [Google Sheets](https://docs.google.com/spreadsheets/d/1XW7B8uJXqhWbA-ssNdg-yLGVKJ6-zs-nqy5UxN3s-8I/edit#gid=0) 
        [Excel]()
> - `Test Protocol` 
      [Google Sheets](https://docs.google.com/spreadsheets/d/1XW7B8uJXqhWbA-ssNdg-yLGVKJ6-zs-nqy5UxN3s-8I/edit#gid=742696996) 
      [Excel ]()
> - ---





#### System Requirement Specifications
    1. AC Components:
        1. one LCD to show the data.
        2. One 3*3 keypad to enter the desired temperature and control the curren temp.
        3. One button for stop (PB1)
        4. One Ultrasonic sensor.
    
    2. System Requirements:
        1. The car starts initially from 0 speed.
        2. The default rortation direction is to the right.
        3. Press Keypad_2 to start or stop the robit.
        4. After pressing start:
                1.	The LCD will display a centered message in line 1 “Set Def. Rot.”
                2.	The LCD will display the selected option in line 2 “Right”
                3.	The robot will wait for 5 seconds to choose between Right and Left
                4.	When PB1 is pressed once, the default rotation will be Left and the LCD line 2 will be updated
                5.	When PB1 is pressed again, the default rotation will be Right and the LCD line 2 will be updated
                6.	For each press the default rotation will changed and the LCD line 2 is updated
                7.	After the 5 seconds the default value of rotation is set
                8.	The robot will move after 2 seconds from setting the default direction of rotation.

        5. For No obstacles or objects is far than 70 centimeters.
                1.	The robot will move forward with 30% speed for 5 seconds
                2.	After 5 seconds it will move with 50% speed as long as there was no object or objects are located at more than 70 centimeters distance
                3.	The LCD will display the speed and moving direction in line 1: “Speed:00% Dir: F/B/R/S”, F: forward, B: Backwards, R: Rotating, and S: Stopped
                4.	The LCD will display Object distance in line 2 “Dist.: 000 Cm”

        6. For Obstacles located between 30 and 70 centimeters:
                1.	The robot will decrease its speed to 30%
                2.	LCD data is updated
        7. For Obstacles located between 20 and 30 centimeters
                1.	The robot will stop and rotates 90 degrees to right/left according to the chosen configuration
                2.	The LCD data is updated

        8. For Obstacles located less than 20 centimeters
        	1.	The robot will stop, move backwards with 30% speed until distance is greater than 20 and less than 30
                2.	The LCD data is updated
                3.	Then preform point 8
        9. Obstacles surrounding the robot (Bonus)
                1.	If the robot rotated for 360 degrees without finding any distance greater than 20 it will stop
                2.	LCD data will be updated.
                3.	The robot will frequently (each 3 seconds) check if any of the obstacles was removed or not and move in the direction of the furthest object.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Layered Architecture & System Modules
![obs_avoi_rob_LAyered Arch](https://github.com/sherifkhadr/SPRINTS_Obstacle_Car_Avoidance/assets/60091384/edaed449-654b-4064-a0b6-c296ab5995cc)


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Circuit Schematic
> `For lower versions you need to import the Clip_file inside your project, then update the hex file`
> - `Simulation_proteus version 8.13`[Proteus Link](https://github.com/sherifkhadr/SPRINTS_Obstacle_Car_Avoidance/blob/main/Simulation/Obstacle_Avoidance_Robot.pdsprj)
> - ` Clip_file`[Clip_file](https://github.com/sherifkhadr/SPRINTS_Obstacle_Car_Avoidance/blob/main/Simulation/lowerVersionsClip.pdsclip)
        
        
![Proteus Simulation](https://github.com/sherifkhadr/SPRINTS_Obstacle_Car_Avoidance/assets/60091384/c9fdff62-2666-4dff-b9b9-d028ab184020)




