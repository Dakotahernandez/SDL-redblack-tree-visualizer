# SDL-RedBlack-Tree-Visualizer

## Goal
The goal of this project is to implement a Red-Black Tree data structure and visualize its operations using the `SDL_Plotter` class. The primary objectives are:

- To understand the properties of Red-Black Trees.
- Implement insertion, deletion, and rebalancing operations.
- Create a visual representation of the tree using `SDL_Plotter`.

## To do list 
1)get sdl working on everything on everyones computers 
2)understand redblack trees
3)build working redblack tree
4)have sdl screen recieve data that effects red black tree
5)have sdl display trew

### Documentation Standard

#### Comments
- Comment all code that is not simple and straightforward.
- Comments must explain **what** is happening and **why**.

#### Function Block Comments
/*
 * description:
 * return:
 * precondition:
 * postcondition:

 * 
 */

Requirements

SDL2
SDL_MIXER

##### How to add and set up SDL2 and SDL_Mixer on xcode on mac
1)if you dont have homebrew download in your terminal using the following command <br />
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" <br />
2)download SDL2 and the mixer in your terminal using homebrew use the following command <br />
brew install sdl2 sdl2_mixer  <br />
3)Create a new xcode project:set as a command line tool using c++ <br />
4) Link SDL2 and SDL2_mixer Binary Libraries in Xcode <br />
You need to link the SDL2 and SDL2_mixer binary libraries to your Xcode project. <br />
In Xcode, select your project from the Project Navigator (left panel). <br />
Under Targets, select your project target (usually the same name as your project). <br />
Go to the Build Phases tab. <br />
In the Link Binary With Libraries section, click the + button. <br />
Choose Add Other <br />
once the tab comes up use the keybind command + shift + G <br />
then search /opt/homebrew/lib  <br />
Add libSDL2.dylib and libSDL2_mixer.dylib to your project(it will say open instead of add but it will add) <br />
5)Set Up Header Search Paths <br />
Select your project in the Project Navigator (left-hand side). <br />
Go to the Build Settings tab. <br />
In the search bar, type Header Search Paths. <br />
Double-click on Header Search Paths and add the following paths: <br />
For SDL2: /opt/homebrew/include  <br />
For SDL2_mixer: /opt/homebrew/include/SDL2 <br />
leave both as non recursive <br />
6)Set Up Library Search Paths <br />
In Build Settings, search for Library Search Paths. <br />
Double-click Library Search Paths and add  <br />
For SDL2: /opt/homebrew/include  <br />
For SDL2_mixer: /opt/homebrew/include/SDL2 <br />
non recursive again <br />
7)finally theres been a recent update to the SDL libraies so their signauture is diffrent <br />
and flagged by apple security so you must turn off signature checking  <br />
Select your project in the Project Navigator (the left panel). <br />
Go to the "Signing & Capabilities" Tab: <br />
Add the "Disable Library Validation" Entitlement: <br />
Scroll down to see if the "App Sandbox" capability is enabled.  <br />
If not, add it by clicking the + button in the upper-left corner and selecting App Sandbox. <br />
Once App Sandbox is added, click on it to expand the entitlement options. <br />
Under Security, you’ll find the Disable Library Validation option. <br />
Enable it by checking the box next to Disable Library Validation. <br />
 <br />
the SDL is now properlly connected <br />
now clean your build (shift + command + k) <br />
try and build (shift + command + b)it before running to try and make sure there are no error <br />
if it builds safely run it(command + r) <br />
additional notes  <br />
if you cant find your paths for the search paths you can search for your search paths in your console with  <br />
find / -name "SDL2" 2>/dev/null <br />

