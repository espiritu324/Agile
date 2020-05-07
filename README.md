
# iTag

## Table of Contents
1. [Overview](#Overview)
1. [Product Spec](#Product-Spec)
1. [Wireframes](#Wireframes)
2. [Schema](#Schema)

## Overview
Our project is a game of AR Tag that allows users to play tag with other users. Each player will
earn and lose points according to being tagged or not being it.
### Description
This project, iTag, uses Raycasting for player worldspace, ARKit3 for player detection, and parse dashboard for database work. Each



## Product Spec

### 1. User Stories (Required and Optional)

**Required Must-have Stories**

* User Login and Signup
* User can scroll through list of players and status' (who's it and not it)
* User can view scoreboard with all players
* user can view map
* user can access AR View to detect another player and "tag" them

**Optional Nice-to-have Stories**

* Plot each user location on map
* auto refresh scores with each tag (instead of refreshing manually)
* Plot points on AR View inorder to ensure human detection

### 2. Screen Archetypes

* Login/Sign up
   * Upon opening Application User fills out username and password
* Home Screen
   * Allows users to view status of each player whether they're it or not
* Player Scoreboard
   * Allows users to view scores of each other player
* Notification Board
   * Notifies all users of someone being tagged
* Map View
   * Map view of surrounding area and who's around the user
* AR View
   * Camera view that allows for body detection and plots points to ensure human

### 3. Navigation

**Tab Navigation** 

* Login Screen
* Home Screen showing players status
* Players Scoreboard
* Maps
* Notifications
* Live Camera

**Tab Description** 

* Login Screen
- Username and password validation as well as signup.
* Home Screen
- Shows all current players and their status (hiding/it)
* Players Scoreboard
- Shows all current players scores
* Maps
- Shows map
* Notifications
- Notifications of who is it and when they were tagged
* Live Camera
- Detects players/people in camera view.


## Sprint 1
**Project Issues**
 * Time management
 * COVID19 and having to move
 * Lack of MacOS Devices
 * 
**Goals for next Sprint**
 * Complete DB
 * Complete UI
**Completed List**
 * Started UI
 * Completed Login Screen
 * Completed Map View
**Gifs**
<img src="http://g.recordit.co/RZ9ZYoeJKl.gif" width=600>

## Sprint 2
**Project Issues**
 * Ray Casting Math
 * Merge Conflits on Github
 * COVID19
 * Lack of MacOS Devices
 * Found metal unviable for this project
**Goals for next Sprint**
 * Start Research on AR and Object Detection
 * Implement Map View
 * Implement Camera View
 * Finish Game rules (point calculcation)
**Completed List**
 * Started UI
 * Completed Login Screen
 * Completed Map View
 * Completed DB
 * Completed basic UI
**Gifs**
<img src="http://g.recordit.co/XvzafAEZe1.gif" width=600>

## Sprint 3
**Project Issues**
 * ARKit3 needing an A12 chip device
 * Merge Conflits on Github
 * COVID19
 * Lack of MacOS Devices
 * Converting code from C# to Objective C header
 * Loading issues with AR View
**Goals for next Sprint**
 * Finish implementing Object Detection with rest of project
 * Implement Ray Casting to score
 * Merge lat/long coordinates with map and clarify with object detection
**Completed List**
 * Started UI
 * Completed Login Screen
 * Completed Map View
 * Completed DB
 * Completed basic UI
 * Research for AR and Object Detection
 * Body detection with both 2D and 3D functuality
 * Game Rules
 * Basic Camera View
 * Basic Map view
**Gifs**
<img src="http://g.recordit.co/1mBcCZnVWk.gif" width=600>

## Sprint 4
**Project Issues**
 * ARKit3 needing an A12 chip device
 * Multiple devices needed for demo
 * Merge Conflits on Github
 * COVID19
 * Lack of MacOS Devices
 * Random errors when loading to singular device (Loading.Entity error)
**Goals for next Sprint**
 * Fix any issues or leaks
 * Record final demo
 * Successfully play with multiple devices
**Completed List**
 * Started UI
 * Completed Login Screen
 * Completed Map View
 * Completed DB
 * Completed basic UI
 * Research for AR and Object Detection
 * Body detection with both 2D and 3D functuality
 * Game Rules
 * Basic Camera View
 * Basic Map view
 * Implementation of Ray Casting
 * Implementation of Object Detection
**Gifs**
* will update with final sprint
<img src="YOUR_WIREFRAME_IMAGE_URL" width=600>
