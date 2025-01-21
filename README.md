# Elroe_Labyrinth - Console App

## General Description
The Erloe Labyrinth is home to the most dangerous monsters. These monsters patrol the labyrinth and fight for control against monsters of other species. Each monster has its own set of abilities, which it uses during interactions with other monsters.

## Labyrinth Description
The Erloe Labyrinth can be represented as an N x M grid. Each coordinate (i, j) represents a room that can be either empty (denoted by '_') or a wall (denoted by '#'). The labyrinth is surrounded by walls, but these walls are not explicitly represented in the description.

The coordinates of the corners are:

- Top-left: (1, 1)
- Top-right: (1, M)
- Bottom-left: (N, 1)
- Bottom-right: (N, M)
  
When a monster moves in a specific direction, the coordinates change as follows:

- North (N): the first coordinate decreases.
- East (E): the second coordinate increases.
- South (S): the first coordinate increases.
- West (V): the second coordinate decreases.

If a monster attempts to move into a wall, it stays in place.

If a monster successfully moves into a room already occupied by another monster, an interaction occurs between the two monsters. The moving monster is called the INVADER, and the monster already in the room is the DEFENDER.

## Monster Description
Each monster is described by at least the following:

- Name: a string.
- Species: a string.
- Attack Power: an integer.
- Health Points: an integer.

## Ability Description
Each ability is described by at least the following:

- Base Power: an integer.
- Attack Coefficient: an integer.
- Health Coefficient: an integer.
- Type: one of {COMBAT, HEAL, BUFF}.
- The effective power of an ability is calculated as:
    - Base Power + [Attack Coefficient × Monster's Attack / 100] + [Health Coefficient × Monster's Health / 100], where "[]" indicates the integer part.

## Ability Types:

- COMBAT: decreases the target's health points by the ability's effective power.
- HEAL: increases the target's health points by the ability's effective power.
- BUFF: increases the target's attack power by the ability's effective power.

## Monster Interactions
An interaction between monsters happens in turns. The interaction ends when at least one monster is eliminated (Health Points ≤ 0) or when at least one monster retreats.

During a turn, the following occur:

The INVADER selects an ability.
The DEFENDER selects an ability.
Both abilities execute in parallel.
If exactly one ability has the FIRST_STRIKE effect, it executes first.

## Behavior Description

The relevant behaviors are:
  - VIOLENT: selects the most powerful COMBAT ability.


  
## Input Format

The first line contains four natural numbers: N M K D.

The next N lines describe the labyrinth grid, each line containing M characters ('_' or '#').

The following K lines describe each monster in the format:

  NAME SPECIES ATTACK HEALTH I J C_INVADER C_DEFENDER C_SUPPORT

The next A lines describe abilities in the format:
  NAME BASE_POWER ATTACK_COEF HEALTH_COEF TYPE
  
The next D lines describe the monsters' actions for each day, with K actions per line.

## Output Format
For each remaining monster after D days, output a line in the format:
NAME SPECIES ATTACK HEALTH I J

