# Social Network Recommendation System

This project implements a social network recommendation system that suggests connections for users based on their skills, connections, and other attributes such as university, field of study, and work location. The goal is to create an efficient and logical method for recommending relevant users to connect within a social network, similar to platforms like LinkedIn.

## Project Objective
The main objective of this project is to build a social network by linking individuals based on their skills and professional background. The system evaluates each user's connections up to five degrees of separation and provides suggestions for potential connections that closely match their profile.

## Key Features
- **Degree-Based Recommendations:** Identifies connections up to five degrees away from the target user to suggest the most relevant connections.
- **Skill-Based Prioritization:** Gives higher priority to users with shared skills, ensuring that the most suitable connections are recommended.
- **User Preferences:** Allows users to specify which attributes (e.g., skills, university, field of study) are more important in finding potential connections.
- **Dynamic Network Updates:** Supports adding new users and connections dynamically, allowing the network to evolve over time.

## Technologies Used
- **Graph Theory:** Utilized for building and traversing the social network graph.
- **Data Structures:** Maps and lists are used for efficient handling of user connections and attributes.


## How to Use
- Input data includes user details, skills, and connections, provided in JSON format.
- Run the program with a specified target user to receive connection suggestions based on their preferences and attributes.

This project serves as a practical implementation of graph theory in building a social network and showcases methods for evaluating and recommending connections based on multi-dimensional criteria.
