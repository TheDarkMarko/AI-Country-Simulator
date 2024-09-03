# AI-Country-Simulator
AI Country Simulator is a C++ program that simulates the dynamics of a country, including political, economic, and social factors, updating every five seconds.

State Simulation in C++
This program simulates the dynamics of a state over time, modeling various factors such as political actions, economic changes, and social conditions. The simulation represents one year of the state's life every five seconds of real time, providing a detailed view of how different events impact the state.

Features
Agent Types:

Politician: Manages popularity and enacts laws that affect the state. Actions include introducing new laws, repealing existing ones, and addressing protests.
Citizens: Participate in protests and affect employment rates.
Students: Their graduation rates fluctuate based on various conditions.
State Dynamics:

Economy: Tracks Gross Domestic Product (GDP), economic growth, and inflation.
Population: Adjusts based on immigration and emigration rates.
Stability: Monitors state stability, which can be affected by protests, wars, and other events.
Events:

Wars: Triggered by international tensions, affecting stability and mobilization.
Inflation and Economic Growth: Affected by various events and policies.
Terrorist Attacks and Assassinations: Can lead to emergency elections or significant changes in the state.
Protests: Can result from new laws or their repeal, affecting stability and government policies.
Simulation Process:

The simulation runs indefinitely or until the state collapses. Each year, the simulation updates the state's status based on random events and agent actions.
Reports include GDP, GDP per capita, stability, inflation, and economic growth, providing insight into the state’s health.

How to Run

Compile the program using a C++ compiler.
Run the executable to start the simulation.

g++ -o main.cpp
Or duble click on Project1.exe


Requirements:
C++11 or later
Standard C++ libraries
