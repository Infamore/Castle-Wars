# Objective

A minigame that assigns attributes to each class object that represents a CPU or NPC that are denoted as ```Wizard```, ```Knight```, ```Novice```. The goal is to defend the castle from a boss that begins the journey from a thousand miles away. Each turn the player has an option from the menu to either train, heal, list members, stall for a round, enter the final stage, or quit the game. However, after the round the boss gets closer to the castle. Once the boss reaches the destination the final stage begins. The NPC/CPU gains levels by earning experience points through battling random instances that updates the total amount of experience points. In the final form the player continues to the last stage where all developed NPC's or CPU's participate in battle with the final boss.

# Classes

## Wizard
The ```Wizard``` is a clan member that has a ```MaxHP``` of 100. The wizard class can also vary depending on whether the user selects the ```divine``` or ```arcane``` bonus that deals extra damage during a battle. 

## Knight
The ```Knight``` is a clan member that has a ```MaxHP``` of 120 along with a feature of using a sword that allows an additional boost to the damage dealt to random NPC's. The class instance also has an armor attribute that mitigates the damage dealt by random NPC's or during the final stage.

## Novice
The ```Novice``` is a clan member that has a ```MaxHP``` of 80. The novice has an additional boost to its attack stat called luck. The amount of luck increases each time the novice levels up. 

## Monster
The ```Monster``` is a random CPU/NPC that has various attributes that contributes to the process of battling the player's team/clan. The final boss and all random NPC's are all derived from this class and holds a vector of objects to allow for the battling process.

# Functions

- ```updateXP()``` is a public member function of the ```Knight```, ```Wizard```, and ```Novice``` classes that increments all common member variables. The distinct updates include increasing the armor level, magic bonus, and the luck of the ```Knight```, ```Wizard```, and ```Novice``` classes respectively.

- ```getAttack()``` is a public member function of the ```Knight```, ```Wizard```, and ```Novice``` classes that increments the private member variable ```attack```. The weapon power, magic bonus, and the luck of the ```Knight```, ```Wizard```, and ```Novice``` classes are included in the calculation of retrieving the total damage.

- ```updateHP()``` is a public member function of the ```Knight```, ```Wizard```, ```Novice```, and ```Monster``` classes that change the HP of each class instance. There are different adjustments according to each class. For example, the ```Knight``` object has armor that reduces the reduction of HP when attacked by the ```Monster``` class.

- ```
