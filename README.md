MacPenumbra - Based on Vanilla and Rehatched
==============
A project to create a modernised version of Frictional Games' HPL1 game engine and Penumbra game series source code.  Aiming to be as close to vanilla as possible.

NOTE: Currently this is NOT ARM64 compatible for Macs due to a CG.Framework dependency.  Otherwise, for x86_64 Intel Mac users, this is playable.

NOTE: This is currently under heavy development.  We WILL have a proper universal macOS version eventually!  Contributors are welcome.

Building
--------
All dependencies are included in the repository. This is mostly because many of them are (very) old versions.

### macOS

* Open the Xcode project
* Select Penumbra Overture target
* Build the target
* Copy the built application and the `rehatched` folder into your pre-existing Penumbra game folder
* Run the app (macOS 11.5 or newer required)

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
