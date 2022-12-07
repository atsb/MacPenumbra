MacPenumbra
==============
A project to create a modernised version of Frictional Games' HPL1 game engine and Penumbra game series source code.

To play the game after building.  Copy your Penumber Overture game data into Applications/Penumbra Overture.  After that, copy the .app bundle into this directory also.  Then just run the app bundle.  Penumbra and HPL1 were never designed to read/write from the Application Support directory and changing this is quite a convoluted process as there is a lot of Objective-C code handling resources and files as well as all the file read/write code depending on this structure.

NOTE: This is currently under heavy development.  I've largely gone back to the original code and am porting it from scratch as rehatched broke a lot of things.  This won't take very long and we WILL have a proper macOS version soon!

Building
--------
All dependencies are included in the repository. This is mostly because many of them are (very) old versions.

### macOS

* Open the Xcode project
* Select Penumbra Overture target or build each target seperately, make sure to select Universal Macs as the system.
* Build the target
* Copy the built application and the `rehatched` folder into your pre-existing Penumbra game folder
* Run the app (macOS 11.6 or newer required)

I have it setup to build the app straight into the game folder and I've symlinked the rehatched folder
in there as well, but setting that up is left as an exercise for the reader.

Project Goals
-------------
The primary goal is to get Penumbra Overture fully functional as a 64-bit Mac app so that it
can be enjoyed on macOS 11.6 and newer.  A fully vanilla experience is the goal, nothing more, nothing less.

Project Links
-------------
This repo encompasses 2 repos from Frictional Games:

* [HPL1Engine](https://github.com/FrictionalGames/HPL1Engine)
* [PenumbraOverture](https://github.com/FrictionalGames/PenumbraOverture)

There are a couple of reasons why this is not just a fork of these:
The 2 projects were designed to share some dependencies and are closely interrelated
so having them in one repo with the dependencies makes development simpler. In addition,
some of the dependencies are very old and/or have been specially built and/or modified
to work with this project. Finally, Frictional Games do not have time to properly
respond to pull requests etc so their original repos should be considered more of
a preservation effort than a live project.

Licence and Copyright
---------------------
Penumbra, Penumbra: Overture and HPL are all Copyright [Frictional Games](https://frictionalgames.com/). 
All code and assets included in this repo are licensed under GPL3, see the LICENSE file for details.

The Penumbra games and all their assets are not included with this project,
you need a pre-existing installation of the game.
