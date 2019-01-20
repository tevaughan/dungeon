# dungeon

ASCII hack-and-slash game inspired by old AD&amp;D, BSD hack, and Sir-Tech's
Wizardry.

This project is the reboot of a project that I worked on for a few months about
35 years ago, in Applesoft BASIC on an Apple II.

The only executable that is built at present is the unit-tests executable, and
not much has so far been implemented.  What I have so far are only:

- Infrastructure for simulating the roll of dice.
- Code representing character abilities.
- Code representing character races.

The first executable for the user is likely to be an interactive program for
generating a character and storing the character in a database.

The underlying infrastructure will be implemented as a library so that
different, thin executables, each with its own user-interface (curses, X11,
etc.) can be provided.

Eventually, there will be an executable for game-play.  At first, it will
implement a pub at which characters from the database can be assembled into a
party.  Then it will implement a market at which characters in the party can
buy and sell equipment.  Finally, it will allow entry into a multi-level maze.

A separate executable will allow for the random generation and editing of
mazes.

## License

Dungeon is copyrighted by Thomas E. Vaughan and distributed under the [terms of
the GPL, version 3 or later](LICENSE), except for
 - [enum.h](src/lib/enum.h), which is copyrighted by Anton Bachin and
   distributed under the terms of the BSD two-clause (FreeBSD) license and
 - [catch.hpp](src/test/catch.hpp), which is copyrighted by Two Blue Cubes Ltd.
   and distributed under the terms of the Boost Software License, Version 1.0.
